#include "gestion_jeu.h"



int main(int argc, char **argv) 
{
    (void)argc;
    (void)argv;
    int taille = 17;
    printf("Bienvenue dans le jeu du chasseur et du lapin\n");
    int nbLancer = 1;
    int resultat[nbLancer];
    int nb_iterations[nbLancer];
    for(int i = 0; i < nbLancer; i++)
    {
        resultat[i] = lancer_jeu_avec_graphisme(taille, &nb_iterations[i]);
        printf("Iteration %d\n", i);
    }

    int nb_victoire_chasseur = 0;
    int nb_victoire_lapin = 0;
    int nb_iterations_total = 0;
    for(int i = 0; i < nbLancer; i++)
    {
        if(resultat[i] == 0)
        {
            nb_victoire_chasseur++;
        }
        else
        {
            nb_victoire_lapin++;
        }
        nb_iterations_total += nb_iterations[i];
    }

    printf("Le chasseur a gagné %d fois\n", nb_victoire_chasseur);
    printf("Le lapin a gagné %d fois\n", nb_victoire_lapin);
    printf("Le nombre moyen d'itérations est de %d\n", nb_iterations_total/nbLancer);
    return 0;
}