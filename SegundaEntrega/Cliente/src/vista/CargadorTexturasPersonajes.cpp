#include "CargadorTexturasPersonajes.h"
#include "../tools/Constantes.h"
#include "../tools/SDL_Utils.h"

CargadorTexturasPersonajes::CargadorTexturasPersonajes(SDL_Renderer* renderizador){
    /// TEXTURAS PERSONAJE 1
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_ARRIBA, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_ARRIBA_DERECHA, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_DERECHA, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_ABAJO_DERECHA, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_ABAJO, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_ABAJO_IZQUIERDA, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_IZQUIERDA, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_ARRIBA_IZQUIERDA, renderizador));

    /// TEXTURAS PERSONAJE 2
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_ARRIBA, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_ARRIBA_DERECHA, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_DERECHA, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_ABAJO_DERECHA, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_ABAJO, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_ABAJO_IZQUIERDA, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_IZQUIERDA, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_ARRIBA_IZQUIERDA, renderizador));

    /// TEXTURAS PERSONAJE 3
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_ARRIBA, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_ARRIBA_DERECHA, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_DERECHA, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_ABAJO_DERECHA, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_ABAJO, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_ABAJO_IZQUIERDA, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_IZQUIERDA, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_ARRIBA_IZQUIERDA, renderizador));

    /// TEXTURAS PERSONAJE 4
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_ARRIBA, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_ARRIBA_DERECHA, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_DERECHA, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_ABAJO_DERECHA, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_ABAJO, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_ABAJO_IZQUIERDA, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_IZQUIERDA, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_ARRIBA_IZQUIERDA, renderizador));

    /// TEXTURAS PERSONAJE DESCONECTADO
    this->texturas_personaje_desconectado.emplace_back(crearTextura(RUTA_PERSONAJE_DESCONECTADO, renderizador));
    this->texturas_personaje_desconectado.emplace_back(crearTextura(RUTA_PERSONAJE_DESCONECTADO, renderizador));
    this->texturas_personaje_desconectado.emplace_back(crearTextura(RUTA_PERSONAJE_DESCONECTADO, renderizador));
    this->texturas_personaje_desconectado.emplace_back(crearTextura(RUTA_PERSONAJE_DESCONECTADO, renderizador));
    this->texturas_personaje_desconectado.emplace_back(crearTextura(RUTA_PERSONAJE_DESCONECTADO, renderizador));
    this->texturas_personaje_desconectado.emplace_back(crearTextura(RUTA_PERSONAJE_DESCONECTADO, renderizador));
    this->texturas_personaje_desconectado.emplace_back(crearTextura(RUTA_PERSONAJE_DESCONECTADO, renderizador));
    this->texturas_personaje_desconectado.emplace_back(crearTextura(RUTA_PERSONAJE_DESCONECTADO, renderizador));

}

std::vector<SDL_Texture*> CargadorTexturasPersonajes::getTexturas(int n_personaje){
    if (n_personaje == 0) {
        return this->texturas_personaje_1;

    } else if (n_personaje == 1) {
        return this->texturas_personaje_2;

    } else if (n_personaje == 2) {
        return this->texturas_personaje_3;

    } else if (n_personaje == 3){
        return this->texturas_personaje_4;
    } else{
        return  this->texturas_personaje_desconectado;
    }
}

CargadorTexturasPersonajes::~CargadorTexturasPersonajes(){
    for (auto &i: this->texturas_personaje_1) {
        SDL_DestroyTexture(i);
    }
    for (auto &i: this->texturas_personaje_2) {
        SDL_DestroyTexture(i);
    }
    for (auto &i: this->texturas_personaje_3) {
        SDL_DestroyTexture(i);
    }
    for (auto &i: this->texturas_personaje_4) {
        SDL_DestroyTexture(i);
    }

}