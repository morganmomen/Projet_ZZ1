typedef struct
{
    int *liste_sommet;
    int poids;
}etat;

int calculPoids(int** grapheComplet, etat* state, int N);
etat *genereCycleHamiltonien(int **grapheComplet,int N);
int* permuter(int* liste, int i, int j);
void genereEtat(int** grapheComplet, etat * state, etat * newState, int N);

