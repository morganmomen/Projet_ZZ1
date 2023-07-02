#define N 4
#define NB_RULES 25
typedef struct
{
    int possibleValues[N];
    int rules[N];
    int priority;
}rule_t;


typedef struct
{
    rule_t *rules[NB_RULES];
    int energy;
}ruleSet_t;

rule_t *generateRule();
ruleSet_t **generateRuleSet();
void printRule(rule_t *rule);
void printRuleSet(rule_t **rules);
void freeRule(rule_t *rule);
void freeRuleSet(rule_t **rules);