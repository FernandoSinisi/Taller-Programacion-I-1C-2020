
#ifndef PRIMERAENTREGA_COLISIONADOR_H
#define PRIMERAENTREGA_COLISIONADOR_H


#include <vector>
#include "Enemigo.h"
#include "../tools/Constantes.h"

class Colisionador {
public:
    Colisionador();

    static bool hayColision(int *pos1, std::string tipo_1, int *pos2, std::string tipo_2);

    virtual ~Colisionador();

    static void obtenerVertices(int *vertices, const int *pos_inicial, int ancho, int alto);

    static bool hayColisiones(int pos[2], std::string tipo, std::vector<Enemigo *> enemigos);
};


#endif //PRIMERAENTREGA_COLISIONADOR_H
