#include "recuit_simule.h"
#include <stdlib.h>






state * recuit_simule (int ** grapheComplet,int N, int T, int calculPoids(int** grapheComplet, etat *state, int N)) 
{
    etat * state = genereCycleHamiltonien(grapheComplet, N);
    etat * newState = malloc(sizeof(etat));
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