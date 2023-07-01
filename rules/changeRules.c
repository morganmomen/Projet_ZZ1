#include "changeRules.h"
#include "rules.h"

regle *changeRule1(regle *rule) {
  int randompos;
  int randomval;
  int randomprio;

  randompos = rand() % N;
  randomval = rand() % N;
  randomprio = rand() % N;
  rule->rules[randompos] = rule->possibleValues[randomval];
  rule->priority = randomprio;
  return rule;
}

regle *changeRule2(regle *rule, int energy(regle *rule)) {
  regle *bestRule = malloc(sizeof(regle));
  bestRule = rule;
    int bestEnergy = energy(rule);
    int randompos = rand() % N;
    for (int i = 0; i < N; i++)
    {
        rule->rules[randompos] = rule->possibleValues[i];
        if (energy(rule) < bestEnergy)
        {
            bestRule = rule;
            bestEnergy = energy(rule);
        }
    }
    

  return rule;
}

regle *changeRule3(regle *rule, int energy(regle *rule),int pos) 
{
    regle *bestRule = malloc(sizeof(regle));
    bestRule = rule;
    int bestEnergy = energy(rule);
    for (int i = 0; i < N; i++)
    {
        rule->rules[pos] = rule->possibleValues[i];
        if (energy(rule) < bestEnergy)
        {
            bestRule = rule;
            bestEnergy = energy(rule);
        }
    }
  return rule;
}