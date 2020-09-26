#ifndef SERVIDOR_HILOACEPTADOR_H
#define SERVIDOR_HILOACEPTADOR_H


#include <mutex>
#include "../modelo/Servidor.h"
#include "Hilo.h"
#include "../modelo/Cliente.h"

class HiloAceptador : public Hilo {

private:
    std::vector<Cliente*> *clientes;
    std::mutex *mutex;
    Servidor *servidor;
    ColaProtegida<uint16_t>* cola_recibir;
    ColaProtegida<Cliente*>* cola_clientes_aceptados;

public:
    HiloAceptador(std::vector<Cliente*> *c,std::mutex *mutex_peers, Servidor *s, ColaProtegida<uint16_t>* cola_inputs);

    void ejecutar();

    void matar();

    bool estaActivo();

    void protocoloAceptar();

    ~HiloAceptador();

};


#endif //SERVIDOR_HILOACEPTADOR_H
