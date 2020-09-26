#ifndef SERVIDOR_CONSTANTES_H
#define SERVIDOR_CONSTANTES_H

#include <iostream>
#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <string>
#include <SDL2/SDL_ttf.h>
#include "../modelo/Posicion.h"
#include <iostream>
#include <bits/stdc++.h>
#include <SDL2/SDL_quit.h>


/// COMUNICACIÓN ///
static const int FIX_PUERTO_SUCIO = 2649; //Numero random
static const int FD_DEFECTO = -1;
static const int CANTIDAD_REINTENTOS_RECONEXION = 7;

static constexpr int CANT_CONEXIONES_MAX = 32;
static constexpr int N_JUGADORES_MAX = 4;

static constexpr uint32_t MS_PING_ALTO = 80;
static constexpr uint32_t MS_PING_DESCONECTADO = 6500;

static constexpr unsigned int SEGUNDOS_TIMEOUT = 0;
static constexpr unsigned int MICROSEGUNDOS_TIMEOUT = 50000; /* 0,05 segundos  */
static const std::chrono::seconds TIMEOUT_JUEGO = std::chrono::seconds(600); //Es mucho a propósito
static const std::chrono::seconds TIMEOUT_NOMBRES = std::chrono::seconds(2);
static constexpr unsigned int MILISEG_LOCK_CERRAR_FD = 16; /* 0,016 segundos  */
static constexpr unsigned int MILISEG_COLA_VACIA = 16; /* 0,016 segundos  */

static constexpr int CONECTADO_NO_LISTO = -2;


/// MENSAJES (para enviar) ///
static constexpr char* MSJ_JUGADOR_CONECTADO = (char*) " jugador(es) conectado(s).";
static std::string MSJ_INICIO_SV = "Servidor iniciado.";
static std::string MSJ_CLIENTE_LISTO = "Listo";
static std::string MSJ_CERRAR_CLIENTE = "cerrate";
static std::string MSJ_DATOS_VALIDOS = "datos_validos";
static std::string MSJ_DATOS_INVALIDOS = "datos_invalidos";
static std::string MSJ_CLIENTE_YA_CONECTADO = "cliente_ya_conectado";
static std::string MSJ_SERVER_LLENO = "server_lleno";

static std::string MSJ_SEPARADOR = " ";
static std::string MSJ_DESCONOCIDO = "desconocido";

static std::string MSJ_COLA_VACIA = "cola vacia";
static std::string MSJ_NUMERO_PERSONAJE_DESCONECTADO = "4";

static std::string MSJ_PING = "ping";


/// TECLAS (para recibir) ///
static constexpr Uint16 COLA_VACIA = 65535;

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

static constexpr Uint16 TECLA_JUEGO_MAX = 1000;


static std::map<Uint16, std::string> mapeo_nro_letra = {
        { 1001, "A" }, { 1002, "B" }, { 1003, "C"}, { 1004, "D" }, { 1005, "E" }, { 1006, "F" },
        { 1007, "G" }, { 1008, "H" }, { 1009, "I"}, { 1010, "J" }, { 1011, "K" }, { 1012, "L" },
        { 1013, "M" }, { 1014, "N" }, { 1015, "O"}, { 1016, "P" }, { 1017, "Q" }, { 1018, "R" },
        { 1019, "S" }, { 1020, "T" }, { 1021, "U"}, { 1022, "V" }, { 1023, "W" }, { 1024, "X" },
        { 1025, "Y" }, { 1026, "Z" },

        { 1027, "0"}, { 1028, "1" }, { 1029, "2" }, { 1030, "3" },
        { 1031, "4" }, { 1032, "5" }, { 1033, "6"}, { 1034, "7" }, { 1035, "8" }, { 1036, "9" },
        { 1037, "." },

        { 1040, "a" }, { 1041, "b" }, { 1042, "c"}, { 1043, "d" }, { 1044, "e" }, { 1045, "f" },
        { 1046, "g" }, { 1047, "h" }, { 1048, "i"}, { 1049, "j" }, { 1050, "k" }, { 1051, "l" },
        { 1052, "m" }, { 1053, "n" }, { 1054, "o"}, { 1055, "p" }, { 1056, "q" }, { 1057, "r" },
        { 1058, "s" }, { 1059, "t" }, { 1060, "u"}, { 1061, "v" }, { 1062, "w" }, { 1063, "x" },
        { 1064, "y" }, { 1065, "z" }
};


/// GENERALES ///
static const double EPSILON_DOUBLE= 0.005;
static constexpr int ESCALA_FONDO = 1;



/// LOGGING ///
static std::string RUTA_LOG = "../data/logs/log_";
static std::string RUTA_LOG_AUX = "log_";

static constexpr char *FLAG_LOG = (char *) "-l";
static constexpr char *FLAG_RUTA_CONFIG = (char *) "-c";
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

static constexpr char *LOG_COMANDO_CONSOLA = (char *) "Utilizando el modo de logueo provisto por consola.";
static constexpr char *ERROR_FALLA_DE_CARGA_JSON_DEFAULT = (char *) "No se ha podido cargar el archivo de configuracion default";
static constexpr char *ERROR_SETEO_LOG = (char *) "Modo de log incorrecto. Seteado en DEBUG.";
static constexpr char *ERROR_LOG = (char *) "No se pudo crear el archivo de log en la ruta esperada. Logueando en ruta local.";
static constexpr char *ERROR_IMG_FALTANTE = (char *) "Imagen faltante: ";
static constexpr char *ERROR_PARAMETRO_POR_CONSOLA_INVALIDO = (char *) "El modo de log ingresado por consola no es valido";
static constexpr char *ERROR_FORMATO_JSON = (char *) "Se encontró un error en el json. Línea: ";
static constexpr char *ERROR_FORMATO_JSON_2 = (char *) ". Se usará configuración por defecto.";
static constexpr char *ERROR_USUARIOS_JSON_LOCAL = (char *) "No se encontraron usuarios en el archivo de configuracion provisto. Se tomaran los valores por defecto";
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

static constexpr char *LOG_ERROR_TIPO_ENEMIGO_1_INVALIDO = (char *) "El tipo de enemigo 1 ingresado en el json es invalido";
static constexpr char *LOG_ERROR_TIPO_ENEMIGO_2_INVALIDO = (char *) "El tipo de enemigo 2 ingresado en el json es invalido";
static constexpr char *LOG_ERROR_TIPO_ENEMIGO_1_INVALIDO_DEFAULT = (char *)  "El tipo de enemigo 1 en la configuracion default es invalido";
static constexpr char *LOG_ERROR_TIPO_ENEMIGO_2_INVALIDO_DEFAULT = (char *)  "El tipo de enemigo 2 en la configuracion default es invalido";

static constexpr char *LOG_NO_LOC_JSON = (char *) "No se encontró JSON local. Leyendo archivo por defecto.";
static constexpr char *LOG_LOC_JSON = (char *) "Leyendo archivo JSON local.";
static constexpr char *LOG_CONFIG_PARAMETROS = (char *) "Se usa el archivo de configuracion pasado por consola.";
static constexpr char *LOG_CONFIG_SIN_PARAMETROS = (char *) "No se paso un archivo json de configuracion por parametro.";
static constexpr char *LOG_PUERTO_CONSOLA_INVALIDO = (char *) "El puerto ingresado por consola es invalido, se usara el puerto por defecto";

static constexpr char *LOG_JUEGO_INICIADO = (char *) "Juego iniciado.";
static constexpr char *LOG_JUEGO_FINALIZADO = (char *) "Juego finalizado.";
static constexpr char* LOG_SIGUIENTE_NIVEL = (char*) "Nivel finalizado.";
static constexpr char *LOG_FIN_JUEGO_CORRECTO = (char *) "Se ha alcanzado el final del ultimo nivel correctamente.";
static constexpr char *LOG_JUEGO_CERRADO_POR_USER = (char *) "Juego cerrado por usuario";
static constexpr char *LOG_NUEVO_NIVEL = (char *) "Nuevo nivel iniciado. Numero: ";
static constexpr char *LOG_NIVEL_FINALIZADO = (char *) "Nivel finalizado.";
static constexpr char *LOG_MOV_SUP_IZQ = (char *) "La nave se mueve al margen superior izquierdo.";
static constexpr char *LOG_MOV_SUP_DER = (char *) "La nave se mueve al margen superior derecho.";
static constexpr char *LOG_MOV_ABA_IZQ = (char *) "La nave se mueve al margen inferior izquierdo.";
static constexpr char *LOG_MOV_ABA_DER = (char *) "La nave se mueve al margen inferior derecho.";
static constexpr char *LOG_MOV_ARRIBA = (char *) "La nave se mueve hacia arriba.";
static constexpr char *LOG_MOV_IZQ = (char *) "La nave se mueve a la izquierda.";
static constexpr char *LOG_MOV_DER = (char *) "La nave se mueve a la derecha.";
static constexpr char *LOG_MOV_ABAJO = (char *) "La nave se mueve hacia abajo.";

static constexpr char *LOG_MULTIPLES_ARGS = (char *) "Se demasiados argumentos";
static constexpr char *LOG_FALTAN_PARAMETROS = (char *) "No se ingresaron suficientes argumentos";

static constexpr char *LOG_MODO_DE_LOGUEO = (char *) "El modo de logueo es: ";
static constexpr char *LOG_INICIO_JSON = (char *) "Se detalla lo leído del JSON...";
static constexpr char *LOG_PATH_E1 = (char *) "Clase de enemigo 1: ";
static constexpr char *LOG_PATH_E2 = (char *) "Clase de enemigo 2: ";
static constexpr char *LOG_CANT_E1_1 = (char *) "Cant. de enemigo 1 en Nivel 1: ";
static constexpr char *LOG_CANT_E1_2 = (char *) "Cant. de enemigo 1 en Nivel 2: ";
static constexpr char *LOG_CANT_E2_1 = (char *) "Cant. de enemigo 2 en Nivel 1: ";
static constexpr char *LOG_CANT_E2_2 = (char *) "Cant. de enemigo 2 en Nivel 2: ";
static constexpr char *LOG_CANT_MAX_E = (char *) "Cant. maxima de enemigos por Nivel: ";

static constexpr char *LOG_NOMBRE_USUARIO = (char *) "Jugador: ";

static constexpr char *LOG_INIT_VERBOSE = (char *) "Se detallan valores adicionales utilizados.";
static constexpr char *LOG_V_JSON_DEFAULT = (char *) "Ruta del JSON por defecto: ";

static constexpr char *LOG_V_ANCHO_VENT = (char *) "Ancho ventana: ";
static constexpr char *LOG_V_ALTO_VENT = (char *) "Alto ventana: ";
static constexpr char *LOG_V_X_PERSONAJE = (char *) "X personaje: ";
static constexpr char *LOG_V_Y_PERSONAJE = (char *) "Y personaje: ";
static constexpr char *LOG_V_VEL_PERSONAJE = (char *) "Velocidad de movimiento personaje: ";
static constexpr char *LOG_V_VEL_FONDO = (char *) "Velocidad de movimiento del fondo: ";
static constexpr char *LOG_INIT_CARGA = (char *) "Iniciando la carga de la configuracion";
static constexpr char *LOG_FINAL_CARGA = (char *) "Finalizada la carga de la configuracion";

static constexpr char *LOG_COLISION_ENTRE_ENEMIGOS = (char *) "Colision entre enemigos al crearlos. Pos:(";

static constexpr char *LOG_ERROR_BIND_1 = (char *) "No se pudo realizar el bind: socket fd es -1";
static constexpr char *LOG_ERROR_BIND_2 = (char *) "No se pudo realizar el bind.";

static constexpr char *LOG_ERROR_ACEPTAR_CLIENTE = (char *) "Error para aceptar cliente, se cerrara el servidor.";
static constexpr char *LOG_ERROR_USUARIO_INVALIDO = (char *) "No se pudo agregar usuario del archivo de configuracion custom.";
static constexpr char *LOG_ERROR_USUARIO_INVALIDO_DEFAULT = (char *) "No se pudo agregar usuario del archivo de configuracion default";
static constexpr char *LOG_ERROR_PASS_INVALIDO = (char *) "No se pudo agregar password del archivo de configuracion custom";
static constexpr char *LOG_ERROR_PASS_INVALIDO_DEFAULT = (char *) "No se pudo agregar password del archivo de configuracion default";

static constexpr char* LOG_ERROR_LONGITUD_USUARIO = (char*) "La longitud del nombre de este usuario es invalida: ";
static constexpr char* LOG_ERROR_USUARIO_REPETIDO = (char*) "Este usuario ya fue registrado: ";
static constexpr char* LOG_ERROR_LONGITUD_PASS = (char*) "La longitud de esta password es invalida: ";

static constexpr char* ERROR_THROW_INICIALIZAR = (char*) "ERROR en inicializar";
static constexpr char* ERROR_THROW_SERVER_BIND = (char*) "ERROR EN SERVER BIND, getaddrinfo: ";
static constexpr char* ERROR_THROW_SERVER_LISTEN = (char*) "ERROR: SERVER LISTEN, error ";
static constexpr char* ERROR_THROW_SERVER_CLOSE = (char*) "ERROR: CIERRE SERVER";

static constexpr char* LOG_CLIENTE_CONECTADO = (char*) "Cliente conectado";
static constexpr char* LOG_CLIENTE_CERRADO = (char*) "Cerrando conexion de fd: ";
static constexpr char* LOG_FIN_ACEPTAR = (char*) "Terminó la fase de aceptación de clientes.";
static constexpr char* LOG_NOMBRE_RECIBIDO = (char*) "Nombre de jugador recibido: ";
static constexpr char* LOG_CLIENTE_VALIDADO = (char *) "Se validó al cliente ";

static constexpr char* LOG_CLIENTE_DESCONECTADO = (char*) "Cliente desconectado: ";
static constexpr char* LOG_APAGAR_FD = (char*) "El servidor apago el fd del cliente ";
static constexpr char* LOG_PEER_SIGUE_CONECTADO = (char*) "El siguiente peer sigue conectado: ";
static constexpr char* LOG_CLIENTE_DE_MAS_BORRADO = (char*) "Se borro cliente de más.";
static constexpr char* LOG_CLIENTE_DESCONECTADO_BORRADO = (char*) "Se borro cliente desconectado.";
static constexpr char* LOG_CLIENTE_INVALIDO_BORRADO = (char*) "Se borro cliente no valido.";
static constexpr char* LOG_CLIENTE_RECONECTADO = (char*) "Se reconecto un cliente.";

static constexpr char*  LOG_MSJ_MANDAR_NUMERO_USUARIO= (char*) "Le esta mandando su numero al usuario ";
static constexpr char*  LOG_MSJ_CANT_JUGADORES_LISTOS= (char*) "Cantidad de jugadores listos: ";
static constexpr char*  LOG_MSJ_TECLA_1= (char*) "Tecla: ";
static constexpr char*  LOG_MSJ_TECLA_2= (char*) " de personaje: ";
static constexpr char*  LOG_MSJ_CLIENTE_LISTO_1= (char*) "El cliente con fd ";
static constexpr char*  LOG_MSJ_CLIENTE_LISTO_2= (char*) " esta listo.";

static constexpr char*  LOG_MSJ_BIND= (char*) "Intento de bind con puerto: ";
static constexpr char*  LOG_MSJ_PUERTO= (char*) "Puerto: ";

static std::map<int, char*> msj_log = {
        { LOG_ERROR, MSJ_LOG_ERROR },
        { LOG_INFO, MSJ_LOG_INFO },
        { LOG_DEBUG, MSJ_LOG_DEBUG }
};

/* Esto en python no pasa!!!
 * Hay que pasarle al map una forma de comparar las claves
 * para que cadenas similares se mapeen igual. */
struct metodoDeComparacion{
    bool operator()(const char* s1, const char* s2) const{
        return std::strcmp(s1, s2) < 0;
    }
};

static std::map<char*, int, metodoDeComparacion> tipos_log = {
        { MSJ_LOG_ERROR, LOG_ERROR },
        { MSJ_LOG_INFO, LOG_INFO },
        { MSJ_LOG_DEBUG, LOG_DEBUG }
};


/// JSON ///
static std::string RUTA_CONFIG_DEFAULT = "../data/config_default.json";
static std::string ERROR_JSON = "No se encontró JSON local. Leyendo archivo por defecto...\n";
static const size_t MAX_LEN_USER = 8;
static const size_t MAX_LEN_PASS = 16;


void setRutaConfig(std::string ruta);

char *getRutaConfig();

static std::string RUTA_IMGS_JSON = "../data/imgs/";

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

int getAnchoEnemigo1();
int getAnchoEnemigo2();

int getAltoEnemigo1();
int getAltoEnemigo2();

int getTamAnchoEnemigo1();
int getTamAnchoEnemigo2();

int getTamAltoEnemigo1();
int getTamAltoEnemigo2();

std::string getPuerto();
void setPuerto(std::string puerto_nuevo);

void agregarNombreUsuario(std::string user);
void agregarPass(std::string pass);

std::vector<std::string> getNombresUsuarios();
std::vector<std::string> getPasswords();

size_t getCantidadUsuarios();




/// MODELO ///
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

static constexpr float DESPLAZAMIENTO_FONDO = 0.23f * ESCALA_FONDO;



static constexpr char* NOMBRE_JUEGO = (char*) "Gley Lancer";

static constexpr char* RUTA_ICONO = (char*)("../data/imgs/icono.png");
static constexpr char* RUTA_FONDO_MENU = (char*)("../data/imgs/fondo_0.png");
static constexpr char* RUTA_FONDO_1_INICIO = (char*)("../data/imgs/fondo_1.png");
static constexpr char* RUTA_FONDO_1_FIN = (char*)("../data/imgs/fondo_fin_1.png");
static constexpr char* RUTA_FONDO_2_INICIO = (char*)("../data/imgs/fondo_2.png");
static constexpr char* RUTA_FONDO_2_FIN = (char*)("../data/imgs/fondo_fin_2.png");

static constexpr char* RUTA_PERSONAJE_ARRIBA = (char*)("../data/imgs/p1.png");
static constexpr char* RUTA_PERSONAJE_ARRIBA_DERECHA = (char*)("../data/imgs/p2.png");
static constexpr char* RUTA_PERSONAJE_DERECHA = (char*)("../data/imgs/p3.png");
static constexpr char* RUTA_PERSONAJE_ABAJO_DERECHA = (char*)("../data/imgs/p4.png");
static constexpr char* RUTA_PERSONAJE_ABAJO = (char*)("../data/imgs/p5.png");
static constexpr char* RUTA_PERSONAJE_ABAJO_IZQUIERDA = (char*)("../data/imgs/p6.png");
static constexpr char* RUTA_PERSONAJE_IZQUIERDA = (char*)("../data/imgs/p7.png");
static constexpr char* RUTA_PERSONAJE_ARRIBA_IZQUIERDA = (char*)("../data/imgs/p8.png");

static constexpr char* RUTA_ENEMIGO_1 = (char*)("../data/imgs/enemigo_1.png");
static constexpr char* RUTA_ENEMIGO_2 = (char*)("../data/imgs/enemigo_2.png");

static constexpr int ANCHO_VENTANA = 800;
static constexpr int ALTO_VENTANA = 600;
//Ancho fondo = Ancho_imagen_fondo * 2 (para que aparezcan enemigos izquierda) * ESCALA_FONDO (para que entren mas enemigos en el nivel)
static constexpr int ANCHO_FONDO = 4000*2*ESCALA_FONDO;

static constexpr int CANTIDAD_NIVELES = 2;
static constexpr int TIEMPO_FIN_NIVEL = 120; // 2 SEGUNDOS --> 2 * 60 fps

static const std::string PRE_POSICION_VENTANA = "Pos_Ventana";
static const std::string PRE_NIVEL_INICIAR = "Nivel_iniciar";
static const std::string PRE_NIVEL_FINALIZAR = "Nivel_finalizar";
static const std::string PRE_NIVEL_NUM = "Nivel";


static std::string PRE_JUGADOR1 = "1";
static std::string PRE_JUGADOR2 = "2";


/// PERSONAJE ///
static constexpr int INCREMENTO_PERSONAJE = 6;
static constexpr int X_PERSONAJE_DEFAULT = ANCHO_FONDO/2;
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

static const Posicion POS_ARRIBA_IZQ = Posicion(-0.707, -0.707);
static const Posicion POS_ARRIBA_DER = Posicion(0.707, -0.707);
static const Posicion POS_ABJAJO_IZQ = Posicion(-0.707, 0.707);
static const Posicion POS_ABAJO_DER = Posicion(0.707, 0.707);
static const Posicion POS_ARRIBA = Posicion(0,-1);
static const Posicion POS_IZQUIERDA = Posicion(-1,0);
static const Posicion POS_ABAJO = Posicion(0, 1);
static const Posicion POS_DERECHA = Posicion(1, 0);
static const Posicion POS_NINGUNA = Posicion(0, 0);
static const Posicion POS_DERECHA_FONDO = Posicion(DESPLAZAMIENTO_FONDO, 0);


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

/*
 * Calculo de la cantidad maxima de enemigos posibles a colocar
 * Se calcula como la superficie del fondo dividido por la superficie del enemigo que mas tamaño ocupa.
 * Este resultado seria el maximo posible, para que quede espacio para el personaje y poder moverse
 * se lo divide por 10.
 */
static const std::string CANTIDAD_ENEMIGO_MAX = std::to_string(
        (ANCHO_FONDO * ALTO_VENTANA / (ANCHO_TIPO_ENEMIGO_4 * ANCHO_TIPO_ENEMIGO_4)) / 10);


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

static std::vector<std::string> tipos_enemigos = { TIPO_VALIDO_ENEMIGO_1,
                                                   TIPO_VALIDO_ENEMIGO_2,
                                                   TIPO_VALIDO_ENEMIGO_3,
                                                   TIPO_VALIDO_ENEMIGO_4,
                                                   TIPO_VALIDO_ENEMIGO_DEFAULT};


/// EXCEPCIONES ///

static const std::string EXCEPCION_ERROR_CONEXION;

#endif //SERVIDOR_CONSTANTES_H
