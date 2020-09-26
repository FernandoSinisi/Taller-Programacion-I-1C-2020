#ifndef SERVIDOR_HILOENVIAR_H
#define SERVIDOR_HILOENVIAR_H

#include "Hilo.h"
#include <condition_variable>
#include "ColaProtegida.h"
#include "../modelo/Servidor.h"

class HiloEnviar: public Hilo {

    int *peer_fd; //El fd de los clientes conectados
    ColaProtegida<std::string> *cola_enviar; //La cola en la que se van a encolar los inputs de los clientes
    Servidor* servidor;

public:
    HiloEnviar(ColaProtegida<std::string> *q, Servidor* s);

    void ejecutar();

    void matar();

    bool estaActivo();

    void sendProtocol();

    ~HiloEnviar();

    void setFD(int *peer);
};


#endif //SERVIDOR_HILOENVIAR_H
