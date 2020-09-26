#include "PersonajeVista.h"
#include "../tools/Constantes.h"
#include "../tools/SDL_Utils.h"

PersonajeVista::PersonajeVista(int pos_x, int pos_y, SDL_Renderer* renderizador){

    this->cargarTexturas(renderizador);

    this->textura_actual = this->texturas[DIRECCION_PERSONAJE_DERECHA];

    initRect(&this->posicion, pos_x, pos_y, ANCHO_PERSONAJE, ALTO_PERSONAJE);
    initRect(&this->sprite_actual, 0, 0, ANCHO_PERSONAJE, ALTO_PERSONAJE);
}

void PersonajeVista::cargarTexturas(SDL_Renderer* renderizador){
    this->texturas.emplace_back(crearTextura(RUTA_PERSONAJE_ARRIBA, renderizador));
    this->texturas.emplace_back(crearTextura(RUTA_PERSONAJE_ARRIBA_DERECHA, renderizador));
    this->texturas.emplace_back(crearTextura(RUTA_PERSONAJE_DERECHA, renderizador));
    this->texturas.emplace_back(crearTextura(RUTA_PERSONAJE_ABAJO_DERECHA, renderizador));
    this->texturas.emplace_back(crearTextura(RUTA_PERSONAJE_ABAJO, renderizador));
    this->texturas.emplace_back(crearTextura(RUTA_PERSONAJE_ABAJO_IZQUIERDA, renderizador));
    this->texturas.emplace_back(crearTextura(RUTA_PERSONAJE_IZQUIERDA, renderizador));
    this->texturas.emplace_back(crearTextura(RUTA_PERSONAJE_ARRIBA_IZQUIERDA, renderizador));

}

SDL_Rect* PersonajeVista::getPosicion(){
    return &this->posicion;
}

SDL_Texture* PersonajeVista::getTextura(){
    return this->textura_actual;
}

SDL_Rect* PersonajeVista::getSpriteActual(){
    return &this->sprite_actual;
}

void PersonajeVista::setSpriteActual(int x, int y){
    this->sprite_actual.x = x;
    this->sprite_actual.y = y;
}

void PersonajeVista::actualizar(int pos_x, int pos_y, int direccion){
    this->posicion.x = pos_x;
    this->posicion.y = pos_y;
    this->textura_actual = this->texturas[(unsigned long)direccion];
}

PersonajeVista::~PersonajeVista() {
    for (auto &i: this->texturas){
        SDL_DestroyTexture(i);
    }
}

