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


int lancer_jeu_sans_graphisme_apprentissage (int taille, int *nb_iterations,ruleSet_t *rules);
void energy1(ruleSet_t rules, int taille, int coef_chasseur, int coef_terrier);
void shuffle(int *array, int n);