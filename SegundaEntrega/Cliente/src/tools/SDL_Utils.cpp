#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SDL_Utils.h"
#include "Constantes.h"
#include "Log.h"

SDL_Texture* crearTextura(char* ruta,  SDL_Renderer* renderizador) {
    SDL_Surface* sup_aux = IMG_Load(ruta);
    loguearInfo(LOG_CARGANDO_IMAGEN_RUTA + std::string(ruta));

    /* Requerimiento adicional: clase del 15 de abril: si no se
     * carga la imagen, debe haber una imagen por defecto*/
    if(!sup_aux){
        sup_aux = IMG_Load(RUTA_IMG_DEFECTO);
        loguearInfo(LOG_IMAGEN_DEFECTO);
        loguearError( std::string(ERROR_IMG_FALTANTE) + ":" + ruta);
    }
    else{
        loguearInfo(LOG_IMAGEN);
    }

    SDL_Texture* textura = SDL_CreateTextureFromSurface(renderizador, sup_aux);
    SDL_FreeSurface(sup_aux);
    return textura;
}

void cargarIcono(char *ruta, SDL_Window* ventana) {
    SDL_Surface* icono = IMG_Load(ruta);
    SDL_SetWindowIcon(ventana, icono);
    SDL_FreeSurface(icono);
}

void initRect(SDL_Rect *rect, int x, int y, int w, int h) {
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
}

bool doublesIguales(double a, double b) {
    return fabs(a - b) < EPSILON_DOUBLE;
}
