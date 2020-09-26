#include <SDL2/SDL.h>
#include "CartelNivelControlador.h"
#include "../tools/Constantes.h"
#include "../tools/Log.h"

CartelNivelControlador::CartelNivelControlador(SDL_Renderer* renderizador) {

    this->cartel = new CartelNivel();
    this->vista_cartel = new CartelNivelVista(renderizador);

    this->cartel_actual = 0;

    this->carteles.push_back(RUTA_FONDO_1_INICIO);
    this->carteles.push_back(RUTA_FONDO_1_FIN);
    this->carteles.push_back(RUTA_FONDO_2_INICIO);
    this->carteles.push_back(RUTA_FONDO_2_FIN);
}

CartelNivelControlador::~CartelNivelControlador() {
    delete(this->cartel);
    delete(this->vista_cartel);
}

bool CartelNivelControlador::inicializar(SDL_Event evento) {
    this->vista_cartel->actualizar(carteles[this->cartel_actual]);
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    while ( this->cartel->continuar() > 0
        && evento.type != SDL_QUIT
        && !keystates[SDL_SCANCODE_ESCAPE] ) {
        SDL_WaitEvent(&evento);
    }
    if( this->cartel_actual == 0 ){
        loguearInfo(LOG_CARTEL_STAGE_1);
    }
    else if( this->cartel_actual == 1 ){
        loguearInfo(LOG_NIVEL_FINALIZADO);
        loguearInfo(LOG_CARTEL_FIN_STAGE_1);
    }
    else if( this->cartel_actual == 2 ){
        loguearInfo(LOG_CARTEL_FIN_STAGE_1_FIN);
        loguearInfo(LOG_NUEVO_NIVEL + std::to_string(2));
        loguearInfo(LOG_CARTEL_STAGE_2);

    }
    else if( this->cartel_actual == 3 ){
        loguearInfo(LOG_CARTEL_FIN_STAGE_2);
    }

    this->cartel_actual++;


    return evento.type != SDL_QUIT && !keystates[SDL_SCANCODE_ESCAPE];
}

