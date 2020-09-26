#include "CargadorTexturasEnemigos.h"
#include "../tools/Constantes.h"
#include "../tools/SDL_Utils.h"


CargadorTexturasEnemigos::CargadorTexturasEnemigos(SDL_Renderer *renderizador) {
    /// TEXTURAS ENEMIGO 1
    this->texturas_enemigo_1.emplace_back(crearTextura(getRutaImagenEnemigo1(), renderizador));
    this->texturas_enemigo_1.emplace_back(crearTextura(getRutaImagenEnemigo1(), renderizador));
    this->texturas_enemigo_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_ENEMIGO_1_DERECHA, renderizador));
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

    /// TEXTURAS ENEMIGO DEFAULT
    this->texturas_enemigo_default.emplace_back(crearTextura(RUTA_IMG_DEFECTO, renderizador));
    this->texturas_enemigo_default.emplace_back(crearTextura(RUTA_IMG_DEFECTO, renderizador));
    this->texturas_enemigo_default.emplace_back(crearTextura(RUTA_IMG_DEFECTO, renderizador));
    this->texturas_enemigo_default.emplace_back(crearTextura(RUTA_IMG_DEFECTO, renderizador));
    this->texturas_enemigo_default.emplace_back(crearTextura(RUTA_IMG_DEFECTO, renderizador));
    this->texturas_enemigo_default.emplace_back(crearTextura(RUTA_IMG_DEFECTO, renderizador));
    this->texturas_enemigo_default.emplace_back(crearTextura(RUTA_IMG_DEFECTO, renderizador));
    this->texturas_enemigo_default.emplace_back(crearTextura(RUTA_IMG_DEFECTO, renderizador));
    
}

std::vector<SDL_Texture *> CargadorTexturasEnemigos::getTexturas(std::string tipo_enemigo) {
    if (tipo_enemigo == getTipoEnemigo1()) {
        return this->texturas_enemigo_1;
    }
    else if (tipo_enemigo == getTipoEnemigo2()){
        return this->texturas_enemigo_2;
    }

    return this->texturas_enemigo_default;

}

CargadorTexturasEnemigos::~CargadorTexturasEnemigos() {
    for (auto &i: this->texturas_enemigo_1) {
        SDL_DestroyTexture(i);
    }

    for (auto &i: this->texturas_enemigo_2) {
        SDL_DestroyTexture(i);
    }
}
