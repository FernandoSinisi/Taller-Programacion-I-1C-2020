#ifndef CLIENTE_MENULOG_H
#define CLIENTE_MENULOG_H

#include <string>
#include <SDL2/SDL.h>

class MenuLog {
    private:
        int actual;

    public:
        explicit MenuLog();
        virtual ~MenuLog();
        int actualizar();
        void configurar(int caso, std::string valor);
        bool estaActivo();
        bool estaIniciado();
        bool estaCancelado(SDL_Event *evento);

    void reestablecer();
};


#endif //CLIENTE_MENULOG_H
