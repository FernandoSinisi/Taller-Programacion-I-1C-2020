#ifndef CLIENTE_MENUJUEGOCONTROLADOR_H
#define CLIENTE_MENUJUEGOCONTROLADOR_H

#include <SDL2/SDL.h>
#include "../vista/MenuJuegoVista.h"
#include "../modelo/MenuJuego.h"

class MenuJuegoControlador {
    MenuJuegoVista* menu_vista;
    MenuJuego* menu;

public:
    explicit MenuJuegoControlador(SDL_Renderer* renderizador);
    virtual ~MenuJuegoControlador();

    void iniciar();
    bool actualizar();
    bool estaIniciado();
    bool estaCancelado(SDL_Event *pEvent);

    void setMenuEspera();
    void reestablecer();
    MenuJuegoVista* getVista();
    void setVista(MenuJuegoVista* vista);
};

#endif //CLIENTE_MENUJUEGOCONTROLADOR_H
