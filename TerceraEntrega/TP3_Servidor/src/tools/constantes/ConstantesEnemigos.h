#ifndef SERVIDOR_CONSTANTESENEMIGOS_H
#define SERVIDOR_CONSTANTESENEMIGOS_H

#include <string>
#include <map>
#include <vector>
#include "ConstantesModelo.h"
#include "ConstantesVentana.h"

#ifndef PI
#define PI 3.14159265
#endif //PI

/// ENEMIGO ///

static constexpr int NRO_ENEMIGO_CLASE_1 = -1;
static constexpr int NRO_ENEMIGO_CLASE_2 = -2;

static constexpr int ENERGIA_ENEM_1 = 100;
static constexpr int ENERGIA_ENEM_2 = 200;

static constexpr int PUNTAJE_MATAR_ENEMIGO_1 = 500;
static constexpr int PUNTAJE_MATAR_ENEMIGO_2 = 1000;

static constexpr int VELOCIDAD_ENEMIGO_1 = 3;
static constexpr int VELOCIDAD_ENEMIGO_2 = 2;

static const std::string TIPO_VALIDO_ENEMIGO_1 = "tipo_enemigo_1";
static const std::string TIPO_VALIDO_ENEMIGO_2 = "tipo_enemigo_2";
static const std::string TIPO_VALIDO_ENEMIGO_DEFAULT = "default";

static constexpr int DIRECCION_ENEMIGO_IZQUIERDA = 0;
static constexpr int DIRECCION_ENEMIGO_DERECHA = 1;

static constexpr int POTENCIA_PROY_ENEM_1 = 15;
static constexpr int POTENCIA_PROY_ENEM_2 = 25;

static constexpr int COOLDOWN_INICIAL_E1=30;
static constexpr int COOLDOWN_INICIAL_E2=120;

static constexpr int CORRECCION_X_1_E=ANCHO_VENTANA + 10;
static constexpr int CORRECCION_X_2_E=ANCHO_VENTANA;
static constexpr int CORRECCION_Y_1_E=175;
static constexpr int CORRECCION_Y_2_E=100;


/*
 * Calculo de la cantidad maxima de enemigos posibles a colocar
 * Se calcula como la superficie del fondo dividido por la superficie del enemigo que mas tamaño ocupa.
 * Este resultado seria el maximo posible, para que quede espacio para el personaje y poder moverse
 * se lo divide por 10.
 */
static const std::string CANTIDAD_ENEMIGO_MAX = std::to_string(
        (ANCHO_FONDO * ALTO_VENTANA / (ANCHO_TIPO_ENEMIGO_REFERENCIA * ANCHO_TIPO_ENEMIGO_REFERENCIA)) / 10);


/*
 * Mapa que contiene los anchos de cada tipo de enemigo valido.
*/
static std::map<std::string, unsigned int> anchos_enemigo = {
        {TIPO_VALIDO_ENEMIGO_1,       ANCHO_TIPO_ENEMIGO_1},
        {TIPO_VALIDO_ENEMIGO_2,       ANCHO_TIPO_ENEMIGO_2},
        {TIPO_VALIDO_ENEMIGO_DEFAULT, ANCHO_TIPO_ENEMIGO_DEFAULT}
};

/*
 * Mapa que contiene los altos de cada tipo de enemigo valido.
*/
static std::map<std::string, unsigned int> altos_enemigos = {
        {TIPO_VALIDO_ENEMIGO_1,       ALTO_TIPO_ENEMIGO_1},
        {TIPO_VALIDO_ENEMIGO_2,       ALTO_TIPO_ENEMIGO_2},
        {TIPO_VALIDO_ENEMIGO_DEFAULT, ALTO_TIPO_ENEMIGO_DEFAULT}
};
/*
 * Mapa que contiene los tamaños de anchos de los tipos de enemigos en la vista .
*/
static std::map<std::string, unsigned int> tam_anchos_enemigos = {
        {TIPO_VALIDO_ENEMIGO_1,       TAM_ANCHO_TIPO_ENEMIGO_1},
        {TIPO_VALIDO_ENEMIGO_2,       TAM_ANCHO_TIPO_ENEMIGO_2},
        {TIPO_VALIDO_ENEMIGO_DEFAULT, TAM_ANCHO_TIPO_ENEMIGO_DEFAULT}
};

/*
 * Mapa que contiene los tamaños de alto de los tipos de enemigos en la vista .
*/
static std::map<std::string, unsigned int> tam_altos_enemigos = {
        {TIPO_VALIDO_ENEMIGO_1,       TAM_ALTO_TIPO_ENEMIGO_1},
        {TIPO_VALIDO_ENEMIGO_2,       TAM_ALTO_TIPO_ENEMIGO_2},
        {TIPO_VALIDO_ENEMIGO_DEFAULT, TAM_ALTO_TIPO_ENEMIGO_DEFAULT}
};

/// ENEMIGOS ///

static constexpr int INVERSION_DIR_EJE_ENEMIGO = -1;

///MOVIMIENTO ENEMIGO TIPO 1///
static std::vector<Posicion> MOVIMIENTO_ENEMIGO1_ABA_IZQ = { POS_ABAJO,POS_IZQUIERDA};
static std::vector<Posicion> MOVIMIENTO_ENEMIGO1_ABA_DER = { POS_ABAJO,POS_DERECHA};
static std::vector<Posicion> MOVIMIENTO_ENEMIGO1_ARR_IZQ = { POS_ARRIBA,POS_IZQUIERDA};

static std::vector<Posicion> MOVIMIENTO_ENEMIGO1_ARR_DER = { POS_ARRIBA,POS_DERECHA};

static constexpr int VALOR_CONTADOR_MOV_ENEMIGO_TIPO_1_ALINEANDOSE = 30;
static constexpr int VALOR_CONTADOR_MOV_ENEMIGO_TIPO_1_QUIETO = 30;
static constexpr int VALOR_CONTADOR_MOV_ENEMIGO_TIPO_1_ARRANQUE = 80;

static constexpr int VALOR_CONTADOR_MOV_ENEMIGO_TIPO_1_TERMINA = 180;
static constexpr int POS_MOV_EJE_Y_ENEMIGO_1 = 0;
static constexpr int POS_MOV_EJE_X_ENEMIGO_1 = 1;

static constexpr int POS_INVALIDA_MOV_ENEMIGO_1 = 2;

///MOVIMIENTO ENEMIGO TIPO 2///
static constexpr int LIMITE_POS_X_VENTANA_ENEMIGO_2 = 50;
static constexpr int INCREMENTO_DEZPLAZAMIENTO_EJE_Y_ENEMIGO_2 = 6;


///JEFES///

static constexpr int NRO_ENEMIGO_JEFE = -3;

static constexpr int ENERGIA_JEFE = 1000;
static constexpr int PUNTOS_AL_MORIR_JEFE = 2000;


static const std::string TIPO_JEFE_1 = "Jefe_1";
static constexpr int ANCHO_JEFE_1 = 364;
static constexpr int ALTO_JEFE_1 = 283;

static constexpr int POS_X_JEFE_1 = ANCHO_FONDO;
static constexpr int POS_Y_JEFE_1 = (ALTO_VENTANA - ALTO_JEFE_1) / 2;

static constexpr int VELOCIDAD_JEFE_1 = 2;

static constexpr int CORRECCION_X_JEFE_1 = 30;
static constexpr int POTENCIA_PROY_JEFE_1 = 30;

static std::vector<std::string> tipos_enemigos = { TIPO_VALIDO_ENEMIGO_1,
                                                   TIPO_VALIDO_ENEMIGO_2,
                                                   TIPO_JEFE_1,
                                                   TIPO_VALIDO_ENEMIGO_DEFAULT};

static constexpr int TIEMPO_COOLDOWN_DISPAROS_JEFE_1 = 10;

static std::vector<std::string> TIPOS_JEFES = { TIPO_JEFE_1};

static constexpr int CONT_DISPAROS_CERO = 0;
static constexpr int CONT_DISPAROS_UNO = 1;
static constexpr int CONT_DISPAROS_DOS = 2;
static constexpr int CONT_DISPAROS_TRES = 3;
static constexpr int CONT_DISPAROS_CUATRO = 4;
static constexpr int CONT_DISPAROS_CINCO = 5;
static constexpr int CONT_DISPAROS_SEIS = 6;
static constexpr int CONT_DISPAROS_SIETE = 7;
static constexpr int CONT_DISPAROS_OCHO = 8;

static constexpr int MIN_VALOR_COOLDOWN = 1;
static constexpr int CORRECCION_Y_DISPARO=60;

static constexpr double ANGULO_1_J3=(5.0 * PI) / 6.0;
static constexpr double ANGULO_2_J3=(23.0 * PI) / 24.0;
static constexpr double ANGULO_3_J3=(25.0 * PI) / 24.0;
static constexpr double ANGULO_4_J3=(7.0 * PI) / 6.0;

static constexpr int INCREMENTO_COOLDOWN_J3_1=3;
static constexpr int INCREMENTO_COOLDOWN_J3_2=6;
static constexpr int INCREMENTO_COOLDOWN_J3_3=10;

///MOVIMIENTO JEFE 1///

static constexpr int VALOR_LIMITE_Y_ARRIBA = 100; //No representan un posicion, pero ayudan a que el jefe
static constexpr int VALOR_LIMITE_Y_ABAJO = 140; // se quede en ventana y no se vaya por el eje y.

static constexpr int DIR_ADELANTE_EN_EJE = 1;
static constexpr int DIR_ATRAS_EJE_Y = -1;
static constexpr int DIR_FRENAR_EJE_Y = 0;

static constexpr int TOPE_HORIZONTAL_JEFE_1 = 50;

#endif //SERVIDOR_CONSTANTESENEMIGOS_H
