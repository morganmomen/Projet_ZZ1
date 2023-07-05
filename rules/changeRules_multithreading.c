#include "changeRules.h"
#include <limits.h>

void copyRuleSet(ruleSet_t rules, ruleSet_t* copy) {
  copy->rules = malloc(NB_RULES*sizeof(rule_t));
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
}
int choose_rule() {
  int rule = rand() % NB_RULES;
  return rule;
}
int choose_parameter() {
  int parameter = rand() % 10;
  return parameter;
}
void insertRule(ruleSet_t ruleset, ruleSet_t *attempt_ruleset, int parameter,
                int possibility, int nb_rule) {

  copyRuleSet(ruleset, attempt_ruleset);
  switch (parameter) {
  case 0:
    attempt_ruleset->rules[nb_rule]._case[parameter] = possibility;
    break;
  case 1:
    attempt_ruleset->rules[nb_rule]._case[parameter] = possibility;
    break;
  case 2:
    attempt_ruleset->rules[nb_rule]._case[parameter] = possibility;
    break;
  case 3:
    attempt_ruleset->rules[nb_rule]._case[parameter] = possibility;
    break;
  case 4:
    attempt_ruleset->rules[nb_rule].direction_predateur = possibility;
    break;
  case 5:
    attempt_ruleset->rules[nb_rule].direction_terrier = possibility;
    break;
  case 6:
    attempt_ruleset->rules[nb_rule].distance_predateur = possibility;
    break;
  case 7:
    attempt_ruleset->rules[nb_rule].distance_terrier = possibility;
    break;
  case 8:
    attempt_ruleset->rules[nb_rule].action = possibility;
    break;
  case 9:
    attempt_ruleset->rules[nb_rule].priority = possibility;
    break;
  default:
    break;
  }
}
void change_case2(ruleSet_t ruleset, int nb_rule, int parameter, void energy(ruleSet_t rules,int taille, int coef_chasseur, int coef_terrier),int taille,ruleSet_t* bestRules) {
  int bestEnergy = INT_MAX;
  int bestruleSet = -1;
  ruleSet_t ruleset_attempt[6];
  ruleSet_t tempRuleset;
  for (int i = 0; i < 6; i++) {
    insertRule(ruleset, &tempRuleset, parameter, i - 1, nb_rule);
    energy(tempRuleset,taille,0,1);
    if (tempRuleset.energy <= bestEnergy) {
      bestEnergy = tempRuleset.energy;
      bestruleSet = i;
    }
    ruleset_attempt[i]=tempRuleset;
  }
  *bestRules=ruleset_attempt[bestruleSet];
}

void change_direction_2(ruleSet_t ruleset, int nb_rule, int parameter, void energy(ruleSet_t rules,int taille, int coef_chasseur, int coef_terrier), int taille,ruleSet_t* bestRules) {
  int bestEnergy = INT_MAX;
  int bestruleSet = -1;
  ruleSet_t ruleset_attempt[5];
  ruleSet_t tempRuleset;
  for (int i = 0; i < 5; i++) {
    insertRule(ruleset, &tempRuleset, parameter, i - 1, nb_rule);
    energy(tempRuleset,taille,0,1);
    if (tempRuleset.energy <= bestEnergy) {
      bestEnergy = tempRuleset.energy;
      bestruleSet = i;
    }
    ruleset_attempt[i]=tempRuleset;
  }
  *bestRules=ruleset_attempt[bestruleSet];
}
void change_distance_2(ruleSet_t ruleset, int nb_rule, int parameter, void energy(ruleSet_t rules,int taille, int coef_chasseur, int coef_terrier),int taille,ruleSet_t* bestRules) {
  int bestEnergy = INT_MAX;
  int bestruleSet = -1;
  ruleSet_t ruleset_attempt[4];
  ruleSet_t tempRuleset;
  for (int i = 0; i < 4; i++) {
    insertRule(ruleset, &tempRuleset, parameter, i -1,nb_rule);
    energy(tempRuleset,taille,0,1);
    if (tempRuleset.energy <= bestEnergy) {
      bestEnergy = tempRuleset.energy;
      bestruleSet = i;
    }
    ruleset_attempt[i]=tempRuleset;
  }
  *bestRules=ruleset_attempt[bestruleSet];
}

void change_action_2(ruleSet_t ruleset, int nb_rule, int parameter, void energy(ruleSet_t rules,int taille, int coef_chasseur, int coef_terrier),int taille,ruleSet_t* bestRules) {
  int bestEnergy = INT_MAX;
  int bestruleSet = -1;
  ruleSet_t ruleset_attempt[3];
  ruleSet_t tempRuleset;
  for (int i = 0; i < 3; i++) {
     insertRule(ruleset, &tempRuleset, parameter, i, nb_rule);
    energy(tempRuleset,taille,0,1);
    if (tempRuleset.energy <= bestEnergy) {
      bestEnergy = tempRuleset.energy;
      bestruleSet = i;
    }
    ruleset_attempt[i]=tempRuleset;
  }
  *bestRules=ruleset_attempt[bestruleSet];
}

void change_priority_2(ruleSet_t ruleset, int nb_rule, int parameter, void energy(ruleSet_t rules,int taille, int coef_chasseur, int coef_terrier),int taille,ruleSet_t* bestRules) {
  int bestEnergy = INT_MAX;
  int bestruleSet = -1;
  ruleSet_t ruleset_attempt[3];
  ruleSet_t tempRuleset;
  for (int i = 1; i < 4; i++) {
    insertRule(ruleset, &tempRuleset, parameter, i, nb_rule);

    energy(tempRuleset,taille,0,1);
    if (tempRuleset.energy <= bestEnergy) {
      bestEnergy = tempRuleset.energy;
      bestruleSet = i;
    }
    ruleset_attempt[i-1]=tempRuleset;
  }
  *bestRules=ruleset_attempt[bestruleSet-1];
}
void changeRule2(ruleSet_t *rules,int taille,void energy(ruleSet_t rules,int taille, int coef_chasseur, int coef_terrier), ruleSet_t * bestRules, int nb_rule, int parameter) {
    printf("nb_rule : %d\n",nb_rule );
    printf("parameter : %d\n",parameter );
  switch (parameter) {

  case 0:
    change_case2(*rules, nb_rule, parameter, energy,taille,bestRules);
    break;
  case 1:
    change_case2(*rules, nb_rule, parameter, energy,taille,bestRules);
    break;
  case 2:
    change_case2(*rules, nb_rule, parameter, energy,taille,bestRules);
    break;
  case 3:
    change_case2(*rules, nb_rule, parameter, energy,taille,bestRules);
    break;
  case 4:
    change_direction_2(*rules, nb_rule, parameter, energy,taille,bestRules);
    break;
  case 5:
    change_direction_2(*rules, nb_rule, parameter, energy,taille,bestRules);
    break;
  case 6:
    change_distance_2(*rules, nb_rule, parameter, energy,taille,bestRules);
    break;
  case 7:
    change_distance_2(*rules, nb_rule, parameter, energy,taille,bestRules);
    break;
  case 8:
    change_action_2(*rules, nb_rule, parameter, energy,taille,bestRules);
    break;
  case 9:
    change_priority_2(*rules, nb_rule, parameter, energy,taille,bestRules);
    break;
  default:
    break;
  }
}
