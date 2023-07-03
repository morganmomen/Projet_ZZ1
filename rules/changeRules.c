#include "changeRules.h"
#include "rules.h"

case_t change_case(case_t *_case, int direction, int changement) {
  switch (changement) {
  case 1:
    if (_case[direction] != 3)
      _case[direction] = _case[direction] + changement;
    break;

  case -1:
    if (_case[direction] != -1) {
      _case[direction] = _case[direction] + changement;
    }
    break;
  }
  return *_case;
}
direction4_t change_direction(direction4_t *direction, int changement) {
  switch (changement) {
  case 1:
    if (*direction != 3)
      *direction = *direction + changement;
    break;
  case -1:
    if (*direction != 0)
      *direction = *direction + changement;
    break;
  }
  return *direction;
}
distance_t change_distance(distance_t *distance, int changement) {
  switch (changement) {
  case 1:
    if (*distance != 2)
      *distance = *distance + changement;
    break;
  case -1:
    if (*distance != 0)
      *distance = *distance + changement;
    break;
  }
  return *distance;
}
action_t change_action(action_t *action, int changement) {
  switch (changement) {
  case 1:
    if (*action != 3)
      *action = *action + changement;
    break;
  case -1:
    if (*action != 0)
      *action = *action + changement;
    break;
  }
  return *action;
}
int change_priority(int priority, int changement) {
  switch (changement) {
  case 1:
    if (priority != 3)
      priority = priority + changement;
    break;
  case -1:
    if (priority != 0)
      priority = priority + changement;
    break;
  }
  return priority;
}
rule_t *changeRule(ruleSet_t rules, int id_rule) {
  rule_t *rule_attempt_1;
  rule_t *rule_attempt_2;
  rule_t *best_rule;
  int energy_attempt_1;
  int energy_attempt_2;
  for (int i = 0; i < 4; i++) {
    rule_attempt_1->_case[i] = change_case(rules.rules[id_rule]->_case, i, 1);
    rule_attempt_2->_case[i] = change_case(rules.rules[id_rule]->_case, i, -1);
    rules.rules[id_rule] = rule_attempt_1;
    energy_attempt_1 = energy(rules);
    rules.rules[id_rule] = rule_attempt_2;
    energy_attempt_2 = energy(rules);
    if (energy_attempt_1 < energy_attempt_2) {
      best_rule = rule_attempt_1;
    } else {
      best_rule = rule_attempt_2;
    }
  }
  rule_attempt_1->direction_predateur =
      change_direction(&(rules.rules[id_rule]->direction_predateur), 1);
  rules.rules[id_rule] = rule_attempt_1;
  rule_attempt_2->direction_predateur =
      change_direction(&(rules.rules[id_rule]->direction_predateur), -1);
  rules.rules[id_rule] = rule_attempt_2;
  energy_attempt_1 = energy(rules);
  energy_attempt_2 = energy(rules);
  if (energy_attempt_1 < energy_attempt_2) {
    best_rule = rule_attempt_1;
  } else {
    best_rule = rule_attempt_2;
  }
  rule_attempt_1->direction_terrier =
      change_direction(&(rules.rules[id_rule]->direction_terrier), 1);
  rules.rules[id_rule] = rule_attempt_1;
  rule_attempt_2->direction_terrier =
      change_direction(&(rules.rules[id_rule]->direction_terrier), -1);
  rules.rules[id_rule] = rule_attempt_2;
  energy_attempt_1 = energy(rules);
  energy_attempt_2 = energy(rules);
  if (energy_attempt_1 < energy_attempt_2) {
    best_rule = rule_attempt_1;
  } else {
    best_rule = rule_attempt_2;
  }
  rule_attempt_1->distance_predateur =
      change_distance(&(rules.rules[id_rule]->distance_predateur), 1);
  rules.rules[id_rule] = rule_attempt_1;
  rule_attempt_2->distance_predateur =
      change_distance(&(rules.rules[id_rule]->distance_predateur), -1);
  rules.rules[id_rule] = rule_attempt_2;
  energy_attempt_1 = energy(rules);
  energy_attempt_2 = energy(rules);
  if (energy_attempt_1 < energy_attempt_2) {
    best_rule = rule_attempt_1;
  } else {
    best_rule = rule_attempt_2;
  }
  rule_attempt_1->distance_terrier =
      change_distance(&(rules.rules[id_rule]->distance_terrier), 1);
  rules.rules[id_rule] = rule_attempt_1;
  rule_attempt_2->distance_terrier =
      change_distance(&(rules.rules[id_rule]->distance_terrier), -1);
  rules.rules[id_rule] = rule_attempt_2;
  energy_attempt_1 = energy(rules);
  energy_attempt_2 = energy(rules);
  if (energy_attempt_1 < energy_attempt_2) {
    best_rule = rule_attempt_1;
  } else {
    best_rule = rule_attempt_2;
  }
  rule_attempt_1->action = change_action(&(rules.rules[id_rule]->action), 1);
  rules.rules[id_rule] = rule_attempt_1;
  rule_attempt_2->action = change_action(&(rules.rules[id_rule]->action), -1);
  rules.rules[id_rule] = rule_attempt_2;
  energy_attempt_1 = energy(rules);
  energy_attempt_2 = energy(rules);
  if (energy_attempt_1 < energy_attempt_2) {
    best_rule = rule_attempt_1;
  } else {
    best_rule = rule_attempt_2;
  }
  rule_attempt_1->priority = change_priority(rules.rules[id_rule]->priority, 1);
  rules.rules[id_rule] = rule_attempt_1;
  rule_attempt_2->priority =
      change_priority(rules.rules[id_rule]->priority, -1);
  rules.rules[id_rule] = rule_attempt_2;
  energy_attempt_1 = energy(rules);
  energy_attempt_2 = energy(rules);
  if (energy_attempt_1 < energy_attempt_2) {
    best_rule = rule_attempt_1;
  } else {
    best_rule = rule_attempt_2;
  }

  return best_rule;
}

ruleSet_t *changeRuleSet(ruleSet_t *rules) {
  for (int i = 0; i < NB_RULES; i++)
    rules->rules[i] = changeRule(*rules, i);
  return rules;
}