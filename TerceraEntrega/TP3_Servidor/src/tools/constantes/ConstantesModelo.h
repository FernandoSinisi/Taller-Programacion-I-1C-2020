#ifndef SERVIDOR_CONSTANTESMODELO_H
#define SERVIDOR_CONSTANTESMODELO_H

#include "ConstantesGenerales.h" //Aca esta guardada la constante de escala fondo
#include "ConstantesVentana.h"
#include "../../modelo/juego/Posicion.h"

/// MODELO ///

static constexpr int NRO_NIVEL_INICIAL=1;
static constexpr int NRO_NIVEL_FINAL=3;


// 32 segundos de tiemout puro +
// + 3 ????
// 7 game over
// 2 cerrar clientes

static constexpr int TIMEOUT_PARA_GAMEOVER_DESCONECTADOS = 30000; // 30 segundos

static constexpr unsigned int MILISEG_TIMEOUT_EVENTOS = 16; /* 0,016 segundos */
static constexpr unsigned int ANCHO_PERSONAJE = 90;
static constexpr unsigned int ALTO_PERSONAJE = 50;
static constexpr unsigned int TAM_ANCHO_PERSONAJE = ANCHO_PERSONAJE;
static constexpr unsigned int TAM_ALTO_PERSONAJE = ALTO_PERSONAJE;

static constexpr unsigned int ANCHO_TIPO_ENEMIGO_1 = 84;
static constexpr unsigned int ALTO_TIPO_ENEMIGO_1 = 42;
static constexpr unsigned int TAM_ANCHO_TIPO_ENEMIGO_1 = ANCHO_TIPO_ENEMIGO_1;
static constexpr unsigned int TAM_ALTO_TIPO_ENEMIGO_1 = ALTO_TIPO_ENEMIGO_1;
static constexpr unsigned int ANCHO_TIPO_ENEMIGO_2 = 120;
static constexpr unsigned int ALTO_TIPO_ENEMIGO_2 = 110;
static constexpr unsigned int TAM_ANCHO_TIPO_ENEMIGO_2 = ANCHO_TIPO_ENEMIGO_2 / 2;
static constexpr unsigned int TAM_ALTO_TIPO_ENEMIGO_2 = ALTO_TIPO_ENEMIGO_2 / 2;
static constexpr unsigned int ANCHO_TIPO_ENEMIGO_REFERENCIA = 64;

static constexpr unsigned int TAM_ALTO_TIPO_ENEMIGO_DEFAULT = 50;
static constexpr unsigned int TAM_ANCHO_TIPO_ENEMIGO_DEFAULT = 40;
static constexpr unsigned int ALTO_TIPO_ENEMIGO_DEFAULT = 50;
static constexpr unsigned int ANCHO_TIPO_ENEMIGO_DEFAULT = 40;

static constexpr unsigned int ANCHO_PROYECTIL = 92;
static constexpr unsigned int ALTO_PROYECTIL = 29;
static constexpr unsigned int TAM_ANCHO_PROYECTIL = ANCHO_PROYECTIL;
static constexpr unsigned int TAM_ALTO_PROYECTIL = ALTO_PROYECTIL;

static constexpr int ANCHO_ALTO_PROYECTIL_ENEMIGO = 25;

static constexpr int POTENCIA_PROY_PERSONAJE = 50;

///DESPLAZAMIENTO FONDO///
//TODO ENTREGA: Poner desplazamiento_fondo en 0.23f
static constexpr float DESPLAZAMIENTO_FONDO = 0.23f * ESCALA_FONDO;     /// <- ENTREGA
//static constexpr float DESPLAZAMIENTO_FONDO = 1.5f * ESCALA_FONDO;    /// <- DEBUG

static constexpr float PROPORCION_ALEJAMIENTO_JEFES = 0.7f;

/// POSICIONES
static const Posicion POS_ARRIBA_IZQ = Posicion(-0.707, -0.707);
static const Posicion POS_ARRIBA_DER = Posicion(0.707, -0.707);
static const Posicion POS_ABAJO_IZQ = Posicion(-0.707, 0.707);
static const Posicion POS_ABAJO_DER = Posicion(0.707, 0.707);
static const Posicion POS_ARRIBA = Posicion(0,-1);
static const Posicion POS_IZQUIERDA = Posicion(-1,0);
static const Posicion POS_ABAJO = Posicion(0, 1);
static const Posicion POS_DERECHA = Posicion(1, 0);
static const Posicion POS_NINGUNA = Posicion(0, 0);
static const Posicion POS_DERECHA_FONDO = Posicion(DESPLAZAMIENTO_FONDO, 0);

#endif //SERVIDOR_CONSTANTESMODELO_H
