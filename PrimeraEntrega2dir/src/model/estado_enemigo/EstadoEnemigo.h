#ifndef PRIMERAENTREGA_ESTADOENEMIGO_H
#define PRIMERAENTREGA_ESTADOENEMIGO_H

#include "../Posicion.h"

class EstadoEnemigo {

public:
    virtual bool estaQuieto() = 0;

    virtual bool estaActivo() = 0;

    virtual ~EstadoEnemigo() = default;

};

#endif //PRIMERAENTREGA_ESTADOENEMIGO_H
