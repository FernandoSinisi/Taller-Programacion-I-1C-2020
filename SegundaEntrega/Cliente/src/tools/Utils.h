#ifndef PRIMERAENTREGA_UTILS_H
#define PRIMERAENTREGA_UTILS_H

#include "Constantes.h"
#include <cstdlib>
#include <ctime>

void obtenerRandom(int *pos);

bool verificarTipoDeLog(char *log_recibido);

bool numeroValido(char *numero_ingresado);

bool tipoEnemigoValido(char *tipo);

bool existeArchivo(char *nombre);

std::string obtenerLineaDeError(std::string error);


#endif //PRIMERAENTREGA_UTILS_H
