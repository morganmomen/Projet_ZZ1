#include "recuit_simule.h"
#include <../rules/changeRules.h>
#include <../rules/rules.h>
#include <../rules/energy.h>






regle_t ** recuit_simule (regle_t **rules,int T, int energy(int** grapheComplet, regle_t **state, int N)) 
{
    regle_t ** newrules = malloc(NB_RULES*sizeof(rules));
    while (T > 0) 
    {
        genereEtat(grapheComplet, state, newState, N);
        if (calculPoids(grapheComplet,newState,N) < calculPoids(grapheComplet,state,N)) 
        if (calculPoids(grapheComplet,newState,N) > state->poids) state=newState;
        double p = exp((state->poids - calculPoids(grapheComplet,newState,N)) / T);
        if (p > rand() / RAND_MAX) state=newState;
        T--;
    }
    return state;
}