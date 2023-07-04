#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../Map/crea_map.h"
#include "../dijkstra/dijkstra.h"
#include "../affichage/affichage_fct.h"
#include "../affichage/init_SDL.h"



#ifndef __GERE_CHASSEUR__H
#define __GERE_CHASSEUR__H



void chercher_position_lapin (int ** map,int taille, position * position_lapin);
int deplacement_chasseur (int ** map,int taille, position *  position_chasseur,position *  position_lapin);
int chasse (int ** map,int taille,position *  position_chasseur);
void deplacementaleatoire (int ** map, position *  position_chasseur);
#endif