
#include "Juego.h"
#include "../tools/Constantes.h"
#include <vector>

Juego::Juego(int n_clientes) {
    personajes = new std::vector<Personaje*>();

    for(int i = 0; i < n_clientes; ++i){
        this->personajes->push_back(new Personaje(X_PERSONAJE_DEFAULT,
                                       Y_PERSONAJE_DEFAULT + Y_PERSONAJE_DEFAULT*i,
                                        INCREMENTO_PERSONAJE, i)
                                    );
    }

    this->numero_nivel = 1;
    this->nivel_empezado = false;

    this->tipos_enemigos_nivel_1.push_back(getTipoEnemigo1());
    this->tipos_enemigos_nivel_1.push_back(getTipoEnemigo2());

    this->cantidad_enemigos_nivel_1.push_back(getCantEnemigo1Nivel1());
    this->cantidad_enemigos_nivel_1.push_back(getCantEnemigo2Nivel1());

    //TODO: ENEMIGOS DEL NIVEL 2

    this->tipos_enemigos_nivel_2.push_back(getTipoEnemigo1());
    this->tipos_enemigos_nivel_2.push_back(getTipoEnemigo2());

    this->cantidad_enemigos_nivel_2.push_back(getCantEnemigo1Nivel2());
    this->cantidad_enemigos_nivel_2.push_back(getCantEnemigo2Nivel2());


    this->nivel = new Nivel(this->personajes, this->tipos_enemigos_nivel_1, this->cantidad_enemigos_nivel_1);
}

void Juego::setNombreJugador(const Uint16 n, std::string nombre) {
    (*personajes)[n]->setNombre(nombre);
}

std::string Juego::getNombreJugador(Uint16 n) {
    return  (*personajes)[n]->getNombre();
}


void Juego::actualizar(){
    if (!this->nivel_empezado){
        return;
    }

    this->nivel->actualizar();

}

void Juego::actualizar(int input) {
    int tecla = input / CANT_CONEXIONES_MAX;
    int nro_personaje = input % CANT_CONEXIONES_MAX;

    unsigned long iterador = 0;
    unsigned long personaje = 0;
    while(iterador < this->personajes->size()){
        if ((*(this->personajes))[iterador]->getNumeroPersonaje() == nro_personaje){
            personaje = iterador;
            break;
        }
        ++iterador;
    }

    if (!this->nivel_empezado){

        if (tecla == TECLA_LISTO) {
            (*(this->personajes))[personaje]->setListo(true);

        }
        unsigned long jugadores_conectados = 0;
        unsigned long personajes_listos = 0;

        for (unsigned long i=0; i < this->personajes->size(); ++i){
            if ((*(this->personajes))[i]->estaListo()){
                personajes_listos += 1;
            }
            if ((*(this->personajes))[i]->estaConectado()){
                jugadores_conectados += 1;
            }
        }

        if (personajes_listos == jugadores_conectados){
            this->nivel_empezado = true;
        }

    }

    else {
        this->nivel->actualizar(tecla, personaje);
    }
}

std::string Juego::getEstadoPersonajes(){
    return this->nivel->getEstadoPersonajes();
}

std::string Juego::getEstadoEnemigos(){
    return this->nivel->getEstadoEnemigos();
}

std::string Juego::getEstadoFondo() {
    return this->nivel->getEstadoFondo();
}

void Juego::desconectarPersonaje(int nro_personaje) {
    this->nivel->desconectarPersonaje(nro_personaje);
}

void Juego::conectarPersonaje(int nro_personaje) {
    this->nivel->conectarPersonaje(nro_personaje);
}

bool Juego::getNivelFinalizado() {
    bool finalizado = this->nivel->getNivelFinalizado();

    if (finalizado) {
        this->avanzarNivel();
    }

    if (this->numero_nivel <= CANTIDAD_NIVELES){
        return finalizado;
    }

    return false;
}

void Juego::avanzarNivel() {
    if ((++this->numero_nivel) <= CANTIDAD_NIVELES) {
        delete(this->nivel);

        for(auto &personaje: *(this->personajes)){
            personaje->setPosX(X_PERSONAJE_DEFAULT);
            personaje->setPosY(Y_PERSONAJE_DEFAULT + Y_PERSONAJE_DEFAULT * personaje->getNumeroPersonaje());
            personaje->setListo(false);
            personaje->actualizar(POS_NINGUNA);
        }
        this->nivel_empezado = false;

        this->nivel = new Nivel(this->personajes, this->tipos_enemigos_nivel_2, this->cantidad_enemigos_nivel_2);
    }
}

bool Juego::estaActivo(){
    //Juego corriendo
    return this->nivel->estaActivo();
}

bool Juego::nivelEmpezado(){
    return this->nivel_empezado;
}

void Juego::terminar(){
    this->nivel->terminar();
}

bool Juego::finalizado() {
    return( ( this->numero_nivel == CANTIDAD_NIVELES ) && ( this->nivel->getNivelFinalizado() ) );
}

int Juego::getNumeroNivel() {
    return (this->numero_nivel - 1);
}

Juego::~Juego(){
    delete this->nivel;
    for (auto &personaje: *(this->personajes)){
        delete(personaje);
    }
}

