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
    regle_t *rules[NB_RULES];
    int energy;
}ruleSet_t;
