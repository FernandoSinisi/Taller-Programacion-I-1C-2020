#include "JuegoControlador.h"
#include <SDL2/SDL.h>
#include "../vista/JuegoVista.h"
#include "../tools/Log.h"

JuegoControlador::JuegoControlador() {
    this->vista = new JuegoVista();
    this->menu = new MenuJuegoControlador(this->vista->getRenderizador());
    this->menu_log = nullptr;
    this->cartel_controlador = new CartelControlador(this->vista->getRenderizador(),
                                                     CARTELES);
    this->tecla_apretada = TECLA_NINGUNA;

    this->cola_actualizaciones_vista = new ColaProtegida<std::string>();
    this->hilo_dibujador = new HiloDibujador(this->cola_actualizaciones_vista, this->vista);
    this->hilo_dibujador->ejecutar();
}

JuegoControlador::~JuegoControlador() {
    delete(this->hilo_dibujador);
    delete(this->vista);
    delete(this->cartel_controlador);
    if (this->menu) {
        delete(this->menu);
    }
    if (this->menu_log) {
        delete(this->menu_log);
    }
    delete(this->cola_actualizaciones_vista);

    TTF_Quit();
    SDL_Quit();
}

void JuegoControlador::reiniciar() {
    delete(this->hilo_dibujador);
    delete(this->cola_actualizaciones_vista);

    this->vista->reiniciar();

    this->resetearCartel();

    if (this->menu) {
        delete(this->menu);
    }
    if (this->menu_log) {
        delete(this->menu_log);
    }

    this->menu_log = nullptr;

    this->menu = new MenuJuegoControlador(this->vista->getRenderizador());

    this->cola_actualizaciones_vista = new ColaProtegida<std::string>();
    this->hilo_dibujador = new HiloDibujador(this->cola_actualizaciones_vista, this->vista);
    this->hilo_dibujador->ejecutar();

}

bool JuegoControlador::iniciar() {
    this->menu->iniciar();
    this->vista->iniciar();
    //this->vista->actualizar(this->juego->getEstadoPersonaje());
    return true;
}

void JuegoControlador::cartelIniciarJuego(){
    this->cartel_controlador->setIniciarJuego();
}

bool JuegoControlador::actualizarMenu() {
    return this->menu->actualizar();
}

bool JuegoControlador::inicioElJuego() {
    return this->menu->estaIniciado();
}

bool JuegoControlador::juegoCancelado(SDL_Event *evento) {
     if (this->menu) return this->menu->estaCancelado(evento);
     else return this->menu_log->estaCancelado(evento);
}

bool JuegoControlador::actualizar(SDL_Event* evento, ColaProtegida<uint16_t>* cola_inputs) {
    //this->vista->dibujar();

//    this->vista->getFondo()->actualizar();

//    std::string estado_personaje = this->juego->getEstadoPersonaje();
//    this->vista->actualizar(estado_personaje);

//    int cantidad_enemigos = this->juego->getCantidadEnemigos();
/*
    for (int i = 0; i < cantidad_enemigos; i = i + 1) {
        std::string estado_enemigo = this->juego->getEstadoEnemigo(i);
        this->vista->actualizar(estado_enemigo);
    }
*/
//    std::string estado_fondo = this->juego->getEstadoFondo();
//    this->vista->actualizar(estado_fondo);

    SDL_PollEvent(evento);
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    if (evento->type == SDL_QUIT or keystates[SDL_SCANCODE_ESCAPE]) {
        loguearInfo(LOG_JUEGO_CERRADO_POR_USER);
        this->terminar();
        return false;
    }

    if (keystates[SDL_SCANCODE_UP] and keystates[SDL_SCANCODE_LEFT]) {
        if (this->tecla_apretada != TECLAS_ARRIBA_IZQUIERDA) {
            cola_inputs->encolar(TECLAS_ARRIBA_IZQUIERDA);
            loguearDebug(LOG_MOV_SUP_IZQ);
            this->tecla_apretada = TECLAS_ARRIBA_IZQUIERDA;
        }

    } else if (keystates[SDL_SCANCODE_UP] and keystates[SDL_SCANCODE_RIGHT]) {
        if (this->tecla_apretada != TECLAS_ARRIBA_DERECHA) {
            cola_inputs->encolar(TECLAS_ARRIBA_DERECHA);
            loguearDebug(LOG_MOV_SUP_DER);
            this->tecla_apretada = TECLAS_ARRIBA_DERECHA;
        }

    } else if (keystates[SDL_SCANCODE_DOWN] and keystates[SDL_SCANCODE_LEFT]) {
        if (this->tecla_apretada != TECLAS_ABAJO_IZQUIERDA) {
            cola_inputs->encolar(TECLAS_ABAJO_IZQUIERDA);
            loguearDebug(LOG_MOV_ABA_IZQ);
            this->tecla_apretada = TECLAS_ABAJO_IZQUIERDA;
        }

    } else if (keystates[SDL_SCANCODE_DOWN] and keystates[SDL_SCANCODE_RIGHT]) {
        if (this->tecla_apretada != TECLAS_ABAJO_DERECHA) {
            cola_inputs->encolar(TECLAS_ABAJO_DERECHA);
            loguearDebug(LOG_MOV_ABA_DER);
            this->tecla_apretada = TECLAS_ABAJO_DERECHA;
        }

    } else if (keystates[SDL_SCANCODE_UP]) {
        if (this->tecla_apretada != TECLA_ARRIBA) {
            cola_inputs->encolar(TECLA_ARRIBA);
            loguearDebug(LOG_MOV_ARRIBA);
            this->tecla_apretada = TECLA_ARRIBA;
        }

    } else if (keystates[SDL_SCANCODE_LEFT]) {
        if (this->tecla_apretada != TECLA_IZQUIERDA) {
            cola_inputs->encolar(TECLA_IZQUIERDA);
            loguearDebug(LOG_MOV_IZQ);
            this->tecla_apretada = TECLA_IZQUIERDA;
        }

    } else if (keystates[SDL_SCANCODE_DOWN]) {
        if (this->tecla_apretada != TECLA_ABAJO) {
            cola_inputs->encolar(TECLA_ABAJO);
            loguearDebug(LOG_MOV_ABAJO);
            this->tecla_apretada = TECLA_ABAJO;
        }

    } else if (keystates[SDL_SCANCODE_RIGHT]) {
        if (this->tecla_apretada != TECLA_DERECHA) {
            cola_inputs->encolar(TECLA_DERECHA);
            loguearDebug(LOG_MOV_DER);
            this->tecla_apretada = TECLA_DERECHA;
        }

    } else if (this->tecla_apretada != TECLA_NINGUNA) {
        cola_inputs->encolar(TECLA_NINGUNA);
        this->tecla_apretada = TECLA_NINGUNA;

    }

    return   (evento->type != SDL_QUIT)
          && !(keystates[SDL_SCANCODE_ESCAPE]);
}

void JuegoControlador::desactivarInput(){
    this->cartel_controlador->desactivarInput();
}

void JuegoControlador::activarInput(){
    this->cartel_controlador->activarInput();
}

bool JuegoControlador::iniciarNivel(SDL_Event* evento){
    return this->cartel_controlador->iniciarNivel(evento);
}

void JuegoControlador::finalizarNivel(){
    //TODO esto solo si finaliza el nivel ganandolo OJO SI PIERDE NO ES MOSTRAR EL CARTEL SIGUIENTE.
    this->cartel_controlador->cambiar();
    this->vista->avanzarNivel();
}

void JuegoControlador::actualizarVista(std::string estado){
    this->cola_actualizaciones_vista->encolar(estado);
    //this->vista->actualizar(estado);
}

/*
bool JuegoControlador::avanzarNivel(){
    if (!this->cartel_controlador->iniciar(this->evento)){
        this->terminar();
        return false;
    }

    if (this->juego->estaActivo() and !this->cartel_controlador->actualizar(this->evento)){
        this->terminar();
        return false;
    }

    return true;
}

 */
void JuegoControlador::terminar() {
    this->vista->destruir();
}

void JuegoControlador::menuLogReestablecer() {
    this->menu_log->reestablecer();
}

void JuegoControlador::reestablecerMenu() {
    this->menu->reestablecer();
}

bool JuegoControlador::actualizarCartel(SDL_Event* evento) {
    return this->cartel_controlador->actualizar(evento, false);
}

void JuegoControlador::retrocederCartel() {
    this->cartel_controlador->retrocederCartel();
}

void JuegoControlador::resetearCartel() {
    this->cartel_controlador->resetearCarteles();
}

void JuegoControlador::cambiarCartel() {
    this->cartel_controlador->cambiar();
}

int JuegoControlador::actualizarMenuLog() {
    return this->menu_log->actualizar();
}

bool JuegoControlador::menuLogEstaIniciado() {
    return this->menu_log->estaIniciado();
}

void JuegoControlador::actualizarJugadoresConectados(std::string mensaje) {
    this->cartel_controlador->actualizarJugadoresConectados(mensaje);
}

void JuegoControlador::iniciarVista() {
    this->vista->iniciar();
}

//Setea los carteles de nivel y el nivel a dibujar a partir de un mensaje de la forma "PRE_NIVEL_NUM n", con n el numero de nivel (entre 0 y 2)
void JuegoControlador::actualizarNivel(std::string estado_nivel){
    std::stringstream str(estado_nivel);
    std::string aux;
    str >> aux;
    if (aux == PRE_NIVEL_NUM){
        str >> aux;
        int nivel = (int)strtol(aux.c_str(), NULL, 10);
        this->cartel_controlador->setNivel(nivel);
        this->vista->setNivel(nivel);
    }
}


void JuegoControlador::cerrarMenuPrincipal() {
    delete (this->menu);
    this->menu = nullptr;
    this->menu_log = new MenuLogControlador(this->vista->getRenderizador());
}

void JuegoControlador::recrearMenu() {
    delete(this->menu_log);
    this->menu_log = nullptr;
    this->menu = new MenuJuegoControlador(this->vista->getRenderizador());
}
