#include "init_SDL.h"

int initSDL(SDL_Window ** window, SDL_Renderer ** renderer)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    *window = SDL_CreateWindow("Meilleur chemin", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800 , 800, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    return 1;
}


SDL_Texture * loadTexture(char * path, SDL_Renderer * renderer)
{
    SDL_Texture *texture = IMG_LoadTexture(renderer,path);
    if (texture == NULL) printf("Texture is NULL\n"); 
    return texture;
}