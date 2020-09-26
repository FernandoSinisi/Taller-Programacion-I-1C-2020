#include "JuegoControlador.h"
#include <SDL2/SDL.h>
#include "../view/JuegoVista.h"
#include "../model/Juego.h"
#include "../tools/Log.h"
#include "../tools/CargadorDeConfiguracion.h"

JuegoControlador::JuegoControlador(int argc, char* argv[]) {
    CargadorDeConfiguracion cargador;
    cargador.cargar(argc, argv);

    this->vista = new JuegoVista();
    this->juego = new Juego(getCantEnemigo1Nivel1(), getCantEnemigo2Nivel1(), getCantEnemigo1Nivel2(), getCantEnemigo2Nivel2());
    this->cartel = new CartelNivelControlador(this->vista->getRenderizador());
    this->tecla_apretada = TECLA_NINGUNA;

    this->fps = 0;
}

JuegoControlador::~JuegoControlador() {
    delete (this->vista);
    delete (this->juego);
    delete (this->cartel);
    TTF_Quit();
    SDL_Quit();
}

bool JuegoControlador::inicializar() {
    logueoDeConstantes();
    loguearInfo(LOG_JUEGO_INICIADO);
    /* En el futuro, esta entidad debe ser un controlador de un "nivel", no
     * solo un cartel, y el controlador del juego debe tener un arreglo para
     * guardar todos los niveles.*/
    if (!this->cartel->inicializar(this->evento)) {
        this->terminar();
        return false;
    }
    loguearInfo(LOG_CARTEL_STAGE_1_FIN);
    loguearInfo(LOG_NUEVO_NIVEL + std::to_string(1));

    this->vista->inicializar();
    this->vista->actualizar(this->juego->getEstadoPersonaje());
    return true;
}

bool JuegoControlador::estaActivo() {
    return this->juego->estaActivo();
}

void JuegoControlador::actualizar() {
    Uint32 startclock = SDL_GetTicks();

    this->juego->actualizar();
    this->vista->dibujar();
    this->vista->getFondo()->actualizar();

    std::string estado_personaje = this->juego->getEstadoPersonaje();
    this->vista->actualizar(estado_personaje);

    std::string estado_enemigos = this->juego->getEstadoEnemigo();
    this->vista->actualizar(estado_enemigos);

    std::string estado_fondo = this->juego->getEstadoFondo();
    this->vista->actualizar(estado_fondo);

    SDL_PollEvent(&evento);
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    if (evento.type == SDL_QUIT or keystates[SDL_SCANCODE_ESCAPE]) {
        loguearInfo(LOG_JUEGO_CERRADO_POR_USER);
        this->terminar();
    }

    if (keystates[SDL_SCANCODE_UP] and keystates[SDL_SCANCODE_LEFT]) {
        if (this->tecla_apretada != TECLAS_ARRIBA_IZQUIERDA) {
            this->juego->actualizar(TECLAS_ARRIBA_IZQUIERDA);
            loguearDebug(LOG_MOV_SUP_IZQ);
            this->tecla_apretada = TECLAS_ARRIBA_IZQUIERDA;
        }

    } else if (keystates[SDL_SCANCODE_UP] and keystates[SDL_SCANCODE_RIGHT]) {
        if (this->tecla_apretada != TECLAS_ARRIBA_DERECHA) {
            this->juego->actualizar(TECLAS_ARRIBA_DERECHA);
            loguearDebug(LOG_MOV_SUP_DER);
            this->tecla_apretada = TECLAS_ARRIBA_DERECHA;
        }

    } else if (keystates[SDL_SCANCODE_DOWN] and keystates[SDL_SCANCODE_LEFT]) {
        if (this->tecla_apretada != TECLAS_ABAJO_IZQUIERDA) {
            this->juego->actualizar(TECLAS_ABAJO_IZQUIERDA);
            loguearDebug(LOG_MOV_ABA_IZQ);
            this->tecla_apretada = TECLAS_ABAJO_IZQUIERDA;
        }

    } else if (keystates[SDL_SCANCODE_DOWN] and keystates[SDL_SCANCODE_RIGHT]) {
        if (this->tecla_apretada != TECLAS_ABAJO_DERECHA) {
            this->juego->actualizar(TECLAS_ABAJO_DERECHA);
            loguearDebug(LOG_MOV_ABA_DER);
            this->tecla_apretada = TECLAS_ABAJO_DERECHA;
        }

    } else if (keystates[SDL_SCANCODE_UP]) {
        if (this->tecla_apretada != TECLA_ARRIBA) {
            this->juego->actualizar(TECLA_ARRIBA);
            loguearDebug(LOG_MOV_ARRIBA);
            this->tecla_apretada = TECLA_ARRIBA;
        }

    } else if (keystates[SDL_SCANCODE_LEFT]) {
        if (this->tecla_apretada != TECLA_IZQUIERDA) {
            this->juego->actualizar(TECLA_IZQUIERDA);
            loguearDebug(LOG_MOV_IZQ);
            this->tecla_apretada = TECLA_IZQUIERDA;
        }

    } else if (keystates[SDL_SCANCODE_DOWN]) {
        if (this->tecla_apretada != TECLA_ABAJO) {
            this->juego->actualizar(TECLA_ABAJO);
            loguearDebug(LOG_MOV_ABAJO);
            this->tecla_apretada = TECLA_ABAJO;
        }

    } else if (keystates[SDL_SCANCODE_RIGHT]) {
        if (this->tecla_apretada != TECLA_DERECHA) {
            this->juego->actualizar(TECLA_DERECHA);
            loguearDebug(LOG_MOV_DER);
            this->tecla_apretada = TECLA_DERECHA;
        }

    } else if (this->tecla_apretada != TECLA_NINGUNA) {
        this->juego->actualizar(TECLA_NINGUNA);
        this->tecla_apretada = TECLA_NINGUNA;

    }

    // Limitas FPS a 60
    Uint32 deltaclock = SDL_GetTicks() - startclock;
    if (deltaclock < MILISEG_TIMEOUT_EVENTOS) {
        std::this_thread::sleep_for(std::chrono::milliseconds(MILISEG_TIMEOUT_EVENTOS - deltaclock));
    }
    //Si el juego ha finalizado
    if (this->juego->finalizado()) {
        if (!this->cartel->inicializar(this->evento)) {
            this->terminar();
        }
        loguearInfo(LOG_CARTEL_FIN_STAGE_2_FIN);
        loguearInfo(LOG_FIN_JUEGO_CORRECTO);
        this->terminar();
    }


    //Avanzar de nivel
    if (this->juego->getNivelFinalizado()) {
        if (this->avanzarNivel()) {
            this->vista->actualizar(PRE_NIVEL_FINALIZADO);
        }
    }

    this->fps++;
    if(SDL_GetTicks() % 1000 < startclock % 1000 ){
        std::cout << "FPS: " << this->fps << std::endl;
        this->fps = 0;
    }
}

bool JuegoControlador::avanzarNivel() {
    if (!this->cartel->inicializar(this->evento)) {
        this->terminar();
        return false;
    }

    if (this->juego->estaActivo() and !this->cartel->inicializar(this->evento)) {
        this->terminar();
        return false;
    }

    loguearInfo(LOG_CARTEL_STAGE_2_FIN);

    return true;
}

void JuegoControlador::terminar() {
    this->juego->terminar();
    this->vista->destruir();
    loguearInfo(LOG_JUEGO_FINALIZADO);
}


void JuegoControlador::logueoDeConstantes() {
    loguearDebug(LOG_INIT_VERBOSE);
    loguearDebug(LOG_V_JSON_DEFAULT + RUTA_CONFIG_DEFAULT);
    loguearDebug(LOG_V_IMG_DEFAULT + std::string(RUTA_IMG_DEFECTO));
    loguearDebug(LOG_V_IMG_LOGO + std::string(RUTA_ICONO));

    loguearDebug(LOG_V_IMG_LV_1 + std::string(RUTA_FONDO_1_INICIO));
    loguearDebug(LOG_V_IMG_LV_1_FIN + std::string(RUTA_FONDO_1_FIN));
    loguearDebug(LOG_V_IMG_LV_2 + std::string(RUTA_FONDO_2_INICIO));
    loguearDebug(LOG_V_IMG_LV_2_FIN + std::string(RUTA_FONDO_2_FIN));

    loguearDebug(LOG_V_IMG_ARR + std::string(RUTA_PERSONAJE_ARRIBA));
    loguearDebug(LOG_V_IMG_ARR_DER + std::string(RUTA_PERSONAJE_ARRIBA_DERECHA));
    loguearDebug(LOG_V_IMG_DER + std::string(RUTA_PERSONAJE_DERECHA));
    loguearDebug(LOG_V_IMG_ABA_DER + std::string(RUTA_PERSONAJE_ABAJO_DERECHA));
    loguearDebug(LOG_V_IMG_ABA + std::string(RUTA_PERSONAJE_ABAJO));
    loguearDebug(LOG_V_IMG_ABA_IZQ + std::string(RUTA_PERSONAJE_ABAJO_IZQUIERDA));
    loguearDebug(LOG_V_IMG_IZQ + std::string(RUTA_PERSONAJE_IZQUIERDA));
    loguearDebug(LOG_V_IMG_ARR_IZQ + std::string(RUTA_PERSONAJE_ARRIBA_IZQUIERDA));

    loguearDebug(LOG_V_IMG_ENEMIGO_1 + std::string(getRutaImagenEnemigo1()));
    loguearDebug(LOG_V_IMG_ENEMIGO_2 + std::string(getRutaImagenEnemigo2()));
    loguearDebug(LOG_V_ANCHO_VENT + std::to_string(ANCHO_VENTANA));
    loguearDebug(LOG_V_ALTO_VENT + std::to_string(ALTO_VENTANA));
    loguearDebug(LOG_V_X_PERSONAJE + std::to_string(X_PERSONAJE));
    loguearDebug(LOG_V_Y_PERSONAJE + std::to_string(Y_PERSONAJE));
    loguearDebug(LOG_V_VEL_PERSONAJE + std::to_string(INCREMENTO_PERSONAJE));
    loguearDebug(LOG_V_VEL_FONDO + std::to_string(DESPLAZAMIENTO_FONDO));
}
