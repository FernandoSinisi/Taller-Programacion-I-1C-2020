#include <iostream>
#include "ControladorServidor.h"
#include "../tools/Log.h"
#include "../tools/Utils.h"
#include <vector>

ControladorServidor::ControladorServidor(int argc, char* argv[]) {
    CargadorDeConfiguracion cargador;
    cargador.cargar(argc, argv);

    this->socket_server = new Servidor();
    this->juego_controlador = nullptr;
    this->hilo_aceptador = nullptr;
    this->clientes.reserve(CANT_CONEXIONES_MAX);

    this->fps = 0;
    this->nivel_principio = true;
}

void ControladorServidor::inicializar() {
    this->socket_server->inicializar();
    loguearInfo(MSJ_INICIO_SV);
    this->hilo_aceptador = new HiloAceptador(&this->clientes,&this->mutex,this->socket_server,&this->cola_recv);

    this->aceptarCliente();

    if (!this->estaActivo()) {
        return;
    }

    this->juego_controlador = new JuegoControlador((int)this->clientes.size());

    //Vacio el buffer de inputs
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    while(this->cola_recv.desencolar(COLA_VACIA) != COLA_VACIA){
        std::this_thread::sleep_for(std::chrono::milliseconds(MILISEG_TIMEOUT_EVENTOS));
    }

    this->enviarATodos(PRE_NIVEL_INICIAR);
    //ENVIAR NIVEL_ARRANCAR
    //ESPERAR JUGADORES_LISTOS
    //Empezar mecanica_nivel mandando estados y recibiendo inputs

    //this->juego_controlador->inicializar((int)this->peers.size());
    //TODO: Enviar a los clientes la cantidad de jugadores para que
    // sepan cuantos objetos jugadorVista crear
}

void ControladorServidor::aceptarCliente() {
    this->hilo_aceptador->ejecutar();

    int cantidad_listos = 0;
    int diferencia_listo = 0;
    while (cantidad_listos < (int)getCantidadUsuarios() ) {

        diferencia_listo = this->recibirInfoCliente();
        cantidad_listos += diferencia_listo;

        if(diferencia_listo != 0){
            this->enviarATodos(std::to_string(cantidad_listos) + MSJ_JUGADOR_CONECTADO);
        }

        diferencia_listo = this->borrarDesconectados();
        cantidad_listos -= diferencia_listo;
        if(diferencia_listo != 0){
            this->enviarATodos(std::to_string(cantidad_listos) + MSJ_JUGADOR_CONECTADO);
        }



        //tiempo_final = std::chrono::system_clock::now();

        /*
         * Este sleep es para arreglar una condicion de carrera producido entre este hilo y el hilo recv
         * (de alguno de los clientes).
         *
         * El error se produce (puede producirse) en el caso de que un cliente se desconecte y el hilo recv
         * intente tomar el mutex para bloquearlo (lock) y cerrar el fd. El problema es que en este ciclo
         * while puede suceder que el intervalo de tiempo del unlock() y el lock() que se encuentra en la
         * linea siguiente al sleep puede ser tan corto que el hilo recv no llegue a enterarse de que puede
         * tomar el mutex para bloquearlo y cerrar el fd (Tanto este hilo como el hilo recv compiten por el
         * lock del mutex una vez este lo desbloquea pero pasaba que en muchos casos era este hilo el que ganaba
         * la carrera por tomar el mutex).
         *
         * Por lo tanto si se deja este espacio de tiempo (sleep), en el que el mutex esta desbloquado, se logra que
         * el hilo recv pueda tomar el mutex, bloquearlo para cerrar su fd correctamente y luego liberarlo.
         */
        std::this_thread::sleep_for(std::chrono::milliseconds(MILISEG_LOCK_CERRAR_FD));

    }

    loguearInfo(LOG_MSJ_CANT_JUGADORES_LISTOS + std::to_string(cantidad_listos));

    if (!this->estaActivo()) {
        return;
    }

    //tengo que borrar a todos los clientes conectados que no estan listos y sobran
    this->mutex.lock();
    this->borrarNoListos();
    this->mutex.unlock();

    //Le envio a los clientes un mensaje para que esperen recibirListo su numero de jugador
    this->enviarATodos(MSJ_CLIENTE_LISTO);

    //Si no le puedo enviar el mensaje a algun cliente entonces es porque se cayo luego de logearse
    //no lo elimino de la lista sino que lo dejo disponible para reconectarse
    diferencia_listo = this->actualizarDesconectados();

    //cantidad_listos -= diferencia_listo; <---- TODO: Ver si hay que borrar esta linea

    this->enviarATodos(cantidad_listos + MSJ_JUGADOR_CONECTADO );

    this->mutex.lock();
    //Le mando al cliente su numero de jugador, en cuanto lo reciba comienza el juego y sale el cartel de stage 1, etc..
    for (size_t i = 0; i < (size_t)cantidad_listos; ++i) {
        //ASIGNO A CADA CLIENTE SU NUMERO EL NUMERO DE JUGADOR QUE LE CORRESPONDE
        this->clientes[i]->asignarNroCliente(i);
        if(this->clientes[i]->estaListo()){
            this->clientes[i]->enviarMensaje(std::to_string(i));
            this->clientes[i]->enviarMensaje(PRE_NIVEL_NUM + SEPARADOR + std::to_string(0));
        }
        loguearInfo( LOG_MSJ_MANDAR_NUMERO_USUARIO + this->clientes[i]->getUsuario() + ": " + std::to_string(i));
    }
    this->mutex.unlock();
}

void ControladorServidor::borrarNoListos(){

    //VENIR CON EL MUTEX BLOQUEADO !!

    for (size_t i = 0; i < this->clientes.size(); ++i) {
        //todo: user invalido con listo = 116

        if (!this->clientes[i]->estaListo() and !esUsuarioValido(this->clientes[i]->getUsuario(), this->clientes[i]->getPassword())) {
            this->clientes[i]->enviarMensaje(MSJ_SERVER_LLENO);
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            delete(this->clientes[i]);
            this->clientes.erase(this->clientes.begin() + (int)i);
            loguearDebug(LOG_CLIENTE_DE_MAS_BORRADO);
            --i;
        }
    }
}

int ControladorServidor::actualizarDesconectados(){
    int diferencia = 0;
    this->mutex.lock();
    for (size_t i = 0; i < this->clientes.size(); ++i) {
        if (this->clientes[i]->getFD() == -1){
            this->clientes[i]->setListo(false);
            diferencia += 1;
        }
    }
    this->mutex.unlock();
    return diferencia;
}

int ControladorServidor::borrarDesconectados(){
    int diferencia = 0;
    this->mutex.lock();
    for(long unsigned i=0; i < this->clientes.size();){
        //SI EL JUGADOR SE DESCONECTO
        if (this->clientes[i]->getFD() == -1){
            //SI ESTABA LISTO Y SE DESCONECTO LE RESTO UNO A LA CANTIDAD DE JUGADORES LISTOS
            if (this->clientes[i]->estaListo()){
                diferencia += 1;
            }
            //LIBERO EL ESPACIO DE MEMORIA ASIGNADA PARA ESOS OBJETOS Y LOS ELIMINO DEL VECTOR DE HILOS
            delete(this->clientes[i]);
            this->clientes.erase(this->clientes.begin() + (int)i);
            loguearDebug(LOG_CLIENTE_DESCONECTADO_BORRADO);
        } else{
            ++i;
        }
    }
    this->mutex.unlock();
    return diferencia;
}

int ControladorServidor::recibirInfoCliente(){
    Uint16 mensaje = 0;
    unsigned short cantidad_listos = 0;
    long unsigned i;
    std::string letra;
    Uint16 aux_id;          //Numero entre 0 y CANT_CONEXIONES_MAX
    Uint16 msj_real;

    mensaje = this->cola_recv.desencolar(COLA_VACIA);

    while(mensaje != COLA_VACIA ){

        aux_id = mensaje % CANT_CONEXIONES_MAX;
        i = 0;
        this->mutex.lock();
        while( i < this->clientes.size() ){

            if ( (this->clientes[i]->getNroCliente() % CANT_CONEXIONES_MAX) == ( int ) aux_id ){

                msj_real = (Uint16) (mensaje - aux_id) / CANT_CONEXIONES_MAX;

                if(msj_real == TECLA_FIN_PASS) {
                    //Verifico si el usuario ya esta en el juego
                    bool no_esta = false;
                    auto itr = this->clientes.begin();
                    while(itr != this->clientes.end() and
                          (this->clientes[i]->getUsuario() != (*itr)->getUsuario() or
                           this->clientes[i]->getPassword() != (*itr)->getPassword() or
                           this->clientes[i]->getNroCliente() == (*itr)->getNroCliente() or
                           (*itr)->estaListo() == false)
                            ){
                        ++itr;
                    }

                    if(itr == this->clientes.end()){
                        no_esta = true;
                    }

                    if (this->esValidoCliente(clientes[i]) and no_esta) {
                        this->clientes[i]->enviarMensaje(MSJ_DATOS_VALIDOS);
                        clientes[i]->setListo(true);
                        cantidad_listos++;
                        loguearDebug(LOG_MSJ_CLIENTE_LISTO_1 + std::to_string( clientes[i]->getFD()) + LOG_MSJ_CLIENTE_LISTO_2);

                    } else {
                        if (no_esta) {
                            this->clientes[i]->enviarMensaje(MSJ_DATOS_INVALIDOS);
                        } else {
                            this->clientes[i]->enviarMensaje(MSJ_CLIENTE_YA_CONECTADO);
                        }
                        std::this_thread::sleep_for(std::chrono::milliseconds(200));
                        delete (clientes[i]);
                        this->clientes.erase(this->clientes.begin() + (int)i);
                        loguearInfo(LOG_CLIENTE_INVALIDO_BORRADO);
                    }

                    loguearInfo( LOG_CLIENTE_VALIDADO + clientes[i]->getUsuario() );
                }

                else if(msj_real == TECLA_FIN_NOMBRE){
                    clientes[i]->setNombreCompleto(true);
                }
                else{
                    letra = mapeo_nro_letra[msj_real];
                    clientes[i]->agregarCaracter(letra);
                }
                break;
            }
            i++;
        }
        this->mutex.unlock();
        mensaje = this->cola_recv.desencolar(COLA_VACIA);
    }
    return cantidad_listos;
}

bool ControladorServidor::esValidoCliente(Cliente *cliente){
    //Ya vengo con el mutex bloqueado de la funcion recibirInfoCliente
    bool infoValida = esUsuarioValido(cliente->getUsuario(), cliente->getPassword());
    if(infoValida){
        for(auto &c: this->clientes){
            if ((c->getUsuario().compare(cliente->getUsuario()) == 0 ) && (c->getFD() != -1) ){
                return true;
            }
        }
    }
    return false;

}

void ControladorServidor::actualizar(){
    Uint32 startclock = SDL_GetTicks();

    //Reviso que si estan todos los clientes listos, borro a los que no correspondan:
    size_t cant_listos = 0;
    this->mutex.lock();
    auto itr = this->clientes.begin();
    while(itr != this->clientes.end()){
        if ((*itr)->estaListo()){
            ++cant_listos;
        }
        ++itr;
    }
    if (cant_listos == getCantidadUsuarios() and cant_listos < this->clientes.size()){
        this->borrarNoListos();
    }

    //actualizo los inputs de los clientes
    this->actualizarInputs();
    this->mutex.unlock();

    //Al principio del nivel este no arranca hasta que todos los clientes esten listos
    this->juego_controlador->actualizar();

    if (this->juego_controlador->nivelEmpezado()) {

        std::string mensaje_estado_personajes = this->juego_controlador->getEstadoPersonajes();
        std::string mensaje_estado_enemigos = this->juego_controlador->getEstadoEnemigos();
        std::string mensaje_estado_fondo = this->juego_controlador->getEstadoFondo();

        this->mutex.lock();
        for (long unsigned i=0; i<this->clientes.size();++i){
            if(this->clientes[i]->getFD() != -1 && this->clientes[i]->estaListo()){
                if (this->nivel_principio) {
                    this->clientes[i]->actualizarPingInicial();
                }

                else if (this->clientes[i]->pingRecibido()){
                    this->clientes[i]->enviarMensaje(mensaje_estado_personajes);
                    this->clientes[i]->enviarMensaje(mensaje_estado_enemigos);
                    this->clientes[i]->enviarMensaje(mensaje_estado_fondo);
                    this->clientes[i]->enviarMensaje(MSJ_PING);
                    this->clientes[i]->setPingRecibido(false);
                }

                else if (this->clientes[i]->getPing() > MS_PING_DESCONECTADO) {
                    this->clientes[i]->desconectar();
                    this->juego_controlador->desconectar(this->clientes[i]->getNroCliente());
                }
            }
        }
        this->mutex.unlock();

        if(this->nivel_principio){
            this->nivel_principio = false;
        }
    }

    // Fin del juego
    if (this->juego_controlador->juegoFinalizado()) {
        this->enviarATodos(PRE_NIVEL_FINALIZAR);
        std::this_thread::sleep_for(std::chrono::seconds(3));
        this->enviarATodos(MSJ_CERRAR_CLIENTE);
        return;
    }

    //Avanzar de nivel
    if (this->juego_controlador->nivelFinalizado()) {
        this->enviarATodos(PRE_NIVEL_FINALIZAR);
        std::this_thread::sleep_for(std::chrono::seconds(3));
        this->enviarATodos(PRE_NIVEL_INICIAR);
        this->nivel_principio = true;
    }

    // Limito las actualizaciones por segundo a 60
    Uint32 deltaclock = SDL_GetTicks() - startclock;
    if (deltaclock < MILISEG_TIMEOUT_EVENTOS) {
        std::this_thread::sleep_for(std::chrono::milliseconds(MILISEG_TIMEOUT_EVENTOS - deltaclock));
    }

    this->fps++;
    if(SDL_GetTicks() % 1000 < startclock % 1000 ){
        //std::cout << "FPS: " << this->fps << std::endl;
        this->fps = 0;
    }

}

bool ControladorServidor::estaActivo(){
    int jugadores_desconectados = 0;
    std::unique_lock<std::mutex> lock(this->mutex);
    for(auto &c: this->clientes){
        if(c->getFD()==-1){
            ++jugadores_desconectados;
        }
    }
    if(jugadores_desconectados == (int)this->clientes.size() ) { // or this->juego_controlador->estaActivo()){
        this->actualizarInputs(); //Solo para logueo
        return false;
    }
    return true;
}

void ControladorServidor::enviarATodos(std::string mensaje){
    this->mutex.lock();
    for (long unsigned i=0; i<this->clientes.size();++i){
        if(this->clientes[i]->getFD() != -1 && this->clientes[i]->estaListo()){
            this->clientes[i]->enviarMensaje(mensaje);
        }
    }
    this->mutex.unlock();
}

void ControladorServidor::actualizarInputs(){

    //VENGO CON EL MUTEX BLOQUEADO DEL ACTUALIZAR

    //Popea de la cola_recv y  le manda los inputs al modelo del juego
    uint16_t input = this->cola_recv.desencolar(COLA_VACIA);
    while(input != COLA_VACIA) {

        //Cliente desconectado:
        if (input / CANT_CONEXIONES_MAX == 0) {
            auto itr = this->clientes.begin();
            while (itr != this->clientes.end() and ((*itr)->getNroCliente() != input % CANT_CONEXIONES_MAX)) {
                ++itr;
            }
            if (itr == this->clientes.end()) {
                return;
            }
            //Su fd debe ser -1 ya que se desconecto
            (*itr)->setListo(false);

            loguearInfo( LOG_CLIENTE_DESCONECTADO + (*itr)->getUsuario() );

            this->juego_controlador->desconectar((*itr)->getNroCliente());

        //Recibi rta del ping:
        }
        else if (input / CANT_CONEXIONES_MAX == TECLA_PING_RECIBIDO) {
            auto itr = this->clientes.begin();
            while (itr != this->clientes.end() and ((*itr)->getNroCliente() != input % CANT_CONEXIONES_MAX)) {
                ++itr;
            }
            if (itr == this->clientes.end()) {
                return;
            }
            (*itr)->setPingRecibido(true);

        //Recibi una letra:
        }

        else if (input > (TECLA_JUEGO_MAX * CANT_CONEXIONES_MAX)) {

            //itr = iterador que apunta al cliente nuevo que esta mandando sus datos de reconexion
            auto itr = this->clientes.begin();
            while (itr != this->clientes.end() and ((*itr)->getNroCliente() != input % CANT_CONEXIONES_MAX)) {
                ++itr;
            }
            if (itr == this->clientes.end()) {
                return;
            }

            if (input / CANT_CONEXIONES_MAX == TECLA_FIN_PASS) {

                //itr2 = iterador que apunta al cliente que tenga el mismo nombre, contraseña que el cliente nuevo y este desconectado
                bool ya_esta_conectado = false;
                auto itr2 = this->clientes.begin();
                while (itr2 != this->clientes.end()) {
                    if ((*itr2)->getUsuario() == (*itr)->getUsuario() and (*itr2)->getPassword() == (*itr)->getPassword()){
                        if ((*itr2)->getFD() != -1){
                            if ((*itr2)->getNroCliente() != (*itr)->getNroCliente()){
                                ya_esta_conectado = true;
                            }

                        } else {
                            loguearInfo( LOG_CLIENTE_VALIDADO + (*itr2)->getUsuario() );
                            break;
                        }

                    }
                    ++itr2;
                }

                if (itr2 == this->clientes.end()) {
                    if (ya_esta_conectado) {
                        (*itr)->enviarMensaje(MSJ_CLIENTE_YA_CONECTADO);
                    } else {
                        (*itr)->enviarMensaje(MSJ_DATOS_INVALIDOS);
                    }
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                    delete ((*itr));
                    this->clientes.erase(itr++);
                    loguearInfo(LOG_CLIENTE_INVALIDO_BORRADO);
                    return;
                }

                else {
                    (*itr)->enviarMensaje(MSJ_DATOS_VALIDOS);
                    (*itr)->enviarMensaje(MSJ_CLIENTE_LISTO);
                    (*itr)->asignarNroCliente((size_t)(*itr2)->getNroCliente());
                    (*itr)->enviarMensaje(std::to_string((*itr)->getNroCliente()));
                    (*itr)->enviarMensaje(PRE_NIVEL_NUM + SEPARADOR + std::to_string(this->juego_controlador->getNumeroNivel()));
                    (*itr)->setListo(true);
                    this->juego_controlador->conectar((*itr)->getNroCliente());
                    loguearDebug(LOG_CLIENTE_RECONECTADO);
                    loguearDebug(LOG_MSJ_CLIENTE_LISTO_1 + std::to_string((*itr)->getFD()) + LOG_MSJ_CLIENTE_LISTO_2);

                    delete ((*itr2));
                    this->clientes.erase(itr2++);

                    (*itr)->actualizarPingInicial();
                    return;
                }

            } else if (input / CANT_CONEXIONES_MAX == TECLA_FIN_NOMBRE){
                (*itr)->setNombreCompleto(true);
            } else {
                /* TODO: Agregar "letra" recibida al nombre/pass del cliente nuevo y seguir esperando para ver si
                 *       tiene el nombre/pass de algun cliente que este jugando y se haya desconectado
                 */

                std::string letra = mapeo_nro_letra[input / CANT_CONEXIONES_MAX];
                (*itr)->agregarCaracter(letra);

            }

        //Recibi un input del juego:
        } else {
            //En caso de desconexion solo popea el numero de jugador, en ese caso el juego deberia poder interpretarlo correctamente
            this->juego_controlador->actualizar(input);
        }

        input = this->cola_recv.desencolar(COLA_VACIA);
    }
}

ControladorServidor::~ControladorServidor() {
    this->enviarATodos(MSJ_CERRAR_CLIENTE);
    this->mutex.lock();
    for(auto &c: this->clientes){
        delete(c);
    }
    this->mutex.unlock();
    if (this->hilo_aceptador) {
        delete(this->hilo_aceptador);
    }
    this->mutex.lock();
    delete(this->socket_server);
    this->mutex.unlock();
    delete(this->juego_controlador);
}