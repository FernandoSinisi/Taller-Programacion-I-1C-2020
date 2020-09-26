#ifndef SERVIDOR_JUEGO_CONTROLADOR_H
#define SERVIDOR_JUEGO_CONTROLADOR_H

#include <string>
#include "../modelo/Juego.h"
#include "../tools/CargadorDeConfiguracion.h"

class JuegoControlador{

    private:
        Juego* juego;

    public:
        JuegoControlador(int n_clientes);
       ~JuegoControlador();

        //Juego* getJuego();

        bool estaActivo();
        void actualizar();
        void actualizar(uint16_t input);
        std::string getEstadoPersonajes();
        std::string getEstadoEnemigos();
        std::string getEstadoFondo();

        void conectar(int nro_cliente);
        void desconectar(int nro_cliente);

        bool nivelEmpezado();
        //bool avanzarNivel();
        int getNumeroNivel();
        void terminar();

        bool juegoFinalizado();

        void setNombreJugador(Uint16 n, std::string nombre);
        std::string getNombreJugador(Uint16 n);

    bool nivelFinalizado();
};

#endif //SERVIDOR_JUEGO_CONTROLADOR
