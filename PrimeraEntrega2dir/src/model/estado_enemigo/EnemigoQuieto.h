#ifndef PRIMERAENTREGA_ENEMIGOQUIETO_H
#define PRIMERAENTREGA_ENEMIGOQUIETO_H

#include "../Enemigo.h"
#include "EstadoEnemigo.h"

class EnemigoQuieto : public EstadoEnemigo {
private:
    Enemigo *enemigo;
public:
    EnemigoQuieto(Enemigo *ene);

    bool estaQuieto() override;

    bool estaActivo() override;

    Posicion getDireccion();

    ~EnemigoQuieto() override;
};


#endif //PRIMERAENTREGA_ENEMIGOQUIETO_H
