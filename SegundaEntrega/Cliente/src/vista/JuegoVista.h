#ifndef CLIENTE_JUEGOVISTA_H
#define CLIENTE_JUEGOVISTA_H

#include <SDL2/SDL.h>
//#include "../modelo/Juego.h"
#include "../tools/Constantes.h"
#include "PersonajeVista.h"
#include "EnemigoVista.h"
//#include "FondoVista.h"
#include <string>
#include "CargadorTexturasEnemigos.h"
#include "CargadorTexturasPersonajes.h"
#include "NivelVista.h"

class JuegoVista{
    
    private:
        SDL_Window* ventana; /* Para agregar elementos visuales. */
        //SDL_Texture* textura_juego; /* Para poner el fondo de pantalla. */
        SDL_Renderer* renderizador; /* Permite visibilizar estructuras. */
        std::vector<PersonajeVista*> personajes_vista;
        std::map<std::string, std::vector<EnemigoVista*>*> enemigos_vista_map;
        NivelVista* nivel;
        CargadorTexturasEnemigos* cargadorEnemigos;
        CargadorTexturasPersonajes* cargadorPersonajes;

        uint32_t fps;
        uint32_t t_anterior_frame;

    public:
        explicit JuegoVista();
        virtual ~JuegoVista();

        SDL_Renderer* getRenderizador();
        void iniciar();

        void crearVistaPersonajes(int cantidad);
        void eliminarVistaPersonajes(int cantidad);

        void crearVistaEnemigos(std::string tipo, int cantidad);
        void actualizarVistaEnemigos(std::string tipo, int cantidad, std::stringstream* stream_estado);
        void eliminarVistaEnemigos(std::string tipo, int cantidad);
        void decodificarEstadoEnemigos(std::string estado);

        void actualizar(std::string estado);
        void avanzarNivel();
        void dibujar();
        void destruir();
        FondoVista* getFondo();
        void mostrarJugadoresConectados();

        void setNivel(int nro_nivel);

        void reiniciar();
};

#endif //CLIENTE_JUEGOVISTA_H