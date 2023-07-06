#include "./gere_chasseur.h"




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

void deplacementaleatoire (int ** map, position *  position_chasseur)
{
    srand(time(NULL) * rand());
    int deplacement []={-1,-1,-1,-1};
    int p;
    int count =0;
    if (map[position_chasseur->x +1][position_chasseur->y]==0)
    {
        deplacement[count]=0;
        count++;
    }
    if (map[position_chasseur->x -1][position_chasseur->y]==0)
    {
        deplacement[count]=1;
        count++;
    }
    if (map[position_chasseur->x][position_chasseur->y+1]==0)
    {
        deplacement[count]=2;
        count++;
    }
    if (map[position_chasseur->x][position_chasseur->y-1]==0)
    {
        deplacement[count]=3;
        count++;
    }
    int prochain_etat;
    if (count>0)
    {
        p=rand()%count;
        prochain_etat = deplacement[p];
    }
    else
    {
        prochain_etat=4;
    }
    switch (prochain_etat) {
    case 0:
      position_chasseur->x ++;
      break;
    case 1:
      position_chasseur->x --;
      break;
    case 2:
      position_chasseur->y ++;
      break;
    case 3:
      position_chasseur->y --;
      break;
    default:
      break;
  }
}




int deplacement_chasseur (int ** map,int taille, position *  position_chasseur,position *  position_lapin)
{
    int depart = (taille+2) * position_chasseur->x + position_chasseur->y;
    int arriver = (taille+2) * position_lapin->x + position_lapin->y;
    int * suivant =NULL;
    suivant= dijkstra (map,depart,arriver,taille+2);
    srand(time(NULL) * rand());
    
    int * etat_prochain;
    int tailleChemin;
    etat_prochain= obtenirChemin(suivant,arriver,&tailleChemin);

    if (tailleChemin >(taille/2))
    {
        map[position_chasseur->x ][position_chasseur->y]=0;
        deplacementaleatoire(map,position_chasseur);
        map[position_chasseur->x ][position_chasseur->y]=4;
    }
    else 
    {
        if (rand()%2==0)
        {
            map[position_chasseur->x ][position_chasseur->y]=0;
            deplacementaleatoire(map,position_chasseur);
            map[position_chasseur->x ][position_chasseur->y]=4;
        }
        else
        {
            if (tailleChemin>2)
            {
                map[position_chasseur->x ][position_chasseur->y]=0;
                position_chasseur->x = ceil (etat_prochain[tailleChemin-2]/(taille+2));
                position_chasseur->y = etat_prochain[tailleChemin-2] - (position_chasseur->x * (taille+2))  ;
                map[position_chasseur->x ][position_chasseur->y]=4;
            }
            if (tailleChemin==2)
            {
                map[position_chasseur->x ][position_chasseur->y]=0;
                position_chasseur->x = ceil( etat_prochain[1]/(taille+2));
                position_chasseur->y = etat_prochain[1] - (position_chasseur->x * (taille+2))  ;
                map[position_chasseur->x ][position_chasseur->y]=4;
            }
        }
    }
    if ((map[1][1]!=2)&&(position_chasseur->x!=1)&&(position_chasseur->y!=1))
    {
        map[1][1]=2;
    }
    //afficher_map(map,taille+2);

    free(suivant);
    free(etat_prochain);
    return(tailleChemin-1);

}



   

int chasse (int ** map,int taille,position *  position_chasseur)
{
    afficher_map(map,taille+2);

    SDL_Window * window = NULL;
    SDL_Renderer * renderer = NULL;
    initSDL(&window,&renderer);

    affichefond(renderer,window,map,taille+2);
    SDL_RenderPresent(renderer);
    //SDL_Delay(1000);
    
    position * position_lapin = malloc(sizeof(position));
    int chasser = 1;
    position * position_terrier=malloc(sizeof(position));
    position_terrier->x=1;
    position_terrier->y=1;
    //while(chasser==1){ 
    while(chasser==1){  
        chercher_position_lapin(map,taille,position_lapin);
        printf("\n\n");
        if (deplacement_chasseur (map,taille,position_chasseur,position_lapin)==1)
        {
            chasser = 0;
        }
        if ((position_terrier->x==position_lapin->x)&&(position_terrier->y==position_lapin->y))
        {
            chasser = 2;
        }

        afficher_map(map,taille+2);
        SDL_RenderClear(renderer);
        affichefond(renderer,window,map,taille+2);
        SDL_RenderPresent(renderer);
        //SDL_Delay(50);
    }
    printf("FINI\n");
    free(position_terrier);
    free(position_lapin);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    return(chasser);
}