#ifndef CLIENTE_MENUJUEGO_H
#define CLIENTE_MENUJUEGO_H

#include <string>

class MenuJuego {
  private:
    int actual;
    bool activo;

   public:
        MenuJuego();
        virtual ~MenuJuego();

        int inicializar();
        int actualizar();
        bool estaActivo();
        bool estaIniciado();
        bool estaCancelado(SDL_Event* evento);
        void reestablecer();
};

#endif //CLIENTE_MENUJUEGO_H
