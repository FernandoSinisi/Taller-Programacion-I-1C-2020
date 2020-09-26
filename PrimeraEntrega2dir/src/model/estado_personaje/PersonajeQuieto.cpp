#include "PersonajeQuieto.h"
#include "PersonajeMoviendose.h"
#include "../../tools/Constantes.h"

PersonajeQuieto::PersonajeQuieto(Personaje* per): personaje(per) {

}

void PersonajeQuieto::actualizar() {

}

void PersonajeQuieto::actualizar(Posicion direccion_nueva){
    if (direccion_nueva != POS_NINGUNA) {
        this->personaje->setEstado(new PersonajeMoviendose(personaje, direccion_nueva));
    }
}

bool PersonajeQuieto::estaQuieto(){
    return true;
}

Posicion PersonajeQuieto::getDireccion(){
    Posicion direccion(0,0);
    return direccion;
}

//Este metodo no hace nada
void PersonajeQuieto::actualizarColision(Posicion pos_colision){
    Posicion pos = pos_colision;
}

PersonajeQuieto::~PersonajeQuieto() = default;
