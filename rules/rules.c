#include "rules.h"
#include "energy.h"
#include <stdio.h>
#include <stdlib.h>

void generateRule( rule_t *rule) {
  srand(time(NULL) + rand());
  rule->_case[0] = (rand() % 4) -1;
  rule->_case[1] = (rand() % 4) -1;
  rule->_case[2] = (rand() % 4) -1;
  rule->_case[3] = (rand() % 4) -1;
  rule->direction_predateur = (rand() % 5) -1;
  rule->direction_terrier = (rand() % 5) -1;
  rule->distance_predateur = (rand() % 3) -1;
  rule->distance_terrier = (rand() % 3) -1;
  rule->action = (rand() % 4);
  rule->priority = (rand() % 4);
  
}


// ruleSet_t **generateRuleSet() {
//   rule_t **rules = malloc(sizeof(ruleSet_t *));
//   for (int i = 0; i < NB_RULES; i++)
//     generateRule(&rules[i]);
//   return rules;
// }

void printRule(rule_t *rule) {
 printf("Rule:[%d,%d,%d,%d,%d,%d,%d,%d] => %d (%d)\n", rule->_case[0], rule->_case[1], rule->_case[2], rule->_case[3], rule->direction_predateur, rule->direction_terrier, rule->distance_predateur, rule->distance_terrier, rule->action, rule->priority);
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
