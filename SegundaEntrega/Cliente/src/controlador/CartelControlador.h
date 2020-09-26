#ifndef CLIENTE_CARTELCONTROLADOR_H
#define CLIENTE_CARTELCONTROLADOR_H

#include <SDL2/SDL_image.h>
#include "../modelo/Cartel.h"
#include "../vista/CartelVista.h"
#include <string>

class CartelControlador {
    private:
        Cartel* cartel;
        CartelVista* vista_cartel;

    public:
        CartelControlador(SDL_Renderer* renderizador, std::vector<char*> c);
        virtual ~CartelControlador();

        void desactivarInput();
        void activarInput();
        void retrocederCartel();
        bool actualizar(SDL_Event* evento, bool usar_numero);
        void cambiar();
        bool iniciarNivel(SDL_Event* evento);

        //Setea el cartel al anterior al de los que aparecen en el transcurso del juego (stages)
        void setIniciarJuego();

        void resetearCarteles();

        bool esperaInput();
        void actualizarJugadoresConectados(std::string mensaje);

        void setNivel(int nivel);
};

#endif //CLIENTE_CARTELCONTROLADOR_H
