#include "PersonajeVista.h"
#include "../tools/Constantes.h"
#include "../tools/SDL_Utils.h"

PersonajeVista::PersonajeVista(int pos_x, int pos_y, int nro_personaje_nuevo, CargadorTexturasPersonajes* cargador){

    this->texturas = cargador->getTexturas(nro_personaje_nuevo);

    this->textura_actual = this->texturas[DIRECCION_PERSONAJE_DERECHA];

    initRect(&this->posicion, pos_x, pos_y, ANCHO_PERSONAJE, ALTO_PERSONAJE);
    initRect(&this->sprite_actual, 0, 0, ANCHO_PERSONAJE, ALTO_PERSONAJE);

    this->nro_personaje = nro_personaje_nuevo;
}

int PersonajeVista::getNumeroPersonaje(){
    return this->nro_personaje;
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

void PersonajeVista::actualizarTexturas(int nro_personaje_nuevo, CargadorTexturasPersonajes* cargador){
    this->texturas = cargador->getTexturas(nro_personaje_nuevo);
    this->nro_personaje = nro_personaje_nuevo;
}

PersonajeVista::~PersonajeVista() {

}

