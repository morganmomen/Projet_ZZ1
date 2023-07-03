#include "recuit_simule.h"
#include "rules/changeRules.h"
#include "rules/energy.h"
#include "rules/rules.h"

ruleSet_t *recuit_simule(ruleSet_t *rules, int T, int energy(ruleSet_t *rules)) {
  ruleSet_t *newRules;
  while (T > 0) {
    newRules = changeRuleSet(rules);
    if (energy(newRules) < energy(rules))
      rules = newRules;
    double p = exp((energy(rules) - energy(newRules)) / T);
    if (p > rand() / RAND_MAX)
      rules = newRules;
    T--;
  }
  return rules;
}
