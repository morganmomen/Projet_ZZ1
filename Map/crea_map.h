#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "../dijkstra/dijkstra.h"
//#include "../Chasseur/gere_chasseur.h"

#ifndef __CREA_MAP__H
#define __CREA_MAP__H


typedef struct {
    int x;
    int y;
}position;


int ** init_map (int taille);
int ** crea_map (int taille,int nombre_obstacle_max);
void afficher_map (int ** map,int taille);
void liberer_map (int ** map, int taille);
position* generateMaze(int** maze, int taille);
void apparition_chasseur (int ** map,int taille,position * position_chasseur);



#endif