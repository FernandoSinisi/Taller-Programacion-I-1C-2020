#ifndef PRIMERAENTREGA_ENEMIGO_H
#define PRIMERAENTREGA_ENEMIGO_H
#include "Posicion.h"
#include "../tools/Constantes.h"
#include "estado_enemigo/EstadoEnemigo.h"
#include <string>

class Enemigo {
    private:
        Posicion posicion;
        Posicion pos_ventana;
        Posicion direccion_mirando;
        EstadoEnemigo* estado;
        std::string tipo;
        bool esta_en_ventana;
        bool se_mueve;

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
        void actualizar();

        Posicion getPosicionVentana();
        void setPosicionVentana(Posicion pos);

        bool getEstaEnVentana();
        void setEstaEnVentana(bool en_ventana);

        bool seMueve();
        ~Enemigo();

};

#endif //PRIMERAENTREGA_ENEMIGO_H
