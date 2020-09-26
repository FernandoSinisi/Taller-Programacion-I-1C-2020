#include <SDL2/SDL.h>
#include "CartelControlador.h"
#include "../tools/Constantes.h"

CartelControlador::CartelControlador(SDL_Renderer* renderizador, std::vector<char*> c) {
    this->cartel = new Cartel(c);
    this->vista_cartel = new CartelVista(renderizador);
}

CartelControlador::~CartelControlador() {
    delete(this->cartel);
    delete(this->vista_cartel);
}

bool CartelControlador::actualizar(SDL_Event* evento, bool usar_numero) {
    if(this->cartel->continuar(evento)){
        if(usar_numero){
            this->vista_cartel->actualizar(this->cartel->getCartel(), this->cartel->getNumeroActual());
        }

        else{
            this->vista_cartel->actualizar(this->cartel->getCartel());
        }

        return true;
    }

    return false;
}

void CartelControlador::resetearCarteles(){
    this->cartel->setCartel(-1);
}

void CartelControlador::setIniciarJuego() {
    this->cartel->setCartel(CANTIDAD_CARTELES_PRE_JUEGO - 1);
}

void CartelControlador::cambiar() {
    this->vista_cartel->actualizar( (size_t)this->cartel->cambiar());
}

void CartelControlador::desactivarInput(){
    this->cartel->setEsperaInput(false);
}

void CartelControlador::activarInput(){
    this->cartel->setEsperaInput(true);
}

void CartelControlador::retrocederCartel() {
    this->cartel->retrocederCartel();
}

bool CartelControlador::esperaInput() {
    return this->cartel->esperaInput();
}

void CartelControlador::actualizarJugadoresConectados(std::string mensaje) {
    this->vista_cartel->actualizarJugadoresConectados(mensaje);
}

bool CartelControlador::iniciarNivel(SDL_Event* evento) {
    this->cambiar();
    this->cartel->iniciarNumero();
    bool continuar = true;

    for(size_t i = 0; i < CANTIDAD_CARTELES_NROS && continuar; i += 1) {
        auto tiempo_inicial = std::chrono::system_clock::now();
        auto tiempo_final = std::chrono::system_clock::now();

        while( (tiempo_final - tiempo_inicial) < TIMEOUT_NUMERO_NIVEL
                && continuar ){
            SDL_WaitEventTimeout(evento, MILISEG_TIMEOUT_EVENTOS);
            continuar = this->actualizar(evento, true);
            tiempo_final = std::chrono::system_clock::now();
        }

        this->cartel->proximoNumero();
    }

    return continuar;
}

void CartelControlador::setNivel(int nivel){
    this->cartel->setCartel(nivel*2 + 2);
}
