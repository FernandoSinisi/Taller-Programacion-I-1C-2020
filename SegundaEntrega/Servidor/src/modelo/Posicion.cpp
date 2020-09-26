#include "Posicion.h"
#include "../tools/SDL_Utils.h"

Posicion::Posicion(){
    this->pos.push_back(0);
    this->pos.push_back(0);
}

Posicion::Posicion(double pos_x, double pos_y){
    this->pos.push_back(pos_x);
    this->pos.push_back(pos_y);
}

Posicion::Posicion(const Posicion& pos_copia){
    this->pos.push_back(pos_copia.getX());
    this->pos.push_back(pos_copia.getY());
}

double Posicion::getX() const{
    return this->pos[0];
}

double Posicion::getY() const{
    return this->pos[1];
}

void Posicion::setX(double new_x){
    this->pos[0] = new_x;
}

void Posicion::setY(double new_y){
    this->pos[1] = new_y;
}

Posicion& Posicion::operator+=(Posicion otra_posicion){
    this->pos[0] += otra_posicion.getX();
    this->pos[1] += otra_posicion.getY();
    return *this;
}

Posicion& Posicion::operator-=(Posicion otra_posicion){
    this->pos[0] -= otra_posicion.getX();
    this->pos[1] -= otra_posicion.getY();
    return *this;
}

bool Posicion::operator==(Posicion otra_posicion){
    return ( doblesIguales( this->pos[0], otra_posicion.getX())
              and
            doblesIguales( this->pos[1], otra_posicion.getY())
            );
}

bool Posicion::operator!=(Posicion otra_posicion){
    return ! ( (*this) == otra_posicion );
}

Posicion Posicion::operator+(Posicion otra_posicion){
    //Construccion por copia
    Posicion aux(*this);
    aux+=otra_posicion;
    return aux;
}


Posicion Posicion::operator*(double entero){
    //Construccion por copia
    Posicion aux(*this);
    aux.setX(aux.getX() * entero);
    aux.setY(aux.getY() * entero);
    return aux;
}

Posicion::~Posicion(){
    //do nothing
}
