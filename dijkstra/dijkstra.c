#include "dijkstra.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int **transform_for_dijktra(int **mat, int taille) {
  int **matrice = malloc((taille + 2) * sizeof(int *));
  for (int i = 0; i < (taille + 2); i++) {
    matrice[i] = malloc((taille + 2) * sizeof(int));
    for (int j = 0; j < (taille + 2); j++) {
      if (mat[i][j] != 0 && mat[i][j] != 2) {
        matrice[i][j] = 1;
      }
    }
  }
  return matrice;
}

int trouverMinDistance(int distance[], int visite[], int numSommet) {
  int minDistance = INT_MAX;
  int minIndex;

  for (int i = 0; i < numSommet; i++) {
    if (!visite[i] && distance[i] <= minDistance) {
      minDistance = distance[i];
      minIndex = i;
    }
  }

  return minIndex;
}

void afficherChemin(int parent[], int sommet) {
  if (parent[sommet] == -1) {
    printf("%d ", sommet);
    return;
  }

  afficherChemin(parent, parent[sommet]);
  printf("%d ", sommet);
}

int *dijkstra(int graphe[][10], int depart, int arrivee, int taille) {
  int distance[taille * taille];
  int parent[taille * taille];
  int visite[taille * taille];

  for (int i = 0; i < taille * taille; i++) {
    distance[i] = INT_MAX;
    visite[i] = 0;
    parent[i] = -1;
  }

  distance[depart] = 0;

  for (int i = 0; i < taille * taille - 1; i++) {
    int u = trouverMinDistance(distance, visite, taille * taille);

    visite[u] = 1;

    int ligne = u / taille;
    int colonne = u % taille;

    if (ligne > 0 && graphe[ligne - 1][colonne] == 0 &&
        !visite[(ligne - 1) * taille + colonne] &&
        distance[u] + 1 < distance[(ligne - 1) * taille + colonne]) {
      distance[(ligne - 1) * taille + colonne] = distance[u] + 1;
      parent[(ligne - 1) * taille + colonne] = u;
    }

    if (ligne < taille - 1 && graphe[ligne + 1][colonne] == 0 &&
        !visite[(ligne + 1) * taille + colonne] &&
        distance[u] + 1 < distance[(ligne + 1) * taille + colonne]) {
      distance[(ligne + 1) * taille + colonne] = distance[u] + 1;
      parent[(ligne + 1) * taille + colonne] = u;
    }

    if (colonne > 0 && graphe[ligne][colonne - 1] == 0 &&
        !visite[ligne * taille + colonne - 1] &&
        distance[u] + 1 < distance[ligne * taille + colonne - 1]) {
      distance[ligne * taille + colonne - 1] = distance[u] + 1;
      parent[ligne * taille + colonne - 1] = u;
    }

    if (colonne < taille - 1 && graphe[ligne][colonne + 1] == 0 &&
        !visite[ligne * taille + colonne + 1] &&
        distance[u] + 1 < distance[ligne * taille + colonne + 1]) {
      distance[ligne * taille + colonne + 1] = distance[u] + 1;
      parent[ligne * taille + colonne + 1] = u;
    }
  }

  afficherChemin(parent, arrivee);
  return parent;
}
