#include "apprentissage_multithreading.h"

int main() {
  srand(time(NULL) * rand());
  int nb_iterations;
  int taille = 15;
  ruleSet_t rules;
  rules.rules = malloc(sizeof(rule_t) * NB_RULES);
  ruleSet_t bestRules;
  readRulesFromFile("../initRegle.txt", &(rules.rules));
  // printf("ALED1\n");
  // printRuleSet(&rules);
  rules.energy = 0;
  int nombre_lancer = 240;
  int rule_and_parameter[240];
  for (int i = 0; i < nombre_lancer; i++)
    rule_and_parameter[i] = i;
  shuffle(rule_and_parameter, nombre_lancer);
  int chosen_rule_and_parameter;
  for (int i = 0; i < nombre_lancer; i++) {
    chosen_rule_and_parameter = rule_and_parameter[i];
    int nbrule = ceil(chosen_rule_and_parameter / 10);
    int parameter = (chosen_rule_and_parameter % 10);
    changeRule2(&rules, taille, energy_multithreading, &bestRules, nbrule,
                parameter);
    copyRuleSet(bestRules, &rules);
    printf("Progression de l'apprentissage : %d%%\n",
           (i * 100) / nombre_lancer);
  }

  writeRulesToFile(bestRules.rules, NB_RULES, "../bestRules.txt");

  return 0;
}