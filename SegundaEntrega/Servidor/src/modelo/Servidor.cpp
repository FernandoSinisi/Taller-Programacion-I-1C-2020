#include "Servidor.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <cstdint>
#include <string>
#include <iostream>
#include <algorithm>
#include <errno.h>
//#include <string.h>
#include "../tools/Constantes.h"
#include "../tools/Log.h"

Servidor::Servidor() {
    this->fd = FD_DEFECTO;
    this->puerto = new char[getPuerto().size() + 1]; //Puerto va a ser un numero entre 1025 y 7025, es decir que con 4 caracteres me alcanza
    for (long unsigned i = 0; i <= getPuerto().size(); ++i) {
        ((char*)(this)->puerto)[i] = '\0';
    }
    std::strncpy((char *)this->puerto, getPuerto().c_str(), getPuerto().size());
    ((char*)(this)->puerto)[getPuerto().size()] = '\0';
}

void Servidor::inicializar() {
    try {
        int contador = 0;
        this->fd = Servidor::bind(this->puerto);
        int num = (((std::atoi(getPuerto().c_str()) + FIX_PUERTO_SUCIO) % 6000) + 1025);
        std::string puerto_alternativo = std::to_string(num);
        while (this->fd == -1){
            std::this_thread::sleep_for(std::chrono::milliseconds(MILISEG_COLA_VACIA));
            if (contador == CANTIDAD_REINTENTOS_RECONEXION)  {
                puerto_alternativo = getPuerto();
                contador = 0;
            }
            std::strncpy((char *)this->puerto, puerto_alternativo.c_str(), puerto_alternativo.size());
            ((char*)(this)->puerto)[puerto_alternativo.size()] = '\0';
            loguearInfo(LOG_MSJ_BIND + std::string(this->puerto));
            this->fd = Servidor::bind(this->puerto);
            if (this->fd == -1) {
                contador++;
                num = (((std::atoi(puerto_alternativo.c_str()) + FIX_PUERTO_SUCIO) % 6000) + 1025);
                puerto_alternativo = std::to_string(num);
            }
        }
        loguearInfo(LOG_MSJ_PUERTO + std::string(this->puerto));

        Servidor::listen();

    } catch (std::string &error_desc) {
        throw "ERROR en inicializar";
    }
}

int Servidor::bind(const char *&port) {
    struct addrinfo hints;
    struct addrinfo *res;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;            /* IPv4 */
    hints.ai_socktype = SOCK_STREAM;    /* TCP */
    hints.ai_flags = AI_PASSIVE;        /* Para que sea servidor */
    int aux = getaddrinfo(NULL, port, &hints, &res);

    if (aux != 0) {
        throw ("ERROR EN SERVER BIND, getaddrinfo: " + std::string(::gai_strerror(aux)) + "\n");
    }

    int socket_fd;
    bool socket_conectado = false;
    struct addrinfo *ptr;

    for (ptr = res; ptr != NULL and !socket_conectado; ptr = ptr->ai_next) {
        /*  Creamos el socket definiendo la familia (deberia ser AF_INET IPv4),
         *  el tipo de socket (deberia ser SOCK_STREAM TCP) y el protocolo (AI_PASIVE)
         */
        socket_fd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

        if (socket_fd == -1) {
            loguearError(LOG_ERROR_BIND_1);
        } else {
            aux = ::bind(socket_fd, ptr->ai_addr, ptr->ai_addrlen);

            if (aux == -1) {
                loguearError(LOG_ERROR_BIND_2);
                Servidor::cerrar(socket_fd);
            }

            socket_conectado = (aux != -1);
        }
    }

    /* Finalmente, la **lista** de direcciones debe ser liberada */
    ::freeaddrinfo(res);

    if (socket_conectado) {
        return socket_fd;
    }

    return -1;
}

void Servidor::listen() {
    int aux = ::listen(this->fd, 0); //Puede tener hasta 1 (0+1) clientes en espera antes del accept

    if (aux == -1) {
        Servidor::cerrar(this->fd);
        throw ("ERROR: SERVER LISTEN, error " + std::string(strerror(errno)) + "\n");
    }
}

int Servidor::seleccionarCliente() {
    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = MICROSEGUNDOS_TIMEOUT;
    fd_set set;
    FD_ZERO(&set);
    FD_SET(this->fd, &set);
    return ::select(FD_SETSIZE, &set, NULL, NULL, &timeout);
}

int Servidor::aceptarCliente() {
    int peer_socket_fd = ::accept(this->fd, NULL, NULL);

    if (peer_socket_fd == FD_DEFECTO) {
        //loguearError(LOG_ERROR_ACEPTAR_CLIENTE);

    } else {
        loguearInfo(LOG_CLIENTE_CONECTADO);
        int flags = 1;
        setsockopt(peer_socket_fd, IPPROTO_TCP, TCP_NODELAY, (void *)&flags, sizeof(flags));
    }

    return peer_socket_fd;
}

int Servidor::recibirMensajeCliente(int peer_fd, void *buffer) {
    long int longitud_msg = sizeof(std::uint16_t);
    bool socket_conectado = true;
    long int recv_bytes_total = 0;
    long int recv_bytes = 0;

    while (socket_conectado and (recv_bytes_total < longitud_msg)) {
        recv_bytes = ::recv(peer_fd, &((char *) buffer)[recv_bytes_total],
                            (size_t)(longitud_msg - recv_bytes_total), 0);

        //Si recv_bytes es -1 o 0 entonces el cliente se desconecto (por ejemplo tiro del cable)
        if (recv_bytes <= 0) {
            socket_conectado = false;

        } else {
            recv_bytes_total += recv_bytes;
        }
    }

    if (socket_conectado) {
        return (int) recv_bytes_total;
    }

    return (int) recv_bytes;
}

long int Servidor::enviarMensajeCliente(int peer_fd, void *msg, long unsigned int size) {
    long int bytes_sent;
    bool socket_conectado = true;
    long unsigned int bytes_sent_total = 0;
    while (bytes_sent_total < size and socket_conectado) {
        bytes_sent = ::send(peer_fd, &((char *) msg)[bytes_sent_total],
                            size - bytes_sent_total, MSG_NOSIGNAL);
        //Si bytes_sent es negativo entonces el cliente se desconecto
        if (bytes_sent <= 0) {
            socket_conectado = false;
            bytes_sent_total = 0;

        } else {
            bytes_sent_total += (unsigned long)(bytes_sent);
        }
    }

    return (long)(bytes_sent_total);
}

void Servidor::apagar(int peer_fd) {
    if (peer_fd != -1) {
        ::shutdown(peer_fd, SHUT_RDWR);
        this->cerrar(peer_fd);
    }
}


void Servidor::apagar() {
    if (this->fd != -1){
        ::shutdown(this->fd, SHUT_RDWR);
        this->cerrar(this->fd);
        this->fd = -1;
    }
}

void Servidor::cerrar(int sock_fd) {
    if (sock_fd != -1) {
        int close_resultado = ::close(sock_fd);
        if (close_resultado == -1) {
            throw "ERROR: CIERRE SERVER";
        }
    }
}

Servidor::~Servidor() {
    /*Cierro el socket aceptador*/
    if (this->fd != -1) {
        this->apagar();
    }
    delete(this->puerto);
}

bool Servidor::esta_prendido() {
    return this->fd != -1;
}

