#ifndef CLIENTE_CONSTANTES_H
#define CLIENTE_CONSTANTES_H

#include <iostream>
#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <string>
#include <SDL2/SDL_ttf.h>

/// COMUNICACIÓN ///
static std::string IP_DEFECTO = "127.0.0.1";
static std::string PUERTO_DEFECTO = "3333";
static const int FIX_PUERTO_SUCIO = 2649; //Numero random

void setFin(bool f);
bool getFin();

static constexpr unsigned int MILISEG_TIMEOUT_EVENTOS = 5; /* 0,05 segundos */
static constexpr int CANTIDAD_REINTENTOS_RECONEXION = 7;

static constexpr char *TIMEOUT = (char *) "-1";
static constexpr char *DESCONECTADO = (char *) "-2";

static constexpr unsigned int SEGUNDOS_TIMEOUT_CONNECT = 0;
static constexpr unsigned int MICROSEGUNDOS_TIMEOUT_CONNECT = 500000;

static constexpr unsigned int SEGUNDOS_TIMEOUT_NORMAL = 0;
static constexpr unsigned int MICROSEGUNDOS_TIMEOUT_NORMAL = 0;

static constexpr unsigned int TIMEOUT_RECEPCION_SV = 400000;  // dividir por 60 para cant. segundosr


/// MENSAJES (para recibir) ///
static constexpr char *  MSJ_JUGADOR_CONECTADO = (char*) "jugador(es) conectado(s).";
static std::string MSJ_INICIO_JUEGO = "Listo";
static std::string MSJ_CERRAR_CLIENTE = "cerrate";
static const std::string PRE_NIVEL_INICIAR = "Nivel_iniciar";
static const std::string PRE_NIVEL_FINALIZAR = "Nivel_finalizar";
static const std::string PRE_NIVEL_NUM = "Nivel";

static std::string MSJ_COLA_VACIA = "cola vacia";

static std::string MSJ_DATOS_VALIDOS = "datos_validos";
static std::string MSJ_DATOS_INVALIDOS = "datos_invalidos";
static std::string MSJ_CLIENTE_YA_CONECTADO = "cliente_ya_conectado";
static std::string MSJ_SERVER_LLENO = "server_lleno";

static std::string MSJ_PING = "ping";


/// TECLAS (para enviar) ///
static constexpr Uint16 TECLA_ARRIBA = 1;
static constexpr Uint16 TECLA_IZQUIERDA = 2;
static constexpr Uint16 TECLA_ABAJO = 3;
static constexpr Uint16 TECLA_DERECHA = 4;
static constexpr Uint16 TECLAS_ARRIBA_IZQUIERDA = 5;
static constexpr Uint16 TECLAS_ARRIBA_DERECHA = 6;
static constexpr Uint16 TECLAS_ABAJO_IZQUIERDA = 7;
static constexpr Uint16 TECLAS_ABAJO_DERECHA = 8;
static constexpr Uint16 TECLA_NINGUNA = 10;
static constexpr Uint16 TECLA_LISTO = 11;

static constexpr Uint16 TECLA_PING_RECIBIDO = 500;

static constexpr Uint16 TECLA_FIN_NOMBRE = 1038;
static constexpr Uint16 TECLA_FIN_PASS = 1039;

static std::map<char, Uint16> mapeo_letras = {
        //letras mayúsculas
        {65, 1001}, {66, 1002}, {67, 1003}, {68, 1004}, {69, 1005}, {70, 1006},
        {71, 1007}, {72, 1008}, {73, 1009}, {74, 1010}, {75, 1011}, {76, 1012},
        {77, 1013}, {78, 1014}, {79, 1015}, {80, 1016}, {81, 1017}, {82, 1018},
        {83, 1019}, {84, 1020}, {85, 1021}, {86, 1022}, {87, 1023}, {88, 1024},
        {89, 1025}, {90, 1026},
        // números del 0 al 9
        {48, 1027}, {49, 1028}, {50, 1029}, {51, 1030}, {52, 1031}, {53, 1032},
        {54, 1033}, {55, 1034}, {56, 1035}, {57, 1036},
        // punto
        {46, 1037},
        // letras minúsculas
        {97, 1040}, {98, 1041}, {99, 1042}, {100, 1043}, {101, 1044}, {102, 1045},
        {103, 1046}, {104, 1047}, {105, 1048}, {106, 1049}, {107, 1050}, {108, 1051},
        {109, 1052}, {110, 1053}, {111, 1054}, {112, 1055}, {113, 1056}, {114, 1057},
        {115, 1058}, {116, 1059}, {117, 1060}, {118, 1061}, {119, 1062}, {120, 1063},
        {121, 1064}, {122, 1065}
};


/// GENERALES ///
static const double EPSILON_DOUBLE = 0.005;


/// VENTANA ///
static constexpr char *RUTA_ICONO = (char *) ("../data/imgs/icono.png");
static constexpr char *RUTA_IMG_DEFECTO = (char *) ("../data/imgs/default.png");
static constexpr char *RUTA_FONDO_1_INICIO = (char *) ("../data/imgs/fondo_1.png");
static constexpr char *RUTA_FONDO_1_FIN = (char *) ("../data/imgs/fondo_fin_1.png");
static constexpr char *RUTA_FONDO_2_INICIO = (char *) ("../data/imgs/fondo_2.png");
static constexpr char *RUTA_FONDO_2_FIN = (char *) ("../data/imgs/fondo_fin_2.png");

static constexpr char *RUTA_PERSONAJE_1_ARRIBA = (char *) ("../data/imgs/personajes/p1/d1.png");
static constexpr char *RUTA_PERSONAJE_1_ARRIBA_DERECHA = (char *) ("../data/imgs/personajes/p1/d2.png");
static constexpr char *RUTA_PERSONAJE_1_DERECHA = (char *) ("../data/imgs/personajes/p1/d3.png");
static constexpr char *RUTA_PERSONAJE_1_ABAJO_DERECHA = (char *) ("../data/imgs/personajes/p1/d4.png");
static constexpr char *RUTA_PERSONAJE_1_ABAJO = (char *) ("../data/imgs/personajes/p1/d5.png");
static constexpr char *RUTA_PERSONAJE_1_ABAJO_IZQUIERDA = (char *) ("../data/imgs/personajes/p1/d6.png");
static constexpr char *RUTA_PERSONAJE_1_IZQUIERDA = (char *) ("../data/imgs/personajes/p1/d7.png");
static constexpr char *RUTA_PERSONAJE_1_ARRIBA_IZQUIERDA = (char *) ("../data/imgs/personajes/p1/d8.png");

static constexpr char *RUTA_PERSONAJE_2_ARRIBA = (char *) ("../data/imgs/personajes/p2/d1.png");
static constexpr char *RUTA_PERSONAJE_2_ARRIBA_DERECHA = (char *) ("../data/imgs/personajes/p2/d2.png");
static constexpr char *RUTA_PERSONAJE_2_DERECHA = (char *) ("../data/imgs/personajes/p2/d3.png");
static constexpr char *RUTA_PERSONAJE_2_ABAJO_DERECHA = (char *) ("../data/imgs/personajes/p2/d4.png");
static constexpr char *RUTA_PERSONAJE_2_ABAJO = (char *) ("../data/imgs/personajes/p2/d5.png");
static constexpr char *RUTA_PERSONAJE_2_ABAJO_IZQUIERDA = (char *) ("../data/imgs/personajes/p2/d6.png");
static constexpr char *RUTA_PERSONAJE_2_IZQUIERDA = (char *) ("../data/imgs/personajes/p2/d7.png");
static constexpr char *RUTA_PERSONAJE_2_ARRIBA_IZQUIERDA = (char *) ("../data/imgs/personajes/p2/d8.png");

static constexpr char *RUTA_PERSONAJE_3_ARRIBA = (char *) ("../data/imgs/personajes/p3/d1.png");
static constexpr char *RUTA_PERSONAJE_3_ARRIBA_DERECHA = (char *) ("../data/imgs/personajes/p3/d2.png");
static constexpr char *RUTA_PERSONAJE_3_DERECHA = (char *) ("../data/imgs/personajes/p3/d3.png");
static constexpr char *RUTA_PERSONAJE_3_ABAJO_DERECHA = (char *) ("../data/imgs/personajes/p3/d4.png");
static constexpr char *RUTA_PERSONAJE_3_ABAJO = (char *) ("../data/imgs/personajes/p3/d5.png");
static constexpr char *RUTA_PERSONAJE_3_ABAJO_IZQUIERDA = (char *) ("../data/imgs/personajes/p3/d6.png");
static constexpr char *RUTA_PERSONAJE_3_IZQUIERDA = (char *) ("../data/imgs/personajes/p3/d7.png");
static constexpr char *RUTA_PERSONAJE_3_ARRIBA_IZQUIERDA = (char *) ("../data/imgs/personajes/p3/d8.png");

static constexpr char *RUTA_PERSONAJE_4_ARRIBA = (char *) ("../data/imgs/personajes/p4/d1.png");
static constexpr char *RUTA_PERSONAJE_4_ARRIBA_DERECHA = (char *) ("../data/imgs/personajes/p4/d2.png");
static constexpr char *RUTA_PERSONAJE_4_DERECHA = (char *) ("../data/imgs/personajes/p4/d3.png");
static constexpr char *RUTA_PERSONAJE_4_ABAJO_DERECHA = (char *) ("../data/imgs/personajes/p4/d4.png");
static constexpr char *RUTA_PERSONAJE_4_ABAJO = (char *) ("../data/imgs/personajes/p4/d5.png");
static constexpr char *RUTA_PERSONAJE_4_ABAJO_IZQUIERDA = (char *) ("../data/imgs/personajes/p4/d6.png");
static constexpr char *RUTA_PERSONAJE_4_IZQUIERDA = (char *) ("../data/imgs/personajes/p4/d7.png");
static constexpr char *RUTA_PERSONAJE_4_ARRIBA_IZQUIERDA = (char *) ("../data/imgs/personajes/p4/d8.png");

static constexpr char *RUTA_PERSONAJE_DESCONECTADO = (char *) ("../data/imgs/personajes/p_desconectado.png");

static constexpr char *RUTA_IMAGEN_TIPO_ENEMIGO_1 = (char *) ("../data/imgs/enemigo_1.png");
static constexpr char *RUTA_IMAGEN_TIPO_ENEMIGO_1_DERECHA = (char *) ("../data/imgs/enemigo_1d.png");
static constexpr char *RUTA_IMAGEN_TIPO_ENEMIGO_2 = (char *) ("../data/imgs/enemigo_2.png");

static constexpr char *NOMBRE_JUEGO = (char *) "Gley Lancer";
static constexpr int X_VENTANA = 500;
static constexpr int Y_VENTANA = 200;
static constexpr int ANCHO_VENTANA = 800;
static constexpr int ALTO_VENTANA = 600;
static constexpr int ANCHO_FONDO = 4000;
static constexpr int ANCHO_CAPA = 3200;
static constexpr int STATE_VENTANA = SDL_WINDOW_SHOWN;
static constexpr int CANTIDAD_NIVELES = 2;

static const float VELOCIDAD_CAPA_5 = 2*1.0f;
static const float VELOCIDAD_CAPA_4 = 2*1.5f;
static const float VELOCIDAD_CAPA_3 = 2*2.5f;
static const float VELOCIDAD_CAPA_2 = 2*3.75f;
static const float VELOCIDAD_CAPA_1 = 2*7.0f;
static const std::string PRE_POSICION_VENTANA = "Pos_Ventana";

static constexpr uint32_t MILISEG_MIN_FPS = 8;


/// FUENTE ///
static constexpr char *NOMBRE_FUENTE = (char *) ("../data/FreeSans.ttf");

static constexpr unsigned int TAM_FUENTE_CHICA = 24;
static constexpr unsigned int TAM_FUENTE_NORMAL = 30;


/// MENU ///
static constexpr char *RUTA_FONDO_MENU = (char *) ("../data/imgs/fondo_0.png");
static constexpr char *RUTA_FONDO_CONECTANDO = (char *) ("../data/imgs/fondo_conectando.png");
static constexpr char *RUTA_FONDO_ESPERA = (char *) ("../data/imgs/fondo_espera.png");
static constexpr char *RUTA_FONDO_VALIDAR = (char *) ("../data/imgs/fondo_validar.png");

static constexpr char *RUTA_NUM_1 = (char *) ("../data/imgs/num1.png");
static constexpr char *RUTA_NUM_2 = (char *) ("../data/imgs/num2.png");
static constexpr char *RUTA_NUM_3 = (char *) ("../data/imgs/num3.png");


// Refactor: si se agrega un cartel aca, también hay
// que sumarlo en CartelVista.
// Y CUIDADO SI ES UN CARTEL PRE_JUEGO (hay que aumentar una variable)
// :|
static std::vector<char *> CARTELES = {
        RUTA_FONDO_CONECTANDO,
        RUTA_FONDO_ESPERA,
        RUTA_FONDO_1_INICIO,
        RUTA_FONDO_1_FIN,
        RUTA_FONDO_2_INICIO,
        RUTA_FONDO_2_FIN
};


static const int CANTIDAD_CARTELES_PRE_JUEGO = 2;
static const int CANTIDAD_CARTELES = (int) CARTELES.size();
static const int CANTIDAD_CARTELES_NROS= 3;

static const std::chrono::seconds TIMEOUT_NUMERO_NIVEL = std::chrono::seconds(1);

static constexpr char *TITULO_CARTEL_CONEXION = (char *) ("Error de conexión");
static constexpr char *MSJ_CARTEL_CONEXION = (char *) ("La combinación IP/Puerto no es válida.");
static constexpr char *MSJ_SIN_CONEXION = (char *) ("No hay servidor disponible para los datos provistos.");
static constexpr char *TITULO_CREDENCIALES = (char *) ("Error de credenciales");
static constexpr char *MSJ_USR_PASS_MAL = (char *) ("Se deben especificar un usuario y una password.");
static constexpr char *MSJ_SV_REJECTED_YA_CONECTADO = (char *) ("El usuario con esas credenciales ya esta jugando.");
static constexpr char *MSJ_SV_REJECTED = (char *) ("La combinación Usuario/Password no es válida.");
static constexpr char *MSJ_SV_LLENO = (char *) ("El servidor al que quizo conectarse esta lleno.");

static constexpr char *MSJ_FIN = (char *) ("Reinicio de la aplicación");
static constexpr char *MSJ_ACLARACION_FIN = (char *) ("Se perdió la conexión con el servidor.");

static constexpr SDL_Color COLOR_BLANCO = {255, 255, 255, 0};
static constexpr SDL_Color COLOR_GRIS = {119, 136, 153, 0};
static constexpr int MENU_OPCION_1 = 1;
static constexpr int MENU_OPCION_2 = 2;
static constexpr int MENU_OPCION_ULT = MENU_OPCION_2;
static constexpr int MENU_INICIAR = -3;
static constexpr int MENU_SALIR = -1;

static constexpr char *MENSAJE_CONECTARSE = (char *) ("CONECTARSE");
static constexpr char *MENSAJE_SALIR = (char *) ("SALIR");

static constexpr char *MENSAJE_USUARIO = (char *) ("USUARIO");
static constexpr char *MENSAJE_PASS = (char *) ("PASSWORD");
static constexpr char *MENSAJE_INICIAR = (char *) ("INICIAR");

static constexpr int MENU_VALIDAR_1 = 1;
static constexpr int MENU_VALIDAR_2 = 2;
static constexpr int MENU_VALIDAR_3 = 3;
static constexpr int MENU_VALIDAR_ULT = MENU_VALIDAR_3;

static constexpr char *BACKSPACE = (char *) ("BORRAR");

void setIP(std::string ip);
const char *getIPServidorCte();
char* getIPServidor();

void setPuerto(std::string puerto);
const char *getPuertoServidorCte();
char* getPuertoServidor();

void setUsuario(std::string n, bool trim);
char *getUsuario();

void setPass(std::string n, bool trim);
char *getPass();
char* getPassAsteriscos();

int getAnchoEnemigo1();
int getAnchoEnemigo2();

int getAltoEnemigo1();
int getAltoEnemigo2();

int getTamAnchoEnemigo1();
int getTamAnchoEnemigo2();

int getTamAltoEnemigo1();
int getTamAltoEnemigo2();

void setTipoEnemigo1(std::string tipo);
std::string getTipoEnemigo1();

void setTipoEnemigo2(std::string tipo);
std::string getTipoEnemigo2();

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

static constexpr unsigned int MAX_LEN_USUARIO = 8;
static constexpr unsigned int MAX_LEN_PASS = 16;

static std::map<char *, int> anchos = {
        {MENSAJE_CONECTARSE,    std::strlen(MENSAJE_CONECTARSE) * TAM_FUENTE_NORMAL},
        {MENSAJE_SALIR,         std::strlen(MENSAJE_SALIR) * TAM_FUENTE_NORMAL},
        {MENSAJE_USUARIO,        std::strlen(MENSAJE_USUARIO) * TAM_FUENTE_NORMAL},
        {MENSAJE_PASS,        std::strlen(MENSAJE_PASS) * TAM_FUENTE_NORMAL},
        {MSJ_JUGADOR_CONECTADO, std::strlen(MSJ_JUGADOR_CONECTADO) * TAM_FUENTE_CHICA},
        {MENSAJE_INICIAR, std::strlen(MENSAJE_INICIAR) * TAM_FUENTE_NORMAL}
};


/// PERSONAJE ///
static constexpr unsigned int ANCHO_PERSONAJE = 90;
static constexpr unsigned int ALTO_PERSONAJE = 50;
static constexpr int X_PERSONAJE_DEFAULT = 0;
static constexpr int Y_PERSONAJE_DEFAULT = 100;
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


/// ENEMIGO ///
static const std::string PRE_POSICION_ENEMIGO = "Pos_Enemigo";
static const std::string TIPO_VALIDO_ENEMIGO_1 = "tipo_enemigo_1";
static const std::string TIPO_VALIDO_ENEMIGO_2 = "tipo_enemigo_2";
static const std::string TIPO_VALIDO_ENEMIGO_3 = "tipo_enemigo_3";
static const std::string TIPO_VALIDO_ENEMIGO_4 = "tipo_enemigo_4";
static const std::string TIPO_VALIDO_ENEMIGO_DEFAULT = "default";
static constexpr int DIRECCION_ENEMIGO_ARRIBA = 0;
static constexpr int DIRECCION_ENEMIGO_ARRIBA_DERECHA = 1;
static constexpr int DIRECCION_ENEMIGO_DERECHA = 2;
static constexpr int DIRECCION_ENEMIGO_ABAJO_DERECHA = 3;
static constexpr int DIRECCION_ENEMIGO_ABAJO = 4;
static constexpr int DIRECCION_ENEMIGO_ABAJO_IZQUIERDA = 5;
static constexpr int DIRECCION_ENEMIGO_IZQUIERDA = 6;
static constexpr int DIRECCION_ENEMIGO_ARRIBA_IZQUIERDA = 7;


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
        {TIPO_VALIDO_ENEMIGO_3,       ANCHO_TIPO_ENEMIGO_3},
        {TIPO_VALIDO_ENEMIGO_4,       ANCHO_TIPO_ENEMIGO_4},
        {TIPO_VALIDO_ENEMIGO_DEFAULT, ANCHO_TIPO_ENEMIGO_DEFAULT}
};

/*
 * Mapa que contiene los altos de cada tipo de enemigo valido.
*/
static std::map<std::string, unsigned int> altos_enemigos = {
        {TIPO_VALIDO_ENEMIGO_1,       ALTO_TIPO_ENEMIGO_1},
        {TIPO_VALIDO_ENEMIGO_2,       ALTO_TIPO_ENEMIGO_2},
        {TIPO_VALIDO_ENEMIGO_3,       ALTO_TIPO_ENEMIGO_3},
        {TIPO_VALIDO_ENEMIGO_4,       ALTO_TIPO_ENEMIGO_4},
        {TIPO_VALIDO_ENEMIGO_DEFAULT, ALTO_TIPO_ENEMIGO_DEFAULT}
};
/*
 * Mapa que contiene los tamaños de anchos de los tipos de enemigos en la vista .
*/
static std::map<std::string, unsigned int> tam_anchos_enemigos = {
        {TIPO_VALIDO_ENEMIGO_1,       TAM_ANCHO_TIPO_ENEMIGO_1},
        {TIPO_VALIDO_ENEMIGO_2,       TAM_ANCHO_TIPO_ENEMIGO_2},
        {TIPO_VALIDO_ENEMIGO_3,       TAM_ANCHO_TIPO_ENEMIGO_3},
        {TIPO_VALIDO_ENEMIGO_4,       TAM_ANCHO_TIPO_ENEMIGO_4},
        {TIPO_VALIDO_ENEMIGO_DEFAULT, TAM_ANCHO_TIPO_ENEMIGO_DEFAULT}
};

/*
 * Mapa que contiene los tamaños de alto de los tipos de enemigos en la vista .
*/
static std::map<std::string, unsigned int> tam_altos_enemigos = {
        {TIPO_VALIDO_ENEMIGO_1,       TAM_ALTO_TIPO_ENEMIGO_1},
        {TIPO_VALIDO_ENEMIGO_2,       TAM_ALTO_TIPO_ENEMIGO_2},
        {TIPO_VALIDO_ENEMIGO_3,       TAM_ALTO_TIPO_ENEMIGO_3},
        {TIPO_VALIDO_ENEMIGO_4,       TAM_ALTO_TIPO_ENEMIGO_4},
        {TIPO_VALIDO_ENEMIGO_DEFAULT, TAM_ALTO_TIPO_ENEMIGO_DEFAULT}
};

/// JSON ///
static std::string RUTA_CONFIG_DEFAULT = "../data/config_default.json";

void setRutaConfig(std::string ruta);

char *getRutaConfig();

/// LOGGING ///
static std::string RUTA_LOG = "../data/logs/log_";
static const int DIR_DER = 0;
static constexpr char *LOG_DEF_CON = (char *) "Valores de conexión por defecto:";

static constexpr char *FLAG_LOG = (char *) "-l";
static constexpr char *FLAG_RUTA_CONFIG = (char *) "-c";
static constexpr char *FLAG_IP = (char *) "-i";	
static constexpr char *FLAG_PUERTO = (char *) "-p";

static constexpr int ARGC_MAX_CANTIDAD_PARAMETROS = 5;
static constexpr int ARGC_MIN_CANTIDAD_PARAMETROS = 3;

static std::string EXTENSION_LOG = ".log";
static constexpr int LOG_ERROR = 1;
static constexpr char *MSJ_LOG_ERROR = (char *) "ERROR";
static constexpr int LOG_INFO = 2;
static constexpr char *MSJ_LOG_INFO = (char *) "INFO";
static constexpr int LOG_DEBUG = 3;
static constexpr char *MSJ_LOG_DEBUG = (char *) "DEBUG";

static std::string RUTA_LOG_AUX = "log_";
static constexpr char* LOG_IP = (char *) "IP del servidor ";
static constexpr char* LOG_PUERTO = (char *) "Puerto del servidor: ";
static constexpr char* LOG_ERROR_GETADDR = (char *) "Error en el getaddrinfo. ¿Datos de conexión incorrectos?";
static constexpr char* LOG_ERROR_SEND = (char *) "No se pudo enviar un mensaje: error por desconexión.";
static constexpr char* LOG_CONEXION_EXITOSA = (char *) "Conexión exitosa.";
static constexpr char* LOG_CONEXION_CERRADA = (char *) "Conexión cerrada.";
static constexpr char* LOG_INTENTAR_CONEXION = (char *) "Se intentará conectar al servidor con los siguientes valores configurados:";
static constexpr char* LOG_SIN_FUENTE = (char *) "No se pudo cargar la fuente.";

static constexpr char* LOG_COMANDO_CONSOLA = (char *) "Utilizando el modo de logueo provisto por consola.";
static constexpr char* ERROR_FALLA_DE_CARGA_JSON_DEFAULT = (char *) "No se ha podido cargar el archivo de configuracion default";
static constexpr char* ERROR_SETEO_LOG = (char *) "Modo de log incorrecto. Seteado en DEBUG.";
static constexpr char* ERROR_LOG = (char *) "No se pudo crear el archivo de log, o el mismo es inaccesible.";
static constexpr char* ERROR_IMG_FALTANTE = (char *) "Imagen faltante: ";
static constexpr char* LOG_ERROR_FUENTE = (char *) "No se pudo abrir el archivo de la fuente.";
static constexpr char* LOG_NO_LOC_JSON = (char *) "No se encontró JSON local. Leyendo archivo por defecto.";
static constexpr char* LOG_LOC_JSON = (char *) "Leyendo archivo JSON local.";
static constexpr char* LOG_LOC_JSON_DEFAULT = (char *) "Leyendo archivo JSON por defecto.";
static constexpr char* LOG_CONFIG_PARAMETROS = (char *) "Se usa el archivo de configuracion pasado por consola.";
static constexpr char* LOG_CONFIG_SIN_PARAMETROS = (char *) "No se paso un archivo json de configuracion por parametro.";
static constexpr char* LOG_MODO_DEFAULT_CORRECTO = (char *) "Se leyo correctamente el modo del archivo por defecto.";
static constexpr char* LOG_MSJ_LISTO = (char *) " Se avisa al servidor que esta listo el cliente.";
static constexpr char* LOG_MSJ_NOMBRE_VALIDADO = (char *) " El usuario logro loguearse con el nombre: ";
static constexpr char* LOG_MSJ_PASSWORD_VALIDADO = (char *) "  El usuario logro loguearse con el password: ";

static constexpr char* ERROR_PARAMETRO_POR_CONSOLA_INVALIDO = (char *) "El modo de log ingresado por consola no es valido";
static constexpr char* ERROR_FONDO_11_FALTANTE = (char *) "No se encontro ruta de capa 1 de fondo 1 en json local, se usara una ruta por defecto. ";
static constexpr char* ERROR_FONDO_11_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 1 de fondo 1 en config default";
static constexpr char* ERROR_FONDO_12_FALTANTE = (char *) "No se encontro ruta de capa 2 de fondo 1 en json local, se usara una ruta por defecto. ";
static constexpr char* ERROR_FONDO_12_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 2 de fondo 1 en config default.";
static constexpr char* ERROR_FONDO_13_FALTANTE = (char *) "No se encontro ruta de capa 3 de fondo 1 en json local, se usara una ruta por defecto. ";
static constexpr char* ERROR_FONDO_13_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 3 de fondo 1 en config default.";
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
static constexpr char* ERROR_FORMATO_JSON = (char *) "Se encontró un error en el json. Línea: ";
static constexpr char* ERROR_FORMATO_JSON_2 = (char *) ". Se usará configuración por defecto.";

static constexpr char* LOG_ERROR_MODO_LOG_LOCAL = (char*) "Modo de logueo ingresado en archivo de configuracion incorrecto, se leera el modo por defecto.";
static constexpr char* LOG_ERROR_SIN_DEFAULT = (char*) "No existe archivo jason por defecto.";
static constexpr char* ERROR_FORMATO_JSON_DEFAULT = (char*) ". No se cargara informacion a partir de este error. ";

static constexpr char* LOG_ERROR_TIPO_ENEMIGO_1_INVALIDO = (char *) "El tipo de enemigo 1 ingresado en el json es invalido, tomaremos el valor por default.";
static constexpr char* LOG_ERROR_TIPO_ENEMIGO_2_INVALIDO = (char *) "El tipo de enemigo 2 ingresado en el json es invalido, tomaremos el valor por default.";
static constexpr char* LOG_ERROR_TIPO_ENEMIGO_1_INVALIDO_DEFAULT = (char *)  "El tipo de enemigo 1 en la configuracion default es invalido";
static constexpr char* LOG_ERROR_TIPO_ENEMIGO_2_INVALIDO_DEFAULT = (char *)  "El tipo de enemigo 2 en la configuracion default es invalido";

static constexpr char* LOG_JUEGO_INICIADO = (char *) "Juego iniciado.";
static constexpr char* LOG_JUEGO_FINALIZADO = (char *) "Juego finalizado.";
static constexpr char* LOG_JUEGO_CERRADO_POR_USER = (char *) "Juego cerrado por usuario";
static constexpr char* LOG_SIGUIENTE_NIVEL = (char *) "Nivel finalizado.";
static constexpr char* LOG_FIN_MENU = (char *) "Se sale del menú y se inician los niveles.";
static constexpr char* LOG_MOV_SUP_IZQ = (char *) "La nave se mueve al margen superior izquierdo.";
static constexpr char* LOG_MOV_SUP_DER = (char *) "La nave se mueve al margen superior derecho.";
static constexpr char* LOG_MOV_ABA_IZQ = (char *) "La nave se mueve al margen inferior izquierdo.";
static constexpr char* LOG_MOV_ABA_DER = (char *) "La nave se mueve al margen inferior derecho.";
static constexpr char* LOG_MOV_ARRIBA = (char *) "La nave se mueve hacia arriba.";
static constexpr char* LOG_MOV_IZQ = (char *) "La nave se mueve a la izquierda.";
static constexpr char* LOG_MOV_DER = (char *) "La nave se mueve a la derecha.";
static constexpr char* LOG_MOV_ABAJO = (char *) "La nave se mueve hacia abajo.";

static constexpr char* LOG_MULTIPLES_ARGS = (char *) "Se pasaron demasiados argumentos";
static constexpr char* LOG_FALTAN_PARAMETROS = (char *) "No se ingresaron suficientes argumentos";

static constexpr char* LOG_MODO_DE_LOGUEO = (char *) "El modo de logueo es: ";
static constexpr char* LOG_INICIO_JSON = (char *) "Se detalla lo leído del JSON...";
static constexpr char* LOG_PATH_E1 = (char *) "Clase de enemigo 1: ";
static constexpr char* LOG_PATH_E2 = (char *) "Clase de enemigo 2: ";
static constexpr char* LOG_CANT_E1 = (char *) "Cant. de enemigo 1: ";
static constexpr char* LOG_CANT_E2 = (char *) "Cant. de enemigo 2: ";
static constexpr char* LOG_PATH_F1C1 = (char *) "Ruta de capa 1 de fondo 1: ";
static constexpr char* LOG_PATH_F1C2 = (char *) "Ruta de capa 2 de fondo 1: ";
static constexpr char* LOG_PATH_F1C3 = (char *) "Ruta de capa 3 de fondo 1: ";
static constexpr char *LOG_PATH_F1C4 = (char *) "Ruta de capa 4 de fondo 1: ";
static constexpr char *LOG_PATH_F1C5 = (char *) "Ruta de capa 5 de fondo 1: ";
static constexpr char *LOG_PATH_F1C6 = (char *) "Ruta de capa 6 de fondo 1: ";
static constexpr char *LOG_PATH_F2C1 = (char *) "Ruta de capa 1 de fondo 2: ";
static constexpr char *LOG_PATH_F2C2 = (char *) "Ruta de capa 2 de fondo 2: ";
static constexpr char *LOG_PATH_F2C3 = (char *) "Ruta de capa 3 de fondo 2: ";
static constexpr char *LOG_PATH_F2C4 = (char *) "Ruta de capa 4 de fondo 2: ";
static constexpr char *LOG_PATH_F2C5 = (char *) "Ruta de capa 5 de fondo 2: ";
static constexpr char *LOG_PATH_F2C6 = (char *) "Ruta de capa 6 de fondo 2: ";

static constexpr char* LOG_INIT_VERBOSE = (char *) "Se detallan valores adicionales utilizados.";
static constexpr char* LOG_V_JSON_DEFAULT = (char *) "Ruta del JSON por defecto: ";
static constexpr char* LOG_V_IMG_DEFAULT = (char *) "Ruta del imagen por defecto: ";
static constexpr char* LOG_V_IMG_LOGO = (char *) "Ruta de la imagen del logo: ";
static constexpr char* LOG_V_IMG_MENU = (char *) "Ruta de la imagen del menú: ";

static constexpr char* LOG_V_IMG_LV_1 = (char *) "Ruta de la imagen del nivel 1: ";
static constexpr char* LOG_V_IMG_LV_1_FIN = (char *) "Ruta de la imagen del fin de nivel 1: ";
static constexpr char* LOG_V_IMG_LV_2 = (char *) "Ruta de la imagen del nivel 2: ";
static constexpr char* LOG_V_IMG_LV_2_FIN = (char *) "Ruta de la imagen del fin de nivel 2: ";

static constexpr char* LOG_V_IMG_ARR = (char *) "Ruta de la imagen del personaje arriba: ";
static constexpr char* LOG_V_IMG_ARR_DER = (char *) "Ruta de la imagen del personaje en diagonal sup. der.: ";
static constexpr char* LOG_V_IMG_DER = (char *) "Ruta de la imagen del personaje a la derecha: ";
static constexpr char* LOG_V_IMG_ABA_DER = (char *) "Ruta de la imagen del personaje en diagonal inf. der.: ";
static constexpr char* LOG_V_IMG_ABA = (char *) "Ruta de la imagen del personaje abajo: ";
static constexpr char* LOG_V_IMG_ABA_IZQ = (char *) "Ruta de la imagen del personaje inf. izq.: ";
static constexpr char* LOG_V_IMG_IZQ = (char *) "Ruta de la imagen del personaje izq.: ";
static constexpr char* LOG_V_IMG_ARR_IZQ = (char *) "Ruta de la imagen del personaje sup. izq.: ";

static constexpr char* LOG_V_IMG_ENEMIGO_1 = (char *) "Ruta de la imagen del enemigo 1: ";
static constexpr char* LOG_V_IMG_ENEMIGO_2 = (char *) "Ruta de la imagen del enemigo 2: ";
static constexpr char* LOG_V_ANCHO_VENT = (char *) "Ancho ventana: ";
static constexpr char* LOG_V_ALTO_VENT = (char *) "Alto ventana: ";
static constexpr char* LOG_V_X_PERSONAJE = (char *) "X personaje: ";
static constexpr char* LOG_V_Y_PERSONAJE = (char *) "Y personaje: ";
static constexpr char* LOG_V_VEL_PERSONAJE = (char *) "Velocidad de movimiento personaje: ";
static constexpr char* LOG_V_VEL_FONDO = (char *) "Velocidad de movimiento del fondo: ";
static constexpr char* LOG_INIT_CARGA = (char *) "Iniciando la carga de la configuracion";
static constexpr char* LOG_FINAL_CARGA = (char *) "Finalizada la carga de la configuracion";

static constexpr char* LOG_COLISION_ENTRE_ENEMIGOS = (char *) "Colision entre enemigos al crearlos. Pos:(";

static constexpr char* LOG_CREACION_VENTANA_JUEGO = (char *) "Se crea la ventana del juego.";
static constexpr char* LOG_CARGANDO_ICONO = (char *) "Se esta cargando el icono del juego...";
static constexpr char* LOG_CARGANDO_IMAGEN_RUTA = (char *) "Se esta cargando la imagen de la ruta: ";
static constexpr char* LOG_IMAGEN = (char *) "La imagen se cargo exitosamente.";
static constexpr char* LOG_IMAGEN_DEFECTO = (char *) "La imagen en la ruta pedida no pudo ser encontrada, se usara la imagen por defecto en su lugar.";
static constexpr char* LOG_ICONO = (char *) "La imagen del icono se cargo exitosamente.";
static constexpr char* LOG_ICONO_DEFECTO = (char *) "No se encontro la imagen del icono, se cargo la imagen por defecto en su lugar.";
static constexpr char* LOG_CARTEL_STAGE_1 = (char *) "Aparece el cartel de inicio del nivel 1( STAGE 1 ).";
static constexpr char* LOG_CARTEL_STAGE_1_FIN = (char *) "Se sale del cartel de inicio del nivel 1.";
static constexpr char* LOG_CARTEL_FIN_STAGE_1 = (char *) "Aparece el cartel de fin del nivel 1( STAGE 1 CLEARED ).";
static constexpr char* LOG_CARTEL_FIN_STAGE_1_FIN = (char *) "Se sale del cartel de fin del nivel 1.";
static constexpr char* LOG_CARTEL_STAGE_2 = (char *) "Aparece el cartel de inicio del nivel 2( STAGE 2 ).";
static constexpr char* LOG_CARTEL_STAGE_2_FIN = (char *) "Se sale del cartel de inicio del nivel 2.";
static constexpr char* LOG_CARTEL_FIN_STAGE_2 = (char *) "Aparece el cartel de fin del nivel 2( STAGE 2 CLEARED ).";
static constexpr char* LOG_CARTEL_FIN_STAGE_2_FIN = (char *) "Se sale del cartel de fin del nivel 2.";

static constexpr char* LOG_NRO_JUGADOR = (char *) "Número de jugador: ";
static constexpr char* LOG_INICIO_ENVIO_NOMBRE = (char *) "Empezando a enviar el nombre... ";
static constexpr char* LOG_FIN_ENVIO_NOMBRE = (char *) "Fin del a envío del nombre.";
static constexpr char* LOG_ERROR_ENVIAR = (char *) "Error en el enviar datos al servidor.";
static constexpr char* LOG_ERROR_RECIBIR = (char *) "Error en el recibir datos del servidor.";

static constexpr char* LOG_MSJ_FD = (char *) "El fd de la conexion es : ";
static constexpr char* LOG_INTENTO_CONEXION_PUERTO = (char *) "Intento de conexion con puerto: ";
static constexpr char* LOG_ERROR_DATOS_INVALIDOS = (char *) "Datos inválidos de conexión.";
static constexpr char* LOG_ERROR_CONEXION_CLIENTE = (char *) "Error en la conexión del cliente.";


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

static std::map<char*, int, metodoDeComparacion> tipos_log = {
        {MSJ_LOG_ERROR, LOG_ERROR},
        {MSJ_LOG_INFO,  LOG_INFO},
        {MSJ_LOG_DEBUG, LOG_DEBUG}
};

/// EXCEPCIONES ///

static constexpr char *EXCEPCION_ERROR_CONEXION = (char *) "Error. Servidor inaccesible para los datos provistos.";

#endif //CLIENTE_CONSTANTES_H
