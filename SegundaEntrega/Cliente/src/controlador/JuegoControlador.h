#ifndef CLIENTE_JUEGOCONTROLADOR_H
#define CLIENTE_JUEGOCONTROLADOR_H

#include "../vista/JuegoVista.h"
#include "../tools/Constantes.h"
#include "../hilos/ColaProtegida.h"
#include "../hilos/HiloDibujador.h"
#include "MenuJuegoControlador.h"
#include "CartelControlador.h"
#include "MenuLogControlador.h"
#include <SDL2/SDL.h>

class JuegoControlador{
    private:
        JuegoVista* vista;
        MenuJuegoControlador* menu;
        MenuLogControlador* menu_log;
        CartelControlador* cartel_controlador;
        TextoSDL* jugadoresConectados;

        int tecla_apretada;

        ColaProtegida<std::string>* cola_actualizaciones_vista;
        HiloDibujador* hilo_dibujador;

    public:
        explicit JuegoControlador();
        virtual ~JuegoControlador();

        void desactivarInput();
        void activarInput();
        void retrocederCartel();
        bool actualizarMenu();
        void reestablecerMenu();
        bool inicioElJuego();
        bool juegoCancelado(SDL_Event *pEvent);
        bool iniciarNivel(SDL_Event* evento);
        void finalizarNivel();
        void iniciarVista();
        void actualizarVista(std::string estado);

        bool actualizarCartel(SDL_Event* evento);
        void cambiarCartel();

        void resetearCartel();

        bool iniciar();
        bool actualizar(SDL_Event* evento, ColaProtegida<uint16_t>* cola_inputs);
        void terminar();

        bool menuLogEstaIniciado();
        void menuLogReestablecer();
        int actualizarMenuLog();
        void actualizarJugadoresConectados(std::string mensaje);
        void cartelIniciarJuego();

        void actualizarNivel(std::string estado_nivel);

        void cerrarMenuPrincipal();
        void recrearMenu();

    void reiniciar();
};

#endif //CLIENTE_JUEGOCONTROLADOR
