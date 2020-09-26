#include "MenuJuegoControlador.h"
#include "../tools/Constantes.h"
#include "../modelo/MenuJuego.h"
#include "../vista/MenuJuegoVista.h"
#include <SDL2/SDL.h>

MenuJuegoControlador::MenuJuegoControlador(SDL_Renderer* renderizador) {
    this->menu_vista = new MenuJuegoVista(renderizador);
    this->menu = new MenuJuego();
}

MenuJuegoControlador::~MenuJuegoControlador() {
    delete(this->menu_vista);
    delete(this->menu);
}

MenuJuegoVista* MenuJuegoControlador::getVista(){
    return this->menu_vista;
}

void MenuJuegoControlador::setVista(MenuJuegoVista* v) {
    this->menu_vista = v;
}

void MenuJuegoControlador::iniciar() {
    this->menu->inicializar();
}

bool MenuJuegoControlador::actualizar() {
    if(this->menu->estaActivo()) {
        int continuar = this->menu->actualizar();
        this->menu_vista->actualizar(continuar);
        return continuar > 0;
    }

    return false;
}

bool MenuJuegoControlador::estaIniciado() {
    return this->menu->estaIniciado();
}

bool MenuJuegoControlador::estaCancelado(SDL_Event *evento) {
    return this->menu->estaCancelado(evento);
}

void MenuJuegoControlador::setMenuEspera() {
    this->menu_vista->setMenuEspera();
}

void MenuJuegoControlador::reestablecer() {
    this->menu->reestablecer();
}
