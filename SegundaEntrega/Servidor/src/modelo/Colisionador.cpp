#include "Colisionador.h"

Colisionador::Colisionador() {}

bool Colisionador::hayColisiones(int *nueva_posicion, std::string tipo_actual, std::vector<Enemigo *> enemigos) {
    bool existeColision = false;
    if (enemigos.empty()) {
        return existeColision;
    }
    unsigned long cantidad_posiciones = enemigos.size();
    for (unsigned long i = 0; i < cantidad_posiciones; ++i) {
        int pos_enemigo[2] = {(int) enemigos[i]->getPosX(), (int) enemigos[i]->getPosY()};
        existeColision =
                existeColision || hayColision(nueva_posicion, tipo_actual, pos_enemigo, enemigos[i]->getTipo());
    }
    return existeColision;

}

bool Colisionador::hayColision(int *pos1, std::string tipo_1, int *pos2, std::string tipo_2) {

    int vertices_1[4];
    int vertices_2[4];
    if (getTipoEnemigo1() == tipo_1) {
        obtenerVertices(vertices_1, pos1, getTamAnchoEnemigo1(), getTamAltoEnemigo1());
    } else {
        obtenerVertices(vertices_1, pos1, getTamAnchoEnemigo2(), getTamAltoEnemigo2());
    }
    if (getTipoEnemigo1() == tipo_2) {
        obtenerVertices(vertices_2, pos2, getTamAnchoEnemigo1(), getTamAltoEnemigo1());
    } else {
        obtenerVertices(vertices_2, pos2, getTamAnchoEnemigo2(), getTamAltoEnemigo2());
    }

    bool colision_en_x = vertices_1[0] < vertices_2[1] && vertices_1[1] > vertices_2[0];
    bool colision_en_y = vertices_1[2] < vertices_2[3] && vertices_1[3] > vertices_2[2];

    return colision_en_x && colision_en_y;
}

void Colisionador::obtenerVertices(int *vertices, const int *pos_inicial, int ancho, int alto) {
    vertices[0] = pos_inicial[0];
    vertices[1] = pos_inicial[0] + ancho;
    vertices[2] = pos_inicial[1];
    vertices[3] = pos_inicial[1] + alto;
}


Colisionador::~Colisionador() {

}
