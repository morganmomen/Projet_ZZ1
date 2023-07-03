#include "rules.h"
case_t change_case(case_t *_case, int direction, int changement);
direction4_t change_direction(direction4_t *direction, int changement);
distance_t change_distance(distance_t *distance, int changement);
action_t change_action(action_t *action, int changement);
int change_priority(int priority, int changement);
rule_t *changeRule(ruleSet_t rules, int id_rule);
ruleSet_t *changeRuleSet(ruleSet_t *rules);