#include "Ventana.h"
#include "../tools/Constantes.h"

Ventana::Ventana(float incremento) {
    this->posicion_x_fondo = ANCHO_FONDO/2;
    this->incremento_ventana = incremento;
    initRect(&this->marco_ventana, 0, 0, ANCHO_VENTANA,ALTO_VENTANA);
}

/*Este metodo detecta y corrige al personaje para que
 su imagen no se escape por el borde de la ventana de la vista*/
void Ventana::corregirColisionBorde(Personaje *personaje) {

    SDL_Rect posicionPersonaje;
    SDL_Rect interseccion;

    initRect(&posicionPersonaje,
            (int) personaje->getPosicionVentana().getX(),
            (int) personaje->getPosicionVentana().getY(),
            ANCHO_PERSONAJE,
            ALTO_PERSONAJE);


    if ( ! SDL_IntersectRect(&posicionPersonaje,&marco_ventana,&interseccion) ){
        return;
    }

    if ( interseccion.w < posicionPersonaje.w) {

        if (interseccion.x == posicionPersonaje.x) {
            personaje->actualizarColision(POS_DERECHA);

        } else {
            personaje->actualizarColision(POS_IZQUIERDA);
        }
    }


    if ( interseccion.h < posicionPersonaje.h ) {
        if (interseccion.y == posicionPersonaje.y) {
            personaje->actualizarColision(POS_ABAJO);
        } else {
           personaje->actualizarColision(POS_ARRIBA);
        }
    }
}

void Ventana::actualizar(){
    this->posicion_x_fondo += this->incremento_ventana;
}

double Ventana::getX() {
    return this->posicion_x_fondo;
}

void Ventana::actualizarPosicionVistaPersonaje(Personaje* personaje) {
    Posicion pos_ventana;

    pos_ventana.setX(personaje->getPosX() - this->posicion_x_fondo);
    pos_ventana.setY(personaje->getPosY());

    personaje->setPosicionVentana(pos_ventana);

}

void Ventana::actualizarPosicionVistaEnemigo(Enemigo* enemigo) {

    Posicion pos_ventana;

    pos_ventana.setX(enemigo->getPosX() - posicion_x_fondo);
    pos_ventana.setY(enemigo->getPosY());

    enemigo->setPosicionVentana(pos_ventana);

    SDL_Rect posicionEnemigo;
    SDL_Rect interseccion;

    std::string tipo_enemigo = std::string(enemigo->getTipo());

    if (tipo_enemigo == std::string(getTipoEnemigo1())){
        initRect(&posicionEnemigo,
                 (int) enemigo->getPosicionVentana().getX(),
                 (int) enemigo->getPosicionVentana().getY(),
                 getTamAnchoEnemigo1(),
                 getTamAltoEnemigo1());
    } else {
        initRect(&posicionEnemigo,
                 (int) enemigo->getPosicionVentana().getX(),
                 (int) enemigo->getPosicionVentana().getY(),
                 getTamAnchoEnemigo2(),
                 getTamAltoEnemigo2());
    }



    if ( ! SDL_IntersectRect(&posicionEnemigo,&marco_ventana,&interseccion) ){
        enemigo->setEstaEnVentana(false);
    } else {
        enemigo->setEstaEnVentana(true);
    }

}




