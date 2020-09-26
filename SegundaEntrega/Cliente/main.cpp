#include <iostream>
#include "src/controlador/ControladorCliente.h"
#include "src/tools/Constantes.h"

int main(int argc, const char* argv[]) {
    setFin(false);
    ControladorCliente* cliente = new ControladorCliente(argc, argv);
    while(!getFin()){
        if (cliente->iniciar()) {
            while (cliente->estaActivo()) {
                cliente->actualizar();
            }
        }
        // fin en falso     -> reset
        // fin en verdadero -> cerrarse
        if(!getFin()){
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, MSJ_FIN,
                                     MSJ_ACLARACION_FIN, NULL);
            loguearError(MSJ_ACLARACION_FIN);
            cliente->reiniciar();
        }
    }
    delete (cliente);
    return 0;
}


