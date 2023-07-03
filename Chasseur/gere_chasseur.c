#include "./gere_chasseur.h"


int * apparition_chasseur (int ** map,int taille)
{
    int placer =0;
    int position [2];
    srand(time(NULL));
    int proba=40;
    int p;
    int i =1;
    int j=1;
    int milieu = (taille+1)/2;
    while ((i<milieu)&&(placer))
    {
        while ((j<milieu)&&(placer))
        {
            if ((map[i][j]!=1)&&(((map[i-1][j]!=1)||(map[i+1][j]!=1))||((map[i][j+1]!=1)||(map[i][j+1]!=1))))
            {
                p=rand()%100;
                if (p<proba)
                {
                    map[i][j]=4;
                    position[0]=i;
                    position[1]=j;
                    placer=1;
                }

            }

        }

    }
}


void deplacement_chasseur (int ** map,int taille,int * position)
{
    
}