#include "apprentissagev1.h"





int main()
{
    srand(time(NULL)*rand());
    int nb_iterations;
    int taille = 15;
    ruleSet_t rules;
    rules.rules = malloc(sizeof(rule_t) * NB_RULES);
    ruleSet_t bestRules;
    readRulesFromFile("../initRegle.txt", &(rules.rules));
    rules.energy = INT_MAX;
    int nombre_lancer = 240;
    int rule_and_parameter[240];
    for (int i = 0; i < 240; i++) rule_and_parameter[i] = i;
    shuffle(rule_and_parameter,240);
    int chosen_rule_and_parameter;
    for (int i = 0; i < nombre_lancer; i++)
    {
        // printf("Etape %d\n", i);
        // printRuleSet(&rules);
        chosen_rule_and_parameter = rule_and_parameter[i];
        int nbrule = ceil(chosen_rule_and_parameter / 10);
        int parameter =(chosen_rule_and_parameter % 10);
        changeRule2(&rules,taille,energy1,&bestRules,nbrule,parameter);
        copyRuleSet(bestRules, &rules);
        printf("Progression de l'apprentissage : %d%%\n", (i * 100) / nombre_lancer);
    }
    printf("Energy : %d\n",rules.energy);
    writeRulesToFile(rules.rules,NB_RULES, "../input_regles.txt");
    return 0;
}