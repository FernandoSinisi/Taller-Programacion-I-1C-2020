#ifndef SERVIDOR_ARMAMENTOJEFE1_H
#define SERVIDOR_ARMAMENTOJEFE1_H

#include "Armamento.h"

class ArmamentoJefe1: public Armamento  {
private:
    int contador_disparos;
public:
    ArmamentoJefe1(int potencia_proyectiles);
    ~ArmamentoJefe1();
    //Como el jefe puede disparar dos tiros desde distinta posicion inicial hacia el personaje, necesita recibir
    //su posicion para calcular la direccion internamente, en lugar de recibir directamente una direccion como en el armamento de los enemigos normales
    void actualizar(Posicion pos, Posicion pos_personaje) override;
    Proyectil *usar(Posicion pos_inic, Posicion direccion) override;
    void setEstaDisparando(bool disparando) override;
    void disparoSimpleCentral(Posicion pos_inic);
    void disparoDobleCentral(Posicion pos_inic);
    void disparoTriple(Posicion pos_inic);
    void disparoCuadruple(Posicion pos_inic);
    void disparoDobleHoming(Posicion pos_inic, Posicion pos_personaje);
};


#endif //SERVIDOR_ARMAMENTOJEFE1_H
