#ifndef PRIMERAENTREGA_ENEMIGOINACTIVO_H
#define PRIMERAENTREGA_ENEMIGOINACTIVO_H

#include "../Enemigo.h"
#include "EstadoEnemigo.h"

class EnemigoInactivo : public EstadoEnemigo {
private:
    Enemigo *enemigo;
public:
    EnemigoInactivo(Enemigo *ene);

    bool estaQuieto() override;

    bool estaActivo() override;

    ~EnemigoInactivo() override;

};


#endif //PRIMERAENTREGA_ENEMIGOINACTIVO_H
