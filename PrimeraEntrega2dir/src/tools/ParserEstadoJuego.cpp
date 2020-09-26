#include "ParserEstadoJuego.h"
#include "Constantes.h"
#include <string>
#include <vector>

std::vector<int> parserRespuestaPersonajePosicion(std::string estado) {
    std::vector<int> res;
    std::istringstream iss(estado);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                     std::istream_iterator<std::string>());

    for(unsigned long i = 1; i< results.size(); i++){
        res.push_back((int)std::stof(results[i]));
    }
    return res;
}

std::vector<int> parserRespuestaEnemigoPosicion(std::string estado) {
    std::vector<int> res;
    std::istringstream iss(estado);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                     std::istream_iterator<std::string>());

    for(unsigned long i = 3; i< 6; i++){
        res.push_back((int)std::stof(results[i]));
    }
    return res;
}

std::string parserTipoRespuesta(std::string estado) {
    std::istringstream iss(estado);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                     std::istream_iterator<std::string>());

    return results[0];
}

int parserRespuestaEnemigo(std::string estado) {
    std::istringstream iss(estado);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                     std::istream_iterator<std::string>());

    return (int)std::stof(results[1]);
}

bool parserRespuestaEnemigoActivo(std::string estado){
    std::istringstream iss(estado);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                     std::istream_iterator<std::string>());
    return  results[2] == "1";
}

int parserRespuestaVentanaPosicion(std::string estado){
    std::istringstream iss(estado);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                     std::istream_iterator<std::string>());

    return (int)std::stof(results[1]);
}