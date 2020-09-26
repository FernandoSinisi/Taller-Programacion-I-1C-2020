#ifndef PRIMERA_ENTREGA_JUEGO_H
#define PRIMERA_ENTREGA_JUEGO_H

#include <SDL2/SDL_stdinc.h>
#include <string>
#include "Personaje.h"
#include "Enemigo.h"
#include "../tools/Constantes.h"
#include "Ventana.h"

class Nivel{
    
    private:
        int nro_nivel;
        bool activado;
        Personaje* personaje;
        std::vector<Enemigo*> enemigos;
        int cantidad_enemigos;
        Ventana* ventana;

        int contador; //Variable momentanea, es condicion para pasar de nivel
        bool finalizado;


public:
        explicit Nivel(std::vector<std::string> tipo_enemigos_nivel, std::vector<int> cantidad_enemigos_nivel);
        virtual ~Nivel();

        void actualizar();
        void actualizar(int input);

        std::string getEstadoPersonaje();
        std::string getEstadoEnemigo();
        std::string getEstadoFondo();

        bool getNivelFinalizado();

        bool estaActivo();
        int getCantidadEnemigos();
        void setCantidadEnemigos(int n);

        void moverVentana();
        void calcularPosicionesVentana();

        void crearEnemigos(std::vector<std::string> tipo_enemigos_nivel, std::vector<int> cantidad_enemigos_nivel);
        void terminar();

};

#endif //PRIMERA_ENTREGA_JUEGO_H
