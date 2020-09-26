#ifndef SERVIDOR_CARGADORDECONFIGURACION_H
#define SERVIDOR_CARGADORDECONFIGURACION_H

#include <jsoncpp/json/json.h>

class CargadorDeConfiguracion {

public:
    void cargar(int argc, char* argv[]);

    static void manejoDeSet(char *valor_res, char *valor_default, bool arch_local ,
                            void(*funcion_set)(std::string), bool(*funcion_verificar)(char*), char* ERROR_CASO_RES, char* ERROR_CASO_DEFAULT);

    bool corregirCantidadEnemigos(int* cant_enemigo_1, int* cant_enemigo_2);

};

#endif //SERVIDOR_CARGADORDECONFIGURACION_H
