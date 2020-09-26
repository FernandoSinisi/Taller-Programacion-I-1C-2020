#include "Enemigo.h"
#include "estado_enemigo/EnemigoQuieto.h"

Enemigo::Enemigo(double pos_x, double pos_y, std::string tipo)
        : posicion(pos_x, pos_y),
        direccion_mirando(-1,0),
        estado(new EnemigoQuieto(this)),
        tipo(tipo),
        esta_en_ventana{true} {
    if (pos_x < ANCHO_FONDO / 2) {
        this->se_mueve = true;
    } else {
        this->se_mueve = false;
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

void Enemigo::actualizar() {
    if (this->se_mueve) {
        this->posicion.setX(this->getPosX() + DESPLAZAMIENTO_FONDO*2);
    }
}

bool Enemigo::seMueve() {
    return this->se_mueve;
}

Enemigo::~Enemigo(){
    delete(this->estado);
}

