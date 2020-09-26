#ifndef CLIENTE_JUEGOSONIDO_H
#define CLIENTE_JUEGOSONIDO_H

#include <SDL2/SDL_mixer.h>
#include <vector>
#include <string>
#include <iostream>
#include <thread>
#include "../tools/ConstantesMusica.h"

class JuegoSonido {

private:

    Mix_Music *menu;
    Mix_Music *nivel;
    std::vector<std::string> rutas_musicas_nivel;
    bool muted;
    bool sfx_muted;

    Mix_Chunk *sfx_disparo;
    Mix_Chunk *sfx_explosion;
    Mix_Chunk *sfx_impacto_enemigo;
    Mix_Chunk *sfx_impacto_personaje;
    Mix_Chunk *sfx_opcion_menu_abajo;
    Mix_Chunk *sfx_opcion_menu_seleccionar;
    Mix_Chunk *sfx_input_tecla_login;
    Mix_Chunk *sfx_propulsion;

public:
    JuegoSonido();
    ~JuegoSonido();

    void playMenu();
    void stopMenu();
    void playNivel(int nro_nivel);
    void playMusicaFinNivel();
    void playMusicaGameOver();
    void stopMusicaNivel();
    void playJefe1();

    bool musicaSonando();
    void playDisparo();
    void playExplosion();
    void playImpactoEnemigo();
    void playImpactoPersonaje();
    void playOpcionMenuAbajo();
    void playOpcionMenuSeleccionar();
    void playTeclaLogin();
    void playPropulsionPersonaje();

    void playMenuAux();
    void playNivelAux(int n);

    void mute();
    void muteSFX();
    void unmute();
    void unmuteSFX();

    void playJefe(char *ruta);

    void playMusicaStages();

    void stopMusicaStages();
};


#endif //CLIENTE_JUEGOSONIDO_H
