#include "src/controlador/ControladorServidor.h"
#include "src/tools/Constantes.h"

void ejecutarJuego(int argc, char* argv[]){
    ControladorServidor servidor(argc, argv);
    servidor.inicializar();

    while(servidor.estaActivo()) {
        servidor.actualizar();
    }
}

int main(int argc, char* argv[]) {
    ejecutarJuego(argc, argv);
    return 0;
}
