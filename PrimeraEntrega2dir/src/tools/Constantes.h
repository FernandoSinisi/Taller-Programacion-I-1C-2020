#ifndef PRIMERAENTREGA_CONSTANTES_H
#define PRIMERAENTREGA_CONSTANTES_H

#include <iostream>
#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <string>
#include <SDL2/SDL_ttf.h>
#include "../model/Posicion.h"


/// GENERALES ///
static const double EPSILON_DOUBLE = 0.005;


/// JSON ///
static std::string RUTA_CONFIG_DEFAULT = "../data/config_default.json";

void setRutaConfig(std::string ruta);
char *getRutaConfig();


/// CLIENTE * ///
static constexpr unsigned int MILISEG_TIMEOUT_EVENTOS = 16; /* 0,016 segundos */
static constexpr unsigned int ANCHO_PERSONAJE = 90;
static constexpr unsigned int ALTO_PERSONAJE = 50;

static constexpr unsigned int ANCHO_TIPO_ENEMIGO_1 = 84;
static constexpr unsigned int ALTO_TIPO_ENEMIGO_1 = 42;
static constexpr unsigned int TAM_ANCHO_TIPO_ENEMIGO_1 = ANCHO_TIPO_ENEMIGO_1;
static constexpr unsigned int TAM_ALTO_TIPO_ENEMIGO_1 = ALTO_TIPO_ENEMIGO_1;
static constexpr unsigned int ANCHO_TIPO_ENEMIGO_2 = 120;
static constexpr unsigned int ALTO_TIPO_ENEMIGO_2 = 110;
static constexpr unsigned int TAM_ANCHO_TIPO_ENEMIGO_2 = ANCHO_TIPO_ENEMIGO_2 / 2;
static constexpr unsigned int TAM_ALTO_TIPO_ENEMIGO_2 = ALTO_TIPO_ENEMIGO_2 / 2;
static constexpr unsigned int ANCHO_TIPO_ENEMIGO_3 = 65;
static constexpr unsigned int ALTO_TIPO_ENEMIGO_3 = 61;
static constexpr unsigned int TAM_ANCHO_TIPO_ENEMIGO_3 = ANCHO_TIPO_ENEMIGO_3;
static constexpr unsigned int TAM_ALTO_TIPO_ENEMIGO_3 = ALTO_TIPO_ENEMIGO_3;
static constexpr unsigned int ANCHO_TIPO_ENEMIGO_4 = 64;
static constexpr unsigned int ALTO_TIPO_ENEMIGO_4 = 73;
static constexpr unsigned int TAM_ANCHO_TIPO_ENEMIGO_4 = ANCHO_TIPO_ENEMIGO_4;
static constexpr unsigned int TAM_ALTO_TIPO_ENEMIGO_4 = ALTO_TIPO_ENEMIGO_4;

static constexpr unsigned int TAM_ALTO_TIPO_ENEMIGO_DEFAULT = 50;
static constexpr unsigned int TAM_ANCHO_TIPO_ENEMIGO_DEFAULT = 40;
static constexpr unsigned int ALTO_TIPO_ENEMIGO_DEFAULT = 50;
static constexpr unsigned int ANCHO_TIPO_ENEMIGO_DEFAULT = 40;

static constexpr float DESPLAZAMIENTO_FONDO = 0.5f;
static const float VELOCIDAD_CAPA_5 = 1.0f;
static const float VELOCIDAD_CAPA_4 = 1.5f;
static const float VELOCIDAD_CAPA_3 = 2.5f;
static const float VELOCIDAD_CAPA_2 = 3.75f;
static const float VELOCIDAD_CAPA_1 = 7.0f;


/// VENTANA *///
static constexpr char *RUTA_IMG_DEFECTO = (char *) ("../data/imgs/default.png");
static constexpr char *RUTA_ICONO = (char *) ("../data/imgs/icono.png");
static constexpr char *RUTA_FONDO_1_INICIO = (char *) ("../data/imgs/fondo_1.png");
static constexpr char *RUTA_FONDO_1_FIN = (char *) ("../data/imgs/fondo_fin_1.png");
static constexpr char *RUTA_FONDO_2_INICIO = (char *) ("../data/imgs/fondo_2.png");
static constexpr char *RUTA_FONDO_2_FIN = (char *) ("../data/imgs/fondo_fin_2.png");
static constexpr char *RUTA_PERSONAJE_ARRIBA = (char *) ("../data/imgs/personaje/p1.png");
static constexpr char *RUTA_PERSONAJE_ARRIBA_DERECHA = (char *) ("../data/imgs/personaje/p2.png");
static constexpr char *RUTA_PERSONAJE_DERECHA = (char *) ("../data/imgs/personaje/p3.png");
static constexpr char *RUTA_PERSONAJE_ABAJO_DERECHA = (char *) ("../data/imgs/personaje/p4.png");
static constexpr char *RUTA_PERSONAJE_ABAJO = (char *) ("../data/imgs/personaje/p5.png");
static constexpr char *RUTA_PERSONAJE_ABAJO_IZQUIERDA = (char *) ("../data/imgs/personaje/p6.png");
static constexpr char *RUTA_PERSONAJE_IZQUIERDA = (char *) ("../data/imgs/personaje/p7.png");
static constexpr char *RUTA_PERSONAJE_ARRIBA_IZQUIERDA = (char *) ("../data/imgs/personaje/p8.png");
static constexpr char *RUTA_IMAGEN_TIPO_ENEMIGO_1 = (char *) ("../data/imgs/enemigo_1.png");
static constexpr char *RUTA_IMAGEN_TIPO_ENEMIGO_1_D = (char *) ("../data/imgs/enemigo_1d.png");
static constexpr char *RUTA_IMAGEN_TIPO_ENEMIGO_2 = (char *) ("../data/imgs/enemigo_2.png");

static constexpr char *NOMBRE_JUEGO = (char *) "Gley Lancer";
static constexpr int X_VENTANA = 500;
static constexpr int Y_VENTANA = 200;
static constexpr int ANCHO_VENTANA = 800;
static constexpr int ALTO_VENTANA = 600;
static constexpr int ANCHO_FONDO = 16000;
static constexpr int ANCHO_CAPA = 3200;
static constexpr int STATE_VENTANA = SDL_WINDOW_SHOWN;
static constexpr int CANTIDAD_NIVELES = 2;
static constexpr int TIEMPO_FIN_NIVEL = 120; // 2 SEGUNDOS --> 2 * 60 fps

static const std::string PRE_POSICION_VENTANA = "Pos_Ventana";
static const std::string PRE_NIVEL_FINALIZADO = "Nivel_finalizado";


/// PERSONAJE ///
static constexpr int X_PERSONAJE = 0;
static constexpr int Y_PERSONAJE = (ALTO_VENTANA - ALTO_PERSONAJE) / 2;
static constexpr int INCREMENTO_PERSONAJE = 6;
static const std::string PRE_POSICION_JUGADOR = "Pos_Jugador";
static const std::string SEPARADOR = " ";
static constexpr int DIRECCION_PERSONAJE_ARRIBA = 0;
static constexpr int DIRECCION_PERSONAJE_ARRIBA_DERECHA = 1;
static constexpr int DIRECCION_PERSONAJE_DERECHA = 2;
static constexpr int DIRECCION_PERSONAJE_ABAJO_DERECHA = 3;
static constexpr int DIRECCION_PERSONAJE_ABAJO = 4;
static constexpr int DIRECCION_PERSONAJE_ABAJO_IZQUIERDA = 5;
static constexpr int DIRECCION_PERSONAJE_IZQUIERDA = 6;
static constexpr int DIRECCION_PERSONAJE_ARRIBA_IZQUIERDA = 7;
static constexpr int TECLA_ARRIBA = 1;
static constexpr int TECLA_IZQUIERDA = 2;
static constexpr int TECLA_ABAJO = 3;
static constexpr int TECLA_DERECHA = 4;
static constexpr int TECLAS_ARRIBA_IZQUIERDA = 5;
static constexpr int TECLAS_ARRIBA_DERECHA = 6;
static constexpr int TECLAS_ABAJO_IZQUIERDA = 7;
static constexpr int TECLAS_ABAJO_DERECHA = 8;
static constexpr int TECLA_NINGUNA = 10;

static const Posicion POS_ARRIBA_IZQ = Posicion(-0.707, -0.707);
static const Posicion POS_ARRIBA_DER = Posicion(0.707, -0.707);
static const Posicion POS_ABJAJO_IZQ = Posicion(-0.707, 0.707);
static const Posicion POS_ABAJO_DER = Posicion(0.707, 0.707);
static const Posicion POS_ARRIBA = Posicion(0, -1);
static const Posicion POS_IZQUIERDA = Posicion(-1, 0);
static const Posicion POS_ABAJO = Posicion(0, 1);
static const Posicion POS_DERECHA = Posicion(1, 0);
static const Posicion POS_NINGUNA = Posicion(0, 0);
static const Posicion POS_DERECHA_FONDO = Posicion(DESPLAZAMIENTO_FONDO, 0);

/// ENEMIGO ///
static const std::string PRE_POSICION_ENEMIGO = "Pos_Enemigo";
static const std::string TIPO_VALIDO_ENEMIGO_1 = "tipo_enemigo_1";
static const std::string TIPO_VALIDO_ENEMIGO_2 = "tipo_enemigo_2";
static const std::string TIPO_VALIDO_ENEMIGO_DEFAULT = "default";
static constexpr int DIRECCION_ENEMIGO_ARRIBA = 0;
static constexpr int DIRECCION_ENEMIGO_ARRIBA_DERECHA = 1;
static constexpr int DIRECCION_ENEMIGO_DERECHA = 2;
static constexpr int DIRECCION_ENEMIGO_ABAJO_DERECHA = 3;
static constexpr int DIRECCION_ENEMIGO_ABAJO = 4;
static constexpr int DIRECCION_ENEMIGO_ABAJO_IZQUIERDA = 5;
static constexpr int DIRECCION_ENEMIGO_IZQUIERDA = 6;
static constexpr int DIRECCION_ENEMIGO_ARRIBA_IZQUIERDA = 7;

/*
 * Calculo de la cantidad maxima de enemigos posibles a colocar
 * Se calcula como la superficie del fondo dividido por la superficie del enemigo que mas tamaño ocupa.
 * Este resultado seria el maximo posible, para que quede espacio para el personaje y poder moverse
 * se lo divide por 10.
 */
static const std::string CANTIDAD_ENEMIGO_MAX = std::to_string(
        (ANCHO_FONDO * ALTO_VENTANA / (ANCHO_TIPO_ENEMIGO_4 * ANCHO_TIPO_ENEMIGO_4)) / 10);

/*
 * Mapa que contiene la imagen de cada tipo de enemigo valido.
*/
static std::map<std::string, char *> tipos_enemigos_imagen = {
        {TIPO_VALIDO_ENEMIGO_1,       RUTA_IMAGEN_TIPO_ENEMIGO_1},
        {TIPO_VALIDO_ENEMIGO_2,       RUTA_IMAGEN_TIPO_ENEMIGO_2},
        {TIPO_VALIDO_ENEMIGO_DEFAULT, RUTA_IMG_DEFECTO}
};

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

/// LOGGING ///
static std::string RUTA_LOG = "../data/logs/log_";
static std::string RUTA_LOG_AUX = "log_";

static constexpr char *FLAG_LOG = (char *) "-l";
static constexpr char *FLAG_RUTA_CONFIG = (char *) "-c";

static constexpr int ARGC_MAX_CANTIDAD_PARAMETROS = 5;
static constexpr int ARGC_MIN_CANTIDAD_PARAMETROS = 3;

static std::string EXTENSION_LOG = ".log";
static constexpr int LOG_ERROR = 1;
static constexpr char *MSJ_LOG_ERROR = (char *) "ERROR";
static constexpr int LOG_INFO = 2;
static constexpr char *MSJ_LOG_INFO = (char *) "INFO";
static constexpr int LOG_DEBUG = 3;
static constexpr char *MSJ_LOG_DEBUG = (char *) "DEBUG";

static constexpr char *LOG_COMANDO_CONSOLA = (char *) "Utilizando el modo de logueo provisto por consola.";
static constexpr char *ERROR_FALLA_DE_CARGA_JSON_DEFAULT = (char *) "No se ha podido cargar el archivo de configuracion default";
static constexpr char *ERROR_SETEO_LOG = (char *) "Modo de log incorrecto en archivo por defecto. Seteado en DEBUG.";
static constexpr char *ERROR_LOG = (char *) "No se pudo crear el archivo de log en la ruta esperada. Logueando en ruta local.";
static constexpr char *ERROR_IMG_FALTANTE = (char *) "Imagen faltante: ";
static constexpr char *ERROR_PARAMETRO_POR_CONSOLA_INVALIDO = (char *) "El modo de log ingresado por consola no es valido";
static constexpr char *ERROR_FONDO_11_FALTANTE = (char *) "No se encontro ruta de capa 1 de fondo 1 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_11_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 1 de fondo 1 en config default";
static constexpr char *ERROR_FONDO_12_FALTANTE = (char *) "No se encontro ruta de capa 2 de fondo 1 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_12_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 2 de fondo 1 en config default.";
static constexpr char *ERROR_FONDO_13_FALTANTE = (char *) "No se encontro ruta de capa 3 de fondo 1 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_13_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 3 de fondo 1 en config default.";

static constexpr char *ERROR_FONDO_14_FALTANTE = (char *) "No se encontro ruta de capa 4 de fondo 1 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_14_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 4 de fondo 1 en config default.";

static constexpr char *ERROR_FONDO_15_FALTANTE = (char *) "No se encontro ruta de capa 5 de fondo 1 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_15_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 5 de fondo 1 en config default.";

static constexpr char *ERROR_FONDO_16_FALTANTE = (char *) "No se encontro ruta de capa 6 de fondo 1 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_16_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 6 de fondo 1 en config default.";

static constexpr char *ERROR_FONDO_21_FALTANTE = (char *) "No se encontro ruta de capa 1 de fondo 2 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_21_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 1 de fondo 2 en config default. ";
static constexpr char *ERROR_FONDO_22_FALTANTE = (char *) "No se encontro ruta de capa 2 de fondo 2 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_22_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 2 de fondo 2 en config default. ";
static constexpr char *ERROR_FONDO_23_FALTANTE = (char *) "No se encontro ruta de capa 3 de fondo 2 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_23_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 3 de fondo 2 en config default. ";

static constexpr char *ERROR_FONDO_24_FALTANTE = (char *) "No se encontro ruta de capa 4 de fondo 2 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_24_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 4 de fondo 2 en config default. ";

static constexpr char *ERROR_FONDO_25_FALTANTE = (char *) "No se encontro ruta de capa 5 de fondo 2 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_25_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 5 de fondo 2 en config default. ";

static constexpr char *ERROR_FONDO_26_FALTANTE = (char *) "No se encontro ruta de capa 6 de fondo 2 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_26_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 6 de fondo 2 en config default. ";

static constexpr char *ERROR_FORMATO_JSON = (char *) "Se encontró un error en el json. Línea: ";
static constexpr char *ERROR_FORMATO_JSON_2 = (char *) ". Se usará configuración por defecto.";
static constexpr char *LOG_ERROR_SUPERADA_CANTIDAD_MAXIMA_ENEMIGOS_1 = (char *) "Se ha superado la cantidad maxima de enemigos posibles en el nivel 1, se realizara una correccion";
static constexpr char *LOG_ERROR_SUPERADA_CANTIDAD_MAXIMA_ENEMIGOS_2 = (char *) "Se ha superado la cantidad maxima de enemigos posibles en el nivel 2, se realizara una correccion";
static constexpr char *LOG_ERROR_NUMERO_ENEMIGOS_1_1_INVALIDO = (char *) "La cantidad de enemigos tipo 1 en el nivel 1 ingresada en el json es invalida";
static constexpr char *LOG_ERROR_NUMERO_ENEMIGOS_1_2_INVALIDO = (char *) "La cantidad de enemigos tipo 1 en el nivel 2 ingresada en el json es invalida";
static constexpr char *LOG_ERROR_NUMERO_ENEMIGOS_1_1_INVALIDO_DEFAULT = (char *) "La cantidad de enemigos tipo 1 en el nivel 1 en la configuracion default es invalida";
static constexpr char *LOG_ERROR_NUMERO_ENEMIGOS_1_2_INVALIDO_DEFAULT = (char *) "La cantidad de enemigos tipo 1 en el nivel 2 en la configuracion default es invalida";
static constexpr char *LOG_ERROR_NUMERO_ENEMIGOS_2_1_INVALIDO = (char *) "La cantidad de enemigos tipo 2 en el nivel 1 ingresada en el json es invalida";
static constexpr char *LOG_ERROR_NUMERO_ENEMIGOS_2_2_INVALIDO = (char *) "La cantidad de enemigos tipo 2 en el nivel 2 ingresada en el json es invalida";
static constexpr char *LOG_ERROR_NUMERO_ENEMIGOS_2_1_INVALIDO_DEFAULT = (char *) "La cantidad de enemigos tipo 2 en el nivel 1 en la configuracion default es invalida";
static constexpr char *LOG_ERROR_NUMERO_ENEMIGOS_2_2_INVALIDO_DEFAULT = (char *) "La cantidad de enemigos tipo 2 en el nivel 2 en la configuracion default es invalida";
static constexpr char *LOG_ERROR_MODO_LOG_LOCAL = (char*) "Modo de logueo ingresado en archivo de configuracion incorrecto, se leera el modo por defecto.";
static constexpr char *LOG_ERROR_SIN_DEFAULT = (char*) "No existe archivo json por defecto.";
static constexpr char *ERROR_FORMATO_JSON_DEFAULT = (char*) ". No se cargará información a partir de este error. ";

static constexpr char *LOG_ERROR_TIPO_ENEMIGO_1_INVALIDO = (char *) "El tipo de enemigo 1 ingresado en el json es invalido, tomaremos el valor por default.";
static constexpr char *LOG_ERROR_TIPO_ENEMIGO_2_INVALIDO = (char *) "El tipo de enemigo 2 ingresado en el json es invalido, tomaremos el valor por default.";
static constexpr char *LOG_ERROR_TIPO_ENEMIGO_1_INVALIDO_DEFAULT = (char *)  "El tipo de enemigo 1 en la configuracion default es invalido";
static constexpr char *LOG_ERROR_TIPO_ENEMIGO_2_INVALIDO_DEFAULT = (char *)  "El tipo de enemigo 2 en la configuracion default es invalido";

static constexpr char *LOG_NO_LOC_JSON = (char *) "No se encontró json local. Leyendo archivo por defecto.";
static constexpr char *LOG_LOC_JSON_DEFAULT = (char *) "Leyendo archivo json por defecto.";
static constexpr char *LOG_CONFIG_PARAMETROS = (char *) "Se usa el archivo de configuracion pasado por consola.";
static constexpr char *LOG_CONFIG_SIN_PARAMETROS = (char *) "No se pasó un archivo json de configuracion por parámetro.";
static constexpr char *LOG_MODO_DEFAULT_CORRECTO = (char *) "Se leyó correctamente el modo del archivo por defecto.";

static constexpr char *LOG_JUEGO_INICIADO = (char *) "Juego iniciado.";
static constexpr char *LOG_JUEGO_FINALIZADO = (char *) "Juego finalizado.";
static constexpr char *LOG_FIN_JUEGO_CORRECTO = (char *) "Se ha alcanzado el final del último nivel correctamente.";
static constexpr char *LOG_JUEGO_CERRADO_POR_USER = (char *) "Juego cerrado.";
static constexpr char *LOG_NUEVO_NIVEL = (char *) "Nuevo nivel iniciado. Número: ";
static constexpr char *LOG_NIVEL_FINALIZADO = (char *) "Nivel finalizado.";
static constexpr char *LOG_MOV_SUP_IZQ = (char *) "La nave se mueve en diagonal al margen superior izquierdo.";
static constexpr char *LOG_MOV_SUP_DER = (char *) "La nave se mueve en diagonal al margen superior derecho.";
static constexpr char *LOG_MOV_ABA_IZQ = (char *) "La nave se mueve en diagonal al margen inferior izquierdo.";
static constexpr char *LOG_MOV_ABA_DER = (char *) "La nave se mueve en diagonal al margen inferior derecho.";
static constexpr char *LOG_MOV_ARRIBA = (char *) "La nave se mueve hacia arriba.";
static constexpr char *LOG_MOV_IZQ = (char *) "La nave se mueve a la izquierda.";
static constexpr char *LOG_MOV_DER = (char *) "La nave se mueve a la derecha.";
static constexpr char *LOG_MOV_ABAJO = (char *) "La nave se mueve hacia abajo.";

static constexpr char *LOG_MULTIPLES_ARGS = (char *) "Demasiados argumentos por flag.";
static constexpr char *LOG_FALTAN_PARAMETROS = (char *) "No se ingresaron suficientes parámetros";

static constexpr char *LOG_MODO_DE_LOGUEO = (char *) "El modo de logueo es: ";
static constexpr char *LOG_INICIO_JSON = (char *) "Se detalla lo leído del json...";
static constexpr char *LOG_PATH_E1 = (char *) "Clase de enemigo 1: ";
static constexpr char *LOG_PATH_E2 = (char *) "Clase de enemigo 2: ";
static constexpr char *LOG_CANT_E1_1 = (char *) "Cant. de enemigo 1 en Nivel 1: ";
static constexpr char *LOG_CANT_E1_2 = (char *) "Cant. de enemigo 1 en Nivel 2: ";
static constexpr char *LOG_CANT_E2_1 = (char *) "Cant. de enemigo 2 en Nivel 1: ";
static constexpr char *LOG_CANT_E2_2 = (char *) "Cant. de enemigo 2 en Nivel 2: ";
static constexpr char *LOG_CANT_MAX_E = (char *) "Cant. maxima de enemigos por Nivel: ";
static constexpr char *LOG_PATH_F1C1 = (char *) "Ruta de capa 1 de fondo 1: ";
static constexpr char *LOG_PATH_F1C2 = (char *) "Ruta de capa 2 de fondo 1: ";
static constexpr char *LOG_PATH_F1C3 = (char *) "Ruta de capa 3 de fondo 1: ";
static constexpr char *LOG_PATH_F1C4 = (char *) "Ruta de capa 4 de fondo 1: ";
static constexpr char *LOG_PATH_F1C5 = (char *) "Ruta de capa 5 de fondo 1: ";
static constexpr char *LOG_PATH_F1C6 = (char *) "Ruta de capa 6 de fondo 1: ";
static constexpr char *LOG_PATH_F2C1 = (char *) "Ruta de capa 1 de fondo 2: ";
static constexpr char *LOG_PATH_F2C2 = (char *) "Ruta de capa 2 de fondo 2: ";
static constexpr char *LOG_PATH_F2C3 = (char *) "Ruta de capa 3 de fondo 2: ";
static constexpr char *LOG_PATH_F2C4 = (char *) "Ruta de capa 4 de fondo 2: ";
static constexpr char *LOG_PATH_F2C5 = (char *) "Ruta de capa 5 de fondo 2: ";
static constexpr char *LOG_PATH_F2C6 = (char *) "Ruta de capa 6 de fondo 2: ";

static constexpr char *LOG_INIT_VERBOSE = (char *) "Se detallan valores adicionales utilizados.";
static constexpr char *LOG_V_JSON_DEFAULT = (char *) "Ruta del json por defecto: ";
static constexpr char *LOG_V_IMG_DEFAULT = (char *) "Ruta de la imagen por defecto: ";
static constexpr char *LOG_V_IMG_LOGO = (char *) "Ruta de la imagen del logo: ";

static constexpr char *LOG_V_IMG_LV_1 = (char *) "Ruta de la imagen del nivel 1: ";
static constexpr char *LOG_V_IMG_LV_1_FIN = (char *) "Ruta de la imagen del fin de nivel 1: ";
static constexpr char *LOG_V_IMG_LV_2 = (char *) "Ruta de la imagen del nivel 2: ";
static constexpr char *LOG_V_IMG_LV_2_FIN = (char *) "Ruta de la imagen del fin de nivel 2: ";

static constexpr char *LOG_V_IMG_ARR = (char *) "Ruta de la imagen del personaje arriba: ";
static constexpr char *LOG_V_IMG_ARR_DER = (char *) "Ruta de la imagen del personaje en diagonal sup. der.: ";
static constexpr char *LOG_V_IMG_DER = (char *) "Ruta de la imagen del personaje a la derecha: ";
static constexpr char *LOG_V_IMG_ABA_DER = (char *) "Ruta de la imagen del personaje en diagonal inf. der.: ";
static constexpr char *LOG_V_IMG_ABA = (char *) "Ruta de la imagen del personaje abajo: ";
static constexpr char *LOG_V_IMG_ABA_IZQ = (char *) "Ruta de la imagen del personaje inf. izq.: ";
static constexpr char *LOG_V_IMG_IZQ = (char *) "Ruta de la imagen del personaje izq.: ";
static constexpr char *LOG_V_IMG_ARR_IZQ = (char *) "Ruta de la imagen del personaje sup. izq.: ";

static constexpr char *LOG_V_IMG_ENEMIGO_1 = (char *) "Ruta de la imagen del enemigo 1: ";
static constexpr char *LOG_V_IMG_ENEMIGO_2 = (char *) "Ruta de la imagen del enemigo 2: ";
static constexpr char *LOG_V_ANCHO_VENT = (char *) "Ancho ventana: ";
static constexpr char *LOG_V_ALTO_VENT = (char *) "Alto ventana: ";
static constexpr char *LOG_V_X_PERSONAJE = (char *) "X personaje: ";
static constexpr char *LOG_V_Y_PERSONAJE = (char *) "Y personaje: ";
static constexpr char *LOG_V_VEL_PERSONAJE = (char *) "Velocidad de movimiento personaje: ";
static constexpr char *LOG_V_VEL_FONDO = (char *) "Velocidad de movimiento del fondo: ";
static constexpr char *LOG_INIT_CARGA = (char *) "Iniciando la carga de la configuracion";
static constexpr char *LOG_FINAL_CARGA = (char *) "Finalizada la carga de la configuración";

static constexpr char *LOG_CREACION_VENTANA_JUEGO = (char *) "Se crea la ventana del juego.";
static constexpr char *LOG_CARGANDO_ICONO = (char *) "Se esta cargando el ícono del juego...";
static constexpr char *LOG_CARGANDO_IMAGEN_RUTA = (char *) "Se esta cargando la imagen de la ruta: ";
static constexpr char *LOG_IMAGEN = (char *) "La imagen se cargó exitosamente.";
static constexpr char *LOG_IMAGEN_DEFECTO = (char *) "La imagen en la ruta pedida no pudo ser encontrada, se usará la imagen por defecto en su lugar.";
static constexpr char *LOG_ICONO = (char *) "La imagen del ícono se cargo exitosamente.";
static constexpr char *LOG_ICONO_DEFECTO = (char *) "No se encontró la imagen del ícono, se cargó la imagen por defecto en su lugar.";
static constexpr char *LOG_CARTEL_STAGE_1 = (char *) "Aparece el cartel de inicio del nivel 1( STAGE 1 ).";
static constexpr char *LOG_CARTEL_STAGE_1_FIN = (char *) "Se sale del cartel de inicio del nivel 1.";
static constexpr char *LOG_CARTEL_FIN_STAGE_1 = (char *) "Aparece el cartel de fin del nivel 1( STAGE 1 CLEARED ).";
static constexpr char *LOG_CARTEL_FIN_STAGE_1_FIN = (char *) "Se sale del cartel de fin del nivel 1.";
static constexpr char *LOG_CARTEL_STAGE_2 = (char *) "Aparece el cartel de inicio del nivel 2( STAGE 2 ).";
static constexpr char *LOG_CARTEL_STAGE_2_FIN = (char *) "Se sale del cartel de inicio del nivel 2.";
static constexpr char *LOG_CARTEL_FIN_STAGE_2 = (char *) "Aparece el cartel de fin del nivel 2( STAGE 2 CLEARED ).";
static constexpr char *LOG_CARTEL_FIN_STAGE_2_FIN = (char *) "Se sale del cartel de fin del nivel 2.";

void setTipoEnemigo1(std::string tipo);
std::string getTipoEnemigo1();

void setCantEnemigo1Nivel1(std::string cant);
void setCantEnemigo1Nivel2(std::string cant);

int getCantEnemigo1Nivel1();
int getCantEnemigo1Nivel2();

void setTipoEnemigo2(std::string tipo);
std::string getTipoEnemigo2();

void setCantEnemigo2Nivel1(std::string cant);
void setCantEnemigo2Nivel2(std::string cant);

int getCantEnemigo2Nivel1();
int getCantEnemigo2Nivel2();

int getCantMaxEnemigos();

void setRutaFondo11(std::string ruta);
char *getRutaFondo11();

void setRutaFondo12(std::string ruta);
char *getRutaFondo12();

void setRutaFondo13(std::string ruta);
char *getRutaFondo13();

void setRutaFondo14(std::string ruta);
char *getRutaFondo14();

void setRutaFondo15(std::string ruta);
char *getRutaFondo15();

void setRutaFondo16(std::string ruta);
char *getRutaFondo16();

void setRutaFondo21(std::string ruta);
char *getRutaFondo21();

void setRutaFondo22(std::string ruta);
char *getRutaFondo22();

void setRutaFondo23(std::string ruta);
char *getRutaFondo23();

void setRutaFondo24(std::string ruta);
char *getRutaFondo24();

void setRutaFondo25(std::string ruta);
char *getRutaFondo25();

void setRutaFondo26(std::string ruta);
char *getRutaFondo26();

char *getRutaImagenEnemigo1();
char *getRutaImagenEnemigo2();

int getAnchoEnemigo1();
int getAnchoEnemigo2();

int getAltoEnemigo1();
int getAltoEnemigo2();

int getTamAnchoEnemigo1();
int getTamAnchoEnemigo2();

int getTamAltoEnemigo1();
int getTamAltoEnemigo2();

static std::map<int, char *> msj_log = {
        {LOG_ERROR, MSJ_LOG_ERROR},
        {LOG_INFO,  MSJ_LOG_INFO},
        {LOG_DEBUG, MSJ_LOG_DEBUG}
};


/* Esto en python no pasa!!!
 * Hay que pasarle al map una forma de comparar las claves
 * para que cadenas similares se mapeen igual. */
struct metodoDeComparacion {
    bool operator()(const char *s1, const char *s2) const {
        return std::strcmp(s1, s2) < 0;
    }
};

static std::map<char *, int, metodoDeComparacion> tipos_log = {
        {MSJ_LOG_ERROR, LOG_ERROR},
        {MSJ_LOG_INFO,  LOG_INFO},
        {MSJ_LOG_DEBUG, LOG_DEBUG}
};


#endif //PRIMERAENTREGA_CONSTANTES_H
