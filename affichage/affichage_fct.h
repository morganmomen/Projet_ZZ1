#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "init_SDL.h"


void affichefond(SDL_Renderer * renderer,SDL_Window * window ,int** map, int taille);
void afficheLapin(SDL_Renderer * renderer,SDL_Window * window ,int** map, int x, int y);
void afficheChasseur(SDL_Renderer * renderer,SDL_Window * window ,int** map, int x, int y);
