#include "Nivel.h"
#include "Jefe1.h"

//Creo el vector de personajes_vivos vivos como una COPIA del vector de personajes_vivos pers, es decir copio elemento a elemento
//las referencias a los personajes_vivos de pers y si elimino un elemento de la lista de personajes_vivos vivos con erase, esta
//eliminacion NO afecta a el vector original pers, ya que personajes_vivos vivos es una copia

Nivel::Nivel(std::vector<Personaje*>* pers,
        std::vector<std::string> tipo_enemigos_nivel,
        std::vector<int> cantidad_enemigos_nivel, int n_nivel): personajes_vivos(*pers) {

    this->personajes = pers;
    this->cantidad_enemigos = 0;
    this->nro_nivel = n_nivel;
    this->crearEnemigos(tipo_enemigos_nivel, cantidad_enemigos_nivel);
    this->ventana = new Ventana(DESPLAZAMIENTO_FONDO);
    this->finalizado = false;
    this->contador = 0;

    if ( this->nro_nivel == NRO_NIVEL_FINAL ){
        this->jefes.push_back(new Jefe1(POS_X_JEFE_1,POS_Y_JEFE_1,POTENCIA_PROY_JEFE_1));
        this->enemigos.push_back(this->jefes[0]);
        this->cantidad_enemigos += 1;
    }

    //recordar de setear proyectiles_personajes despues de crear a los enemigos y personajes_vivos
    this->setearProyectiles();
}

Nivel::~Nivel() {
    delete (this->ventana);
    int  i = 0;
    while( i < (this->cantidad_enemigos)){
        delete (this->enemigos[(unsigned long)i]);
        i = i + 1;
    }

    for (auto &a: *(this->proyectiles_personajes) ) {
        delete(a);
    }

    this->proyectiles_personajes->clear();
    delete(this->proyectiles_personajes);

    for (auto &a: *(this->proyectiles_enemigos) ) {
        delete(a);
    }

    this->proyectiles_enemigos->clear();
    delete(this->proyectiles_enemigos);

}

void Nivel::actualizar() {

    this->limpiarEfectos();

    //SE CALCULA UNA SOLA VEZ LA CANTIDAD DE PERSONAJES VIVOS
    //SI SE LLEGARA A MODIFICAR EN ESTE METODO MAS ADELANTE TENDRIAMOS UN BUG
    for (unsigned long i = 0; i < this->personajes_vivos.size(); ++i) {
        this->ventana->corregirColisionBorde(this->personajes_vivos[i]);
    }

    this->actualizarPersonajes();
    this->actualizarProyectiles(this->proyectiles_personajes);
    this->actualizarEnemigos();
    this->actualizarProyectiles(this->proyectiles_enemigos);
    this->actualizarColisionProyectilConEnemigo();
    this->actualizarColisionProyectilConPersonaje();
    this->actualizarColisionPersonajeConEnemigo();
    this->actualizarVentana();
}

void Nivel::actualizarPersonajes(){
    for (unsigned long i = 0; i < this->personajes_vivos.size(); ++i) {
        (this->personajes_vivos)[i]->actualizar();
        this->ventana->actualizarPosicionVista((this->personajes_vivos)[i]);

        if ( !this->personajes_vivos[i]->estaVivo() ){
            this->posicion_efectos_personajes.push_back(this->personajes_vivos[i]->getPosicionVentana());
            this->personajes_vivos[i]->actualizar(POS_NINGUNA);
            this->personajes_vivos.erase(this->personajes_vivos.begin() + (int) i);
        }
    }
}

void Nivel::actualizarProyectiles(std::vector<Proyectil*>* proyectiles){
    for (auto &proyectil: *proyectiles) {
        this->ventana->actualizarPosicionVista(proyectil);
    }
    for (unsigned long proy_n = 0; proy_n < (*proyectiles).size();) {
        if(!this->ventana->llegoAlFinal()) {
            (*proyectiles)[proy_n]->mover(POS_DERECHA_FONDO);
        }
        (*proyectiles)[proy_n]->actualizar();
        if ((*proyectiles)[proy_n]->estaDestruido()) {
            delete ((*proyectiles)[proy_n]);
            (*proyectiles).erase((*proyectiles).begin() + (long) (proy_n));
        } else {
            proy_n++;
        }
    }
}

void Nivel::actualizarEnemigos(){
    size_t n_per_objetivo_disparo = this->personajes_vivos.size();
    double distancia_min = (double)ANCHO_FONDO;
    double distancia_max = 0;
    double distancia_aux;

    for (auto &enemigo: this->enemigos) {
        enemigo->actualizarDireccionContraria();
        this->ventana->actualizarPosicionVista(enemigo);

        if (!(enemigo->getEstaEnVentana())) {
            continue;
        }

        for (size_t per = 0; per < this->personajes_vivos.size(); ++per){
            distancia_aux = Posicion(this->personajes_vivos[per]->getPosX(), this->personajes_vivos[per]->getPosY()).distancia(Posicion(enemigo->getPosX(), enemigo->getPosY()));
            if (this->personajes_vivos[per]->estaConectado()) {
                if (distancia_aux < distancia_min) {
                    enemigo->setPosPersonajeCercano(this->personajes_vivos[per]->getPosicionVentana());
                    distancia_min = distancia_aux;
                }
                if (distancia_aux > distancia_max) {
                    n_per_objetivo_disparo = per;
                    distancia_max = distancia_aux;
                }
            }
        }

        if(n_per_objetivo_disparo < this->personajes_vivos.size()){
            enemigo->setDisparar();
            if( this->personajes_vivos[n_per_objetivo_disparo]->estaConectado() ){
                enemigo->actualizar(Posicion(this->personajes_vivos[n_per_objetivo_disparo]->getPosX(), this->personajes_vivos[n_per_objetivo_disparo]->getPosY()));
            }
            else{
                enemigo->actualizar(Posicion( 0 , enemigo->getPosY() ));
            }
        }

        distancia_min = (double)ANCHO_FONDO;
        distancia_max = 0;
    }
}

void Nivel::actualizarVentana(){

    if ( this->ventana->actualizar() ) {
        for (unsigned long i = 0; i < this->personajes_vivos.size(); ++i) {
            (this->personajes_vivos)[i]->mover(POS_DERECHA_FONDO);
        }
    }

    else if ( !this->hayEnemigosEnVentana() && !this->personajes_vivos.empty() ) {
        this->contador += 1;
        if (this->contador == TIEMPO_FIN_NIVEL){
            this->finalizado = true;
        }
    }
}

void::Nivel::actualizarColisionProyectilConEnemigo(){
    int nro_personaje;
    for (unsigned long proy_n = 0; proy_n < (*this->proyectiles_personajes).size(); proy_n++) {
        if (!(*this->proyectiles_personajes)[proy_n]->getEstaEnVentana()) {
            continue;
        }
        for (unsigned long enemigo_n = 0; enemigo_n < (unsigned long)this->cantidad_enemigos; enemigo_n++) {
            if (!(this->enemigos[enemigo_n]->getEstaEnVentana() && Colisionador::hayColision((*this->proyectiles_personajes)[proy_n], this->enemigos[enemigo_n]))) {
                continue;
            }
            //Me guardo el numero del personaje que disparo por si el proyectil mato al enemigo
            nro_personaje = (*this->proyectiles_personajes)[proy_n]->getNumeroPersonaje();
            this->enemigos[enemigo_n]->impactar((*this->proyectiles_personajes)[proy_n]);
            (*this->proyectiles_personajes)[proy_n]->destruir();
            delete ((*this->proyectiles_personajes)[proy_n]);
            (*this->proyectiles_personajes).erase((*this->proyectiles_personajes).begin() + (long) (proy_n));
            if ( !this->enemigos[enemigo_n]->estaVivo() ){
                //Si el enemigo murio entonces le sumo puntos al personaje
                for (auto &personaje: *(this->personajes)) {
                    if (personaje->getNumeroPersonaje() == nro_personaje) {
                        personaje->agregarPuntaje(this->enemigos[enemigo_n]->getPuntos(), this->nro_nivel);
                        loguearDebug(LOG_PUNTOS_PERSONAJE_1 + std::to_string(this->enemigos[enemigo_n]->getPuntos()) +
                                     LOG_PUNTOS_PERSONAJE_2 + personaje->getNombre());
                        break;
                    }
                }
                if( std::find(TIPOS_JEFES.begin(), TIPOS_JEFES.end(), this->enemigos[enemigo_n]->getTipo())== TIPOS_JEFES.end() ){
                    this->posicion_efectos_enemigos.push_back(this->enemigos[enemigo_n]->getPosicionVentana());
                    loguearDebug(LOG_ENEMIGO_DESTRUIDO + this->enemigos[enemigo_n]->getTipo());
                } else {
                    this->jefes.pop_back();
                    this->posicion_efectos_jefes.push_back(this->enemigos[enemigo_n]->getPosicionVentana());
                    loguearDebug(LOG_JEFE_DESTRUIDO);

                }
                delete (this->enemigos[enemigo_n]);
                this->enemigos.erase(this->enemigos.begin() + (long) (enemigo_n));
                this->cantidad_enemigos--;
                enemigo_n--;
            }
            proy_n--;
            break;
        }
    }
}

void Nivel::actualizarColisionProyectilConPersonaje() {
    int potencia;
    for (unsigned long proy_n = 0; proy_n < (*this->proyectiles_enemigos).size(); proy_n++) {
        if (!(*this->proyectiles_enemigos)[proy_n]->getEstaEnVentana()) {
            continue;
        }
        for (unsigned long personaje_n = 0; personaje_n < this->personajes_vivos.size(); personaje_n++) {
            if (!this->personajes_vivos[personaje_n]->estaConectado() ||
                !Colisionador::hayColision((*this->proyectiles_enemigos)[proy_n], this->personajes_vivos[personaje_n])
                    ) {
                continue;
            }

            potencia = (*this->proyectiles_enemigos)[proy_n]->getPotencia();
            (*this->proyectiles_enemigos)[proy_n]->destruir();
            delete ((*this->proyectiles_enemigos)[proy_n]);
            (*this->proyectiles_enemigos).erase((*this->proyectiles_enemigos).begin() + (long) (proy_n));
            this->personajes_vivos[personaje_n]->impactar(potencia);

            if (!this->personajes_vivos[personaje_n]->estaVivo()) {
                loguearDebug(LOG_MURIO_PERSONAJE + this->personajes_vivos[personaje_n]->getNombre());
                this->posicion_efectos_personajes.push_back(this->personajes_vivos[personaje_n]->getPosicionVentana());
                this->personajes_vivos[personaje_n]->matar();
                this->personajes_vivos[personaje_n]->actualizar(POS_NINGUNA);
                this->personajes_vivos.erase(this->personajes_vivos.begin() + (int) personaje_n);
                personaje_n--;
            }
            proy_n--;
            break;
        }
    }
}

void Nivel::actualizarColisionPersonajeConEnemigo(){
    for (long unsigned personaje = 0; personaje < this->personajes_vivos.size(); personaje++) {
        for (unsigned long enemigo_n = 0; enemigo_n < (unsigned long)this->cantidad_enemigos; enemigo_n++) {
            if ( this->personajes_vivos[personaje]->estaConectado() and
                 this->enemigos[enemigo_n]->getEstaEnVentana() and
                 Colisionador::hayColision(this->personajes_vivos[personaje], this->enemigos[enemigo_n])) {

                // Si está en modo test, está destruyendo la nave
                if( this->personajes_vivos[personaje]->getTest() and !this->enemigos[enemigo_n]->esJefe()) {
                    this->personajes_vivos[personaje]->agregarPuntaje(this->enemigos[enemigo_n]->getPuntos(), this->nro_nivel);
                }

                // Evitar bug de "explosión continua".
                // this->posicion_efectos.push_back(this->personajes_vivos[personaje]->getPosicionVentana());

                this->personajes_vivos[personaje]->matar();
                if ( !this->personajes_vivos[personaje]->estaVivo() ){
                    loguearDebug(LOG_MURIO_PERSONAJE + this->personajes_vivos[personaje]->getNombre());
                    this->posicion_efectos_personajes.push_back(this->personajes_vivos[personaje]->getPosicionVentana());
                    this->personajes_vivos[personaje]->actualizar(POS_NINGUNA);
                    this->personajes_vivos.erase(this->personajes_vivos.begin() + (int) personaje);
                    personaje--;
                }

                if( std::find(TIPOS_JEFES.begin(), TIPOS_JEFES.end(), this->enemigos[enemigo_n]->getTipo())
                    == TIPOS_JEFES.end() ){

                    loguearDebug(LOG_ENEMIGO_DESTRUIDO + this->enemigos[enemigo_n]->getTipo());
                    this->posicion_efectos_enemigos.push_back(this->enemigos[enemigo_n]->getPosicionVentana());
                    this->enemigos[enemigo_n]->matar();
                    delete (this->enemigos[enemigo_n]);
                    this->enemigos.erase(this->enemigos.begin() + (long) (enemigo_n));
                    this->cantidad_enemigos--;
                    enemigo_n--;
                }
                break;
            }
        }
    }
}




void Nivel::actualizar(int tecla, long unsigned personaje) {
    loguearDebug(LOG_MSJ_TECLA_1 + std::to_string(tecla) + LOG_MSJ_TECLA_2 + std::to_string(personaje));

    if (tecla == TECLAS_ARRIBA_IZQUIERDA) {
        (*(this->personajes))[personaje]->actualizar(POS_ARRIBA_IZQ);

    } else if (tecla == TECLAS_ARRIBA_DERECHA) {
        (*(this->personajes))[personaje]->actualizar(POS_ARRIBA_DER);

    } else if (tecla == TECLAS_ABAJO_IZQUIERDA) {
        (*(this->personajes))[personaje]->actualizar(POS_ABAJO_IZQ);

    } else if (tecla == TECLAS_ABAJO_DERECHA) {
        (*(this->personajes))[personaje]->actualizar(POS_ABAJO_DER);

    } else if (tecla == TECLA_ARRIBA) {
        (*(this->personajes))[personaje]->actualizar(POS_ARRIBA);

    } else if (tecla == TECLA_IZQUIERDA) {
        (*(this->personajes))[personaje]->actualizar(POS_IZQUIERDA);

    } else if (tecla == TECLA_ABAJO) {
        (*(this->personajes))[personaje]->actualizar(POS_ABAJO);

    } else if (tecla == TECLA_DERECHA) {
        (*(this->personajes))[personaje]->actualizar(POS_DERECHA);

    } else if (tecla == TECLA_NINGUNA) {
        (*(this->personajes))[personaje]->actualizar(POS_NINGUNA);

    } else if (tecla == TECLA_DISPARAR) {
        (*(this->personajes))[personaje]->disparar();
    }

    else if (tecla == TECLA_NO_DISPARAR) {
        (*(this->personajes))[personaje]->dejarDeDisparar();
    }

    else if (tecla == TECLA_TEST ) {
        (*(this->personajes))[personaje]->setTest();
    }

    else if (tecla == TECLA_PROPULSION ) {
        (*(this->personajes))[personaje]->activarPropulsion();
    }

}

std::string Nivel::getEstadoPersonajes() {
    return ::getEstadoPersonajes(&this->personajes_vivos);
}

std::string Nivel::getEstadoEnemigos() {
    return ::getEstadoEnemigos(&this->enemigos);
}

std::string Nivel::getEstadoFondo() {
   return ::getEstadoFondo(this->ventana);
}

std::string Nivel::getEstadoProyectiles() {
   return ::getEstadoProyectiles(this->proyectiles_personajes,this->proyectiles_enemigos);
}

bool Nivel::hayEnemigosEnVentana() {

    for(auto enemigo: this->enemigos){
        if( enemigo->getEstaEnVentana() ){
            return true;
        }
    }
    return false;
}

std::string Nivel::getEstadoEfectos() {
    std::string aux;
    unsigned int cantidad_tipos_efecto = 0;

    if(!this->posicion_efectos_personajes.empty()){
        aux+= ::getEstadoEfectoPersonaje(posicion_efectos_personajes);
        cantidad_tipos_efecto += 1;
    }

    if(!this->posicion_efectos_enemigos.empty()) {
        aux+= ::getEstadoEfectoEnemigo(posicion_efectos_enemigos);
        cantidad_tipos_efecto += 1;
    }

    if(!this->posicion_efectos_jefes.empty()) {
        aux+= ::getEstadoEfectoJefe(posicion_efectos_jefes);
        cantidad_tipos_efecto += 1;
    }

    return ::getEstadoEfecto(aux,cantidad_tipos_efecto);
}

bool Nivel::getNivelFinalizado(){
    return this->finalizado;
}

void Nivel::desconectarPersonaje(int nro_personaje){
    for (auto &personaje: *this->personajes){
        if (personaje->getNumeroPersonaje() == nro_personaje) {
            personaje->setConectado(false);
            personaje->setListo(false);
            personaje->actualizar(POS_NINGUNA);
            personaje->dejarDeDisparar();
        }
    }
}

void Nivel::crearEnemigos(std::vector<std::string> tipo_enemigos_nivel, std::vector<int> cantidad_enemigos_nivel) {
    int pos_aux[2];
    srand( (unsigned)time( NULL ) );

    std::vector<int> medidas = {getTamAltoEnemigo1(), getTamAnchoEnemigo1(), getTamAltoEnemigo2(),
                                getTamAnchoEnemigo2()};

    for(long unsigned i=0; i<tipo_enemigos_nivel.size(); ++i) {
        int cant_enemigos = cantidad_enemigos_nivel[i];
        for(int j=0; j<cant_enemigos; ++j) {
            obtenerRandom(pos_aux,this->nro_nivel);
            Enemigo* nuevo_enemigo = new Enemigo(pos_aux[0],
                                                 pos_aux[1],
                                                 (char *) (tipo_enemigos_nivel[i]).c_str(),
                                                 medidas[2 * i],
                                                 medidas[2 * i + 1]);

            while (Colisionador::hayColisionesInicialesDeEnemigos(nuevo_enemigo, this->enemigos)) {
                obtenerRandom(pos_aux,this->nro_nivel);
                nuevo_enemigo->setPosX(pos_aux[0]);
                nuevo_enemigo->setPosY(pos_aux[1]);
                nuevo_enemigo->actualizarDireccionInicial();
            }
            if ( this->nro_nivel != NRO_NIVEL_FINAL ){
                nuevo_enemigo->setTopePosicionX(ANCHO_FONDO+ANCHO_VENTANA);
            }
            else{
                nuevo_enemigo->setTopePosicionX((int)(ANCHO_FONDO - PROPORCION_ALEJAMIENTO_JEFES*ANCHO_VENTANA));
            }
            this->enemigos.push_back(nuevo_enemigo);
        }
        this->cantidad_enemigos += cantidad_enemigos_nivel[i];
    }

}

void Nivel::setearProyectiles() {
    this->proyectiles_personajes = new std::vector<Proyectil*>();
    for (auto &personaje_j: *this->personajes) {
        personaje_j->setProyectiles(this->proyectiles_personajes);
    }
    this->proyectiles_enemigos = new std::vector<Proyectil*>();
    for (auto &enemigo_i: this->enemigos) {
        enemigo_i->setProyectiles(this->proyectiles_enemigos);
    }
}

void Nivel::limpiarEfectos() {
    this->posicion_efectos_personajes.clear();
    this->posicion_efectos_enemigos.clear();
    this->posicion_efectos_jefes.clear();
}

