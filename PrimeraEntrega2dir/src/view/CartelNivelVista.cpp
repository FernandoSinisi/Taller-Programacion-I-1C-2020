#include <SDL2/SDL.h>
#include "CartelNivelVista.h"
#include "../tools/SDL_Utils.h"

CartelNivelVista::CartelNivelVista(SDL_Renderer* renderizador) {

    this->renderizador = renderizador;

    SDL_RenderClear(this->renderizador);
}

void CartelNivelVista::actualizar(char* ruta_cartel) {
    this->cartel = crearTextura(ruta_cartel, this->renderizador);
    SDL_RenderCopy(this->renderizador, this->cartel, NULL, NULL);
    SDL_RenderPresent(this->renderizador);
    SDL_DestroyTexture(this->cartel);
}
