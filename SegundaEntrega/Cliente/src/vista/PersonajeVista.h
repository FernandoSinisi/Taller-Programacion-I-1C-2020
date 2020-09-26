#ifndef PRIMERAENTREGA_PERSONAJEVISTA_H
#define PRIMERAENTREGA_PERSONAJEVISTA_H

#include <SDL2/SDL_image.h>
#include "../tools/Constantes.h"
#include "CargadorTexturasPersonajes.h"
#include <vector>

class PersonajeVista {
private:
    SDL_Texture* textura_actual;
    SDL_Rect posicion;
    SDL_Rect sprite_actual;
    int posicionXModelo;
    int pasoX;
    std::vector<SDL_Texture*> texturas;
    int nro_personaje;

public:
    explicit PersonajeVista(int pos_x, int pos_y, int nro_personaje_nuevo, CargadorTexturasPersonajes* cargador);
    virtual ~PersonajeVista();

    int getNumeroPersonaje();
    SDL_Rect* getPosicion();
    SDL_Texture* getTextura();
    void setSpriteActual(int x, int y);
    SDL_Rect* getSpriteActual();
    void actualizar(int pos_x, int pos_y, int direccion);
    void actualizarTexturas(int nro_personaje_nuevo, CargadorTexturasPersonajes* cargador);
};


#endif //PRIMERAENTREGA_PERSONAJEVISTA_H