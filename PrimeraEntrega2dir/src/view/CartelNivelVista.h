#ifndef PRIMERAENTREGA_CARTELNIVELVISTA_H
#define PRIMERAENTREGA_CARTELNIVELVISTA_H

#include <vector>

class CartelNivelVista {
    private:
        SDL_Texture* cartel;
        SDL_Renderer* renderizador;

    public:
        explicit CartelNivelVista(SDL_Renderer* renderizador);
        void actualizar(char* ruta_cartel);
};

#endif //PRIMERAENTREGA_CARTELNIVELVISTA_H
