#include <math.h>
#include <time.h>
/**
 * @brief Algorithme du recuit simulé sur un ensemble de règles
 *
 * @param rules Ensemble de règles
 * @param T Température
 * @param energy Performance de l'ensemble de règles
 * @return rules Ensemble de règles optimisé
 */
ruleSet_t *recuit_simule(ruleSet_t *rules, int T, int energy(ruleSet_t *rules));