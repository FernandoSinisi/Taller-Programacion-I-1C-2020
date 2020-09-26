#include "Jefe1.h"

Jefe1::Jefe1(double pos_x,double pos_y, int potencia) :
       JefeBase(pos_x, pos_y){
    this->tipo = TIPO_JEFE_1;
    this->alto=ALTO_JEFE_1;
    this->ancho=ANCHO_JEFE_1;
    this->velocidad = VELOCIDAD_JEFE_1;
    this->armamento = new ArmamentoJefe1(potencia);


}

void Jefe1::actualizar(Posicion pos_personaje) {
    this->estado->actualizar();
    this->armamento->actualizar(this->posicion, pos_personaje);
    if ( this->contador_daniado > 0 ){
        this->daniado = true;
        this->contador_daniado--;
    }
    else{
        this->daniado = false;
    }
}

bool Jefe1::esJefe() {
    return true;
}
