#ifndef PRIMERAENTREGA_JUEGO_CONTROLADOR_H
#define PRIMERAENTREGA_JUEGO_CONTROLADOR_H

#include "../model/Juego.h"
#include "../view/JuegoVista.h"
#include "CartelNivelControlador.h"
#include <SDL2/SDL.h>

class JuegoControlador{
    private:
        Juego* juego;
        JuegoVista* vista;
        SDL_Event evento;
        int tecla_apretada;
        CartelNivelControlador* cartel;

        int fps;

        void logueoDeConstantes();

    public:
        explicit JuegoControlador(int argc, char* argv[]);
        virtual ~JuegoControlador();

        bool inicializar();
        bool estaActivo();
        void actualizar();
        bool avanzarNivel();
        void terminar();
};

#endif //PRIMERAENTREGA_JUEGO_CONTROLADOR
