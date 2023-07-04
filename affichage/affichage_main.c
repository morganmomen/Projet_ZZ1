#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../Map/crea_map.h"
#include "affichage_fct.h"
#include "init_SDL.h"

int main(int argc, char const *argv[]) {
  (void)argc;
  (void)argv;
  int N = 17;
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  initSDL(&window, &renderer);
  int nombre_obstacle_max = pow((N - 3), 2);

  int **maze;
  maze = init_map(N);

  generateMaze(maze, N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }

<<<<<<< HEAD
  affichefond(renderer, window, maze, N);
=======
    affichefond(renderer,window,maze,N);
   
>>>>>>> corrections

  SDL_RenderPresent(renderer);
  SDL_Delay(3000);

  afficher_map(maze, N);
  liberer_map(maze, N);

  return 0;
}
