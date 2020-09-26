#include "EnemigoTipo2Moviendose.h"

EnemigoTipo2Moviendose::EnemigoTipo2Moviendose(Enemigo *enemigo_nuevo):
        enemigo(enemigo_nuevo),
        direccion(POS_ARRIBA),
        velocidad(enemigo_nuevo->getVelocidad()),
        llego_area_jefe(false){

}

EnemigoTipo2Moviendose::~EnemigoTipo2Moviendose(){

}

bool EnemigoTipo2Moviendose::estaQuieto() {
    return false;
}

void EnemigoTipo2Moviendose::activar() {
    //Activar no hace nada porque cuando el enemigo se esta moviendo ya esta activo
}

void EnemigoTipo2Moviendose::actualizar() {

    if (this->llego_area_jefe){
        this->enemigo->mover( this->direccion * this->velocidad);
        return;
    }

    this->obtenerNuevaDireccion();

    if (this->enemigo->getPosX() + direccion.getX()  < this->enemigo->getTopePosicionX()) {
        this->enemigo->mover(this->direccion * this->velocidad);
        if (this->enemigo->getPosX() > (ANCHO_FONDO - ANCHO_VENTANA)) {
            this->enemigo->mover(Posicion(this->direccion.getX() < 0 ? -1 * DESPLAZAMIENTO_FONDO : DESPLAZAMIENTO_FONDO, 0));
        }

    } else {
        this->llego_area_jefe = true;
        if (this->enemigo->direccionContraria()) {
            this->enemigo->actualizarDireccionInicial();
        }
        this->direccion = POS_IZQUIERDA;
        this->enemigo->mover(this->direccion * this->velocidad);
    }

}

void EnemigoTipo2Moviendose::obtenerNuevaDireccion() {
    if (this->enemigo->getPosicionVentana().getX() < LIMITE_POS_X_VENTANA_ENEMIGO_2) {
        this->enemigo->setDireccionContraria(true);
    }

    if (this->enemigo->getPosY() < ALTO_TIPO_ENEMIGO_2 / 2 && this->direccion.getY() < 0) {
        this->direccion.setY(INVERSION_DIR_EJE_ENEMIGO * this->direccion.getY());

    } else if (this->enemigo->getPosY() > ALTO_VENTANA - ALTO_TIPO_ENEMIGO_2 && this->direccion.getY() > 0) {
        this->direccion.setY(INVERSION_DIR_EJE_ENEMIGO * this->direccion.getY());
    }

    this->direccion.setX(this->obtenerDireccionHorizontal());
    this->direccion.setY(this->obtenerDireccionVertical());
    this->direccion = this->direccion.normalizar();

}

double EnemigoTipo2Moviendose::obtenerDireccionHorizontal() {
    double desplazamiento_x_aux = Posicion(0, this->enemigo->getPosY()).distancia(Posicion(0, ALTO_VENTANA / 2));
    desplazamiento_x_aux /= ALTO_VENTANA/4;

    if (!this->enemigo->direccionContraria()) {
        desplazamiento_x_aux *= INVERSION_DIR_EJE_ENEMIGO;
    }

    return desplazamiento_x_aux;
}

double EnemigoTipo2Moviendose::obtenerDireccionVertical() {
    double desplazamiento_y_aux = (ALTO_VENTANA / 2) - abs(this->enemigo->getPosY() - ALTO_VENTANA / 2);
    desplazamiento_y_aux /= (ALTO_VENTANA / 2) - LIMITE_POS_X_VENTANA_ENEMIGO_2;
    desplazamiento_y_aux *= INCREMENTO_DEZPLAZAMIENTO_EJE_Y_ENEMIGO_2;
    if (this->direccion.getY() < 0){
        desplazamiento_y_aux *= INVERSION_DIR_EJE_ENEMIGO;
    }

    return desplazamiento_y_aux;
}
