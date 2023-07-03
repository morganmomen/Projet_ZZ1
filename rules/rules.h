#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


#ifndef RULES_H
#define RULES_H


#define N 4 
#define NB_RULES 25

typedef enum  { JOKER = -1, MUR, VIDE, TERRIER } case_t;

typedef enum { NORD, OUEST, SUD, EST } direction4_t;

typedef enum { PROCHE, MOYEN, LOIN } distance_t;
typedef enum { AVANCER, RECULER, TOURNER_GAUCHE, TOURNER_DROITE } action_t;

typedef struct {
  case_t devant, gauche, derriere, droite;
  direction4_t direction_predateur;
  direction4_t direction_terrier;
  distance_t distance_predateur;
  distance_t distance_terrier;
  action_t action;
  int priority;

} rule_t;

typedef struct joueur
{
  int x, y; // position du joueur
  case_t devant, gauche, derriere, droite;
  direction4_t direction_predateur;
  direction4_t direction_terrier;
  distance_t distance_predateur;
  distance_t distance_terrier;
}joueur_t;


typedef struct {
  rule_t *rules[NB_RULES];
  int energy;
} ruleSet_t;

void generateRule(rule_t *rule);
ruleSet_t **generateRuleSet();
void printRule(rule_t *rule);
void printRuleSet(rule_t **rules);
void freeRule(rule_t *rule);
void freeRuleSet(rule_t **rules);
#endif