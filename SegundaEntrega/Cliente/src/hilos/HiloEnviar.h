#ifndef CLIENTE_HILOENVIAR_H
#define CLIENTE_HILOENVIAR_H

#include "Hilo.h"
#include "ColaProtegida.h"
#include "../controlador/ControladorCliente.h"

class ControladorCliente;
class HiloEnviar : public Hilo {

    //QUE HAGA ALGO PARECIDO AL HILO RECV PERO QUE DESACOLE DE LA COLA DE INPUTS DEL CONTROLADOR CLIENTE
    //CON EL METODO DESACOLAR_BLOQUEANTE DE LA COLA PROTEGIDA Y DESPUES MANDE LO DESACOLADO AL SERVIDOR

    //UNA FORMA DE HACER EL METODO MATAR SERIA COMO EN EL SERVIDOR, QUE LE ACOLAS ALGUN VALOR ESPECIFICO QUE CUANDO
    //LO DESACOLES TE DES CUENTA QUE TENES QUE SALIR DE LA FUNCION DE PROTOCOLO_ENVIAR

    //HAY QUE AGREGAR LOS OBJETOS HILOS EN EL CONTROLADOR_CLIENTE (AL PRINCIPIO COMO ATRIBUTOS, PERO SE DEFINEN DESPUES
    // DE HACER EL NEW CLIENTE (EN LA FUNCION INICIALIZAR DEL CLIENTE CONTROLADOR)
    //HABRIA QUE AGREGAR TAMBIEN QUE EN EL DESTRUCTOR DEL CONTROLADOR CLIENTE LE LLAME AL METODO MATAR DE LOS HILOS
    //PARA QUE TERMINE SU EJECUCION EN CASO DE QUE ESTEN ACTIVOS

    private:
        ColaProtegida<uint16_t>* cola;
        ControladorCliente* cliente;

    public:
        HiloEnviar(ColaProtegida<uint16_t>* q, ControladorCliente *c);
        ~HiloEnviar();

        void ejecutar();
        void matar();

        bool estaActivo();

        void inputEnviar();


};

/*hilo recibir, recibe el hilo desde el servidor el msj del tipo string y lo encola en una cola de msj, el cliente luego los desencola.
 * hilo enviar, desencolaBloqueante de la cola de inpus del tipo uint_16 y lo envia al servidor*/



#endif //CLIENTE_HILOENVIAR_H
