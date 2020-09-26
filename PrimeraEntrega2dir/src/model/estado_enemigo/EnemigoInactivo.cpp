//
// Created by fernando-sinisi on 9/4/20.
//

#include "EnemigoInactivo.h"


EnemigoInactivo::EnemigoInactivo(Enemigo* ene): enemigo(ene) {
}

bool EnemigoInactivo::estaActivo(){
    return false;
}

bool EnemigoInactivo::estaQuieto(){
    return true;
}


EnemigoInactivo::~EnemigoInactivo() = default;
