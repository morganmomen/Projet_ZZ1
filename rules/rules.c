#include "rules.h"
#include "energy.h"
#include <stdio.h>
#include <stdlib.h>

void generateRule(rule_t *rule) {
  srand(time(NULL) + rand());
  rule->_case[0] = (rand() % 4) - 1;
  rule->_case[1] = (rand() % 4) - 1;
  rule->_case[2] = (rand() % 4) - 1;
  rule->_case[3] = (rand() % 4) - 1;
  rule->direction_predateur = (rand() % 5) - 1;
  rule->direction_terrier = (rand() % 5) - 1;
  rule->distance_predateur = (rand() % 3) - 1;
  rule->distance_terrier = (rand() % 3) - 1;
  rule->action = (rand() % 4);
  rule->priority = (rand() % 4);
}

ruleSet_t *generateRuleSet() {
  ruleSet_t *rules = (ruleSet_t *)malloc(sizeof(ruleSet_t));
  for (int i = 0; i < NB_RULES; i++)
    generateRule(&(rules->rules[i]));
  return rules;
}

void printRule(rule_t *rule) {
  printf("Rule:[%d,%d,%d,%d,%d,%d,%d,%d] => %d (%d)\n", rule->_case[0],
         rule->_case[1], rule->_case[2], rule->_case[3],
         rule->direction_predateur, rule->direction_terrier,
         rule->distance_predateur, rule->distance_terrier, rule->action,
         rule->priority);
}
void printRuleSet(ruleSet_t *rules) {
  printf("Rule set:\n");
  for (int i = 0; i < NB_RULES; i++)
    printRule(&(rules->rules[i]));
}

void freeRule(rule_t *rule) { free(rule); }
void freeRuleSet(rule_t **rules) {
  for (int i = 0; i < NB_RULES; i++)
    freeRule(rules[i]);
  free(rules);
}


rule_t* readRulesFromFile(int* size, const char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    *size = 0;
    return NULL;
  }

  // Lire le nombre de règles en premier paramètre
  fscanf(file, "%d\n", size);

  // Allouer le tableau pour les règles
  rule_t* rules = (rule_t*)malloc(*size * sizeof(rule_t));

  // Lire les règles à partir du fichier
  int i = 0;
  while (fscanf(file, "[%d,%d,%d,%d,%d,%d,%d,%d] => %d (%d)\n", &rules[i]._case[0], &rules[i]._case[1], &rules[i]._case[2],
                &rules[i]._case[3], &rules[i].direction_predateur, &rules[i].direction_terrier,
                &rules[i].distance_predateur, &rules[i].distance_terrier, &rules[i].action, &rules[i].priority) != EOF) {
    i++;
  }

  fclose(file);
  return rules;
}

void writeRulesToFile(rule_t* rules, int size, const char* filename) {
  FILE* file = fopen(filename, "w");
  if (file == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    return;
  }

  fprintf(file, "%d\n", size); // Écrire le nombre de règles en premier paramètre

  for (int i = 0; i < size; i++) {
    rule_t rule = rules[i];
    fprintf(file, "[%d,%d,%d,%d,%d,%d,%d,%d] => %d (%d)\n", rule._case[0], rule._case[1], rule._case[2], rule._case[3],
            rule.direction_predateur, rule.direction_terrier, rule.distance_predateur, rule.distance_terrier,
            rule.action, rule.priority);
  }

  fclose(file);
}
