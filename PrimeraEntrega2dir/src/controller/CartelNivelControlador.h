#ifndef PRIMERAENTREGA_CARTELNIVELCONTROLADOR_H
#define PRIMERAENTREGA_CARTELNIVELCONTROLADOR_H

#include "../model/CartelNivel.h"
#include "../view/CartelNivelVista.h"

class CartelNivelControlador {
    private:
        CartelNivel* cartel;
        CartelNivelVista* vista_cartel;
        std::vector<char*> carteles;
        size_t cartel_actual;

    public:
        CartelNivelControlador(SDL_Renderer* renderizador);
        virtual ~CartelNivelControlador();

        bool inicializar(SDL_Event evento);
};

#endif //PRIMERAENTREGA_CARTELNIVELCONTROLADOR_H
