#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "rules.h"




action_t choixRule(rule_t *rule, joueur_t *joueur);
int isRuleValid(rule_t *rule, joueur_t *joueur);