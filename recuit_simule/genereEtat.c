#ifndef GENETAT_H
#define GENETAT_H
#include "genereEtat.h"
#endif
#include "recuit_simulé.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calculPoids(int** grapheComplet, etat* state, int N)
{
    int poids = 0;
    for (int i = 0; i < N-1; i++) poids += grapheComplet[state->liste_sommet[i]][state->liste_sommet[i + 1]];
    poids += grapheComplet[state->liste_sommet[N-1]][state->liste_sommet[0]];
    return poids;
}
etat *genereCycleHamiltonien(int **grapheComplet,int N)
{
    etat * etat_initial = malloc(sizeof(etat));
    etat_initial->liste_sommet = malloc((N+1)* sizeof(int));
    for ( int i = 0; i < N; i++) etat_initial->liste_sommet[i] = i;
    etat_initial->liste_sommet[N] = 0;
    etat_initial->poids = calculPoids(grapheComplet, etat_initial, N);
    return etat_initial;
}

int* permuter(int* liste, int i, int j)
{
    int temp = liste[i];
    liste[i] = liste[j];
    liste[j] = temp;
    return liste;
}


void genereEtat(int ** grapheComplet, etat * state, etat * newState, int N)
{
    int i;
    int j;
    do 
    {
        i = rand() % N;
        j = rand() % N;
    } 
    while (i==0 || j==0 || i==N-1 || j== N-1 || i==j);
    newState->liste_sommet = permuter(state->liste_sommet,i,j);
    newState->poids =calculPoids(grapheComplet, newState, N);
}
