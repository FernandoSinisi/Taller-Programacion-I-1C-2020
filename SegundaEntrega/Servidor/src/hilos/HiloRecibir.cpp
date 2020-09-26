#include "HiloRecibir.h"
#include "../tools/Constantes.h"
#include "../tools/Log.h"
#include <cstdint>
#include <netinet/in.h>
#include <iostream>

HiloRecibir::HiloRecibir(ColaProtegida<uint16_t>* cola_inputs, Servidor* s)
                :cola{cola_inputs},
                servidor{s} {
    //El mutex se inicializa implicitamente en el stack
}

void HiloRecibir::ejecutar(){
    if (!this->estaActivo()) {
        this->hilo = std::thread(&HiloRecibir::protocolRecv, this);
    }
}

int HiloRecibir::getNroCliente(){
    return this->n_cliente;
}

int HiloRecibir::getFD(){
    return *(this->fd);
}

void HiloRecibir::matar(){
    this->apagarFD();
    if (this->estaActivo()){
        this->hilo.join();
    }
}

bool HiloRecibir::estaActivo(){
    return this->hilo.joinable();
}


//Va a recibir numeros (unsigned short 16) del fd y los va a pushear a la cola hasta recibirListo un 0 (desconexion)
void HiloRecibir::protocolRecv(){
    uint16_t num[1] {0};
    while(this->servidor->recibirMensajeCliente(*(this->fd), num) == (int)sizeof(uint16_t)) {
        *num = ntohs(*num);
        /* Lo que se recibe del cliente se multiplica por 4 antes de encolarse.
         *
         * De esta forma, como los números de cliente asignados después de la fase
         * inicial son números del 0 al 9, entonces haciendo:
         *
         * mensaje mod 10
         *
         * se obtiene el número de cliente que mandó ese mensaje, lo cual sirve en el
         * actualizar para poder impactar los cambios del modelo recibidos por el servidor
         * en lo que el cliente visualiza.
         *
         * */
        *num =(uint16_t)(((int) *num * CANT_CONEXIONES_MAX ) + this->n_cliente % CANT_CONEXIONES_MAX);
        this->cola->encolar(*num);
    }

    this->apagarFD();
}

void HiloRecibir::asignarNroCliente(int nro_cliente) {
    this->n_cliente = nro_cliente;
}

void HiloRecibir::apagarFD(){
    this->mutex.lock();

    if (*this->fd != -1) {
        //Si el fd no es -1 entonces tomo el control del mutex para que no modifiquen el valor del fd
        //por fuera de este metodo y poder apagarlo correctamente.
        this->cola->encolar((std::uint16_t) this->n_cliente);
        this->servidor->apagar(*(this->fd));
        loguearDebug(LOG_CLIENTE_CERRADO + std::to_string(*(this->fd)) );
        *(this->fd) = -1;
    }

    this->mutex.unlock();
}

void HiloRecibir::setFD(int *peer) {
    this->fd = peer;
    this->n_cliente = *peer + N_JUGADORES_MAX;
}

HiloRecibir::~HiloRecibir(){
    this->apagarFD();
    if (this->estaActivo()) {
        this->matar();
    }
}

