#ifndef SERVIDOR_UTILS_H
#define SERVIDOR_UTILS_H

#include <string>

void obtenerRandom(int *pos);

bool verificarTipoDeLog(char *log_recibido);

bool numeroValido(char *numero_ingresado);

bool tipoEnemigoValido(char* tipo);

bool existeArchivo(char *nombre);

std::string obtenerLineaDeError(std::string error);

bool verificadorPass(char *pass);

bool verificadorUsuario(char *usuario);

bool esUsuarioValido(std::string nombre, std::string pass);



#endif //SERVIDOR_UTILS_H
