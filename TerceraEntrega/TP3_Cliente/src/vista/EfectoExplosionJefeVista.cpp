#include "EfectoExplosionJefeVista.h"

EfectoExplosionJefeVista::EfectoExplosionJefeVista(int x, int y, CargadorTexturasEfectos* cargador) {

    this->tiempo_de_vida=0;
    this->rectangulo_explosion = new SDL_Rect;

    initRect(this->rectangulo_explosion,x-CORRECCIONES_JEFES[0],
             y-CORRECCIONES_JEFES[1],
             EXPLOSIONES_JEFES[0],
            EXPLOSIONES_JEFES[1]);

    this->texturas_explosiones=cargador->getTexturaExplosionJefe();

}

/*
EfectoExplosionJefeVista::~EfectoExplosionJefeVista() {
    delete(this->rectangulo_explosion);
}
*/