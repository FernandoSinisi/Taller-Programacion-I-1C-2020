#include <SDL2/SDL.h>
#include "../tools/Constantes.h"
#include "MenuJuego.h"

MenuJuego::MenuJuego(){
    this->actual = MENU_OPCION_1;
    this->activo = true;
}

MenuJuego::~MenuJuego() {
}

int MenuJuego::inicializar() {
    return this->actual;
}

int MenuJuego::actualizar() {
    Uint8 *keystates = const_cast<Uint8 *>(SDL_GetKeyboardState(NULL));

    if( keystates[SDL_SCANCODE_DOWN] ){
        keystates[SDL_SCANCODE_DOWN] = false;

        if (this->actual == MENU_OPCION_ULT ){
            this->actual = MENU_OPCION_1;

        } else{
            this->actual += 1;
        }
    }

    else if( keystates[SDL_SCANCODE_UP] ){
        keystates[SDL_SCANCODE_UP] = false;

        if ( this->actual == MENU_OPCION_1 ){
            this->actual = MENU_OPCION_ULT;

        } else{
            this->actual -= 1;
        }
    }

    else if( keystates[SDL_SCANCODE_RETURN] ){
        keystates[SDL_SCANCODE_RETURN] = false;

        if(this->actual == MENU_OPCION_1){
            this->activo = false;
            this->actual = MENU_INICIAR;
        }

        else {
            this->activo = false;
            this->actual = MENU_SALIR;
        }
    }

    else if(keystates[SDL_SCANCODE_ESCAPE]){
      keystates[SDL_SCANCODE_ESCAPE] = false;
      this->activo = false;
      this->actual = MENU_SALIR;
    }

    return this->actual;
}

bool MenuJuego::estaActivo() {
    return this->activo;
}

bool MenuJuego::estaIniciado() {
    return this->actual == MENU_INICIAR;
}

bool MenuJuego::estaCancelado(SDL_Event *evento) {
    return (evento->type == SDL_QUIT || this->actual == MENU_SALIR);
}

void MenuJuego::reestablecer() {
    this->activo = true;
    this->actual = MENU_OPCION_1;
}
