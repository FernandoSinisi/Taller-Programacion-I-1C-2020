#include <SDL2/SDL.h>
#include "CartelNivel.h"
#include "../tools/SDL_Utils.h"

CartelNivel::CartelNivel() {
}

CartelNivel::~CartelNivel() {
}

bool CartelNivel::continuar() {
    Uint8 *keystates = const_cast<Uint8 *>(SDL_GetKeyboardState(NULL));

    if (keystates[SDL_SCANCODE_RETURN]) {
        keystates[SDL_SCANCODE_RETURN] = false;
        return false;
    }

    return true;
}
