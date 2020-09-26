#ifndef PRIMERAENTREGA_NIVELVISTA_H
#define PRIMERAENTREGA_NIVELVISTA_H

#include "FondoVista.h"

class NivelVista {
    private:
        std::vector<FondoVista*> fondos;
        size_t nivel_actual;
    public:
        NivelVista( SDL_Renderer* renderizador);
        void avanzarNivel();
        void mostrarFondo(SDL_Renderer *renderizador);
        void actualizarPosicionFondo(int posicion_ventana);
        FondoVista* getFondoActual();
        ~NivelVista();
};


#endif //PRIMERAENTREGA_NIVELVISTA_H
