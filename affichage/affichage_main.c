#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "affichage_fct.h"
#include "init_SDL.h"
#include "../Map/crea_map.h"

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;

    SDL_Window * window = NULL;
    SDL_Renderer * renderer = NULL;
    initSDL(&window,&renderer);
    int nombre_obstacle_max= pow((N-3),2);
    int ** map = crea_map (N,nombre_obstacle_max);

    affichefond(renderer,window,map);
    afficheLapin(renderer,window,map,10,10);
    afficheChasseur(renderer,window,map,2,1);

    SDL_RenderPresent(renderer);
    SDL_Delay(3000);

    afficher_map(map,N);
    liberer_map(map,N);

    return 0;
}