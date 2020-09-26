#include "CargadorTexturasEnemigos.h"
#include "../tools/Constantes.h"
#include "../tools/SDL_Utils.h"


CargadorTexturasEnemigos::CargadorTexturasEnemigos(SDL_Renderer *renderizador) {
    /// TEXTURAS ENEMIGO 1
    this->texturas_enemigo_1.emplace_back(crearTextura(getRutaImagenEnemigo1(), renderizador));
    this->texturas_enemigo_1.emplace_back(crearTextura(getRutaImagenEnemigo1(), renderizador));
    this->texturas_enemigo_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_ENEMIGO_1_D, renderizador));
    this->texturas_enemigo_1.emplace_back(crearTextura(getRutaImagenEnemigo1(), renderizador));
    this->texturas_enemigo_1.emplace_back(crearTextura(getRutaImagenEnemigo1(), renderizador));
    this->texturas_enemigo_1.emplace_back(crearTextura(getRutaImagenEnemigo1(), renderizador));
    this->texturas_enemigo_1.emplace_back(crearTextura(getRutaImagenEnemigo1(), renderizador));
    this->texturas_enemigo_1.emplace_back(crearTextura(getRutaImagenEnemigo1(), renderizador));

    /// TEXTURAS ENEMIGO 2
    this->texturas_enemigo_2.emplace_back(crearTextura(getRutaImagenEnemigo2(), renderizador));
    this->texturas_enemigo_2.emplace_back(crearTextura(getRutaImagenEnemigo2(), renderizador));
    this->texturas_enemigo_2.emplace_back(crearTextura(getRutaImagenEnemigo2(), renderizador));
    this->texturas_enemigo_2.emplace_back(crearTextura(getRutaImagenEnemigo2(), renderizador));
    this->texturas_enemigo_2.emplace_back(crearTextura(getRutaImagenEnemigo2(), renderizador));
    this->texturas_enemigo_2.emplace_back(crearTextura(getRutaImagenEnemigo2(), renderizador));
    this->texturas_enemigo_2.emplace_back(crearTextura(getRutaImagenEnemigo2(), renderizador));
    this->texturas_enemigo_2.emplace_back(crearTextura(getRutaImagenEnemigo2(), renderizador));

}

std::vector<SDL_Texture *> CargadorTexturasEnemigos::getTexturas(std::string tipo_enemigo) {
    if (tipo_enemigo == getTipoEnemigo1()) {
        return this->texturas_enemigo_1;
    }
    //else { NOMBRE_ENEMIGO_2
    return this->texturas_enemigo_2;
}

CargadorTexturasEnemigos::~CargadorTexturasEnemigos() {
    for (auto &i: this->texturas_enemigo_1) {
        SDL_DestroyTexture(i);
    }

    for (auto &i: this->texturas_enemigo_2) {
        SDL_DestroyTexture(i);
    }
}
