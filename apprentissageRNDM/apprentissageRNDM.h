#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <pthread.h>

#include "../Map/crea_map.h"
#include "../dijkstra/dijkstra.h"
#include "../affichage/affichage_fct.h"
#include "../affichage/init_SDL.h"
#include "../Chasseur/gere_chasseur.h"
#include "../lapin/mvt_lapin.h"


void apprentissageAleatoire(int tailleArg, int nombreiteration);
void* thread_jeu(void*arg);
void finalTournoiRules();