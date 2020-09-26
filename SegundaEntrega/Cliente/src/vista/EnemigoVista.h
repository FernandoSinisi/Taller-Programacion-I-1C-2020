#ifndef PRIMERAENTREGA_ENEMIGOVISTA_H
#define PRIMERAENTREGA_ENEMIGOVISTA_H

#include <SDL2/SDL_image.h>
#include "../tools/Constantes.h"
#include <vector>
#include "CargadorTexturasEnemigos.h"
#include "../tools/SDL_Utils.h"

class EnemigoVista {
private:
    SDL_Texture* textura_actual;
    SDL_Rect posicion;
    SDL_Rect sprite_actual;
    int posicionXModelo;
    int pasoX;
    bool esta_vivo;
    std::string tipo_enemigo;
    std::vector<SDL_Texture*> texturas;

public:
    explicit EnemigoVista(int pos_x, int pos_y, std::string tipo_enemigo, CargadorTexturasEnemigos* cargador);
    virtual ~EnemigoVista();

    void cargarRectangulos(int pos_x, int pos_y);
    SDL_Rect* getPosicion();
    SDL_Texture* getTextura();
    void setSpriteActual(int x, int y);
    bool getEstaVivo();
    SDL_Rect* getSpriteActual();
    void actualizar(int pos_x, int pos_y, int direccion);
};


#endif //PRIMERAENTREGA_ENEMIGOVISTA_H
