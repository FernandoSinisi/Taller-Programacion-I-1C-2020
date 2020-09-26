#ifndef PRIMERAENTREGA_PERSONAJEQUIETO_H
#define PRIMERAENTREGA_PERSONAJEQUIETO_H
#include "EstadoPersonaje_I.h"
#include "../Personaje.h"
#include "../Posicion.h"

class PersonajeQuieto: public EstadoPersonaje_I {
private:
    Personaje* personaje;
public:
    PersonajeQuieto(Personaje* per);
    void actualizar();
    Posicion getDireccion();
    void actualizar(Posicion direccion);
    void actualizarColision(Posicion pos_colision);
    bool estaQuieto();

    ~PersonajeQuieto();
};


#endif //PRIMERAENTREGA_PERSONAJEQUIETO_H
