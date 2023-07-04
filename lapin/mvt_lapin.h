//#include "../recuit_simule/recuit_simule.h"
#include "../rules/changeRules.h"
#include "../rules/choixRules.h"
#include "../rules/rules.h"

void deplacement_lapin(int **map, int taille, ruleSet_t *rules,
                       joueur_t *lapin);
int lapin(int **map, joueur_t *lapin, int taille, ruleSet_t *rules);