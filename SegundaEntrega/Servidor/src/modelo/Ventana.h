#ifndef PRIMERAENTREGA_VENTANA_H
#define PRIMERAENTREGA_VENTANA_H

#include <SDL2/SDL_image.h>
#include "Personaje.h"
#include "../tools/SDL_Utils.h"
#include "Enemigo.h"

class Ventana {
    private:
        SDL_Rect marco_ventana;
        double posicion_x_fondo;
        float incremento_ventana;

    public:
        Ventana(float incremento);
        void actualizar();
        void corregirColisionBorde(Personaje* personaje);
        void actualizarPosicionVistaPersonaje(Personaje* personaje);

        void actualizarPosicionVistaEnemigo(Enemigo *enemigo);
        double getX();
};

#endif //PRIMERAENTREGA_VENTANA_H
