#ifndef CLIENTE_CARTEL_H
#define CLIENTE_CARTEL_H

#include <vector>
#include "../tools/Constantes.h"

class Cartel{
    private:
        int cartel_actual;
        int numero_actual;
        bool espera_input;
        std::vector<char*> carteles;

    public:
        explicit Cartel(std::vector<char*> carteles);
        virtual ~Cartel();

        void retrocederCartel();

        bool getEsperaInput();
        void setEsperaInput(bool espera);
        size_t getCartel();
        void setCartel(int nro_cartel);

        bool continuar(SDL_Event* evento);
        char* getCartelActual();
        int cambiar();

        size_t getNumeroActual();
        void proximoNumero();
        void iniciarNumero();

    bool esperaInput();
};

#endif //CLIENTE_CARTEL_H
