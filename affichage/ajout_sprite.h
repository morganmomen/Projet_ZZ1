#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "./init_SDL.h"




void Draw_Lapin(SDL_Window * window,SDL_Renderer * renderer,SDL_Rect * lapin,SDL_Texture ** lapintexture,int* offset_x_lapin,int* offset_y_lapin);

void Draw_Chasseur(SDL_Window * window,SDL_Renderer * renderer,SDL_Rect * chasseur,SDL_Texture ** chasseurtexture,int* offset_x_chasseur,int* offset_y_chasseur);


