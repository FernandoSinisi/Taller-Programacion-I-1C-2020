#include "Personaje.h"
#include <iostream>
#include "estado_personaje/PersonajeQuieto.h"
#include "estado_personaje/PersonajeMoviendose.h"
#include "../tools/Constantes.h"

Personaje::Personaje(double pos_x, double pos_y, int incremento, int n_personaje)
        : posicion(pos_x, pos_y),
        pos_ventana(pos_x,pos_y),
        incremento(incremento),
        direccion_mirando(1,0),
        estado(new PersonajeQuieto(this) ),
        listo(false),
        conectado(true),
        nro_personaje(n_personaje){

}

void Personaje::setPosX(double pos_x){
    this->posicion.setX(pos_x);
}

double Personaje::getPosX(){
    return this->posicion.getX();
}

void Personaje::setPosY(double pos_y){
    this->posicion.setY(pos_y);
}

double Personaje::getPosY(){
    return this->posicion.getY();
}

std::string Personaje::getNombre() {
    return this->nombre;
}

void Personaje::setNombre(std::string n) {
    this->nombre = n;
}

void Personaje::setEstado(EstadoPersonaje_I* estado_nuevo){
    delete(this->estado);
    this->estado = estado_nuevo;
}

void Personaje::mover(Posicion direccion){
    this->posicion += direccion;
}

bool Personaje::estaQuieto(){
    return this->estado->estaQuieto();
}

void Personaje::actualizar(){
    this->estado->actualizar();
}

void Personaje::actualizar(Posicion direccion){

    if (direccion != POS_NINGUNA) {
        this->direccion_mirando = direccion;
    }
    this->estado->actualizar( direccion * (this->incremento) );
}

void Personaje::setConectado(bool estado_actual_conectado) {
    this->conectado = estado_actual_conectado;
}

bool Personaje::estaConectado() {
    return this->conectado;
}

int Personaje::getDireccion() {
    if (this->direccion_mirando == POS_ARRIBA) {
        return DIRECCION_PERSONAJE_ARRIBA;

    } else if ((this->direccion_mirando == POS_ARRIBA_DER)) {
        return DIRECCION_PERSONAJE_ARRIBA_DERECHA;

    } else if ((this->direccion_mirando == POS_DERECHA)) {
        return DIRECCION_PERSONAJE_DERECHA;

    } else if ((this->direccion_mirando == POS_ABAJO_DER)) {
        return DIRECCION_PERSONAJE_ABAJO_DERECHA;

    } else if ((this->direccion_mirando == POS_ABAJO)) {
        return DIRECCION_PERSONAJE_ABAJO;

    } else if ((this->direccion_mirando == POS_ABJAJO_IZQ)) {
        return DIRECCION_PERSONAJE_ABAJO_IZQUIERDA;

    } else if ((this->direccion_mirando == POS_IZQUIERDA)) {
        return DIRECCION_PERSONAJE_IZQUIERDA;

    } //else  if ((this->direccion_mirando == Posicion (-1,1)))
    return DIRECCION_PERSONAJE_ARRIBA_IZQUIERDA;

}

int Personaje::getNumeroPersonaje() {
    return this->nro_personaje;
}

Posicion Personaje::getPosicionVentana() {
    return pos_ventana;
}

void Personaje::setPosicionVentana(Posicion pos) {

    this->pos_ventana = pos;
}

void Personaje::actualizarColision(Posicion pos_colision){
    this->estado->actualizarColision(pos_colision);
}

void Personaje::setListo(bool estado_listo){
    this->listo = estado_listo;
}

bool Personaje::estaListo(){
    return this->listo;
}

Personaje::~Personaje(){
    delete(this->estado);
}
