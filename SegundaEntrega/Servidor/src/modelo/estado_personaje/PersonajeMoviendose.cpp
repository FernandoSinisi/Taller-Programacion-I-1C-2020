//
// Created by nicolas on 17/3/20.
//

#include "PersonajeMoviendose.h"
#include "PersonajeQuieto.h"
#include "../../tools/Constantes.h"

PersonajeMoviendose::PersonajeMoviendose(Personaje* per, Posicion direccion_nueva):
                                                                        personaje(per),  direccion(direccion_nueva){

}

void PersonajeMoviendose::actualizar() {
    this->personaje->mover(this->direccion);
}

void PersonajeMoviendose::actualizar(Posicion direccion_nueva){
    if (direccion_nueva == POS_NINGUNA) {
        this->personaje->setEstado(new PersonajeQuieto(personaje));

    } else if (direccion_nueva != this->direccion) {
        this->direccion.setX(direccion_nueva.getX());
        this->direccion.setY(direccion_nueva.getY());
    }
}

bool PersonajeMoviendose::estaQuieto(){
    return false;
}

Posicion PersonajeMoviendose::getDireccion() {
    return this->direccion;
}

void PersonajeMoviendose::actualizarColision(Posicion pos_colision){

    if(this->direccion.getX() * pos_colision.getX() > 0){
        this->direccion.setX(0);
    }
    if(this->direccion.getY() * pos_colision.getY() > 0){
        this->direccion.setY(0);
    }
    if (this->direccion == POS_NINGUNA){
        this->personaje->setEstado(new PersonajeQuieto(this->personaje));
    }

}

PersonajeMoviendose::~PersonajeMoviendose() = default;