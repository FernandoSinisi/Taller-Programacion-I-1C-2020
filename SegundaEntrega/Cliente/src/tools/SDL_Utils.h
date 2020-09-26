#ifndef CLIENTE_SDL_UTILS_H
#define CLIENTE_SDL_UTILS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

extern SDL_Texture* crearTextura(char* ruta, SDL_Renderer* renderizador);
extern void cargarIcono(char* ruta, SDL_Window* ventana);
extern void initRect(SDL_Rect *rect, int x, int y, int w, int h);

extern bool doublesIguales(double a, double b);

#endif //CLIENTE_SDL_UTILS_H
