#include "./crea_map.h"


int ** init_map (int taille)
{
    taille = taille;
    int **map = malloc((taille+2) * sizeof(int *));
    for (int i = 0; i < (taille+2); i++)
    {
        map[i] = malloc((taille+2) * sizeof(int));
        for (int j = 0; j < (taille+2); j++)
        {
            map[i][j] = 0;
        }
    }
    return map;
}
/*
int ** crea_map (int taille,int nombre_obstacle_max)
{
    int ** map =init_map(taille);
    srand(time(NULL));
    int compteur =0;
    int proba = 35;
    int p;
    map[1][1]=2;
    map[taille][taille]=3;
    for (int i=0;i<(taille+2);i++)
    {
        for (int j=0;j<(taille+2);j++)
        {
            if (((i==0)||(i==taille+1))||((j==0)||(j==taille+1)))
            {
                map[i][j]= 1;
            }
            else
            {
                if ((map[i][j]!=2)&&(map[i][j]!=3))
                {
                    p = rand() % 100;
                    if ((p<proba)&&(compteur<nombre_obstacle_max))
                    {
                        if ((((map[i+1][j]!=1)&&(map[i-1][j]!=1))&&((map[i][j-1]!=1)||(map[i][j+1]!=1)))&&(((map[i-1][j-1]!=1)||(map[i+1][j+1]!=1)))&&((map[i+1][j-1]!=1)||(map[i-1][j+1]!=1)))
                        {
                            if (((map[i][j+1]!=3)&&((map[i+1][j]!=3)&&(map[i+1][j+1]!=3)))&&((map[i][j-1]!=2)&&(map[i-1][j]!=2)))
                            {
                                map[i][j]= 1;
                                compteur++;
                            }
                        }   
                    }
                }
            }
        }
    }
    return(map);
}
*/

void afficher_map (int ** map,int taille)
{
    taille = taille -2;
    for (int i = 0; i < (taille+2); i++)
    {
        printf("[");
        for (int j = 0; j < (taille+2); j++)
        {
            printf("%d", map[i][j]);
            if (j < (taille+1))
            {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

void liberer_map (int ** map, int taille)
{
    taille = taille -2;
    for (int i = 0; i < (taille+2); i++)
    {
        free(map[i]);
    }
    free(map);
}


position* generateMaze(int** maze,int taille) {
    int i, j;
    position* position_chasseur = malloc(sizeof(position));
    position * position_lapin = malloc(sizeof(position));
    //Initialisation du générateur de nombres aléatoires
  

    int depart = (taille) * position_chasseur->x + position_chasseur->y;
    int arriver = (taille) * position_lapin->x + position_lapin->y;
    int * suivant =NULL;
    int * etat_prochain;
    int tailleChemin = 1;

    while(tailleChemin <= 2){
        srand(time(NULL)* rand());
        for (i = 0; i < taille; i++) {
            for (j = 0; j < taille; j++) {
                if (i == 0 || i == taille - 1 || j == 0 || j == taille - 1)
                    maze[i][j] = 1;  // Contour du labyrinthe
                else
                    maze[i][j] = 0;  // Espace libre à l'intérieur du labyrinthe
            }
        }


        //génération aléatoire des murs avec une densité faible
        for (i = 2; i < taille - 1; i += 2) {
            for (j = 2; j < taille - 1; j += 2) {
                if (rand() % 5 != 0) {  // Probabilité de 4/5 pour ajouter un mur
                    maze[i][j] = 1;  // Ajout d'un mur aux emplacements pairs
                    int randDir = rand() % 4;  // Choix aléatoire d'une direction
                    switch (randDir) {
                        case 0:  // Déplacement vers le haut
                            maze[i - 1][j] = 1;
                            break;
                        case 1:  // Déplacement vers le bas
                            maze[i + 1][j] = 1;
                            break;
                        case 2:  // Déplacement vers la gauche
                            maze[i][j - 1] = 1;
                            break;
                        case 3:  // Déplacement vers la droite
                            maze[i][j + 1] = 1;
                            break;
                    }
                }
            }
        }

            
        maze[1][1] = 2;  // Position terrier du lapin
        maze[taille - 2][taille - 2] = 3; // Position du lapin
        position_lapin->x = taille - 2;
        position_lapin->y = taille - 2;

        apparition_chasseur(maze,taille, position_chasseur);


        depart = (taille) * position_chasseur->x + position_chasseur->y;
        arriver = (taille) * position_lapin->x + position_lapin->y;

        printf("taille : %d\n", taille);
    
        suivant= dijkstra (maze,depart,arriver,taille);

        etat_prochain= obtenirChemin(suivant,arriver,&tailleChemin);

        printf("taille chemin debut : %d\n", tailleChemin);
        printf("etat prochain : %d\n", *etat_prochain);
    }

    return position_chasseur;
}



void apparition_chasseur (int ** map,int taille,position * position_chasseur)
{
    int placer =0;
    int i=1;
    int j=1;
    while (placer==0)
    {
        if (map[i][j]==0)
        {
            map[i][j]=4;
            position_chasseur->x=i;
            position_chasseur->y=j;
            placer=1;
        }
        if (j==taille)
        {
            i++;
            j=1;
        }
        else
        {
            j++;
        }
        
        
    }
}