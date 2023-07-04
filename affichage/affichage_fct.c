#include "affichage_fct.h"

int lapinIndex =0;
SDL_Rect lapin[32];
SDL_Texture * lapintexture = NULL;
int offset_x_lapin,offset_y_lapin;

SDL_Rect chasseur[36];
SDL_Texture * chasseurtexture = NULL;
int offset_x_chasseur,offset_y_chasseur;
int chasseurIndex =0;


int window_w=-1, window_h=-1;
SDL_Texture* texture[3] = {NULL,NULL,NULL};
int N = -1;

mouvement  lapin_struct = {0,-1,-1};
mouvement  chasseur_struct = {0,-1,-1};


void affichefond(SDL_Renderer * renderer,SDL_Window * window ,int** map, int taille)
{
 
    if(N==-1){
        N = taille;
    }
        
    
    if(window_w==-1 || window_h==-1){
        SDL_DisplayMode screen;
        SDL_GetCurrentDisplayMode(0, &screen);
        SDL_GetWindowSize(window, &window_w, &window_h);

    }



    int offsetX =   window_w /(N);
    int offsetY = window_h/(N);
    printf("offsetX = %d\n",offsetX);
    printf("offsetY = %d\n",offsetY);

    if(texture[0] == NULL||texture[1] == NULL||texture[2] == NULL){
        texture[0] = loadTexture("../img/gazon.png", renderer);
        texture[1] = loadTexture("../img/brique.png", renderer);
        texture[2] = loadTexture("../img/terrier.png", renderer);
    }

    SDL_RenderClear(renderer);

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            if(map[i][j]==1){
                SDL_Rect rect = {j*offsetX,i*offsetY,offsetY,offsetX};
                if(renderer == NULL) printf("renderer is NULL\n");
                SDL_RenderCopy(renderer, texture[1], NULL, &rect);
            }
            else if(map[i][j]==2){
                SDL_Rect rect = {j*offsetX,i*offsetY,offsetY,offsetX};
                SDL_RenderCopy(renderer, texture[0], NULL, &rect);
                SDL_RenderCopy(renderer, texture[2], NULL, &rect);
            }
            else if(map[i][j]==3){
                SDL_Rect rect = {j*offsetX,i*offsetY,offsetY,offsetX};
                SDL_RenderCopy(renderer, texture[0], NULL, &rect);
                afficheLapin(renderer,window,map,j,i,offsetX,offsetY);

            }
            else if(map[i][j]==4){
                SDL_Rect rect = {j*offsetX,i*offsetY,offsetY,offsetX};
                SDL_RenderCopy(renderer, texture[0], NULL, &rect);
                afficheChasseur(renderer,window,map,j,i,offsetX,offsetY);

            }
            else{
                SDL_Rect rect = {j*offsetX,i*offsetY,offsetY,offsetX};
                SDL_RenderCopy(renderer, texture[0], NULL, &rect);
            }
        }
    }
    SDL_RenderPresent(renderer);

}

void afficheLapin(SDL_Renderer * renderer,SDL_Window * window ,int** map, int x, int y, int offsetX,int offsetY)
{

    if(window_w==-1 || window_h==-1){
        SDL_DisplayMode screen;
        SDL_GetCurrentDisplayMode(0, &screen);
        SDL_GetWindowSize(window, &window_w, &window_h);

    }
    

    Draw_Lapin(window,renderer,lapin,&lapintexture,&offset_x_lapin,&offset_y_lapin);
    if(lapintexture == NULL) printf("PAS DE TEXTURE \n");
    int nb_images_w = 8, nb_images_h=4;

    SDL_Rect destination_lapin={0};
    SDL_Rect source_lapin={0};

    destination_lapin.w = offsetX * 0.5 +10;       
    destination_lapin.h = offsetY * 0.5 +10;
    destination_lapin.y = y*offsetY;
    destination_lapin.x = x*offsetX;

    if(lapin_struct.x_precedent == -1 || lapin_struct.y_precedent == -1){
        lapin_struct.x_precedent = x ;
        lapin_struct.y_precedent = y ;
    }
    else
    {
        int retour = deplacement_orientation(&lapin_struct,x,y);
        lapinIndex =retour*nb_images_w + (lapinIndex + 1) %nb_images_w;
        
    }
  
    source_lapin.x = lapin[lapinIndex].x;
    source_lapin.y = lapin[lapinIndex].y;
    source_lapin.w = lapin[lapinIndex].w;
    source_lapin.h = lapin[lapinIndex].h;

    
    
    SDL_RenderCopy(renderer, lapintexture,&source_lapin, &destination_lapin);
}

void afficheChasseur(SDL_Renderer * renderer,SDL_Window * window ,int** map, int x, int y, int offsetX,int offsetY)
{

    if(window_w==-1 || window_h==-1){
        SDL_DisplayMode screen;
        SDL_GetCurrentDisplayMode(0, &screen);
        SDL_GetWindowSize(window, &window_w, &window_h);

    }
    Draw_Chasseur(window,renderer,chasseur,&chasseurtexture,&offset_x_chasseur,&offset_y_chasseur);
    SDL_Rect destination_chasseur={0};
    SDL_Rect source_chasseur={0};
    int nb_images_w = 9, nb_images_h=4;

    
    destination_chasseur.w = offsetX;       
    destination_chasseur.h = offsetY;
    destination_chasseur.y = y*offsetY;
    destination_chasseur.x = x*offsetX ;

    
    if(chasseur_struct.x_precedent == -1 || chasseur_struct.y_precedent == -1){
        chasseur_struct.x_precedent = x ;
        chasseur_struct.y_precedent = y ;
    }
    else
    {
        int retour = deplacement_orientation(&chasseur_struct,x,y);
        //chasseurIndex =  (chasseurIndex + 1) %nb_images_w;
        chasseurIndex =retour*nb_images_w + (chasseurIndex + 1) %nb_images_w;
        
    }
     
    source_chasseur.x = chasseur[chasseurIndex].x;
    source_chasseur.y = chasseur[chasseurIndex].y;
    source_chasseur.w = chasseur[chasseurIndex].w;
    source_chasseur.h = chasseur[chasseurIndex].h;

    
    SDL_RenderCopy(renderer, chasseurtexture, &source_chasseur, &destination_chasseur);
    SDL_Delay(100);

}


// 0:haut, 1:gauche, 2:bas, 3:va vers la droite 4:neutre
int deplacement_orientation (mouvement * ancien,int x_nouvelle, int y_nouvelle )
{   
    int retour ;
    if (ancien->x_precedent<x_nouvelle)
    {
        retour = 3;
    }
    else if (ancien->x_precedent>x_nouvelle)
    {
        retour = 1;
    }
    else if (ancien->y_precedent<y_nouvelle)
    {
        retour=2;

    }
    else if (ancien->y_precedent>y_nouvelle)
    {
        retour=0;
    }
    else{
        retour=ancien->orientation_precedente;
    }
    ancien->x_precedent = x_nouvelle;
    ancien->y_precedent= y_nouvelle;
    return(retour);
    
}




