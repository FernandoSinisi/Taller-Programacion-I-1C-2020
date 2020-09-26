#ifndef SERVIDOR_JUEGO_H
#define SERVIDOR_JUEGO_H

#include <string>
#include <vector>
#include "Nivel.h"

class Juego {
    Nivel* nivel;
    int numero_nivel;
    int numero_personajes;
    bool nivel_empezado;
    std::vector<int> cantidad_enemigos_nivel_1;
    std::vector<std::string> tipos_enemigos_nivel_1;
    std::vector<Personaje*>* personajes;


    std::vector<int> cantidad_enemigos_nivel_2;
    std::vector<std::string> tipos_enemigos_nivel_2;


public:
    Juego(int n_clientes);

    void actualizar();
    void actualizar(int input);

    std::string getEstadoPersonajes();
    std::string getEstadoEnemigos();
    std::string getEstadoFondo();

    void conectarPersonaje(int nro_personaje);
    void desconectarPersonaje(int nro_personaje);

    bool getNivelFinalizado();
    void avanzarNivel();

    bool nivelEmpezado();
    bool estaActivo();

    int getNumeroNivel();

    void terminar();

    bool finalizado();

    ~Juego();

    void setNombreJugador(const Uint16 n, std::string nombre);
    std::string getNombreJugador(Uint16 n);
};

#endif //SERVIDOR_JUEGO_H
