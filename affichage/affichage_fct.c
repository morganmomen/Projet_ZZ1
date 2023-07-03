#include "affichage_fct.h"

void affichefond(SDL_Renderer * renderer,SDL_Window * window ,int** map)
{
    
    SDL_DisplayMode screen;
    SDL_GetCurrentDisplayMode(0, &screen);

    int window_w, window_h;

    SDL_GetWindowSize(window, &window_w, &window_h);

    int offsetX =   window_w /(N+2);
    int offsetY = window_h/(N+2);
    printf("offsetX = %d\n",offsetX);
    printf("offsetY = %d\n",offsetY);

    SDL_Texture* texture[3];
    texture[0] = loadTexture("../img/gazon.png", renderer);
    texture[1] = loadTexture("../img/brique.png", renderer);
    texture[2] = loadTexture("../img/terrier.png", renderer);



    for(int i =0; i<N+2; i++){
        for(int j =0; j<N+2; j++){
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
            else{
                SDL_Rect rect = {i*offsetX,j*offsetY,offsetX,offsetY};
                SDL_RenderCopy(renderer, texture[0], NULL, &rect);
            }
        }
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);




}