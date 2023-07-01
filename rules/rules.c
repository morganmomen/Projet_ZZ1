#include "rules.h"

regle *generateRule(void) {
  regle *rule = malloc(sizeof(regle));
  for (int i = 0; i < N; i++)
    rule->rules[i] = rand() % N;
  rule->priority = 1;
  return rule;
}

jeu_de_regle *generateRuleSet(int nb_rules) {
  jeu_de_regle *rules = malloc(nb_rules * sizeof(regle *));
  rules->nbrules = nb_rules;
  for (int i = 0; i < nb_rules; i++)
    rules->rule[i] = generateRule();
  return rules;
}

void printRule(regle *rule) {
  printf("Rule: ");
  for (int i = 0; i < N; i++)
    printf("%d ", rule->rules[i]);
  printf("Priority: %d\n", rule->priority);
}
void printRuleSet(jeu_de_regle *rules) {
  printf("Rule set:\n");
  for (int i = 0; i < rules->nbrules; i++)
    printRule(rules->rule[i]);
}

void freeRule(regle *rule) {
  free(rule);
}
void freeRuleSet(jeu_de_regle *rules) {
  for (int i = 0; i < rules->nbrules; i++)
    freeRule(rules->rule[i]);
  free(rules);
}

