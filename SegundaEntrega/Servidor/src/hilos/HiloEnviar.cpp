#include "HiloEnviar.h"
#include "../tools/Constantes.h"
//#include <errno.h>
#include <sys/socket.h>
//#include <unistd.h>
#include <cstdint>
//#include <cstring>
#include <netdb.h>

#include <vector>
#include <iostream>


HiloEnviar::HiloEnviar(ColaProtegida<std::string> *q, Servidor *s)
        : cola_enviar{q},
          servidor{s} {

}

void HiloEnviar::ejecutar() {
    if (!this->estaActivo()) {
        this->hilo = std::thread(&HiloEnviar::sendProtocol, this);
    }
}

void HiloEnviar::matar() {
    if (this->estaActivo()) {
        this->cola_enviar->encolar("CLOSE");
        this->hilo.join();
    }
}

bool HiloEnviar::estaActivo() {
    return this->hilo.joinable();
}

void HiloEnviar::sendProtocol() {
    std::string msg = "";
    char send_msg[4096]{0}; //No le puedo mandar directamente el string, debo enviar array de chars
    std::uint16_t response_length = 0;
    std::uint16_t aux = 0;
    while (msg != "CLOSE" && *this->peer_fd != -1) {
        /* Esta seccion se puede cambiar por un pop de una cola distinta, una cola que sea de strings que el modelo
         * (otro hilo) se encargue de ir llenando conforme se vaya actualizando.
         */

        //============
        msg = this->cola_enviar->desencolar(MSJ_COLA_VACIA);
        while (msg == MSJ_COLA_VACIA) {
            std::this_thread::sleep_for(std::chrono::milliseconds(MILISEG_COLA_VACIA));
            msg = this->cola_enviar->desencolar(MSJ_COLA_VACIA);
        }

        std::copy(msg.begin(), msg.end(), (char *) send_msg);
        send_msg[msg.length()] = '\0';
        response_length = (std::uint16_t) msg.length();
        //============

        aux = ::htons((uint16_t) msg.length());
        if (*this->peer_fd != -1 and msg != MSJ_COLA_VACIA) {
            //Riesgo potencial de race condition: el hilo recibir me setea el fd en -1 CUANDO YA ENTRÉ A ESTE MÉTODO...
            // lo que pasaría es que se le intentaría
            //enviar a un fd inválido un mensaje, y ese intento fallaría.
            // No es ningun problema grave...

            this->servidor->enviarMensajeCliente(*(this->peer_fd), &aux, sizeof(response_length));
            this->servidor->enviarMensajeCliente(*(this->peer_fd), send_msg, response_length);
            //this->send(*this->peer_fd, &aux, sizeof(response_length));
            //this->send(*this->peer_fd, send_msg, response_length);
        }
    }
}

HiloEnviar::~HiloEnviar() {
    if (this->estaActivo()) {
        this->matar();
    }
}

void HiloEnviar::setFD(int *peer) {
    this->peer_fd = peer;
}
