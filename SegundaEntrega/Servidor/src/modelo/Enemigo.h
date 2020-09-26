#ifndef PRIMERAENTREGA_ENEMIGO_H
#define PRIMERAENTREGA_ENEMIGO_H
#include "Posicion.h"
#include "estado_enemigo/EstadoEnemigo.h"
#include <string>
#include "../tools/Constantes.h"

class Enemigo {
    private:
        Posicion posicion;
        Posicion pos_ventana;
        Posicion direccion_mirando;
        EstadoEnemigo* estado;
        std::string tipo;
        bool esta_en_ventana;
        bool direccion_contraria;

    public:
        Enemigo(double pos_x, double pos_y, std::string tipo);

        void setPosX(double posX);
        double getPosX();
        void setPosY(double posY);
        double getPosY();
        void setTipo(std::string tipo);
        std::string getTipo();
        void setEstado(EstadoEnemigo* estado_nuevo);
        bool getActivo();

        Posicion getPosicionVentana();
        void setPosicionVentana(Posicion pos);

        bool getEstaEnVentana();
        void setEstaEnVentana(bool en_ventana);

        bool direccionContraria();
        void actualizar();

        ~Enemigo();

};

#endif //PRIMERAENTREGA_ENEMIGO_H
