#include "JuegoVista.h"
#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "../tools/Constantes.h"
#include "../tools/ParserEstadoJuego.h"
#include "../tools/SDL_Utils.h"

//JuegoVista::JuegoVista() : personaje(nullptr) {
JuegoVista::JuegoVista() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    /* Crear una ventana.
       El solo hecho de crearla ya la muestra en pantalla.
     */
    this->ventana = SDL_CreateWindow(
            NOMBRE_JUEGO,
            X_VENTANA,
            Y_VENTANA,
            ANCHO_VENTANA,
            ALTO_VENTANA,
            STATE_VENTANA
    );

    cargarIcono(RUTA_ICONO, this->ventana);

    this->renderizador = SDL_CreateRenderer(this->ventana, -1, SDL_RENDERER_ACCELERATED);
    this->cargadorEnemigos = new CargadorTexturasEnemigos(this->renderizador);
    this->cargadorPersonajes = new CargadorTexturasPersonajes(this->renderizador);

    this->nivel = new NivelVista(this->renderizador);
    //Los vectores de enemigos_vista y personajes_vista arrancan vacios, instanciados de forma implicita en el stack

    this->fps = 0;
    this->t_anterior_frame = SDL_GetTicks();
}

JuegoVista::~JuegoVista() {
    for (auto &personaje: this->personajes_vista){
        delete(personaje);
    }

    for (auto itr = this->enemigos_vista_map.begin(); itr != this->enemigos_vista_map.end(); ++itr) {
        for (auto &enemigo: *((*itr).second)) {
            delete(enemigo);
        }
    }

    delete (this->nivel);
    delete (this->cargadorEnemigos);
    delete (this->cargadorPersonajes);
}

void JuegoVista::reiniciar() {
    for (auto &personaje: this->personajes_vista){
        delete(personaje);
    }
    for (auto itr = this->enemigos_vista_map.begin(); itr != this->enemigos_vista_map.end(); ++itr) {

        for (auto &enemigo: *((*itr).second)) {
            delete(enemigo);
        }
        (*itr).second->clear();
    }
    this->personajes_vista.clear();
    this->enemigos_vista_map.clear();

    delete (this->nivel);

    this->nivel = new NivelVista(this->renderizador);
}

void JuegoVista::iniciar() {
    /* El clear va DESPUÉS del fondo. */
    SDL_RenderClear(this->renderizador);

}

void JuegoVista::dibujar() {
    /*
                            ::::ACLARACION:::::
    Para los rectagulos tener en cuenta de que la posicion X e Y esta ubicadO en la
    esquina superior izquierda de los mismos.

     */
    SDL_RenderClear(this->renderizador);
    this->nivel->mostrarFondo(this->renderizador);

    for(auto &personaje: this->personajes_vista) {
        SDL_RenderCopy(this->renderizador,
                       personaje->getTextura(),
                       personaje->getSpriteActual(),
                       personaje->getPosicion()
        );
    }

    for (std::map<std::string, std::vector<EnemigoVista*>*>::iterator i = this->enemigos_vista_map.begin();
         i != this->enemigos_vista_map.end(); ++i){

        for(std::vector<EnemigoVista*>::iterator enemigo = i->second->begin(); enemigo != i->second->end(); ++enemigo ){
            SDL_RenderCopy(this->renderizador,
                           (*enemigo)->getTextura(),
                           (*enemigo)->getSpriteActual(),
                           (*enemigo)->getPosicion()
            );
        }
    }

    SDL_RenderPresent(this->renderizador);
    this->fps++;
}

void JuegoVista::crearVistaPersonajes(int cantidad){
    for (int j=0; j<cantidad; ++j){
        this->personajes_vista.push_back(new PersonajeVista(X_PERSONAJE_DEFAULT, Y_PERSONAJE_DEFAULT, (int)this->personajes_vista.size(), this->cargadorPersonajes));
    }
}

void JuegoVista::eliminarVistaPersonajes(int cantidad){
    for (int j=0; j < cantidad; ++j){
        delete(this->personajes_vista[this->personajes_vista.size() - 1]);
        this->personajes_vista.erase(this->personajes_vista.begin() + (int)(this->personajes_vista.size() - 1));
    }
}

void JuegoVista::crearVistaEnemigos(std::string tipo, int cantidad){
    if(this->enemigos_vista_map.find(tipo) == this->enemigos_vista_map.end()){
        this->enemigos_vista_map[tipo] = new std::vector<EnemigoVista*>();

    }
    for (int i=0; i < cantidad; ++i){
        //map.at() lanza excepcion en caso de que no exista la clave
        this->enemigos_vista_map.at(tipo)->push_back(
                new EnemigoVista(0, 0, tipo, this->cargadorEnemigos));
    }

}

void JuegoVista::actualizarVistaEnemigos(std::string tipo, int cantidad, std::stringstream* stream_estado){
    int x, y, d;
    std::string aux;
    for (int j=0; j < cantidad; ++j){
        (*stream_estado) >> aux; //x enemigo
        x = (int)std::stof(aux);
        (*stream_estado) >> aux; //y enemigo
        y = (int)std::stof(aux);
        (*stream_estado) >> aux; //y enemigo
        d = (int)std::stof(aux);

        (*(this->enemigos_vista_map[tipo]))[(long unsigned)j]->actualizar(x,y,d);
    }
}

void JuegoVista::decodificarEstadoEnemigos(std::string estado){

    int cantidad_clase_i;
    std::string clase_i;
    std::string aux;  // palabras extraidas del estados

    std::vector<std::string>::iterator pos_tipo_enemigo;
    std::vector<std::string> tipos_enemigos_vista_actual;

    std::stringstream stream_estado(estado); // stream de las palabras de estado
    stream_estado >> aux; //leo el PRE_ENEMIGO, no sirve de nada pero lo tengo que sacar
    stream_estado >> aux; // leo cantidad de clases de cada enemigo
    int cantidad_clases = atoi(aux.c_str()); // convierto a entero la cantidad de clases

    //Obtengo los tipos de los enemigos actualmente en la vista dibujados
    for (std::map<std::string, std::vector<EnemigoVista*>*>::iterator i = this->enemigos_vista_map.begin();
         i != this->enemigos_vista_map.end(); ++i) {

        tipos_enemigos_vista_actual.push_back(i->first);
    }

    for(int i = 0; i < cantidad_clases; i++){

        stream_estado >> aux; //Clase
        clase_i = aux;

        stream_estado >> aux; //cantidad enemigos de esa clase
        cantidad_clase_i = (int)std::stof(aux);

        //Ajusto las cantidades de enemigos de esa clase en mi map de enemigos vista
        pos_tipo_enemigo = std::find(tipos_enemigos_vista_actual.begin(), tipos_enemigos_vista_actual.end(), clase_i);
        if (pos_tipo_enemigo != tipos_enemigos_vista_actual.end()) {
            tipos_enemigos_vista_actual.erase(pos_tipo_enemigo);
            cantidad_clase_i -= (int) (this->enemigos_vista_map[clase_i]->size());
            if (cantidad_clase_i >= 0) {
                this->crearVistaEnemigos(clase_i, cantidad_clase_i);
            } else {
                this->eliminarVistaEnemigos(clase_i, -1*cantidad_clase_i);
            }
        } else {
            this->crearVistaEnemigos(clase_i, cantidad_clase_i);
        }
        //Recupero el valor de cantidad_clase_i leido
        cantidad_clase_i = (int)std::stof(aux);

        //Actualizo las posiciones de los enemigos de esa clase
        this->actualizarVistaEnemigos(clase_i, cantidad_clase_i, &stream_estado);
    }

    //Elimino los enemigos de clases no recibidas
    for(auto &tipo: tipos_enemigos_vista_actual){
        cantidad_clase_i = (int) this->enemigos_vista_map[tipo]->size();
        this->eliminarVistaEnemigos(tipo, cantidad_clase_i);
    }
}

void JuegoVista::eliminarVistaEnemigos(std::string tipo, int cantidad){
    for (int j=0; j < cantidad; ++j){
        //Borro los enemigos vista que esten de mas en la ventana
        delete((*(this->enemigos_vista_map[tipo]))[this->enemigos_vista_map[tipo]->size() -1]);
        this->enemigos_vista_map[tipo]->erase(this->enemigos_vista_map[tipo]->begin() + (int)(this->enemigos_vista_map[tipo]->size() - 1) );
    }
}

void JuegoVista::actualizar(std::string estado) {

    if (parserTipoRespuesta(estado) == PRE_POSICION_JUGADOR) {
        /* Mensaje estado:
         * Posicion_personaje cantidad_personajes Nro_personaje_visible_1 x_personaje_visible_1 y_personaje_visible_1
         * dir_personaje_visible_1 ... x_personaje_visible_n y_personaje_visible_n dir_personaje_visible_n
         */
        std::vector<int> posicion = parserRespuestaPersonajePosicion(estado);
        //El vector "posicion" va a ser una lista de todos los parametros numericos del estado de personajes visibles,
        //es decir: [cantidad_personajes, nro_personaje, x1, y1, dir1, ... , xn, yn, dirn]
        int n_personajes = posicion[0];
        if(n_personajes >= (int)this->personajes_vista.size()){
            this->crearVistaPersonajes(n_personajes - (int)this->personajes_vista.size());
        } else {
            this->eliminarVistaPersonajes((int)this->personajes_vista.size() - n_personajes);
        }
        for (long unsigned i=0; i < (long unsigned)n_personajes; ++i){
            //Verifico que el numero del personaje_vista sea igual al numero del personaje que recibi
            if (this->personajes_vista[i]->getNumeroPersonaje() != posicion[i*4 + 1]) {
                this->personajes_vista[i]->actualizarTexturas(posicion[i*4 + 1], this->cargadorPersonajes);
            }
            //Actualizo las posiciones y direccion de cada personaje
            this->personajes_vista[i]->actualizar(posicion[i*4 + 2], posicion[i*4 + 3], posicion[i*4 + 4]);
        }
    }

    if (parserTipoRespuesta(estado) == PRE_POSICION_ENEMIGO) {
        this->decodificarEstadoEnemigos(estado);
    }

    //TODO: Agrego este TODO para avisar que estoy dibujando solo en el caso de recibir una actualizacion del fondo
    //TODO: que se recibe siempre
    if (parserTipoRespuesta(estado) == PRE_POSICION_VENTANA) {
        int posicion = parserRespuestaVentanaPosicion(estado);
        this->nivel->actualizarPosicionFondo(posicion);

        Uint32 deltaclock = SDL_GetTicks() - this->t_anterior_frame;
        if (deltaclock < MILISEG_MIN_FPS) {
            std::this_thread::sleep_for(std::chrono::milliseconds(MILISEG_MIN_FPS - deltaclock));
            //SDL_Delay(MILISEG_MIN_FPS - deltaclock);
        }

        this->dibujar();

        if(SDL_GetTicks() % 1000 < this->t_anterior_frame % 1000 ){
            //std::cout << "FPS: " << this->fps << std::endl;
            this->fps = 0;
        }

        this->t_anterior_frame = SDL_GetTicks();

    }
    /*
    if ( parserTipoRespuesta(estado) == PRE_NIVEL_FINALIZAR ){
        this->nivel->avanzarNivel();
    }
     */
}

void JuegoVista::avanzarNivel() {
    this->nivel->avanzarNivel();
}


void JuegoVista::destruir() {
    SDL_DestroyRenderer(this->renderizador);
    SDL_DestroyWindow(this->ventana);
}

SDL_Renderer *JuegoVista::getRenderizador() {
    return this->renderizador;
}


FondoVista *JuegoVista::getFondo() {
    return this->nivel->getFondoActual();
}

void JuegoVista::setNivel(int nro_nivel){
    for (int i = 0; i < nro_nivel; ++i){
        this->nivel->avanzarNivel();
    }

}