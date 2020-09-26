#ifndef PRIMERAENTREGA_JUEGO_VISTA_H
#define PRIMERAENTREGA_JUEGO_VISTA_H

#include <SDL2/SDL.h>
#include "../model/Juego.h"
#include "../tools/Constantes.h"
#include "PersonajeVista.h"
#include "EnemigoVista.h"
#include "FondoVista.h"
#include <string>
#include "CargadorTexturasEnemigos.h"
#include "NivelVista.h"

class JuegoVista{
    
    private:
        SDL_Window* ventana; /* Para agregar elementos visuales. */
        //SDL_Texture* textura_juego; /* Para poner el fondo de pantalla. */
        SDL_Renderer* renderizador; /* Permite visibilizar estructuras. */
        PersonajeVista* personaje;
        std::map<std::string, std::vector<EnemigoVista*>*> enemigos_vista_map;
        NivelVista* nivel;
        CargadorTexturasEnemigos* cargadorEnemigos;

    public:
        explicit JuegoVista();
        virtual ~JuegoVista();

        SDL_Renderer* getRenderizador();
        void inicializar();
        void crearVistaEnemigos(std::string tipo, int cantidad);
        void actualizarVistaEnemigos(std::string tipo, int cantidad, std::stringstream* stream_estado);
        void eliminarVistaEnemigos(std::string tipo, int cantidad);
        void decodificarEstadoEnemigos(std::string estado);
        void actualizar(std::string estado);
        void dibujar();
        void destruir();
        FondoVista* getFondo();
};

#endif //PRIMERAENTREGA_JUEGO_VISTA_H