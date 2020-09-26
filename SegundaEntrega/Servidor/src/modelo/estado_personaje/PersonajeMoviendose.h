#ifndef PRIMERAENTREGA_PERSONAJEMOVIENDOSE_H
#define PRIMERAENTREGA_PERSONAJEMOVIENDOSE_H

#include "EstadoPersonaje_I.h"
#include "../Posicion.h"
#include "../Personaje.h"

class PersonajeMoviendose: public EstadoPersonaje_I {

private:
    Personaje* personaje;
    Posicion direccion;

public:
    PersonajeMoviendose(Personaje* per, Posicion direccion_nueva);
    void actualizar();
    void actualizar(Posicion direccion_nueva);
    void actualizarColision(Posicion pos_colision);
    bool estaQuieto();
    Posicion getDireccion();
    ~PersonajeMoviendose();

};


#endif //PRIMERAENTREGA_PERSONAJEMOVIENDOSE_H
