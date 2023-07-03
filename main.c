#include <stdio.h>
#include <stdlib.h>
#include "rules/rules.h"
#include "rules/changeRules.h"
#include "rules/choixRules.h"

int main(int argc, char **argv)
{
    rule_t rule[NB_RULES];
    for (int i = 0; i < NB_RULES; i++)
    {
        generateRule(&rule[i]);
        printRule(&rule[i]);
    }
    printf("\n");


    joueur_t joueur;
    joueur.devant = 1;
    joueur.gauche = 1;
    joueur.droite = 1;
    joueur.derriere = 0;
    joueur.direction_predateur = 0;
    joueur.direction_terrier = 0;
    joueur.distance_predateur = 1;
    joueur.distance_terrier = 2;
    action_t action = choixRule(rule, &joueur);


    return 0;
}
