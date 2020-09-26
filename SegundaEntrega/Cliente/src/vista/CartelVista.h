#ifndef CLIENTE_CARTELVISTA_H
#define CLIENTE_CARTELVISTA_H

#include <vector>
#include <string>
#include "../vista/TextoSDL.h"

class CartelVista {
    private:
        std::vector<SDL_Texture*> carteles;
        std::vector<SDL_Texture*> numeros;
        SDL_Renderer* renderizador;
        TextoSDL* mensaje_adicional;
        TTF_Font* fuente;

public:
        explicit CartelVista(SDL_Renderer* renderizador);
        virtual ~CartelVista();

        void actualizar(size_t opcion_cartel);
        void actualizar(size_t opcion_cartel, size_t opcion_numero);
        void actualizarJugadoresConectados(std::string mensaje);
};

#endif //CLIENTE_CARTELVISTA_H
