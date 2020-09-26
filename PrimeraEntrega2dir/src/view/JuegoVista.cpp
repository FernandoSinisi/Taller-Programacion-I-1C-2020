#include "JuegoVista.h"
#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "../tools/Constantes.h"
#include "../tools/ParserEstadoJuego.h"
#include "../tools/SDL_Utils.h"
#include "../tools/Log.h"

JuegoVista::JuegoVista() : personaje(nullptr) {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    /* Crear una ventana.
       El solo hecho de crearla ya la muestra en pantalla.
     */
    this->ventana = SDL_CreateWindow(
            NOMBRE_JUEGO,
            X_VENTANA,
            Y_VENTANA,
            ANCHO_VENTANA,
            ALTO_VENTANA,
            STATE_VENTANA
    );

    loguearInfo(LOG_CREACION_VENTANA_JUEGO);

    cargarIcono(RUTA_ICONO, this->ventana);

    this->renderizador = SDL_CreateRenderer(this->ventana, -1, SDL_RENDERER_ACCELERATED);
    this->cargadorEnemigos = new CargadorTexturasEnemigos(this->renderizador);

    this->nivel = new NivelVista(this->renderizador);
}

void JuegoVista::inicializar() {
    /* Forma (fea) de mantener retrocompatibildiad con SDL 1:
    * se crea una superficie (SDL 1) y a partir de la misma
    * se crea la textura_actual (SDL 2), que es la que se renderiza.
   */

    /* Cargo el personaje */
    this->personaje = new PersonajeVista(X_PERSONAJE, Y_PERSONAJE, this->renderizador);

    /* El clear va DESPUÉS del fondo. */
    SDL_RenderClear(this->renderizador);
}

void JuegoVista::crearVistaEnemigos(std::string tipo, int cantidad){
    if(this->enemigos_vista_map.find(tipo) == this->enemigos_vista_map.end()){
        this->enemigos_vista_map[tipo] = new std::vector<EnemigoVista*>();

    }
    for (int i=0; i < cantidad; ++i){
        //map.at() lanza excepcion en caso de que no exista la clave
        this->enemigos_vista_map.at(tipo)->push_back(
                new EnemigoVista(0, 0, tipo, this->cargadorEnemigos));
    }

}

void JuegoVista::dibujar() {
    /*
                            ::::ACLARACION:::::
    Para los rectagulos tener en cuenta de que la posición X e Y esta ubicada en la
    esquina superior izquierda de los mismos.
    */

    this->nivel->mostrarFondo(this->renderizador);

    SDL_RenderCopy(this->renderizador,
                   this->personaje->getTextura(),
                   this->personaje->getSpriteActual(),
                   this->personaje->getPosicion()
    );


    for (std::map<std::string, std::vector<EnemigoVista*>*>::iterator i = this->enemigos_vista_map.begin();
         i != this->enemigos_vista_map.end(); ++i){

        for(std::vector<EnemigoVista*>::iterator enemigo = i->second->begin(); enemigo != i->second->end(); ++enemigo ){
            SDL_RenderCopy(this->renderizador,
                           (*enemigo)->getTextura(),
                           (*enemigo)->getSpriteActual(),
                           (*enemigo)->getPosicion()
            );
        }
    }

    SDL_RenderPresent(this->renderizador);

}

void JuegoVista::actualizar(std::string estado) {
    if (parserTipoRespuesta(estado) == PRE_POSICION_JUGADOR) {
        std::vector<int> posicion = parserRespuestaPersonajePosicion(estado);
        this->personaje->actualizar(posicion[0], posicion[1], posicion[2]);
    }

    if (parserTipoRespuesta(estado) == PRE_POSICION_ENEMIGO) {
        this->decodificarEstadoEnemigos(estado);
    }

    if (parserTipoRespuesta(estado) == PRE_NIVEL_FINALIZADO) {
        this->nivel->cambiarNivel();
    }

    if (parserTipoRespuesta(estado) == PRE_POSICION_VENTANA) {
        int posicion = parserRespuestaVentanaPosicion(estado);
        this->nivel->actualizarPosicionFondo(posicion);
    }

}

void JuegoVista::decodificarEstadoEnemigos(std::string estado){

    int cantidad_clase_i;
    std::string clase_i;
    std::string aux;  // palabras extraidas del estados

    std::vector<std::string>::iterator pos_tipo_enemigo;
    std::vector<std::string> tipos_enemigos_vista_actual;

    std::stringstream stream_estado(estado); // stream de las palabras de estado
    stream_estado >> aux; //leo el PRE_ENEMIGO, no sirve de nada pero lo tengo que sacar
    stream_estado >> aux; // leo cantidad de clases de cada enemigo
    int cantidad_clases = atoi(aux.c_str()); // convierto a entero la cantidad de clases

    //Obtengo los tipos de los enemigos actualmente en la vista dibujados
    for (std::map<std::string, std::vector<EnemigoVista*>*>::iterator i = this->enemigos_vista_map.begin();
         i != this->enemigos_vista_map.end(); ++i) {

        tipos_enemigos_vista_actual.push_back(i->first);
    }

    for(int i = 0; i < cantidad_clases; i++){

        stream_estado >> aux; //Clase
        clase_i = aux;

        stream_estado >> aux; //cantidad enemigos de esa clase
        cantidad_clase_i = (int)std::stof(aux);

        //Ajusto las cantidades de enemigos de esa clase en mi map de enemigos vista
        pos_tipo_enemigo = std::find(tipos_enemigos_vista_actual.begin(), tipos_enemigos_vista_actual.end(), clase_i);
        if (pos_tipo_enemigo != tipos_enemigos_vista_actual.end()) {
            tipos_enemigos_vista_actual.erase(pos_tipo_enemigo);
            cantidad_clase_i -= (int) (this->enemigos_vista_map[clase_i]->size());
            if (cantidad_clase_i >= 0) {
                this->crearVistaEnemigos(clase_i, cantidad_clase_i);
            } else {
                this->eliminarVistaEnemigos(clase_i, -1*cantidad_clase_i);
            }
        } else {
            this->crearVistaEnemigos(clase_i, cantidad_clase_i);
        }
        //Recupero el valor de cantidad_clase_i leido
        cantidad_clase_i = (int)std::stof(aux);

        //Actualizo las posiciones de los enemigos de esa clase
        this->actualizarVistaEnemigos(clase_i, cantidad_clase_i, &stream_estado);
    }

    //Elimino los enemigos de clases no recibidas
    for(auto &tipo: tipos_enemigos_vista_actual){
        cantidad_clase_i = (int) this->enemigos_vista_map[tipo]->size();
        this->eliminarVistaEnemigos(tipo, cantidad_clase_i);
    }
}

void JuegoVista::actualizarVistaEnemigos(std::string tipo, int cantidad, std::stringstream* stream_estado){
    int x, y, d;
    std::string aux;
    for (int j=0; j < cantidad; ++j){
        (*stream_estado) >> aux; //x enemigo
        x = (int)std::stof(aux);
        (*stream_estado) >> aux; //y enemigo
        y = (int)std::stof(aux);
        (*stream_estado) >> aux; //y enemigo
        d = (int)std::stof(aux);

        (*(this->enemigos_vista_map[tipo]))[(long unsigned)j]->actualizar(x,y,d);
    }
}

void JuegoVista::eliminarVistaEnemigos(std::string tipo, int cantidad){
    for (int j=0; j < cantidad; ++j){
        //Borro los enemigos vista que esten de mas en la ventana
        delete((*(this->enemigos_vista_map[tipo]))[this->enemigos_vista_map[tipo]->size() -1]);
        this->enemigos_vista_map[tipo]->erase(this->enemigos_vista_map[tipo]->begin() + (int)(this->enemigos_vista_map[tipo]->size() - 1) );
    }
}

void JuegoVista::destruir() {
    SDL_DestroyRenderer(this->renderizador);
    SDL_DestroyWindow(this->ventana);
}

JuegoVista::~JuegoVista() {
    if (this->personaje != nullptr) {
        delete (this->personaje);
    }

    for (std::map<std::string, std::vector<EnemigoVista*>*>::iterator i = this->enemigos_vista_map.begin();
         i != this->enemigos_vista_map.end(); ++i){

        for(std::vector<EnemigoVista*>::iterator j = i->second->begin(); j != i->second->end(); ++j ){
            delete(*j);
        }
        delete(i->second);
    }

    delete (this->nivel);
    delete (this->cargadorEnemigos);
}

SDL_Renderer *JuegoVista::getRenderizador() {
    return this->renderizador;
}

FondoVista *JuegoVista::getFondo() {
    return this->nivel->getFondoActual();
}
