#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#ifndef __CREA_MAP__H
#define __CREA_MAP__H

int ** init_map (int taille);
int ** crea_map (int taille,int nombre_obstacle_max);
void afficher_map (int ** map,int taille);
void liberer_map (int ** map, int taille);
void generateMaze(int** maze, int taille);


#endif