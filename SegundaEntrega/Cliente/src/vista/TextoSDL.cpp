#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "TextoSDL.h"
#include "../tools/Constantes.h"
#include "../tools/SDL_Utils.h"
#include <string>

TextoSDL::TextoSDL(SDL_Renderer* renderizador, TTF_Font* fuente_nueva, SDL_Color color, int tam, char *msj,
                   int x, int y){
    this->renderizador = renderizador;

    initRect(&this->rectangulo, x, y, tam * (int) strlen(msj), tam);

    this->fuente = fuente_nueva;

    this->color = color;
    this->mensaje = msj;

    SDL_Surface* sup_aux = ::TTF_RenderText_Solid(this->fuente, msj, this->color);
    this->texto = SDL_CreateTextureFromSurface(this->renderizador, sup_aux);
    SDL_FreeSurface(sup_aux);
}

TextoSDL::~TextoSDL() {

    SDL_DestroyTexture(this->texto);
}
SDL_Texture* TextoSDL::getTexto() {
    return this->texto;
}

SDL_Rect* TextoSDL::getRectangulo() {
    return &this->rectangulo;
}

void TextoSDL::setTexto(const char *msj) {
    setTexto(msj, this->color);
}

void TextoSDL::setTexto(const char *msj, SDL_Color c) {
    this->mensaje = const_cast<char *>(msj);
    SDL_DestroyTexture(this->texto);

    SDL_Surface* sup_aux = ::TTF_RenderText_Solid(this->fuente, msj, c);
    this->texto = SDL_CreateTextureFromSurface(this->renderizador, sup_aux);
    SDL_FreeSurface(sup_aux);

    this->rectangulo.w = this->rectangulo.h * (int) strlen(msj);
}

char *TextoSDL::getMensaje() {
    return this->mensaje;
}

SDL_Color TextoSDL::getColor() {
    return this->color;
}
