#include "Juego.h"
#include "../tools/Log.h"

Juego::Juego(int cant_enem_tipo_1_niv_1, int cant_enem_tipo_2_niv_1, int cant_enem_tipo_1_niv_2, int cant_enem_tipo_2_niv_2) {
    this->numero_nivel = 1;

    this->tipos_enemigos_nivel_1.push_back(getTipoEnemigo1());
    this->tipos_enemigos_nivel_1.push_back(getTipoEnemigo2());

    this->cantidad_enemigos_nivel_1.push_back(cant_enem_tipo_1_niv_1);
    this->cantidad_enemigos_nivel_1.push_back(cant_enem_tipo_2_niv_1);

    this->tipos_enemigos_nivel_2.push_back(getTipoEnemigo1());
    this->tipos_enemigos_nivel_2.push_back(getTipoEnemigo2());

    this->cantidad_enemigos_nivel_2.push_back(cant_enem_tipo_1_niv_2);
    this->cantidad_enemigos_nivel_2.push_back(cant_enem_tipo_2_niv_2);

    this->nivel = new Nivel(this->tipos_enemigos_nivel_1, this->cantidad_enemigos_nivel_1);
}

void Juego::actualizar(){
    this->nivel->actualizar();
}

void Juego::actualizar(int input){
    this->nivel->actualizar(input);
}

std::string Juego::getEstadoPersonaje(){
    return this->nivel->getEstadoPersonaje();
}

std::string Juego::getEstadoEnemigo(){
    return this->nivel->getEstadoEnemigo();
}

std::string Juego::getEstadoFondo() {
    return this->nivel->getEstadoFondo();
}

bool Juego::getNivelFinalizado() {
    bool finalizado = this->nivel->getNivelFinalizado();

    if (finalizado) {
        this->avanzarNivel();
    }

    if (this->numero_nivel <= CANTIDAD_NIVELES){
        return finalizado;
    }

    return false;
}

void Juego::avanzarNivel() {
    if ((++this->numero_nivel) <= CANTIDAD_NIVELES ) {
        delete(this->nivel);
        this->nivel = new Nivel(this->tipos_enemigos_nivel_2, this->cantidad_enemigos_nivel_2);
    }
}

bool Juego::estaActivo(){
    return this->nivel->estaActivo();
}

int Juego::getCantidadEnemigos(){
    return this->nivel->getCantidadEnemigos();
}

void Juego::terminar(){
    this->nivel->terminar();
}

bool Juego::finalizado() {
    return( ( this->numero_nivel == CANTIDAD_NIVELES ) && ( this->nivel->getNivelFinalizado() ) );
}

Juego::~Juego(){
    delete this->nivel;
}
