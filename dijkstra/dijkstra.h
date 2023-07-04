
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef __DIJKSTRA__H
#define __DIJKSTRA__H



int **transform_for_dijktra(int **mat, int taille) ;
int trouverMinDistance(int distance[], int visite[], int numSommet);
int * dijkstra(int ** graphe, int depart, int arrivee, int taille);
void afficherChemin(int  parent [], int sommet);
int* obtenirChemin(int predecesseurs[], int sommet, int* tailleChemin);

#endif