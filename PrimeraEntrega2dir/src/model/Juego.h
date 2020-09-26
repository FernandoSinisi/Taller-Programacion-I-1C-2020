#ifndef PRIMERAENTREGA_JUEGO_H
#define PRIMERAENTREGA_JUEGO_H

#include <string>
#include <vector>
#include "Nivel.h"

class Juego {

    Nivel* nivel;
    int numero_nivel;
    std::vector<int> cantidad_enemigos_nivel_1;
    std::vector<std::string> tipos_enemigos_nivel_1;

    std::vector<int> cantidad_enemigos_nivel_2;
    std::vector<std::string> tipos_enemigos_nivel_2;

public:

    Juego(int cant_enem_tipo_1_niv_1, int cant_enem_tipo_2_niv_1, int cant_enem_tipo_1_niv_2, int cant_enem_tipo_2_niv_2);

    void actualizar();
    void actualizar(int input);

    std::string getEstadoPersonaje();
    std::string getEstadoEnemigo();
    std::string getEstadoFondo();

    bool getNivelFinalizado();
    void avanzarNivel();

    bool estaActivo();
    int getCantidadEnemigos();

    bool finalizado();
    void terminar();


    ~Juego();
};


#endif //PRIMERAENTREGA_JUEGO_H
