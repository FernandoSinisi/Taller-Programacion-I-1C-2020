#ifndef SERVIDOR_CONTROLADORSERVIDOR_H
#define SERVIDOR_CONTROLADORSERVIDOR_H

#include <SDL2/SDL_stdinc.h>
#include "../modelo/Servidor.h"
#include "../controlador/JuegoControlador.h"
#include "../tools/Constantes.h"
#include "../hilos/HiloRecibir.h"
#include "../hilos/HiloEnviar.h"
#include "../hilos/ColaProtegida.h"
#include "../modelo/Cliente.h"
#include "../hilos/HiloAceptador.h"
#include <string.h>

class ControladorServidor {
private:
    //El modelo del servidor
    Servidor* socket_server;
    //Los FDs asociados a cada cliente conectado (Inicia con 4 FDs invalidos que van a ir siendo reemplazados conforme se van conectando)
    //std::vector<int> peers;

    //int n_clientes;
    JuegoControlador* juego_controlador;

    //Atributos usados para HILOS
    //std::vector<std::pair<HiloRecibir*, HiloEnviar*>> hilos_clientes;
    //Aca se van a guardar los inputs de cada cliente
    ColaProtegida<uint16_t> cola_recv;
    //Cada una de las colas de esta lista esta asociada con un cliente especifico, ahi se van a encolar los mensajes que se le quiera enviar


    //std::vector<ColaProtegida<std::string>*> colas_send;


    //TODO: De momento no se usa, eventualmente ver si conviene borrar este atributo
    //std::condition_variable cv;
    //Este mutex se usa para proteger el acceso al atributo peers (Lista de fds)
    std::mutex mutex;
    std::vector<Cliente*> clientes;
    HiloAceptador *hilo_aceptador;

    uint32_t fps; //Ver si aumento de segundo e imprimir cantidad de aumentos.
    bool nivel_principio;


public:
    //Crea el modelo del servidor pasandole el puerto y carga CANT_CONEXIONES_MAX valores "-1" en el atributo vector peers
    explicit ControladorServidor(int argc, char* argv[]);
    //Cierra los hilos que sigan corriendo y libera los recursos
    ~ControladorServidor();

    //Inicializa el modelo del servidor (bind y listen) y llama a aceptarCliente()
    void inicializar();
    //Mecanica de esperar a que se conecten la cantidad de clientes que quieran jugar antes de que pase un timeout y asignarles a cada uno un par de hilo send,receive
    void aceptarCliente();
    //(Llamada por aceptarCliente)
    //Llama a una funcion bloqueante aceptar (accept) del modelo para esperar a que se conecte el primer cliente y le asigna un hilo receive y un hilo send
    //void aceptarPrimerCliente();

    //(Llamada por aceptarCliente)
    //Crea un par de hilos send, recv que se le asignan al nuevo cliente conectado.
    void lanzarHilosCliente(int peer);

    //(Llamada por aceptarCliente)
    //Verifica en la cola de inputs si algun cliente mando TECLA_LISTO, en ese caso lo agrega al vector de listos y devuelve la cantidad de listos recibidos
    int recibirListo(std::vector<int>* jugadores_listos);

    //(Llamada por aceptarCliente)
    //Cierra los hilos de los clientes que se desconectaron, ademas borra del vector el fd de la lista de listos en caso de que el cliente hubiese ingresado que lo estaba
    int borrarDesconectados();


    void borrarNoListos();

    int actualizarDesconectados();

        //Verifica los inputs recibidos, actualiza el modelo del juego y le manda a los clientes mensajes que representan el estado del juego actual
    void actualizar();

    //Le envia a todos los clientes conectados el string recibido como argumento
    void enviarATodos(std::string mensaje);

    //Devuelve true en caso de que el modelo del juego este activo o si no se desconectaron TODOS los clientes, sino false
    bool estaActivo();

    //Popea los inputs de la cola_recv y se lo manda al modelo del juego para que actualice el estado de los personajes
    void actualizarInputs();

    //Recibe nombre y password del cliente
    int recibirInfoCliente();

    bool esValidoCliente(Cliente *cliente);

};


#endif //SERVIDOR_CONTROLADORSERVIDOR_H
