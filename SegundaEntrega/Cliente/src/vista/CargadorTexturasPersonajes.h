#ifndef CLIENTE_CARGADORTEXTURASPERSONAJES_H
#define CLIENTE_CARGADORTEXTURASPERSONAJES_H

#include <SDL2/SDL_image.h>
#include <vector>
#include <string>

class CargadorTexturasPersonajes {
private:
    std::vector<SDL_Texture*> texturas_personaje_1; //En principio solo las de las direcciones, luego habra un vector de texturas por estado
    std::vector<SDL_Texture*> texturas_personaje_2;
    std::vector<SDL_Texture*> texturas_personaje_3;
    std::vector<SDL_Texture*> texturas_personaje_4;
    std::vector<SDL_Texture*> texturas_personaje_desconectado;

public:

    CargadorTexturasPersonajes(SDL_Renderer* renderizador);
    std::vector<SDL_Texture*> getTexturas(int n_personaje);
    ~CargadorTexturasPersonajes();

};


#endif //CLIENTE_CARGADORTEXTURASPERSONAJES_H
