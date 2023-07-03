#include "rules.h"
#include "energy.h"

rule_t *generateRule() {
  rule_t *rule = malloc(sizeof(rule_t));
  case_t cases[4] = { JOKER, MUR, VIDE, TERRIER };
  rule->devant = cases[rand() % 4];
  rule->gauche = cases[rand() % 4];
  rule->derriere = cases[rand() % 4];
  rule->droite = cases[rand() % 4];
  direction4_t directions[4] = { NORD, OUEST, SUD, EST };
  rule->direction_predateur = directions[rand() % 4];
  rule->direction_terrier = directions[rand() % 4];
  distance_t distances[3] = { PROCHE, MOYEN, LOIN };
  rule->distance_predateur = distances[rand() % 3];
  rule->distance_terrier = distances[rand() % 3];
  return rule;
}

ruleSet_t **generateRuleSet() {
  ruleSet_t *rules = malloc(sizeof(ruleSet_t *));
  for (int i = 0; i < NB_RULES; i++)
    rules->rules[i] = generateRule();
  rules->energy = energy(rules);
  return rules;
}

void printRule(rule_t *rule) {
  printf("Rule: ");
  switch (rule->devant) {
    case JOKER:
      printf("JOKER ");
      break;
    case MUR:
      printf("MUR ");
      break;
    case VIDE:
      printf("VIDE ");
      break;
    case TERRIER:
      printf("TERRIER ");
      break;
  }
  switch (rule->gauche) {
    case JOKER:
      printf("JOKER ");
      break;
    case MUR:
      printf("MUR ");
      break;
    case VIDE:
      printf("VIDE ");
      break;
    case TERRIER:
      printf("TERRIER ");
      break;
  }
  switch (rule->derriere) {
    case JOKER:
      printf("JOKER ");
      break;
    case MUR:
      printf("MUR ");
      break;
    case VIDE:
      printf("VIDE ");
      break;
    case TERRIER:
      printf("TERRIER ");
      break;
  }
  switch (rule->droite) {
    case JOKER:
      printf("JOKER ");
      break;
    case MUR:
      printf("MUR ");
      break;
    case VIDE:
      printf("VIDE ");
      break;
    case TERRIER:
      printf("TERRIER ");
      break;
  }
  switch (rule->direction_predateur) {
    case NORD:
      printf("NORD ");
      break;
    case OUEST:
      printf("OUEST ");
      break;
    case SUD:
      printf("SUD ");
      break;
    case EST:
      printf("EST ");
      break;
  }
  switch (rule->direction_terrier) {
    case NORD:
      printf("NORD ");
      break;
    case OUEST:
      printf("OUEST ");
      break;
    case SUD:
      printf("SUD ");
      break;
    case EST:
      printf("EST ");
      break;
  }
  switch (rule->distance_predateur) {
    case PROCHE:
      printf("PROCHE ");
      break;
    case MOYEN:
      printf("MOYEN ");
      break;
    case LOIN:
      printf("LOIN ");
      break;
  }
  switch (rule->distance_terrier) {
    case PROCHE:
      printf("PROCHE ");
      break;
    case MOYEN:
      printf("MOYEN ");
      break;
    case LOIN:
      printf("LOIN ");
      break;
  }
  switch (rule->action) {
    case AVANCER:
      printf("AVANCER ");
      break;
    case RECULER:
      printf("RECULER ");
      break;
    case TOURNER_GAUCHE:
      printf("TOURNER_GAUCHE ");
      break;
    case TOURNER_DROITE:
      printf("TOURNER_DROITE ");
      break;
  }
  printf("Priority: %d\n", rule->priority);
}
void printRuleSet(rule_t **rules) {
  printf("Rule set:\n");
  for (int i = 0; i < NB_RULES; i++)
    printRule(rules[i]);
}

void freeRule(rule_t *rule) {
  free(rule);
}
void freeRuleSet(rule_t **rules) {
  for (int i = 0; i < NB_RULES; i++)
    freeRule(rules[i]);
  free(rules);
}

