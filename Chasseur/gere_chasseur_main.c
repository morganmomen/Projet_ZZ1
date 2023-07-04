#include "./gere_chasseur.h"

int main(int argc, char **argv) 
{
    (void)argc;
    (void)argv;

    int taille = 10;
    int nombre_obstacle = 40;
    int ** map;

    map = crea_map (taille,nombre_obstacle);

    int retour_chasse;
    position * position_chasseur = malloc(sizeof(position));
    apparition_chasseur(map,taille,position_chasseur);
    retour_chasse = chasse(map,taille,position_chasseur);

    printf("%d\n",retour_chasse);

    liberer_map(map,taille);
    free(position_chasseur);

    return(0);
}