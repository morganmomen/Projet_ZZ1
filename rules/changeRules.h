#include "rules.h"

/**
 * @brief Change la regle d'une case d'une règle
 *
 * @param _case Structure identifiant le contenu de la case
 * @param direction Détermine la case a regarder (0: haut, 1: gauche, 2: bas, 3:
 * droite)
 * @param changement augmente de 1 ou diminue de 1 la valeur de la case
 * @return case_t
 */
case_t change_case(case_t *_case, int direction, int changement);
/**
 * @brief Change la regle de direction
 *
 * @param direction Structure identifiant la direction du prédateur
 * @param changement augmente de 1 ou diminue de 1 la valeur de la direction
 * @return direction4_t
 */
direction4_t change_direction(direction4_t *direction, int changement);
/**
 * @brief Change la regle de distance
 *
 * @param distance Structure identifiant la distance
 * @param changement augmente de 1 ou diminue de 1 la valeur de la distance
 * @return distance_t
 */
distance_t change_distance(distance_t *distance, int changement);

/**
 * @brief Change la regle d'action
 *
 * @param action Structure identifiant l'action
 * @param changement augmente de 1 ou diminue de 1 la valeur de l'action
 * @return action_t
 */
action_t change_action(action_t *action, int changement);
/**
 * @brief Change la regle de priorité
 *
 * @param priority Structure identifiant la priorité
 * @param changement augmente de 1 ou diminue de 1 la valeur de la priorité
 * @return int
 */
int change_priority(int priority, int changement);
/**
 * @brief Change la regle de l'ensemble de règles en utilisant les fonctions
 * précédentes : change_case, change_direction, change_distance, change_action,
 * change_priority On prend chaques valeurs dans la règle, on augmente de 1 ou
 * diminue de 1 et on compare l'énergie de la règle avec la nouvelle règle. On
 * garde la meilleure règle.
 *
 * @param rules Ensemble de règles
 * @return ruleSet_t*
 */
rule_t *changeRule(ruleSet_t rules, int id_rule);
/**
 * @brief Change l'ensemble de règles en utilisant la fonction changeRule
 *
 * @param rules Ensemble de règles
 * @return ruleSet_t*
 */
ruleSet_t *changeRuleSet(ruleSet_t *rules);