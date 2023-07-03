#include "recuit_simule.h"
#include "rules/changeRules.h"
#include "rules/energy.h"
#include "rules/rules.h"
/**
 * @brief Algorithme du recuit simulé sur un ensemble de règles
 * 
 * @param rules Ensemble de règles 
 * @param T Température
 * @param energy Performance de l'ensemble de règles
 * @return rules Ensemble de règles optimisé 
 */
ruleSet_t *recuit_simule(ruleSet_t *rules, int T,
                         int energy(ruleSet_t *rules)) {
  ruleSet_t *newRules;
  while (T > 0) {
    newRules = changeRuleSet(rules); // Génération d'un nouvel ensemble de règles
    newRules->energy = energy(newRules); // Calcul de la performance de l'ensemble de règles
    if (newRules->energy < rules->energy)
      rules = newRules;
    rules->energy = energy(newRules);
    double p = exp((energy(rules) - energy(newRules)) / T);
    if (p > rand() / RAND_MAX) // Si le nouvel ensemble de règles n'améliore pas la performance, on le garde avec une probabilité p
      rules = newRules;
    rules->energy = energy(newRules);
    T--;
  }
  return rules;
}
