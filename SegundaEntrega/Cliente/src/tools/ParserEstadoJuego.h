#ifndef PRIMERAENTREGA_PARSERESTADOJUEGO_H
#define PRIMERAENTREGA_PARSERESTADOJUEGO_H

#include <string>
#include <vector>

std::vector<int> parserRespuestaPersonajePosicion(std::string estado);
std::string parserTipoRespuesta(std::string estado);
bool parserRespuestaEnemigoActivo(std::string estado);
std::vector<int> parserRespuestaEnemigoPosicion(std::string estado);
int parserRespuestaEnemigo(std::string estado);
int parserRespuestaVentanaPosicion(std::string estado);

#endif //PRIMERAENTREGA_PARSERESTADOJUEGO_H
