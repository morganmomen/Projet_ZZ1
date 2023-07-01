#include "rules.h"
#include "energy.h"

regle_t *generateRule(void) {
  regle_t *rule = malloc(sizeof(regle_t));
  for (int i = 0; i < N; i++)
    rule->rules[i] = rand() % N;
  rule->priority = 1;
  return rule;
}

regle_t **generateRuleSet() {
  regle_t **rules = malloc(NB_RULES * sizeof(regle_t *));
  for (int i = 0; i < NB_RULES; i++)
    rules[i] = generateRule();
  return rules;
}

void printRule(regle_t *rule) {
  printf("Rule: ");
  for (int i = 0; i < N; i++)
    printf("%d ", rule->rules[i]);
  printf("Priority: %d\n", rule->priority);
}
void printRuleSet(regle_t **rules) {
  printf("Rule set:\n");
  for (int i = 0; i < NB_RULES; i++)
    printRule(rules[i]);
}

void freeRule(regle_t *rule) {
  free(rule);
}
void freeRuleSet(regle_t **rules) {
  for (int i = 0; i < NB_RULES; i++)
    freeRule(rules[i]);
  free(rules);
}

