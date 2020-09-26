#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SDL_Utils.h"
#include "Constantes.h"
#include "Log.h"

void initRect(SDL_Rect *rect, int x, int y, int w, int h) {
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
}

bool doblesIguales(double a, double b) {
    return fabs(a - b) < EPSILON_DOUBLE;
}
