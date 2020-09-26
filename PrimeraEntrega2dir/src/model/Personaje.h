#ifndef PRIMERAENTREGA_PERSONAJE_H
#define PRIMERAENTREGA_PERSONAJE_H

#include "estado_personaje/EstadoPersonaje_I.h"
#include "Posicion.h"

class Personaje {
private:
    Posicion posicion;
    Posicion pos_ventana;
    int incremento;
    Posicion direccion_mirando;
    EstadoPersonaje_I* estado;


public:
    Personaje(double pos_x, double pos_y, int incremento);

    void setPosX(double posX);
    double getPosX();
    void setPosY(double posY);
    double getPosY();

    Posicion getPosicionVentana();
    void setPosicionVentana(Posicion pos);

    void actualizarColision(Posicion pos_colision);

    void setEstado(EstadoPersonaje_I* estado_nuevo);
    void mover(Posicion direccion);
    bool estaQuieto();
    void actualizar();
    void actualizar(Posicion direccion);
    //Devuelve la constante que representa a que direccion esta mirando
    int getDireccion();

    void resetearColisiones();

    ~Personaje();
};


#endif //PRIMERAENTREGA_PERSONAJE_H
