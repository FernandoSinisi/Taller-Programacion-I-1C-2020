#include "Utils.h"

/*
 * La posicion en x tiene que ser entre 240 y 3990
 * La posicion en y tiene que ser un numero entre 10 y 520
 */
void obtenerRandom(int *pos) {
    pos[0] = (rand() % (ANCHO_FONDO - 250)) + 240;
    pos[1] = (rand() % (ALTO_VENTANA - 80)) + 10;
}

bool verificarTipoDeLog(char *log_recibido) {
    return strcmp(log_recibido, MSJ_LOG_DEBUG) == 0 ||
           strcmp(log_recibido, MSJ_LOG_INFO) == 0 ||
           strcmp(log_recibido, MSJ_LOG_ERROR) == 0;
}

bool numeroValido(char *numero_ingresado) {
    char *p;
    long resultado = strtol(numero_ingresado, &p, 10);
    if (resultado < 0)
        return false;
    return *p == 0;
}

bool tipoEnemigoValido(char* tipo) {
    return tipos_enemigos_imagen.find(std::string(tipo)) != tipos_enemigos_imagen.end();
}

std::string obtenerLineaDeError(std::string error) {
    std::string::size_type pos = error.find(',');
    if (pos != std::string::npos) {
        return error.substr(0, pos).replace(0, 7, " ");
    } else {
        return error;
    }
}

bool existeArchivo(char *nombre) {
    std::ifstream f(nombre);
    return f.good();
}


