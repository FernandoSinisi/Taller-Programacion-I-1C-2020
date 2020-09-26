#ifndef SERVIDOR_PERSONAJE_H
#define SERVIDOR_PERSONAJE_H

#include "Posicion.h"
#include "estado_personaje/EstadoPersonaje_I.h"
#include <string>

class Personaje {
private:
    Posicion posicion;
    Posicion pos_ventana;
    int incremento;
    std::string nombre;
    Posicion direccion_mirando;
    EstadoPersonaje_I* estado;
    bool listo;
    bool conectado;
    int nro_personaje;

public:
    Personaje(double pos_x, double pos_y, int incremento, int n_personaje);

    void setPosX(double posX);
    double getPosX();
    void setPosY(double posY);
    double getPosY();
    void setNombre(std::string nombre);
    std::string getNombre();

    void setConectado(bool estado_actual_conectado);
    bool estaConectado();

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
    int getNumeroPersonaje();

    void setListo(bool estado_listo);
    bool estaListo();

    void resetearColisiones();
    ~Personaje();
};


#endif //SERVIDOR_PERSONAJE_H
