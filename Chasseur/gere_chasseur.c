#include "./gere_chasseur.h"


void apparition_chasseur (int ** map,int taille,position ** position_chasseur)
{
    int placer =0;
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
                    (*position_chasseur)->x=i;
                    (*position_chasseur)->y=j;
                    placer=1;
                }

            }
            i++;
            j++;
        }
    }
}

void chercher_position_lapin (int ** map,int taille, position **  position_lapin)
{
    int i =1;
    int j=1;
    int trouver =0;
    while ((i<(taille+1))&&(trouver))
    {
        while ((j<(taille+1))&&(trouver))
        {
            if (map[i][j]==3)
            {
                trouver=1;
                (*position_lapin)->x=i;
                (*position_lapin)->y=j;
            }
            i++;
            j++;
        }
    }
}

void deplacement_chasseur (int ** map,position **  position_chasseur,position **  position_lapin)
{
    srand(time(NULL));
    int proba = 50;
    int p;

    if ((*position_chasseur)->x < (*position_lapin)->x)
    {
        if (map[(*position_chasseur)->x +1 ][(*position_chasseur)->y]!=1)
        {
            map[(*position_chasseur)->x][(*position_chasseur)->y]=0;
            (*position_chasseur)->x ++ ;
            map[(*position_chasseur)->x ][(*position_chasseur)->y] =4;
        }
        else
        {
            if ((*position_chasseur)->y < (*position_lapin)->y)
            {
                if (map[(*position_chasseur)->x][(*position_chasseur)->y +1]!=1)
                {
                    map[(*position_chasseur)->x][(*position_chasseur)->y]=0;
                    (*position_chasseur)->y++ ;
                    map[(*position_chasseur)->x ][(*position_chasseur)->y] =4;
                }
                else 
                {
                    p=rand()%100;
                    if ((p<proba)&&(map[(*position_chasseur)->x-1][(*position_chasseur)->y]!=1))
                    {
                        map[(*position_chasseur)->x][(*position_chasseur)->y]=0;
                        (*position_chasseur)->x -- ;
                        map[(*position_chasseur)->x ][(*position_chasseur)->y] =4;
                    }
                    else
                    {
                        map[(*position_chasseur)->x][(*position_chasseur)->y]=0;
                        (*position_chasseur)->y -- ;
                        map[(*position_chasseur)->x ][(*position_chasseur)->y] =4;
                    }
                }
            }
            else
            {
                if (map[(*position_chasseur)->x][(*position_chasseur)->y - 1]!=1)
                {
                    map[(*position_chasseur)->x][(*position_chasseur)->y]=0;
                    (*position_chasseur)->y -- ;
                    map[(*position_chasseur)->x ][(*position_chasseur)->y] =4;
                }
                else 
                {
                    p=rand()%100;
                    if ((p<proba)&&(map[(*position_chasseur)->x-1][(*position_chasseur)->y]!=1))
                    {
                        map[(*position_chasseur)->x][(*position_chasseur)->y]=0;
                        (*position_chasseur)->x -- ;
                        map[(*position_chasseur)->x ][(*position_chasseur)->y] =4;
                    }
                    else
                    {
                        map[(*position_chasseur)->x][(*position_chasseur)->y]=0;
                        (*position_chasseur)->y ++ ;
                        map[(*position_chasseur)->x ][(*position_chasseur)->y] =4;
                    }
                }
            }
        }
    }
    else
    {
       if (map[(*position_chasseur)->x -1 ][(*position_chasseur)->y]!=1)
        {
            map[(*position_chasseur)->x][(*position_chasseur)->y]=0;
            (*position_chasseur)->x -- ;
            map[(*position_chasseur)->x ][(*position_chasseur)->y] =4;
        }
        else
        {
            if (map[(*position_chasseur)->x][(*position_chasseur)->y +1]!=1)
            {
                if ((*position_chasseur)->y < (*position_lapin)->y)
                {
                    map[(*position_chasseur)->x][(*position_chasseur)->y]=0;
                    (*position_chasseur)->y++ ;
                    map[(*position_chasseur)->x ][(*position_chasseur)->y] =4;
                }
                else 
                {
                    p=rand()%100;
                    if ((p<proba)&&(map[(*position_chasseur)->x-1][(*position_chasseur)->y]!=1))
                    {
                        map[(*position_chasseur)->x][(*position_chasseur)->y]=0;
                        (*position_chasseur)->x -- ;
                        map[(*position_chasseur)->x ][(*position_chasseur)->y] =4;
                    }
                    else
                    {
                        map[(*position_chasseur)->x][(*position_chasseur)->y]=0;
                        (*position_chasseur)->y -- ;
                        map[(*position_chasseur)->x ][(*position_chasseur)->y] =4;
                    }
                }
            }
            else
            {
                if (map[(*position_chasseur)->x][(*position_chasseur)->y - 1]!=1)
                {
                    map[(*position_chasseur)->x][(*position_chasseur)->y]=0;
                    (*position_chasseur)->y -- ;
                    map[(*position_chasseur)->x ][(*position_chasseur)->y] =4;
                }
                else 
                {
                    p=rand()%100;
                    if ((p<proba)&&(map[(*position_chasseur)->x-1][(*position_chasseur)->y]!=1))
                    {
                        map[(*position_chasseur)->x][(*position_chasseur)->y]=0;
                        (*position_chasseur)->x -- ;
                        map[(*position_chasseur)->x ][(*position_chasseur)->y] =4;
                    }
                    else
                    {
                        map[(*position_chasseur)->x][(*position_chasseur)->y]=0;
                        (*position_chasseur)->y ++ ;
                        map[(*position_chasseur)->x ][(*position_chasseur)->y] =4;
                    }
                }
            }
        }
    }
}
   

int chasse (int ** map,int taille,position **  position_chasseur)
{
    position * position_lapin = malloc(sizeof(position*));
    int chasser = 1;
    position * position_terrier= malloc(sizeof(position*));
    position_terrier->x=1;
    position_terrier->y=1;
    while (chasser==1)
    {    
        chercher_position_lapin(map,taille,&position_lapin);
        printf("%d %d\n",position_lapin->x,position_lapin->y);
        deplacement_chasseur (map,position_chasseur,&position_lapin);
        if (((*position_chasseur)->x==position_lapin->y)&&((*position_chasseur)->x==position_lapin->y))
        {
            chasser = 0;
        }
        if ((position_terrier->x==position_lapin->y)&&(position_terrier->x==position_lapin->y))
        {
            chasser = 2;
        }
        afficher_map(map,taille);
    }
    free(position_terrier);
    free(position_lapin);
    return(chasser);

}