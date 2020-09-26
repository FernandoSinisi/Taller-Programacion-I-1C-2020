#include "Enemigo.h"
#include "estado_enemigo/EnemigoQuieto.h"

Enemigo::Enemigo(double pos_x, double pos_y, std::string tipo)
        : posicion(pos_x, pos_y),
        direccion_mirando(-1,0),
        estado(new EnemigoQuieto(this)),
        tipo(tipo),
        esta_en_ventana{true} {
    if (pos_x < ANCHO_FONDO / 2) {
        this->direccion_contraria = true;
    } else {
        this->direccion_contraria = false;
    }
}

void Enemigo::setPosX(double pos_x){
    this->posicion.setX(pos_x);
}

double Enemigo::getPosX(){
    return this->posicion.getX();
}

void Enemigo::setPosY(double pos_y){
    this->posicion.setY(pos_y);
}

double Enemigo::getPosY(){
    return this->posicion.getY();
}

void Enemigo::setEstado(EstadoEnemigo* estado_nuevo){
    delete(this->estado);
    this->estado = estado_nuevo;
}

void Enemigo::setTipo(std::string tipo_enemigo) {
    this->tipo = tipo_enemigo;
}

std::string Enemigo::getTipo() {
    return this->tipo;
}


Posicion Enemigo::getPosicionVentana() {
    return pos_ventana;
}

void Enemigo::setPosicionVentana(Posicion pos) {

    this->pos_ventana = pos;
}

bool Enemigo::getEstaEnVentana() {
    return this->esta_en_ventana;
}

void Enemigo::setEstaEnVentana(bool en_ventana){
    this->esta_en_ventana = en_ventana;
}

bool Enemigo::getActivo() {
    return this->estado->estaActivo();
}

bool Enemigo::direccionContraria(){
    return this->direccion_contraria;
}

void Enemigo::actualizar(){
    if (this->direccion_contraria) {
        this->posicion.setX(this->getPosX() + DESPLAZAMIENTO_FONDO*2);
    }
}

Enemigo::~Enemigo(){
    delete(this->estado);
}

