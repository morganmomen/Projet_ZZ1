#include "changeRules_multithreading.h"
#include <limits.h>

void copyRuleSet(ruleSet_t rules, ruleSet_t *copy) {
  copy->rules = malloc(NB_RULES * sizeof(rule_t));
  copy->energy = rules.energy;
  for (int i = 0; i < NB_RULES; i++) {
    copy->rules[i]._case[0] = rules.rules[i]._case[0];
    copy->rules[i]._case[1] = rules.rules[i]._case[1];
    copy->rules[i]._case[2] = rules.rules[i]._case[2];
    copy->rules[i]._case[3] = rules.rules[i]._case[3];
    copy->rules[i].direction_predateur = rules.rules[i].direction_predateur;
    copy->rules[i].direction_terrier = rules.rules[i].direction_terrier;
    copy->rules[i].distance_predateur = rules.rules[i].distance_predateur;
    copy->rules[i].distance_terrier = rules.rules[i].distance_terrier;
    copy->rules[i].action = rules.rules[i].action;
    copy->rules[i].priority = rules.rules[i].priority;
  }
  // printf("Sortie de Copie\n");
  // printRuleSet(&rules);
}

void setup_attempts(ruleSet_t *attempts, int taille_attempts,
                    ruleSet_t intial_ruleset, int parameter, int possibility,
                    int nb_rule) {
  for (int i = 0; i < taille_attempts; i++) {
    attempts[i].rules = malloc(NB_RULES * sizeof(rule_t));
    attempts[i].energy = 0;
  }
  for (int i = 0; i < taille_attempts; i++) {
    copyRuleSet(intial_ruleset, &attempts[i]);
    insertRule(attempts[i], parameter, possibility, nb_rule);
  }
}

int choose_rule() {
  int rule = rand() % NB_RULES;
  return rule;
}
int choose_parameter() {
  int parameter = rand() % 10;
  return parameter;
}
void insertRule(ruleSet_t attempt_ruleset, int parameter, int possibility,
                int nb_rule) {

  switch (parameter) {
  case 0:
    attempt_ruleset.rules[nb_rule]._case[parameter] = possibility;
    break;
  case 1:
    attempt_ruleset.rules[nb_rule]._case[parameter] = possibility;
    break;
  case 2:
    attempt_ruleset.rules[nb_rule]._case[parameter] = possibility;
    break;
  case 3:
    attempt_ruleset.rules[nb_rule]._case[parameter] = possibility;
    break;
  case 4:
    attempt_ruleset.rules[nb_rule].direction_predateur = possibility;
    break;
  case 5:
    attempt_ruleset.rules[nb_rule].direction_terrier = possibility;
    break;
  case 6:
    attempt_ruleset.rules[nb_rule].distance_predateur = possibility;
    break;
  case 7:
    attempt_ruleset.rules[nb_rule].distance_terrier = possibility;
    break;
  case 8:
    attempt_ruleset.rules[nb_rule].action = possibility;
    break;
  case 9:
    attempt_ruleset.rules[nb_rule].priority = possibility;
    break;
  default:
    break;
  }
  // printf("Sortie de changement\n");
  // printRuleSet(&ruleset);
}
void change_case2(ruleSet_t ruleset, int nb_rule, int parameter,
                  void energy_multithreading(ruleSet_t **attempt_rules,
                                             int nb_threads, int taille,
                                             int coef_chasseur,
                                             int coef_terrier),
                  int taille, ruleSet_t *bestRules) {
  int bestEnergy = 0;
  int bestruleSet = 0;
  ruleSet_t ruleset_attempt[6];
  setup_attempts(&ruleset_attempt, 6, ruleset, parameter, 0, nb_rule);
  energy_multithreading(&ruleset_attempt, 6, taille, 0, 1);
  for (int i = 0; i < 6; i++) {
    if (ruleset_attempt[i].energy > bestEnergy) {
      bestEnergy = ruleset_attempt[i].energy;
      bestruleSet = i;
    }
  }
  copyRuleSet(ruleset_attempt[bestruleSet], bestRules);
  bestRules->energy = bestEnergy;
}

void change_direction_2(ruleSet_t ruleset, int nb_rule, int parameter,
                        void energy_multithreading(ruleSet_t **attempt_rules,
                                                   int nb_threads, int taille,
                                                   int coef_chasseur,
                                                   int coef_terrier),
                        int taille, ruleSet_t *bestRules) {
  int bestEnergy = 0;
  int bestruleSet = 0;
  ruleSet_t ruleset_attempt[5];
  setup_attempts(&ruleset_attempt, 5, ruleset, parameter, 0, nb_rule);
  energy_multithreading(&ruleset_attempt, 5, taille, 0, 1);
  for (int i = 0; i < 5; i++) {
    if (ruleset_attempt[i].energy > bestEnergy) {
      bestEnergy = ruleset_attempt[i].energy;
      bestruleSet = i;
    }
  }
  copyRuleSet(ruleset_attempt[bestruleSet], bestRules);
  bestRules->energy = bestEnergy;
}

void change_distance_2(ruleSet_t ruleset, int nb_rule, int parameter,
                       void energy_multithreading(ruleSet_t **attempt_rules,
                                                  int nb_threads, int taille,
                                                  int coef_chasseur,
                                                  int coef_terrier),
                       int taille, ruleSet_t *bestRules) {
  int bestEnergy = 0;
  int bestruleSet = 0;
  ruleSet_t ruleset_attempt[4];
  setup_attempts(&ruleset_attempt, 4, ruleset, parameter, 0, nb_rule);
  energy_multithreading(&ruleset_attempt, 4, taille, 0, 1);
  for (int i = 0; i < 4; i++) {
    if (ruleset_attempt[i].energy > bestEnergy) {
      bestEnergy = ruleset_attempt[i].energy;
      bestruleSet = i;
    }
  }
  copyRuleSet(ruleset_attempt[bestruleSet], bestRules);
  bestRules->energy = bestEnergy;
}

void change_action_2(ruleSet_t ruleset, int nb_rule, int parameter,
                     void energy_multithreading(ruleSet_t **attempt_rules,
                                                int nb_threads, int taille,
                                                int coef_chasseur,
                                                int coef_terrier),
                     int taille, ruleSet_t *bestRules) {
  int bestEnergy = 0;
  int bestruleSet = 0;
  ruleSet_t ruleset_attempt[3];
  setup_attempts(&ruleset_attempt, 3, ruleset, parameter, 0, nb_rule);
  energy_multithreading(&ruleset_attempt, 3, taille, 0, 1);
  for (int i = 0; i < 3; i++) {
    if (ruleset_attempt[i].energy > bestEnergy) {
      bestEnergy = ruleset_attempt[i].energy;
      bestruleSet = i;
    }
  }
  copyRuleSet(ruleset_attempt[bestruleSet], bestRules);
  bestRules->energy = bestEnergy;
}

void change_priority_2(ruleSet_t ruleset, int nb_rule, int parameter,
                       void energy_multithreading(ruleSet_t **attempt_rules,
                                                  int nb_threads, int taille,
                                                  int coef_chasseur,
                                                  int coef_terrier),
                       int taille, ruleSet_t *bestRules) {
  int bestEnergy = 0;
  int bestruleSet = 0;
  ruleSet_t ruleset_attempt[3];
  setup_attempts(&ruleset_attempt, 3, ruleset, parameter, 0, nb_rule);
  energy_multithreading(&ruleset_attempt, 3, taille, 0, 1);
  for (int i = 0; i < 3; i++) {
    if (ruleset_attempt[i].energy > bestEnergy) {
      bestEnergy = ruleset_attempt[i].energy;
      bestruleSet = i;
    }
  }
  copyRuleSet(ruleset_attempt[bestruleSet], bestRules);
  bestRules = bestEnergy;
}
void changeRule2(ruleSet_t *rules, int taille,
                 void energy_multithreading(ruleSet_t **attempt_rules,
                                            int nb_threads, int taille,
                                            int coef_chasseur,
                                            int coef_terrier),
                 ruleSet_t *bestRules, int nb_rule, int parameter) {
  printf("nb_rule : %d\n", nb_rule);
  printf("parameter : %d\n", parameter);
  switch (parameter) {

  case 0:
    change_case2(*rules, nb_rule, parameter, energy_multithreading, taille,
                 bestRules);
    break;
  case 1:
    change_case2(*rules, nb_rule, parameter, energy_multithreading, taille,
                 bestRules);
    break;
  case 2:
    change_case2(*rules, nb_rule, parameter, energy_multithreading, taille,
                 bestRules);
    break;
  case 3:
    change_case2(*rules, nb_rule, parameter, energy_multithreading, taille,
                 bestRules);
    break;
  case 4:
    change_direction_2(*rules, nb_rule, parameter, energy_multithreading,
                       taille, bestRules);
    break;
  case 5:
    change_direction_2(*rules, nb_rule, parameter, energy_multithreading,
                       taille, bestRules);
    break;
  case 6:
    change_distance_2(*rules, nb_rule, parameter, energy_multithreading, taille,
                      bestRules);
    break;
  case 7:
    change_distance_2(*rules, nb_rule, parameter, energy_multithreading, taille,
                      bestRules);
    break;
  case 8:
    change_action_2(*rules, nb_rule, parameter, energy_multithreading, taille,
                    bestRules);
    break;
  case 9:
    change_priority_2(*rules, nb_rule, parameter, energy_multithreading, taille,
                      bestRules);
    break;
  default:
    break;
  }
  //printf("bestRules : \n");
  //printRuleSet(bestRules);
}
