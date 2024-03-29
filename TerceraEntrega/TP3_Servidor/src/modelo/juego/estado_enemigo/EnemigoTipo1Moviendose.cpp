#include "EnemigoTipo1Moviendose.h"


EnemigoTipo1Moviendose::EnemigoTipo1Moviendose(Enemigo *enemigo_nuevo) :
            enemigo(enemigo_nuevo),
            direccion(POS_NINGUNA),
            contador(0),
            velocidad(enemigo_nuevo->getVelocidad()),
            alineandose(true),
            esquivando(false),
            partida(POS_NINGUNA),
            llego_area_jefe(false){

}

EnemigoTipo1Moviendose::~EnemigoTipo1Moviendose(){

}

bool EnemigoTipo1Moviendose::estaQuieto() {
    return this->direccion == POS_NINGUNA && !this->alineandose;
}

void EnemigoTipo1Moviendose::activar() {
    //activar no hace nada porque cuando el enemigo se esta moviendo ya esta activo
}

void EnemigoTipo1Moviendose::actualizar() {

    // El enemigo 1 tiene 3 estados: Alinearse, quedarse quieto y disparar, esquivar en L (primero vertical y luego horizontalmente)

    if (this->llego_area_jefe){
        this->enemigo->mover( this->direccion * this->velocidad);
        return;
    }

    if (this->alineandose) {
        this->direccion = this->obtenerDireccionAlinear(this->enemigo->getPosPersonajeCercano());
    }

    else if (!this->alineandose && !this->esquivando){
        this->actualizarQuieto();
    }

    else if (this->esquivando){
        this->direccion = this->obtenerDireccionEsquivar();
    }

    //Si tiene direccion contraria solo se puede mover para la derecha
    if (this->enemigo->direccionContraria() and this->direccion.getX() < 0){
        this->direccion.setX(this->direccion.getX() * INVERSION_DIR_EJE_ENEMIGO);
    }

    if( this->enemigo->getPosX() + direccion.getX()  < this->enemigo->getTopePosicionX()) {
        if ( this->enemigo->getPosicionVentana().getX() > ( this->enemigo->getPosPersonajeCercano().getX() + ANCHO_PERSONAJE + 200 ) ){
            this->enemigo->setDireccionContraria(false);
        }
        else if (  this->enemigo->getPosicionVentana().getX() + getAltoEnemigo1() + 200 <  this->enemigo->getPosPersonajeCercano().getX() ){
            this->enemigo->setDireccionContraria(true);
        }

        this->enemigo->mover(this->direccion * this->velocidad);

    } else{
        this->actualizarLlegoAreaJefe();
    }
}

Posicion EnemigoTipo1Moviendose::obtenerDireccionAlinear(Posicion pos){

    int dist_y = (int) (( this->enemigo->getPosY() + getAltoEnemigo1() / 2 ) - ( pos.getY() + ALTO_PERSONAJE / 2 ));

    this->contador++;

    if (this->contador >= VALOR_CONTADOR_MOV_ENEMIGO_TIPO_1_ALINEANDOSE && abs(dist_y) <= ((int)ALTO_PERSONAJE / 2)){
        this->alineandose = false;
        this->contador=0;
        return POS_NINGUNA;
    }

    if ( dist_y > ( (int) ALTO_PERSONAJE / 2) ){
        return POS_ARRIBA;
    }
    else if ( dist_y < (-1)*((int)( ALTO_PERSONAJE / 2 ) ) ){
        return POS_ABAJO;
    }

    //else
    return POS_NINGUNA;

}
void EnemigoTipo1Moviendose::actualizarQuieto() {
    if (this->contador == 0) {
        // Si el enemigo no esta mirando al personaje hago que se de vuelta
        if (this->enemigo->getPosicionVentana().getX() < this->enemigo->getPosPersonajeCercano().getX() and !this->enemigo->direccionContraria()) {
            this->enemigo->setDireccionContraria(true);
        } else if (this->enemigo->getPosicionVentana().getX() > this->enemigo->getPosPersonajeCercano().getX() and this->enemigo->direccionContraria()) {
            this->enemigo->setDireccionContraria(false);
        }
    }

    this->contador++;

    if (this->contador == VALOR_CONTADOR_MOV_ENEMIGO_TIPO_1_QUIETO) {
        this->esquivando = true;
        this->contador = 0;
        this->partida = this->enemigo->getPosicionVentana();
    }

}

Posicion EnemigoTipo1Moviendose::obtenerDireccionEsquivar(){

    int pos_vector;
    Posicion dir=POS_NINGUNA;

    if ( this->contador < VALOR_CONTADOR_MOV_ENEMIGO_TIPO_1_ARRANQUE  ){
        pos_vector=POS_MOV_EJE_Y_ENEMIGO_1;

    } else if ( this->contador > VALOR_CONTADOR_MOV_ENEMIGO_TIPO_1_TERMINA && abs(this->enemigo->getPosicionVentana().getX() - this->enemigo->getPosPersonajeCercano().getX()) > 2*ANCHO_TIPO_ENEMIGO_1 )  {
        pos_vector=POS_INVALIDA_MOV_ENEMIGO_1;

    } else {
        pos_vector=POS_MOV_EJE_X_ENEMIGO_1;
    }

    if ( pos_vector == POS_INVALIDA_MOV_ENEMIGO_1 ){
        this->contador=0;
        this->alineandose = true;
        this->esquivando = false;
        return POS_NINGUNA;
    }


    if (this->enemigo->getPosicionVentana().getX() > ANCHO_VENTANA - TOPE_HORIZONTAL_JEFE_1 - ANCHO_TIPO_ENEMIGO_1 && this->direccion.getX() > 0){
        this->partida.setX( (2* ANCHO_VENTANA) / 3);
    }

    if ( ( this->partida.getX() <= ANCHO_VENTANA / 2 ) && ( this->partida.getY() <= ALTO_VENTANA / 2 ) ){
        dir=MOVIMIENTO_ENEMIGO1_ABA_DER[(unsigned long) pos_vector];
    }
    else if ( ( this->partida.getX() >= ANCHO_VENTANA / 2 ) && ( this->partida.getY() <= ALTO_VENTANA / 2 ) ){
        dir=MOVIMIENTO_ENEMIGO1_ABA_IZQ[(unsigned long) pos_vector];
    }
    if ( ( this->partida.getX() <= ANCHO_VENTANA / 2 ) && ( this->partida.getY() >= ALTO_VENTANA / 2 ) ){
        dir=MOVIMIENTO_ENEMIGO1_ARR_DER[(unsigned long) pos_vector];
    }
    if ( ( this->partida.getX() >= ANCHO_VENTANA / 2 ) && ( this->partida.getY() >= ALTO_VENTANA / 2 ) ){
        dir=MOVIMIENTO_ENEMIGO1_ARR_IZQ[(unsigned long) pos_vector];
    }

    this->contador++;

    return dir;
}

void EnemigoTipo1Moviendose::actualizarLlegoAreaJefe() {
    this->llego_area_jefe = true;
    if ( this->enemigo->direccionContraria() ){
        this->enemigo->actualizarDireccionInicial();
    }
    this->direccion = POS_IZQUIERDA;
    this->enemigo->mover( this->direccion * this->velocidad);
}