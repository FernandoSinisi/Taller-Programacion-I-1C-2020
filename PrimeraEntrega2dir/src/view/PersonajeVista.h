#ifndef PRIMERAENTREGA_PERSONAJEVISTA_H
#define PRIMERAENTREGA_PERSONAJEVISTA_H

#include <SDL2/SDL_image.h>
#include "../tools/Constantes.h"
#include <vector>

class PersonajeVista {
private:
    SDL_Texture* textura_actual;
    SDL_Rect posicion;
    SDL_Rect sprite_actual;
    int posicionXModelo;
    int pasoX;
    std::vector<SDL_Texture*> texturas;

public:
    explicit PersonajeVista(int pos_x, int pos_y, SDL_Renderer* renderizador);
    virtual ~PersonajeVista();

    void cargarTexturas(SDL_Renderer* renderizador);
    SDL_Rect* getPosicion();
    SDL_Texture* getTextura();
    void setSpriteActual(int x, int y);
    SDL_Rect* getSpriteActual();
    void actualizar(int pos_x, int pos_y, int direccion);
};


#endif //PRIMERAENTREGA_PERSONAJEVISTA_H