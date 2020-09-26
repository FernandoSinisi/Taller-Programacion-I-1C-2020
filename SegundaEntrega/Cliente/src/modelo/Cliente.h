#ifndef CLIENTE_CLIENTE_H
#define CLIENTE_CLIENTE_H

#include <string>
#include <cstdint>

class Cliente{
private:
    int fd;
    bool esta_conectado;

public:
    Cliente();
    ~Cliente();

    int getFd();
    void conectarse(const char* host, const char* puerto);
    void setIsConnected(bool conectado);
    bool estaActivo();
    void cerrarConexion();

    //Devuelve cuantos bytes se recibieron del buffer, 0 si hubo desconexion o
    //lanza excepcion (string) en caso de error
    int recibir(void* buffer);

    //Carga en el buffer "amount_of_bytes" la cantidad de bytes del mensaje que
    //el Clientee le manda al servidor. (Protocolo: se manda la cantidad de bytes
    //del mensaje y luego el mensaje en cuestion, esta funcion es llamada por recibir)
    //Devuelve true si todavia hay conexion entre el Clientee y el servidor, false
    //si se cerro la conexion o lanza excepcion (string) en caso de error
    int bytesARecibir(void* bytes);

    //Devuelve cuantos bytes se enviaron al Cliente, 0 si hubo desconexion o
    //lanza excepcion (string) en caso de error
    long int enviar(uint16_t* msg);
};


#endif //CLIENTE_CLIENTE_H
