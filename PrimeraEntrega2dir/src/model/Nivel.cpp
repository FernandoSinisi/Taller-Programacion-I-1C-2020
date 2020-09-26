#include "Nivel.h"
#include <SDL2/SDL.h>
#include "Posicion.h"
#include "../tools/Constantes.h"
#include "../tools/Utils.h"
#include "Colisionador.h"
#include "../tools/Log.h"
#include <map>

Nivel::Nivel(std::vector<std::string> tipo_enemigos_nivel, std::vector<int> cantidad_enemigos_nivel) {
    this->personaje = new Personaje(X_PERSONAJE + ANCHO_FONDO / 2, Y_PERSONAJE, INCREMENTO_PERSONAJE);
    this->activado = true;

    this->cantidad_enemigos = 0;
    this->crearEnemigos(tipo_enemigos_nivel, cantidad_enemigos_nivel);

    this->ventana = new Ventana(DESPLAZAMIENTO_FONDO);

    this->finalizado = false;
    this->contador = 0;
}

bool Nivel::estaActivo() {
    return this->activado;
}

void Nivel::actualizar() {

    this->ventana->corregirColisionBorde(this->personaje);

    if (this->ventana->getX() < (ANCHO_FONDO - ANCHO_VENTANA)) {
        this->personaje->mover(POS_DERECHA_FONDO);
        this->ventana->actualizar();

    } else {
        this->contador += 1;
        if (this->contador == TIEMPO_FIN_NIVEL){
            this->finalizado = true;
        }
    }

    this->personaje->actualizar();
    this->ventana->actualizarPosicionVistaPersonaje(this->personaje);

    for(auto &enemigo: this->enemigos) {
        enemigo->actualizar();
        this->ventana->actualizarPosicionVistaEnemigo(enemigo);
    }


}

void Nivel::actualizar(int input) {


    if (input == TECLAS_ARRIBA_IZQUIERDA) {
        this->personaje->actualizar(POS_ARRIBA_IZQ);

    } else if (input == TECLAS_ARRIBA_DERECHA) {
        this->personaje->actualizar(POS_ARRIBA_DER);

    } else if (input == TECLAS_ABAJO_IZQUIERDA) {
        this->personaje->actualizar(POS_ABJAJO_IZQ);

    } else if (input == TECLAS_ABAJO_DERECHA) {
        this->personaje->actualizar(POS_ABAJO_DER);

    } else if (input == TECLA_ARRIBA) {
        this->personaje->actualizar(POS_ARRIBA);

    } else if (input == TECLA_IZQUIERDA) {
        this->personaje->actualizar(POS_IZQUIERDA);

    } else if (input == TECLA_ABAJO) {
        this->personaje->actualizar(POS_ABAJO);

    } else if (input == TECLA_DERECHA) {
        this->personaje->actualizar(POS_DERECHA);

    } else if (input == TECLA_NINGUNA) {
        this->personaje->actualizar(POS_NINGUNA);
    }

}

std::string Nivel::getEstadoPersonaje() {
    std::string estado = (PRE_POSICION_JUGADOR +
                          SEPARADOR +
                          std::to_string((int)this->personaje->getPosicionVentana().getX()) +
                          SEPARADOR +
                          std::to_string((int)this->personaje->getPosicionVentana().getY()) +
                          SEPARADOR +
                          std::to_string((int)this->personaje->getDireccion())
    );
    return estado;
}

std::string Nivel::getEstadoEnemigo() {
    //Pre_pos_enemigo + Cantidad_tipos_enemigos + tipo_1 + cantidad_enemigos_tipo_1 + x_1_tipo_1 + y_1_tipo_1 + x_2_tipo_1 +
    //y_2_tipo_1 + ... + tipo_k + cantidad_enemigos_tipo_k + x_1_tipo_k + y_1_tipo_k + x_2_tipo_k + y_2_tipo_k
    std::string estado = (PRE_POSICION_ENEMIGO);

    long unsigned cantidad;
    std::map<std::string, std::pair<long unsigned, std::string>> tipos;
    std::string posiciones_enemigos;

    int dir = DIRECCION_ENEMIGO_IZQUIERDA;
    for (auto &i: this->enemigos){
        if (i->getEstaEnVentana()){
            if (i->seMueve()) {
                dir = DIRECCION_ENEMIGO_DERECHA;
            } else {
                dir = DIRECCION_ENEMIGO_IZQUIERDA;
            }
            posiciones_enemigos = (SEPARADOR +
                                   std::to_string((int)i->getPosicionVentana().getX()) +
                                   SEPARADOR +
                                   std::to_string((int)i->getPosicionVentana().getY()) +
                                   SEPARADOR +
                                   std::to_string(dir)
            );
            if(tipos.find(i->getTipo()) != tipos.end()) {
                tipos[std::string(i->getTipo())].first = tipos[std::string(i->getTipo())].first + 1;
                tipos[std::string(i->getTipo())].second += posiciones_enemigos;
            } else {
                tipos[std::string(i->getTipo())].first = 1;
                tipos[std::string(i->getTipo())].second = posiciones_enemigos;
            }
        }

    }
    long unsigned cantidad_de_clases = tipos.size();

    estado += (SEPARADOR + std::to_string(cantidad_de_clases));

    for(std::map<std::string, std::pair<long unsigned, std::string>>::iterator par=tipos.begin(); par != tipos.end(); ++par){
        //Tipo enemigo:
        estado += (SEPARADOR + par->first);
        //Cantidad tipo enemigo:
        cantidad = par->second.first;
        estado += (SEPARADOR + std::to_string(cantidad));
        //Posiciones de enemigos de ese tipo
        estado += par->second.second;
    }
    return estado;
}

std::string Nivel::getEstadoFondo() {
    std::string estado = (PRE_POSICION_VENTANA +
                          SEPARADOR +
                          std::to_string((int)((this->ventana->getX() - ANCHO_FONDO/2)/ 2))
    );
    return estado;
}


bool Nivel::getNivelFinalizado(){
    return this->finalizado;
}

void Nivel::crearEnemigos(std::vector<std::string> tipo_enemigos_nivel, std::vector<int> cantidad_enemigos_nivel) {
    int pos_aux[2];
    srand( (unsigned)time( NULL ) );

    for(long unsigned i=0; i<tipo_enemigos_nivel.size(); ++i) {
        int cant_enemigos = cantidad_enemigos_nivel[i];
        for(int j=0; j<cant_enemigos; ++j) {
            obtenerRandom(pos_aux);
            while (Colisionador::hayColisiones(pos_aux, (char *) (tipo_enemigos_nivel[i]).c_str(), this->enemigos)) {
                obtenerRandom(pos_aux);
            }
            this->enemigos.push_back(new Enemigo(pos_aux[0], pos_aux[1], (char*)(tipo_enemigos_nivel[i]).c_str()));
        }
        this->cantidad_enemigos += cantidad_enemigos_nivel[i];
    }

}

void Nivel::terminar() {
    this->activado = false;
}

Nivel::~Nivel() {
    delete (this->personaje);
    delete (this->ventana);
    int  i = 0;
    while( i < this->cantidad_enemigos){
        delete (this->enemigos[(unsigned  long)i]);
        i = i + 1;
    }
}

int Nivel::getCantidadEnemigos() {
    return this->cantidad_enemigos;
}

void Nivel::setCantidadEnemigos(int n) {
    this->cantidad_enemigos = n;
}



