#include "NivelVista.h"

NivelVista::NivelVista( SDL_Renderer* renderizador){
    this->nivel_actual = 0;

    //creo el fondo 1 y lo guardo en el vector;
    FondoVista* fondo_nivel_1 = new FondoVista(getRutaFondo11(),getRutaFondo12(),getRutaFondo13(),getRutaFondo14(),getRutaFondo15(),getRutaFondo16(),renderizador);
    this->fondos.push_back(fondo_nivel_1);

    //creo el fondo 2 y lo guardo en el vector;
    FondoVista* fondo_nivel_2 = new FondoVista(getRutaFondo21(),getRutaFondo22(),getRutaFondo23(),getRutaFondo24(),getRutaFondo25(),getRutaFondo26(),renderizador);
    this->fondos.push_back(fondo_nivel_2);

}
void NivelVista::cambiarNivel(){
    if (this->nivel_actual < CANTIDAD_NIVELES - 1  ) this->nivel_actual++;
}

void NivelVista::actualizarPosicionFondo(int posicion_ventana){
    this->fondos[this->nivel_actual]->actualizar(posicion_ventana);
}

void NivelVista::mostrarFondo(SDL_Renderer *renderizador){
    this->fondos[this->nivel_actual]->actualizar();

    SDL_RenderCopy(renderizador,
                   this->fondos[this->nivel_actual]->getTexturaSextaCapa(),
                   NULL,
                   this->fondos[this->nivel_actual]->getSextaCapa());


    SDL_RenderCopy(renderizador,
                   this->fondos[this->nivel_actual]->getTexturaQuintaCapa(),
                   NULL,
                   this->fondos[this->nivel_actual]->getQuintaCapa());

    SDL_RenderCopy(renderizador,
                   this->fondos[this->nivel_actual]->getTexturaCuartaCapa(),
                   NULL,
                   this->fondos[this->nivel_actual]->getCuartaCapa());

    SDL_RenderCopy(renderizador,
                   this->fondos[this->nivel_actual]->getTexturaTercerCapa(),
                   NULL,
                   this->fondos[this->nivel_actual]->getTercerCapa());

    SDL_RenderCopy(renderizador,
                   this->fondos[this->nivel_actual]->getTexturaSegundaCapa(),
                   NULL,
                   this->fondos[this->nivel_actual]->getSegundaCapa());

    
    SDL_RenderCopy(renderizador,
                   this->fondos[this->nivel_actual]->getTexturaPrimerCapa(),
                   NULL,
                   this->fondos[this->nivel_actual]->getPrimeraCapa());

}

FondoVista* NivelVista::getFondoActual(){
    return this->fondos[this->nivel_actual];
}

NivelVista::~NivelVista(){
    for (auto &i: this->fondos){
        delete i;
    }
}
