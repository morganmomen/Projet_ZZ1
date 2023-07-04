#include "affichage_fct.h"


 int window_w=-1, window_h=-1;
 SDL_Texture* texture[3] = {NULL,NULL,NULL};
 int N = -1;



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
                afficheLapin(renderer,window,map,i,j);

            }
            else if(map[i][j]==4){
                SDL_Rect rect = {j*offsetX,i*offsetY,offsetY,offsetX};
                SDL_RenderCopy(renderer, texture[0], NULL, &rect);
                afficheChasseur(renderer,window,map,i,j);

            }
            else{
                SDL_Rect rect = {j*offsetX,i*offsetY,offsetY,offsetX};
                SDL_RenderCopy(renderer, texture[0], NULL, &rect);
            }
        }
    }

}

void afficheLapin(SDL_Renderer * renderer,SDL_Window * window ,int** map, int x, int y)
{

    if(window_w==-1 || window_h==-1){
        SDL_DisplayMode screen;
        SDL_GetCurrentDisplayMode(0, &screen);
        SDL_GetWindowSize(window, &window_w, &window_h);

    }
    int nb_images_w = 8, nb_images_h=4;
    int zoom =1;
    SDL_Rect destination_lapin={0};
    SDL_Rect source_lapin={0};

    destination_lapin.w = offset_x_lapin * zoom;       
    destination_lapin.h = offset_y_lapin * zoom;
    destination_lapin.y = y;
    destination_lapin.x = x;
  
    source_lapin.x = lapin[lapinIndex[0]][lapinIndex[1]].x;
    source_lapin.y = lapin[lapinIndex[0]][lapinIndex[1]].y;
    source_lapin.w = lapin[lapinIndex[0]][lapinIndex[1]].w;
    source_lapin.h = lapin[lapinIndex[0]][lapinIndex[1]].h;

    lapinIndex[0] = (lapinIndex[0] + 1) % nb_images_w;
    SDL_RenderCopy(renderer, lapintexture, &source_chasseur, &destination_chasseur);
    

}

void afficheChasseur(SDL_Renderer * renderer,SDL_Window * window ,int** map, int x, int y)
{

    if(window_w==-1 || window_h==-1){
        SDL_DisplayMode screen;
        SDL_GetCurrentDisplayMode(0, &screen);
        SDL_GetWindowSize(window, &window_w, &window_h);

    }
     
    SDL_Rect destination_chasseur={0};
    SDL_Rect source_chasseur={0};
    int nb_images_w = 8, nb_images_h=4;

    int zoom =1;
    destination_chasseur.w = offset_x_chasseur * zoom;       
    destination_chasseur.h = offset_y_chasseur * zoom;
    destination_chasseur.y = y;
    destination_chasseur.x = x;

    source_chasseur.x = chasseur[chasseurIndex[0]][chasseurIndex[1]].x;
    source_chasseur.y = chasseur[chasseurIndex[0]][chasseurIndex[1]].y;
    source_chasseur.w = chasseur[chasseurIndex[0]][chasseurIndex[1]].w;
    source_chasseur.h = chasseur[chasseurIndex[0]][chasseurIndex[1]].h;
    chasseurIndex[0] = (chasseurIndex[0] + 1) % nb_images_w;

    SDL_RenderCopy(renderer, lapintexture, &source_chasseur, &destination_chasseur);

}





