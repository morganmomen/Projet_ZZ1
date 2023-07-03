#include "./crea_map.h"



int main(int argc, char **argv) 
{
    (void)argc;
    (void)argv;

    int taille = 10;
    int nombre_obstacle_max=40;
    int ** map = crea_map (taille,nombre_obstacle_max);
    afficher_map(map,taille);
    liberer_map(map,taille);


    return(0);
}