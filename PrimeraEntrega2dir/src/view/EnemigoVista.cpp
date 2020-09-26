#include "EnemigoVista.h"
#include "../tools/Constantes.h"
#include "../tools/SDL_Utils.h"
#include "CargadorTexturasEnemigos.h"

EnemigoVista::EnemigoVista(int pos_x, int pos_y, std::string tipo_enemigo, CargadorTexturasEnemigos* cargador){

    this->tipo_enemigo = tipo_enemigo;
    this->texturas = cargador->getTexturas(tipo_enemigo);
    this->esta_vivo = true;

    //La direccion de los personajes y enemigos puede ser la misma?
    this->textura_actual = this->texturas[DIRECCION_ENEMIGO_IZQUIERDA];

    this-> cargarRectangulos(pos_x, pos_y);
}

void EnemigoVista::cargarRectangulos(int pos_x, int pos_y){
    if (this->tipo_enemigo == getTipoEnemigo1()) {
        // Valores reales de la imagen
        initRect(&this->sprite_actual, 0, 0, getAnchoEnemigo1(), getAltoEnemigo1());

        // Tamaño visualizado en pantalla
        initRect(&this->posicion, pos_x, pos_y, getTamAnchoEnemigo1(), getTamAltoEnemigo1());

    } else{
        initRect(&this->sprite_actual, 0, 0, getAnchoEnemigo2(), getAltoEnemigo2());

        initRect(&this->posicion, pos_x, pos_y, getTamAnchoEnemigo2(), getTamAltoEnemigo2());
    }
}

SDL_Rect* EnemigoVista::getPosicion(){
    return &this->posicion;
}

SDL_Texture* EnemigoVista::getTextura(){
    return this->textura_actual;
}

SDL_Rect* EnemigoVista::getSpriteActual(){
    return &this->sprite_actual;
}

bool EnemigoVista::getEstaVivo(){
    return this->esta_vivo;
}

void EnemigoVista::setSpriteActual(int x, int y){
    this->sprite_actual.x = x;
    this->sprite_actual.y = y;
}

void EnemigoVista::actualizar(int pos_x, int pos_y, int direccion){
    this->posicion.x = pos_x;
    this->posicion.y = pos_y;
    this->textura_actual = this->texturas[(unsigned long)direccion];
}

EnemigoVista::~EnemigoVista() {

}

