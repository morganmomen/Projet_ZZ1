#include "./crea_map.h"


int ** init_map (int taille)
{
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


void afficher_map (int ** map,int taille)
{
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
    for (int i = 0; i < (taille+2); i++)
    {
        free(map[i]);
    }
    free(map);
}