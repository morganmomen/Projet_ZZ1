#include "rules.h"
#include "energy.h"
#include <stdio.h>
#include <stdlib.h>

rule_t *generateRule() {
  rule_t *rule = malloc(sizeof(rule_t));
  for (int i = 0; i < N; i++)
    rule->rules[i] = rand() % N;
  rule->priority = 1;
  return rule;
}

ruleSet_t **generateRuleSet() {
  rule_t **rules = malloc(sizeof(ruleSet_t *));
  for (int i = 0; i < NB_RULES; i++)
    rules[i] = generateRule();
  return rules;
}

void printRule(rule_t *rule) {
 printf("Rule:[%d,%d,%d,%d,%d,%d,%d,%d] => %d (%d)\n", rule->devant, rule->gauche, rule->derriere, rule->droite, rule->direction_predateur, rule->direction_terrier, rule->distance_predateur, rule->distance_terrier, rule->action, rule->priority);
}
void printRuleSet(rule_t **rules) {
  printf("Rule set:\n");
  for (int i = 0; i < NB_RULES; i++)
    printRule(&rules[i]);
}

void freeRule(rule_t *rule) { free(rule); }
void freeRuleSet(rule_t **rules) {
  for (int i = 0; i < NB_RULES; i++)
    freeRule(rules[i]);
  free(rules);
}
