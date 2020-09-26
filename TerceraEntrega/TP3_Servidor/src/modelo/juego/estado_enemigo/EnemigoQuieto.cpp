#include "EnemigoQuieto.h"

EnemigoQuieto::EnemigoQuieto(Enemigo* ene): enemigo(ene) {
}

EnemigoQuieto::~EnemigoQuieto() = default;

bool EnemigoQuieto::estaQuieto(){
    return true;
}

void EnemigoQuieto::actualizar(){
    this->activar();
}

void EnemigoQuieto::activar() {
    std::string tipo = this->enemigo->getTipo();
    if (tipo == TIPO_JEFE_1) {
        this->enemigo->setEstado(new Jefe1Moviendose(this->enemigo));

    } else if (tipo == getTipoEnemigo1()){
        this->enemigo->setEstado(new EnemigoTipo1Moviendose(this->enemigo));
    } else {
        this->enemigo->setEstado(new EnemigoTipo2Moviendose(this->enemigo));
    }

}

Posicion EnemigoQuieto::getDireccion(){
    Posicion direccion(0,0);
    return direccion;
}
