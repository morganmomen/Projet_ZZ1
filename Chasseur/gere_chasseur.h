#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "../Map/crea_map.h"


#ifndef __GERE_CHASSEUR__H
#define __GERE_CHASSEUR__H

#define Inf 9999999

typedef struct {
    int x;
    int y;
}position;


void apparition_chasseur (int ** map,int taille,position * position_chasseur);
void chercher_position_lapin (int ** map,int taille, position * position_lapin);
void deplacement_chasseur (int ** map,int taille, position *  position_chasseur,position *  position_lapin);
int chasse (int ** map,int taille,position *  position_chasseur);

#endif