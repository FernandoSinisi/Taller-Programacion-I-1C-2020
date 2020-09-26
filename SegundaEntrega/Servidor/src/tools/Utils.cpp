#include "Utils.h"
#include "Constantes.h"
#include "Log.h"

void obtenerRandom(int *pos) {
    do {
        //Pos[0] = [240 .. (ANCHO_FONDO -10)]
        //Pos[1] = [10 .. (ANCHO_VENTANA - 70)]
        pos[0] = (rand() % (ANCHO_FONDO - 250)) + 240;
        pos[1] = (rand() % (ALTO_VENTANA - 80)) + 10;

        //Hago que las posiciones se repartan a lo largo de toodo el fondo pero que esten separados una distancia
        //en el eje x igual a ancho_ventana en ambas direcciones al jugador
    } while (pos[0] > (ANCHO_FONDO)/2 - ANCHO_VENTANA and pos[0] < ANCHO_FONDO/2 + ANCHO_VENTANA);
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
    return (std::find(tipos_enemigos.begin(), tipos_enemigos.end(), std::string(tipo)) != tipos_enemigos.end());
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



bool verificadorUsuario(char *usuario){
    size_t len = strlen(usuario);
    std::string msg_err = "";
    if (len > MAX_LEN_USER or len <= 0) {
        msg_err = LOG_ERROR_LONGITUD_USUARIO + std::string(usuario);
        loguearError(msg_err);
        return false;
    }
    std::vector<std::string> nombres_usuarios = getNombresUsuarios();
    if (std::find(nombres_usuarios.begin(), nombres_usuarios.end(), std::string(usuario)) != nombres_usuarios.end()) {
        msg_err = LOG_ERROR_USUARIO_REPETIDO + std::string(usuario);
        loguearError(msg_err);
        return false;
    }
    return true;
}

bool verificadorPass(char *pass){
    size_t len = strlen(pass);
    std::string msg_err = "";
    //std::cout << "pass: " << std::string(pass) << std::endl;
    //std::cout << "long pass: " << len << std::endl;
    if (len > MAX_LEN_PASS or len <= 0) {
        msg_err = LOG_ERROR_LONGITUD_PASS + std::string(pass);
        loguearError(msg_err);
        return false;
    }
    return true;
}

bool esUsuarioValido(std::string nombre, std::string pass){
    std::vector<std::string> nombres = getNombresUsuarios();
    std::vector<std::string> passwords = getPasswords();
    auto pos = std::find(nombres.begin(), nombres.end(), nombre);
    if(pos != nombres.end()){
        long int pos_int = std::distance(nombres.begin(), pos);
        return passwords[(unsigned long)pos_int].compare(pass) == 0;
    }
    return false;
}



