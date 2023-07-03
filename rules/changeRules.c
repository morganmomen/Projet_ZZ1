#include "changeRules.h"
#include "rules.h"

// void changeRule1(rule_t *rule) {
//   int randompos;
//   int randomval;
//   int randomprio;

//   randompos = rand() % N;
//   randomval = rand() % N;
//   randomprio = rand() % N;
//   rule->rules[randompos] = rule->possibleValues[randomval];
//   rule->priority = randomprio;
// }

// void changeRule2(ruleSet_t *rules, int i, int energy(ruleSet_t *rules)) {
//   ruleSet_t *bestRules = malloc(sizeof(ruleSet_t));
//   bestRules = rules;
//   int bestEnergy = rules->energy;
//   int randompos = rand() % N;
//   for (int i = 0; i < N; i++) {
//     rules->rules[i]->rules[randompos] = rules->rules[i]->possibleValues[i];
//     if (energy(rules) < bestEnergy) {
//       bestRules = rules;
//       bestEnergy = energy(rules);
//     }
//   }

//   bestRules->energy = bestEnergy;
// }

// void changeRule3(ruleSet_t *rules, int energy(ruleSet_t *rules), int pos) {
//   ruleSet_t *bestRules = malloc(sizeof(ruleSet_t));
//   bestRules = rules;
//   int bestEnergy = rules->energy;
//   for (int i = 0; i < N; i++) {
//     rules->rules[pos] = rules->rules[i]->possibleValues[i];
//     if (energy(rules) < bestEnergy) {
//       bestRules = rules;
//       bestEnergy = energy(rules);
//     }
//   }
// }
void change_case(case_t case, int changement)
{
  for (int i =0, i<4, i++)
  {
    if (case[i] i<3 changement)
    {
      case[i] = rand() % 4;
    }
  }
}
void change_direction()
void change_distance()
void change_action()
void changeRule4(rule_t *rule, ) 
{
  



}

ruleSet_t **changeRuleSet(ruleSet_t **rules) {
  for (int i = 0; i < NB_RULES; i++)
    changeRule1(rules[i]);
  return rules;
}