#include "rules.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

action_t choixRule(ruleSet_t *rules, joueur_t *joueur);
int isRuleValid(rule_t *rule, joueur_t *joueur);