#define NB_RULES 25

typedef enum { JOKER = -1, VIDE, MUR, TERRIER, LAPIN, CHASSEUR} case_t;

typedef enum { NORD, OUEST, SUD, EST } direction4_t;

typedef enum { PROCHE, MOYEN, LOIN } distance_t;
typedef enum { AVANCER, GAUCHE, RECULER, DROITE } action_t;

typedef struct {
  case_t _case[4];
  direction4_t direction_predateur;
  direction4_t direction_terrier;
  distance_t distance_predateur;
  distance_t distance_terrier;
  action_t action;
  int priority;

} rule_t;

typedef struct {
    int updated;
  rule_t *rules[NB_RULES];
  int energy;
} ruleSet_t;

rule_t *generateRule();
ruleSet_t **generateRuleSet();
void printRule(rule_t *rule);
void printRuleSet(rule_t **rules);
void freeRule(rule_t *rule);
void freeRuleSet(rule_t **rules);