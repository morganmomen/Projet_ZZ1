#include "affichage_fct.h"


 int window_w=-1, window_h=-1;
 SDL_Texture* texture[3] = {NULL,NULL,NULL};



void affichefond(SDL_Renderer * renderer,SDL_Window * window ,int** map)
{
    
 
    
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
                SDL_Rect rect = {i*offsetX,j*offsetY,offsetX,offsetY};
                if(renderer == NULL) printf("renderer is NULL\n");
                printf("rect.x = %d rect.y = %d rect.w = %d rect.h = %d\n",rect.x,rect.y,rect.w,rect.h);
                SDL_RenderCopy(renderer, texture[1], NULL, &rect);
            }
            else if(map[i][j]==2){
                SDL_Rect rect = {i*offsetX,j*offsetY,offsetX,offsetY};
                SDL_RenderCopy(renderer, texture[0], NULL, &rect);
                SDL_RenderCopy(renderer, texture[2], NULL, &rect);
            }
            else if(map[i][j]==3){
                SDL_Rect rect = {i*offsetX,j*offsetY,offsetX,offsetY};
                SDL_RenderCopy(renderer, texture[0], NULL, &rect);
                afficheLapin(renderer,window,map,i,j);

            }
            else if(map[i][j]==4){
                SDL_Rect rect = {i*offsetX,j*offsetY,offsetX,offsetY};
                SDL_RenderCopy(renderer, texture[0], NULL, &rect);
                afficheChasseur(renderer,window,map,i,j);

            }
            else{
                SDL_Rect rect = {i*offsetX,j*offsetY,offsetX,offsetY};
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
    int offsetX =   window_w /(N);
    int offsetY = window_h/(N);

    SDL_Rect rect = {x*offsetX +5,y*offsetY +5,offsetX - 10,offsetY-10};    
    SDL_SetRenderDrawColor(renderer,255,226,161,255);     
                                       
    SDL_RenderFillRect(renderer, &rect); 

}

void afficheChasseur(SDL_Renderer * renderer,SDL_Window * window ,int** map, int x, int y)
{

    if(window_w==-1 || window_h==-1){
        SDL_DisplayMode screen;
        SDL_GetCurrentDisplayMode(0, &screen);
        SDL_GetWindowSize(window, &window_w, &window_h);

    }
    int offsetX =   window_w /(N);
    int offsetY = window_h/(N);

    SDL_Rect rect = {x*offsetX +5,y*offsetY +5,offsetX - 10,offsetY-10};   
    SDL_SetRenderDrawColor(renderer,0,0,255,255);     
                                       
    SDL_RenderFillRect(renderer, &rect); 

}


/*TEMPORAIRE */


