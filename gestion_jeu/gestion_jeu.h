#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <pthread.h>
#include "../Map/crea_map.h"
#include "../dijkstra/dijkstra.h"
#include "../affichage/affichage_fct.h"
#include "../affichage/init_SDL.h"
#include "../Chasseur/gere_chasseur.h"
#include "../lapin/mvt_lapin.h"




#ifndef __GESTION_JEU__H
#define __GESTION_JEU__H


int lancer_jeu_sans_graphisme (int taille, int * nb_iterations);
int lancer_jeu_avec_graphisme (int taille, int *nb_iterations);
int lancer_jeu_avec_graphisme_avec_control_lapin (int taille, int *nb_iterations);


#endif