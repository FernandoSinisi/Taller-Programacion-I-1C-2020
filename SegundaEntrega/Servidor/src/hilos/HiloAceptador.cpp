#include <vector>
#include "HiloAceptador.h"
#include "../tools/Constantes.h"
#include "../tools/Log.h"

HiloAceptador::HiloAceptador(std::vector<Cliente*> *c, std::mutex *mutex_peers, Servidor *s, ColaProtegida<uint16_t>* recibir) :
        clientes{c},
        mutex{mutex_peers},
        servidor{s},
        cola_recibir{recibir}
        {
}

void HiloAceptador::ejecutar() {
    if (!this->estaActivo()) {
        this->hilo = std::thread(&HiloAceptador::protocoloAceptar, this);
    }
}

void HiloAceptador::matar() {
    if(this->estaActivo()){
        this->mutex->lock();
        this->servidor->apagar();
        this->mutex->unlock();
        this->hilo.join();
    }
}

bool HiloAceptador::estaActivo() {
    return this->hilo.joinable();
}

void HiloAceptador::protocoloAceptar() {
    int fd;
    ColaProtegida<std::string> *cola_send = nullptr;
    HiloRecibir *hr = nullptr;
    HiloEnviar *he = nullptr;
    Cliente* cliente_nuevo = nullptr;
    while (this->servidor->esta_prendido()) {
        fd = this->servidor->aceptarCliente();
        this->mutex->lock();
        if ( fd != -1 and this->clientes->size() < (CANT_CONEXIONES_MAX - 2*N_JUGADORES_MAX - 1) ){
            int cant_listos = 0;
            for(auto &c: *(this->clientes)){
                if(c->estaListo()){
                    cant_listos++;
                }
            }
            cola_send = new ColaProtegida<std::string>();
            hr = new HiloRecibir(this->cola_recibir, this->servidor);
            he = new HiloEnviar(cola_send, this->servidor);
            cliente_nuevo = new Cliente(fd, hr, he, cola_send);
            if(cant_listos >= (int) getCantidadUsuarios()){
                //Lo desbloqueo para que no se trabe el juego y al final del if lo vuelvo a bloquear para evitar inconsistencias
                this->mutex->unlock();
                //Le mando el mensaje al cliente de que el server esta lleno
                cliente_nuevo->enviarMensaje(MSJ_SERVER_LLENO);
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
                delete(cliente_nuevo);
                loguearDebug(LOG_CLIENTE_DE_MAS_BORRADO);
                this->mutex->lock();
            } else {
                this->clientes->emplace_back(cliente_nuevo);
            }

        }
        else{
            if(fd != -1) {
                this->servidor->apagar(fd);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds (500));
        }
        mutex->unlock();
    }
}

HiloAceptador::~HiloAceptador() {
    this->matar();

}
