#include "Constantes.h"

static std::string RUTA_CONFIG;

static std::string ip_servidor;
static std::string puerto_servidor;

static int ANCHO_ENEMIGO_1;
static int ALTO_ENEMIGO_1;
static int ANCHO_ENEMIGO_2;
static int ALTO_ENEMIGO_2;
static int TAM_ANCHO_ENEMIGO_1;
static int TAM_ANCHO_ENEMIGO_2;
static int TAM_ALTO_ENEMIGO_1;
static int TAM_ALTO_ENEMIGO_2;
static std::string TIPO_ENEMIGO_1;
static std::string TIPO_ENEMIGO_2;

static std::string RUTA_FONDO_1_1;
static std::string RUTA_FONDO_1_2;
static std::string RUTA_FONDO_1_3;
static std::string RUTA_FONDO_1_4;
static std::string RUTA_FONDO_1_5;
static std::string RUTA_FONDO_1_6;
static std::string RUTA_FONDO_2_1;
static std::string RUTA_FONDO_2_2;
static std::string RUTA_FONDO_2_3;
static std::string RUTA_FONDO_2_4;
static std::string RUTA_FONDO_2_5;
static std::string RUTA_FONDO_2_6;

static std::string RUTA_IMAGEN_ENEMIGO_1;
static std::string RUTA_IMAGEN_ENEMIGO_2;

static bool fin;

void setFin(bool f){
    fin = f;
}

bool getFin(){
    return fin;
}


void setRutaConfig(std::string ruta){
    RUTA_CONFIG = ruta;
}

char* getRutaConfig(){
    return (char*) RUTA_CONFIG.c_str();
}

void setIP(std::string ip){
    ip_servidor = ip;
}

char* getIPServidor() {
    return (char*) ip_servidor.c_str();
}

const char* getIPServidorCte() {
    return ip_servidor.c_str();
}


void setPuerto(std::string puerto){
    if (std::strtol(puerto.c_str(), NULL, 10) > 1024
    && std::strtol(puerto.c_str(),  NULL, 10) < 65536) {
        puerto_servidor = puerto;
    }
}

char* getPuertoServidor() {
    return (char*) puerto_servidor.c_str();
}

const char* getPuertoServidorCte() {
    return puerto_servidor.c_str();
}


void setTipoEnemigo1(std::string tipo) {
    TIPO_ENEMIGO_1 = tipo;
    RUTA_IMAGEN_ENEMIGO_1 = tipos_enemigos_imagen[tipo];
    ANCHO_ENEMIGO_1 = (int) anchos_enemigo[tipo];
    ALTO_ENEMIGO_1 = (int) altos_enemigos[tipo];
    TAM_ALTO_ENEMIGO_1 = (int) tam_altos_enemigos[tipo];
    TAM_ANCHO_ENEMIGO_1 = (int) tam_anchos_enemigos[tipo];
}

void setTipoEnemigo2(std::string tipo) {
    TIPO_ENEMIGO_2 = tipo;
    RUTA_IMAGEN_ENEMIGO_2 = tipos_enemigos_imagen[tipo];
    ANCHO_ENEMIGO_2 = (int) anchos_enemigo[tipo];
    ALTO_ENEMIGO_2 = (int) altos_enemigos[tipo];
    TAM_ALTO_ENEMIGO_2 = (int) tam_altos_enemigos[tipo];
    TAM_ANCHO_ENEMIGO_2 = (int) tam_anchos_enemigos[tipo];
}

std::string getTipoEnemigo1() {
    return TIPO_ENEMIGO_1;
}

std::string getTipoEnemigo2() {
    return TIPO_ENEMIGO_2;
}

void setRutaFondo11(std::string ruta) {
    RUTA_FONDO_1_1 = ruta;
}

char *getRutaFondo11() {
    return (char *) RUTA_FONDO_1_1.c_str();
}

void setRutaFondo12(std::string ruta) {
    RUTA_FONDO_1_2 = ruta;
}

char *getRutaFondo12() {
    return (char *) RUTA_FONDO_1_2.c_str();
}

void setRutaFondo13(std::string ruta) {
    RUTA_FONDO_1_3 = ruta;
}

char *getRutaFondo13() {
    return (char *) RUTA_FONDO_1_3.c_str();
}

void setRutaFondo14(std::string ruta) {
    RUTA_FONDO_1_4 = ruta;
}

char *getRutaFondo14() {
    return (char *) RUTA_FONDO_1_4.c_str();
}

void setRutaFondo15(std::string ruta) {
    RUTA_FONDO_1_5 = ruta;
}

char *getRutaFondo15() {
    return (char *) RUTA_FONDO_1_5.c_str();
}

void setRutaFondo16(std::string ruta) {
    RUTA_FONDO_1_6 = ruta;
}

char *getRutaFondo16() {
    return (char *) RUTA_FONDO_1_6.c_str();
}

void setRutaFondo21(std::string ruta) {
    RUTA_FONDO_2_1 = ruta;
}

char *getRutaFondo21() {
    return (char *) RUTA_FONDO_2_1.c_str();
}

void setRutaFondo22(std::string ruta) {
    RUTA_FONDO_2_2 = ruta;
}

char *getRutaFondo22() {
    return (char *) RUTA_FONDO_2_2.c_str();
}

void setRutaFondo23(std::string ruta) {
    RUTA_FONDO_2_3 = ruta;
}

char *getRutaFondo23() {
    return (char *) RUTA_FONDO_2_3.c_str();
}

void setRutaFondo24(std::string ruta) {
    RUTA_FONDO_2_4 = ruta;
}

char *getRutaFondo24() {
    return (char *) RUTA_FONDO_2_4.c_str();
}

void setRutaFondo25(std::string ruta) {
    RUTA_FONDO_2_5 = ruta;
}

char *getRutaFondo25() {
    return (char *) RUTA_FONDO_2_5.c_str();
}

char *getRutaFondo26() {
    return (char *) RUTA_FONDO_2_6.c_str();
}

void setRutaFondo26(std::string ruta) {
    RUTA_FONDO_2_6 = ruta;
}

char *getRutaImagenEnemigo1() {
    return (char *) RUTA_IMAGEN_ENEMIGO_1.c_str();
}

char *getRutaImagenEnemigo2() {
    return (char *) RUTA_IMAGEN_ENEMIGO_2.c_str();
}

int getAnchoEnemigo1() {
    return ANCHO_ENEMIGO_1;
}

int getAnchoEnemigo2() {
    return ANCHO_ENEMIGO_2;
}

int getAltoEnemigo1() {
    return ALTO_ENEMIGO_1;
}

int getAltoEnemigo2() {
    return ALTO_ENEMIGO_2;
}

int getTamAnchoEnemigo1() {
    return TAM_ANCHO_ENEMIGO_1;
}

int getTamAnchoEnemigo2() {
    return TAM_ANCHO_ENEMIGO_2;
}

int getTamAltoEnemigo1() {
    return TAM_ALTO_ENEMIGO_1;
}

int getTamAltoEnemigo2() {
    return TAM_ALTO_ENEMIGO_2;
}

std::string usuario;
std::string pass;
std::string pass_asteriscos;

void setUsuario(std::string n, bool trim){
    usuario = n;

    if(trim){
        usuario.pop_back();
    }
}

char *getUsuario(){
    return (char *) usuario.c_str();
}

void setPass(std::string n, bool trim){
    pass = n;
    pass_asteriscos = "";

    for(size_t i = 0; i < pass.size(); i++){
        pass_asteriscos += "*";
    }

    if(trim){
        pass.pop_back();
        pass_asteriscos.pop_back();
    }
}

char *getPass(){
    return (char *) pass.c_str();
}

char *getPassAsteriscos(){
    return (char *)pass_asteriscos.c_str();
}

