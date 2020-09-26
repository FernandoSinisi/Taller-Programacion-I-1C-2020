//
// Created by fernando-sinisi on 9/4/20.
//

#include "EnemigoQuieto.h"

EnemigoQuieto::EnemigoQuieto(Enemigo* ene): enemigo(ene) {
}

bool EnemigoQuieto::estaQuieto(){
    return true;
}

bool EnemigoQuieto::estaActivo(){
    return true;
}


Posicion EnemigoQuieto::getDireccion(){
    Posicion direccion(0,0);
    return direccion;
}

EnemigoQuieto::~EnemigoQuieto() = default;

