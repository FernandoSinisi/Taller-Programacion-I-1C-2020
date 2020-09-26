#include "JuegoControlador.h"


JuegoControlador::JuegoControlador(int n_clientes) {
    this->juego = new Juego(n_clientes);
}

void JuegoControlador::setNombreJugador(uint16_t n, std::string nombre) {
    this->juego->setNombreJugador(n, nombre);
}

std::string JuegoControlador::getNombreJugador(uint16_t n) {
    return this->juego->getNombreJugador(n);
}

bool JuegoControlador::estaActivo() {
    return this->juego->estaActivo();
}

void JuegoControlador::actualizar() {
    this->juego->actualizar();

}

void JuegoControlador::conectar(int nro_cliente) {
    this->juego->conectarPersonaje(nro_cliente);
}

void JuegoControlador::desconectar(int nro_cliente) {
    this->juego->desconectarPersonaje(nro_cliente);
}

void JuegoControlador::actualizar(uint16_t input) {
    this->juego->actualizar(input);
}

std::string JuegoControlador::getEstadoPersonajes(){
    return this->juego->getEstadoPersonajes();
}

std::string JuegoControlador::getEstadoEnemigos(){
    return this->juego->getEstadoEnemigos();
}

std::string JuegoControlador::getEstadoFondo(){
    return this->juego->getEstadoFondo();
}

void JuegoControlador::terminar() {
    this->juego->terminar();
    //loguear(LOG_JUEGO_FINALIZADO, LOG_DEBUG);
}

bool JuegoControlador::nivelEmpezado() {
    return this->juego->nivelEmpezado();
}

int JuegoControlador::getNumeroNivel() {
    return this->juego->getNumeroNivel();
}

bool JuegoControlador::nivelFinalizado() {
    return this->juego->getNivelFinalizado();
}

bool JuegoControlador::juegoFinalizado() {
    return this->juego->finalizado();
}

/*
bool JuegoControlador::avanzarNivel(){

    //TODO: Cuando se avanza de nivel los personajes deben pasar a estar "No listos"
    if (this->juego->estaActivo()){
        this->terminar();
        return false;
    }

    return true;
}
*/

JuegoControlador::~JuegoControlador() {
    delete (this->juego);
}