#include "ArmamentoJefe1.h"

ArmamentoJefe1::ArmamentoJefe1(int potencia_proyectiles): Armamento(-1, potencia_proyectiles){
    this->estaDisparando = false;

    this->cooldown_inicial = TIEMPO_COOLDOWN_DISPAROS_JEFE_1;
    this->cooldown = this->cooldown_inicial;

    // Esto es para indicar que el proyectil pertenece a un enemigo y no a un jugador
    this->nro_personaje = NRO_ENEMIGO_JEFE;
    this->potencia = potencia_proyectiles;
    this->contador_disparos = 0;
}

Proyectil* ArmamentoJefe1::usar(Posicion pos_inic, Posicion direccion){
    int velocidad = getTamAnchoProyectil() / 3;
    if (this->cooldown == 1 and this->estaDisparando ) {
        return new Proyectil(pos_inic, direccion * ((3*velocidad) / 10), this->potencia);
    }
    
    return nullptr;

}

void ArmamentoJefe1::disparoSimpleCentral(Posicion pos_inic){
    Proyectil *proyectil = this->usar(pos_inic + Posicion(CORRECCION_X_JEFE_1, (ALTO_JEFE_1 / 2)), POS_IZQUIERDA);
    if (proyectil) {
        proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
        this->proyectiles->push_back(proyectil);
    }
}

void ArmamentoJefe1::disparoDobleCentral(Posicion pos_inic){
    Proyectil *proyectil = this->usar(pos_inic + Posicion(50, (ALTO_JEFE_1 / 2) - CORRECCION_Y_DISPARO), POS_IZQUIERDA);
    if (proyectil) {
        proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
        this->proyectiles->push_back(proyectil);
    }
    proyectil = this->usar(pos_inic + Posicion(50, (ALTO_JEFE_1 / 2) + CORRECCION_Y_DISPARO), POS_IZQUIERDA);
    if (proyectil) {
        proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
        this->proyectiles->push_back(proyectil);
    }
}

void ArmamentoJefe1::disparoTriple(Posicion pos_inic){
    Proyectil *proyectil = this->usar(pos_inic + Posicion(50, (ALTO_JEFE_1 / 2) + CORRECCION_Y_DISPARO), Posicion(ANGULO_1_J3));
    if (proyectil) {
        proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
        this->proyectiles->push_back(proyectil);
    }

    proyectil = this->usar(pos_inic + Posicion(50, (ALTO_JEFE_1 / 2)), POS_IZQUIERDA);
    if (proyectil) {
        proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
        this->proyectiles->push_back(proyectil);
    }

    proyectil = this->usar(pos_inic + Posicion(50, (ALTO_JEFE_1 / 2) - CORRECCION_Y_DISPARO), Posicion(ANGULO_4_J3));
    if (proyectil) {
        proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
        this->proyectiles->push_back(proyectil);
    }
}

void ArmamentoJefe1::disparoCuadruple(Posicion pos_inic){
    Proyectil *proyectil = this->usar(pos_inic + Posicion(50, (ALTO_JEFE_1 / 2) + CORRECCION_Y_DISPARO), Posicion(ANGULO_2_J3));
    if (proyectil) {
        proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
        this->proyectiles->push_back(proyectil);
    }
    proyectil = this->usar(pos_inic + Posicion(50, (ALTO_JEFE_1 / 2) + CORRECCION_Y_DISPARO), Posicion(ANGULO_1_J3));
    if (proyectil) {
        proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
        this->proyectiles->push_back(proyectil);
    }
    proyectil = this->usar(pos_inic + Posicion(50, (ALTO_JEFE_1 / 2) - CORRECCION_Y_DISPARO), Posicion(ANGULO_4_J3));
    if (proyectil) {
        proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
        this->proyectiles->push_back(proyectil);
    }

    proyectil = this->usar(pos_inic + Posicion(50, (ALTO_JEFE_1 / 2) - CORRECCION_Y_DISPARO), Posicion(ANGULO_3_J3));
    if (proyectil) {
        proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
        this->proyectiles->push_back(proyectil);
    }
}

void ArmamentoJefe1::disparoDobleHoming(Posicion pos_inic, Posicion pos_personaje){
    Posicion pos_aux = pos_inic + Posicion(CORRECCION_X_JEFE_1, (ALTO_JEFE_1 / 2) + CORRECCION_Y_DISPARO);
    Proyectil *proyectil = this->usar(pos_aux, pos_aux.direccion(pos_personaje));
    if (proyectil) {
        proyectil->setNumeroPersonaje(NRO_ENEMIGO_CLASE_2);
        this->proyectiles->push_back(proyectil);
    }
    pos_aux = pos_inic + Posicion(CORRECCION_X_JEFE_1, (ALTO_JEFE_1 / 2) - CORRECCION_Y_DISPARO);
    proyectil = this->usar(pos_aux, pos_aux.direccion(pos_personaje));
    if (proyectil) {
        proyectil->setNumeroPersonaje(NRO_ENEMIGO_CLASE_2);
        this->proyectiles->push_back(proyectil);
    }
}

void ArmamentoJefe1::actualizar(Posicion pos_inic, Posicion pos_personaje) {

    switch (this->contador_disparos){
        case CONT_DISPAROS_CERO:
        case CONT_DISPAROS_UNO:
        case CONT_DISPAROS_DOS:
            disparoSimpleCentral(pos_inic);
            break;
        case CONT_DISPAROS_TRES:
        case CONT_DISPAROS_CUATRO:
        case CONT_DISPAROS_CINCO:
            disparoDobleCentral(pos_inic);
            break;
        case CONT_DISPAROS_SEIS:
            disparoTriple(pos_inic);
            break;
        case CONT_DISPAROS_SIETE:
            disparoCuadruple(pos_inic);
            break;
        case CONT_DISPAROS_OCHO:
            disparoDobleHoming(pos_inic, pos_personaje);
            break;
        default:
            break;

    }

    if (this->contador_disparos < CONT_DISPAROS_DOS and this->cooldown == MIN_VALOR_COOLDOWN) {
        this->cooldown = this->cooldown_inicial;
        this->contador_disparos++;
    } else if (this->contador_disparos == CONT_DISPAROS_DOS and this->cooldown == MIN_VALOR_COOLDOWN) {
        this->cooldown = this->cooldown_inicial * INCREMENTO_COOLDOWN_J3_2;
        this->contador_disparos++;
    } else if (this->contador_disparos < CONT_DISPAROS_CINCO and this->cooldown == MIN_VALOR_COOLDOWN) {
        this->cooldown = this->cooldown_inicial;
        this->contador_disparos++;
    } else if (this->contador_disparos == CONT_DISPAROS_CINCO and this->cooldown == MIN_VALOR_COOLDOWN) {
        this->cooldown = this->cooldown_inicial * INCREMENTO_COOLDOWN_J3_2;
        this->contador_disparos++;
    } else if (this->contador_disparos < CONT_DISPAROS_SIETE and this->cooldown == MIN_VALOR_COOLDOWN) {
        this->cooldown = this->cooldown_inicial * INCREMENTO_COOLDOWN_J3_1;
        this->contador_disparos++;
    } else if (this->contador_disparos == CONT_DISPAROS_SIETE and this->cooldown == MIN_VALOR_COOLDOWN) {
        this->cooldown = this->cooldown_inicial * INCREMENTO_COOLDOWN_J3_2;
        this->contador_disparos++;
    } else if (this->contador_disparos == CONT_DISPAROS_OCHO and this->cooldown == MIN_VALOR_COOLDOWN) {
        this->cooldown = this->cooldown_inicial * INCREMENTO_COOLDOWN_J3_3;
        this->contador_disparos = 0;
    } else if (this->cooldown > MIN_VALOR_COOLDOWN) {
        this->cooldown--;
    }

    (void)pos_personaje;
}

void ArmamentoJefe1::setEstaDisparando(bool disparando){
    this->estaDisparando = disparando;
    if (!disparando){
        this->cooldown = this->cooldown_inicial;
    }
}

ArmamentoJefe1::~ArmamentoJefe1(){

}

