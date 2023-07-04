#ifndef INIT_SDL_H
#define INIT_SDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>



int initSDL(SDL_Window ** window, SDL_Renderer ** renderer);
SDL_Texture * loadTexture(char * path, SDL_Renderer * renderer);


#endif