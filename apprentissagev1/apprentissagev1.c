#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../Map/crea_map.h"
#include "../dijkstra/dijkstra.h"
#include "../affichage/affichage_fct.h"
#include "../affichage/init_SDL.h"
#include "../Chasseur/gere_chasseur.h"
#include "../lapin/mvt_lapin.h"

int lancer_jeu_sans_graphisme_apprentissage (int taille, int *nb_iterations,ruleSet_t *rules)
{
    int ** map = NULL;
    map = init_map(taille+2);
    position * position_chasseur = generateMaze(map, taille+2);

    joueur_t lapin;
    lapin.x = taille;
    lapin.y = taille;
    lapin.devant = map[lapin.x][lapin.y - 1];
    lapin.derriere = map[lapin.x][lapin.y + 1];
    lapin.gauche = map[lapin.x - 1][lapin.y];
    lapin.droite = map[lapin.x + 1][lapin.y];
    lapin.direction_predateur = NORD;
    lapin.direction_terrier = NORD;
    lapin.distance_predateur = LOIN;
    lapin.distance_terrier = LOIN;

    position position_lapin;
    position_lapin.x = lapin.x;
    position_lapin.y = lapin.y;
    position position_terrier;
    position_terrier.x=1;
    position_terrier.y=1;

    int drapeau_chasse=1;
    *nb_iterations = 0;
    while (drapeau_chasse == 1)
    {
        *nb_iterations = *nb_iterations + 1;
        deplacement_lapin(map,taille,rules,&lapin);
        position_lapin.x = lapin.x;
        position_lapin.y = lapin.y;
        if (deplacement_chasseur (map,taille,position_chasseur,&position_lapin)==1)
        {
            drapeau_chasse = 0;
        }
        if ((position_terrier.x==lapin.x)&&(position_terrier.y==lapin.y))
        {
            drapeau_chasse = 2;
        }

    }

    liberer_map(map,taille);
    free(position_chasseur);

    return(drapeau_chasse);
    
}

void energy1(ruleSet_t rules, int taille)
{
    int nb_iterations=0;
    int tabenergy[100];
    int energy_min = INT_MAX;
    int energy_max = 0;
    int drapeau_chasseur;
    int energy =0;
    for (int i=0;i<100;i++)
    {
    drapeau_chasseur = lancer_jeu_sans_graphisme_apprentissage(taille, &nb_iterations, &rules);
    if (drapeau_chasseur == 0)
    {
        tabenergy[i] = INT_MAX;
    }
    else if (drapeau_chasseur == 2)
    {
        tabenergy[i] = nb_iterations;
    }
    if (tabenergy[i] < energy_min) energy_min = tabenergy[i];
    if (tabenergy[i] > energy_max) energy_max = tabenergy[i];
    }
    for (int j =0; j<100; j++)
    {
        tabenergy[j] = (tabenergy[j] - energy_min)/ (energy_max - energy_min);
        energy = energy + tabenergy[j]/100;
    }
    rules.energy = energy;
}

 int main()
{
    int nb_iterations;
    int taille = 15;
    ruleSet_t rules;
    rules.rules = malloc(sizeof(rule_t) * NB_RULES);
    ruleSet_t bestRules;
    readRulesFromFile("../initRegle.txt", &(rules.rules));
    rules.energy = INT_MAX;
    int nombre_lancer = 100;
    for (int i = 0; i < nombre_lancer; i++)
    {
        // printf("Etape %d\n", i);
        // printRuleSet(&rules);
        changeRule2(&rules,taille,energy1,&bestRules);
        copyRuleSet(bestRules, &rules);
        printf("Progression de l'apprentissage : %d%%\n", (i * 100) / nombre_lancer);
    }
    printf("Energy : %d\n",rules.energy);
    writeRulesToFile(rules.rules,NB_RULES, "../input_regles.txt");
    return 0;
}