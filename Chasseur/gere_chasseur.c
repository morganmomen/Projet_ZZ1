#include "./gere_chasseur.h"


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

void chercher_position_lapin (int ** map,int taille, position *  position_lapin)
{
    int i =1;
    int j=1;
    int trouver =0;
    while ((i<(taille+1))&&(trouver == 0))
    {
        while ((j<(taille+1))&&(trouver == 0))
        {
            if (map[i][j]==3)
            {
                trouver=1;
                position_lapin->x=i;
                position_lapin->y=j;
            }
            i++;
            j++;
        }
    }
}

void deplacement_chasseur (int ** map,int taille, position *  position_chasseur,position *  position_lapin)
{
    int depart = (taille+2) * position_chasseur->x + position_chasseur->y;
    int arriver = (taille+2) * position_lapin->x + position_lapin->y;
    int * suivant =NULL;
    suivant= dijkstra (map,depart,arriver,taille+2);
    
    int * etat_prochain;
    int tailleChemin;
    etat_prochain= obtenirChemin(suivant,arriver,&tailleChemin);

    printf ("\n %d \n",etat_prochain[tailleChemin-2]);
   
    if (tailleChemin>2)
    {
        map[position_chasseur->x ][position_chasseur->y]=0;
        position_chasseur->x = ceil (etat_prochain[tailleChemin-2]/(taille+2));
        position_chasseur->y = etat_prochain[tailleChemin-2] - (position_chasseur->x * (taille+2))  ;
        printf("\n%d %d \n",position_chasseur->x,position_chasseur->y  );
        map[position_chasseur->x ][position_chasseur->y]=4;
    }
    if (tailleChemin==2)
    {
        map[position_chasseur->x ][position_chasseur->y]=0;
        position_chasseur->x = ceil( etat_prochain[1]/(taille+2));
        position_chasseur->y = etat_prochain[1] - (position_chasseur->x * (taille+2))  ;
        printf("\n%d %d \n",position_chasseur->x,position_chasseur->y  );
        map[position_chasseur->x ][position_chasseur->y]=4;
    }
    if ((map[1][1]!=2)&&(position_chasseur->x!=1)&&(position_chasseur->y!=1))
    {
        map[1][1]=2;
    }

    free(suivant);
    free(etat_prochain);


    

}



   

int chasse (int ** map,int taille,position *  position_chasseur)
{

    SDL_Window * window = NULL;
    SDL_Renderer * renderer = NULL;
    initSDL(&window,&renderer);

    affichefond(renderer,window,map);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
    
    position * position_lapin = malloc(sizeof(position));
    int chasser = 1;
    position * position_terrier=malloc(sizeof(position));
    position_terrier->x=1;
    position_terrier->y=1;
    while(chasser==1){   
        chercher_position_lapin(map,taille,position_lapin);
        printf("\n\n");
        deplacement_chasseur (map,taille,position_chasseur,position_lapin);
        if ((position_chasseur->x==position_lapin->y)&&(position_chasseur->x==position_lapin->y))
        {
            chasser = 0;
        }
        if ((position_terrier->x==position_lapin->y)&&(position_terrier->x==position_lapin->y))
        {
            chasser = 2;
        }

        afficher_map(map,taille+2);
        SDL_RenderClear(renderer);
        affichefond(renderer,window,map);
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }

    free(position_terrier);
    free(position_lapin);
    return(chasser);
}