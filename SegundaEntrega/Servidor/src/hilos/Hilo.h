//
// Created by nicolas on 19/4/20.
//

#ifndef SERVIDOR_HILO_H
#define SERVIDOR_HILO_H

#include <thread>

class Hilo {
    //Atributos que va a tener la clase que herede de thread
protected:
    std::thread hilo;

public:
    virtual void ejecutar() = 0;
    virtual void matar() = 0;
    virtual bool estaActivo() = 0;
    virtual ~Hilo() = default;

};

#endif //SERVIDOR_HILO_H
