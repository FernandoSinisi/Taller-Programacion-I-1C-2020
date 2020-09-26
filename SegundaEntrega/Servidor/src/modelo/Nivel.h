#ifndef SERVIDOR_NIVEL_H
#define SERVIDOR_NIVEL_H

#include <SDL2/SDL_stdinc.h>
#include <string>
#include "Personaje.h"
#include "Ventana.h"
#include "../tools/Constantes.h"

class Nivel{
    
    private:
        int nro_nivel;
        bool activado;
        std::vector<Enemigo*> enemigos;
        int cantidad_enemigos;
        Ventana* ventana;
        std::vector<Personaje*>* personajes;

        int contador; //Variable momentanea, es condicion para pasar de nivel
        bool finalizado;


public:
        Nivel(std::vector<Personaje*>* pers, std::vector<std::string> tipo_enemigos_nivel, std::vector<int> cantidad_enemigos_nivel);

        ~Nivel();

        bool estaActivo();

        void conectarPersonaje(int nro_personaje);
        void desconectarPersonaje(int nro_personaje);

        void actualizar();
        void actualizar(int input, long unsigned nro_personaje);

        std::string getEstadoPersonajes();
        std::string getEstadoFondo();
        std::string getEstadoEnemigos();

        bool getNivelFinalizado();

        int getCantidadEnemigos();
        void setCantidadEnemigos(int n);

        void moverVentana();
        void calcularPosicionesVentana();

    void crearEnemigos(std::vector<std::string> tipo_enemigos_nivel, std::vector<int> cantidad_enemigos_nivel);
        void terminar();

};

#endif //SERVIDOR_NIVEL_H
