#include "./gere_chasseur.h"

int main(int argc, char **argv) 
{
    (void)argc;
    (void)argv;

    int taille = 15;

   // map = crea_map (taille,nombre_obstacle);
   
    int** map;
    map = init_map(taille+2);

    position * position_chasseur = generateMaze(map, taille+2);
        

    int retour_chasse;
    //position * position_chasseur = malloc(sizeof(position));
    //apparition_chasseur(map,taille,position_chasseur);
    retour_chasse = chasse(map,taille,position_chasseur);

    printf("%d\n",retour_chasse);

    liberer_map(map,taille);
    free(position_chasseur);

    

    return(0);
}