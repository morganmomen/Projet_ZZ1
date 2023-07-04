#include "changeRules.h"
// /**
//  * @brief Change la regle d'une case d'une règle
//  *
//  * @param _case Structure identifiant le contenu de la case
//  * @param direction Détermine la case a regarder (0: haut, 1: gauche, 2: bas, 3:
//  * droite)
//  * @param changement augmente de 1 ou diminue de 1 la valeur de la case
//  * @return case_t
//  */
// case_t change_case(case_t *_case, int direction, int changement) {
//   switch (changement) {
//   case 1:
//     if (_case[direction] != 3)
//       _case[direction] = _case[direction] + changement;
//     break;

//   case -1:
//     if (_case[direction] != -1) {
//       _case[direction] = _case[direction] + changement;
//     }
//     break;
//   }
//   return *_case;
// }
// /**
//  * @brief Change la regle de direction
//  * @param direction Structure identifiant la direction
//  * @param changement augmente de 1 ou diminue de 1 la valeur de la direction
//  * @return direction4_t
//  */
// direction4_t change_direction(direction4_t *direction, int changement) {
//   switch (changement) {
//   case 1:
//     if (*direction != 3)
//       *direction = *direction + changement;
//     break;
//   case -1:
//     if (*direction != 0)
//       *direction = *direction + changement;
//     break;
//   }
//   return *direction;
// }
// /**
//  * @brief Change la regle de distance
//  *
//  * @param distance Structure identifiant la distance
//  * @param changement augmente de 1 ou diminue de 1 la valeur de la distance
//  * @return distance_t
//  */
// distance_t change_distance(distance_t *distance, int changement) {
//   switch (changement) {
//   case 1:
//     if (*distance != 2)
//       *distance = *distance + changement;
//     break;
//   case -1:
//     if (*distance != 0)
//       *distance = *distance + changement;
//     break;
//   }
//   return *distance;
// }
// /**
//  * @brief Change la regle d'action
//  *
//  * @param action Structure identifiant l'action
//  * @param changement augmente de 1 ou diminue de 1 la valeur de l'action
//  * @return action_t
//  */
// action_t change_action(action_t *action, int changement) {
//   switch (changement) {
//   case 1:
//     if (*action != 3)
//       *action = *action + changement;
//     break;
//   case -1:
//     if (*action != 0)
//       *action = *action + changement;
//     break;
//   }
//   return *action;
// }
// /**
//  * @brief Change la regle de priorité
//  *
//  * @param priority Structure identifiant la priorité
//  * @param changement augmente de 1 ou diminue de 1 la valeur de la priorité
//  * @return int
//  */
// int change_priority(int priority, int changement) {
//   switch (changement) {
//   case 1:
//     if (priority != 3)
//       priority = priority + changement;
//     break;
//   case -1:
//     if (priority != 0)
//       priority = priority + changement;
//     break;
//   }
//   return priority;
// }
// /**
//  * @brief Change la regle de l'ensemble de règles en utilisant les fonctions
//  * précédentes : change_case, change_direction, change_distance, change_action,
//  * change_priority On prend chaques valeurs dans la règle, on augmente de 1 ou
//  * diminue de 1 et on compare l'énergie de la règle avec la nouvelle règle. On
//  * garde la meilleure règle.
//  *
//  * @param rules Ensemble de règles
//  * @return ruleSet_t*
//  */
// rule_t *changeRule(ruleSet_t rules, int id_rule) {
//   rule_t *rule_attempt_1;
//   rule_t *rule_attempt_2;
//   rule_t *best_rule;
//   int energy_attempt_1;
//   int energy_attempt_2;
//   for (int i = 0; i < 4; i++) {
//     rule_attempt_1->_case[i] = change_case(rules->rules[id_rule]->_case, i, 1);
//     rule_attempt_2->_case[i] = change_case(rules->rules[id_rule]->_case, i, -1);
//     rules.rules[id_rule] = rule_attempt_1;
//     energy_attempt_1 = energy(rules);
//     rules.rules[id_rule] = rule_attempt_2;
//     energy_attempt_2 = energy(rules);
//     if (energy_attempt_1 < energy_attempt_2) {
//       best_rule = rule_attempt_1;
//     } else {
//       best_rule = rule_attempt_2;
//     }
//   }
//   rule_attempt_1->direction_predateur =
//       change_direction(&(rules.rules[id_rule]->direction_predateur), 1);
//   rules.rules[id_rule] = rule_attempt_1;
//   rule_attempt_2->direction_predateur =
//       change_direction(&(rules.rules[id_rule]->direction_predateur), -1);
//   rules.rules[id_rule] = rule_attempt_2;
//   energy_attempt_1 = energy(rules);
//   energy_attempt_2 = energy(rules);
//   if (energy_attempt_1 < energy_attempt_2) {
//     best_rule = rule_attempt_1;
//   } else {
//     best_rule = rule_attempt_2;
//   }
//   rule_attempt_1->direction_terrier =
//       change_direction(&(rules.rules[id_rule]->direction_terrier), 1);
//   rules.rules[id_rule] = rule_attempt_1;
//   rule_attempt_2->direction_terrier =
//       change_direction(&(rules.rules[id_rule]->direction_terrier), -1);
//   rules.rules[id_rule] = rule_attempt_2;
//   energy_attempt_1 = energy(rules);
//   energy_attempt_2 = energy(rules);
//   if (energy_attempt_1 < energy_attempt_2) {
//     best_rule = rule_attempt_1;
//   } else {
//     best_rule = rule_attempt_2;
//   }
//   rule_attempt_1->distance_predateur =
//       change_distance(&(rules.rules[id_rule]->distance_predateur), 1);
//   rules.rules[id_rule] = rule_attempt_1;
//   rule_attempt_2->distance_predateur =
//       change_distance(&(rules.rules[id_rule]->distance_predateur), -1);
//   rules.rules[id_rule] = rule_attempt_2;
//   energy_attempt_1 = energy(rules);
//   energy_attempt_2 = energy(rules);
//   if (energy_attempt_1 < energy_attempt_2) {
//     best_rule = rule_attempt_1;
//   } else {
//     best_rule = rule_attempt_2;
//   }
//   rule_attempt_1->distance_terrier =
//       change_distance(&(rules.rules[id_rule]->distance_terrier), 1);
//   rules.rules[id_rule] = rule_attempt_1;
//   rule_attempt_2->distance_terrier =
//       change_distance(&(rules.rules[id_rule]->distance_terrier), -1);
//   rules.rules[id_rule] = rule_attempt_2;
//   energy_attempt_1 = energy(rules);
//   energy_attempt_2 = energy(rules);
//   if (energy_attempt_1 < energy_attempt_2) {
//     best_rule = rule_attempt_1;
//   } else {
//     best_rule = rule_attempt_2;
//   }
//   rule_attempt_1->action = change_action(&(rules.rules[id_rule]->action), 1);
//   rules.rules[id_rule] = rule_attempt_1;
//   rule_attempt_2->action = change_action(&(rules.rules[id_rule]->action), -1);
//   rules.rules[id_rule] = rule_attempt_2;
//   energy_attempt_1 = energy(rules);
//   energy_attempt_2 = energy(rules);
//   if (energy_attempt_1 < energy_attempt_2) {
//     best_rule = rule_attempt_1;
//   } else {
//     best_rule = rule_attempt_2;
//   }
//   rule_attempt_1->priority = change_priority(rules.rules[id_rule]->priority, 1);
//   rules.rules[id_rule] = rule_attempt_1;
//   rule_attempt_2->priority =
//       change_priority(rules.rules[id_rule]->priority, -1);
//   rules.rules[id_rule] = rule_attempt_2;
//   energy_attempt_1 = energy(rules);
//   energy_attempt_2 = energy(rules);
//   if (energy_attempt_1 < energy_attempt_2) {
//     best_rule = rule_attempt_1;
//   } else {
//     best_rule = rule_attempt_2;
//   }

//   return best_rule;
// }
// /**
//  * @brief Change l'ensemble de règles en utilisant la fonction changeRule
//  *
//  * @param rules Ensemble de règles
//  * @return ruleSet_t*
//  */
// ruleSet_t *changeRuleSet(ruleSet_t *rules) {
//   for (int i = 0; i < NB_RULES; i++)
//     rules->rules[i] = changeRule(*rules, i);
//   return rules;
// }

int choose_rule()
{
  int rule = rand() %NB_RULES;
  return rule;
}
int choose_parameter()
{
  int parameter = rand() %10;
  return parameter; 
}

