#include "src/controller/JuegoControlador.h"
#include "src/tools/Log.h"
#include "src/tools/Constantes.h"

int main(int argc, char *argv[]) {
    JuegoControlador *juego = new JuegoControlador(argc, argv);

    if (juego->inicializar()) {
        while (juego->estaActivo()) {
            juego->actualizar();
        }
    }

    delete (juego);
    return 0;
}