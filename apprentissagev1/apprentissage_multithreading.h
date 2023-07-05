#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <pthread.h>
#include "../Map/crea_map.h"
#include "../dijkstra/dijkstra.h"
#include "../Chasseur/gere_chasseur.h"
#include "../lapin/mvt_lapin.h"

typedef struct 
{
    ruleSet_t rules;
    int taille;
    int coef_chasseur;
    int coef_terrier;
}thread_args_t;

int lancer_jeu_sans_graphisme_apprentissage_multithreading(int taille, int *nb_iterations,ruleSet_t *rules);
void energy_multithreading(ruleSet_t *attempt_rules,int nb_threads, int taille, int coef_chasseur, int coef_terrier);
void *thread_jeu(void* arg);
void shuffle(int *array, int n);


