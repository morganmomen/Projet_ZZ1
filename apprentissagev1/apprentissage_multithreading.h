#include "../Chasseur/gere_chasseur.h"
#include "../Map/crea_map.h"
#include "../dijkstra/dijkstra.h"
#include "../lapin/mvt_lapin.h"
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  ruleSet_t *rules;
  int taille;
} thread_args_t;

int lancer_jeu_sans_graphisme_apprentissage_multithreading(int taille,
                                                           int *nb_iterations,
                                                           ruleSet_t *rules);
void energy_multithreading(ruleSet_t **attempt_rules, int nb_threads,
                           int taille, int coef_chasseur, int coef_terrier);
void *thread_jeu(void *arg);
void shuffle(int *array, int n);
thread_args_t *setup_thread_args(int nb_thread, int taille);
