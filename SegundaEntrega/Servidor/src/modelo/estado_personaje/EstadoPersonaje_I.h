#ifndef PRIMERAENTREGA_ESTADOPERSONAJE_H
#define PRIMERAENTREGA_ESTADOPERSONAJE_H

#include "../Posicion.h"

class EstadoPersonaje_I {

public:
    virtual void actualizar() = 0;
    virtual void actualizar(Posicion direccion_nueva) = 0;
    virtual void actualizarColision(Posicion pos_colision) = 0;
    virtual bool estaQuieto() = 0;
    virtual Posicion getDireccion() = 0;
    //El destructor no hace nada, tira error si no lo declaro
    virtual ~EstadoPersonaje_I() = default;
};

#endif //PRIMERAENTREGA_ESTADOPERSONAJE_H
