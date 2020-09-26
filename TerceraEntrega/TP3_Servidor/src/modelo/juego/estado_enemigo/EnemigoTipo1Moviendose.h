#ifndef SERVIDOR_ENEMIGOTIPO1MOVIENDOSE_H
#define SERVIDOR_ENEMIGOTIPO1MOVIENDOSE_H

#include "IEstadoEnemigo.h"
#include "../Enemigo.h"

class Enemigo;

class EnemigoTipo1Moviendose: public IEstadoEnemigo {

    private:
        Enemigo* enemigo;
        Posicion direccion;
        int contador;
        int velocidad;
        bool alineandose;
        bool esquivando;
        Posicion partida;
        bool llego_area_jefe;


    public:
        EnemigoTipo1Moviendose(Enemigo* enemigo);
        ~EnemigoTipo1Moviendose();
        bool estaQuieto() override;
        void activar() override;
        void actualizar() override;
        Posicion obtenerDireccionAlinear(Posicion pos);
        void actualizarQuieto();
        Posicion obtenerDireccionEsquivar();
        void actualizarLlegoAreaJefe();
};


#endif //SERVIDOR_ENEMIGOTIPO1MOVIENDOSE_H
