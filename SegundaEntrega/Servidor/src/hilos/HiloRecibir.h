//
// Created by nicolas on 19/4/20.
//

#ifndef SERVIDOR_HILORECIBIR_H
#define SERVIDOR_HILORECIBIR_H

#include "Hilo.h"
#include "ColaProtegida.h"
#include "../modelo/Servidor.h"
#include <mutex>

class HiloRecibir: public Hilo {
private:
    int *fd;
    int n_cliente;
    ColaProtegida<uint16_t>* cola;
    std::mutex mutex;
    Servidor* servidor;


public:
    HiloRecibir(ColaProtegida<uint16_t>* cola_inputs, Servidor* s);

    void ejecutar();

    void matar();

    bool estaActivo();

    //Va a recibir numeros (unsigned short 16) del fd y los va a pushear a la cola hasta recibirListo un 0 (desconexion)
    void protocolRecv();

    void asignarNroCliente(int nro_cliente);

    void apagarFD();

    int getFD();

    int getNroCliente();

    ~HiloRecibir();

    void setFD(int *fd);
};


#endif //SERVIDOR_HILORECIBIR_H
