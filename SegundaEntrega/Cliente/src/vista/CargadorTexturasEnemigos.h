#ifndef PRIMERAENTREGA_CARGADORTEXTURASENEMIGOS_H
#define PRIMERAENTREGA_CARGADORTEXTURASENEMIGOS_H

#include <SDL2/SDL_image.h>
#include <vector>
#include <string>

class CargadorTexturasEnemigos {
private:
    std::vector<SDL_Texture*> texturas_enemigo_1; //En principio solo las de las direcciones, luego habra un vector de texturas por estado
    std::vector<SDL_Texture*> texturas_enemigo_2;
    std::vector<SDL_Texture*> texturas_enemigo_default;

public:

    CargadorTexturasEnemigos(SDL_Renderer* renderizador);
    std::vector<SDL_Texture*> getTexturas(std::string tipo_enemigo);
    ~CargadorTexturasEnemigos();

};


#endif //PRIMERAENTREGA_CARGADORTEXTURASENEMIGOS_H
