#include "mvt_lapin.h"
#include "../Chasseur/gere_chasseur.h"

void cherche_chasseur(int **map, int taille, joueur_t *lapin) {
  position *chasseur = malloc(sizeof(position));
  for (int i = 0; i < taille; i++) {
    for (int j = 0; j < taille; j++) {
      if (map[i][j] == CHASSEUR) {
        chasseur->x = i;
        chasseur->y = j;
      }
    }
  }
  int diff_x = chasseur->x - lapin->x;
  int diff_y = chasseur->y - lapin->y;
  if (abs(diff_x) > abs(diff_y)) {
    if (diff_x > 0) {
      lapin->direction_predateur = EST;
    } else {
      lapin->direction_predateur = OUEST;
    }
  } else {
    if (diff_y > 0) {
      lapin->direction_predateur = SUD;
    } else {
      lapin->direction_predateur = NORD;
    }
  }
  if (diff_x + diff_y < (int)taille / 3)
    lapin->distance_predateur = PROCHE;
  else if (((int)2 * taille) / 3 < diff_x + diff_y < (int)taille / 2)
    lapin->distance_predateur = MOYEN;
  else
    lapin->distance_predateur = LOIN;
}

void deplacement_lapin(int **map, int taille, ruleSet_t *rules,
                       joueur_t *lapin) {
  action_t action;
  action = choixRule(rules, lapin);
  map[lapin->x][lapin->y] = VIDE;
  printf("Action : %d\n", action);
  switch (action) {
  case AVANCER:
    printf("Lapin : Je me déplace vers le haut\n");
    if (lapin->devant == MUR)
      printf("Lapin : Je ne peux pas avancer\n");
    else
      lapin->y = lapin->y - 1;
    break;
  case GAUCHE:
    if (lapin->gauche == MUR)
      printf("Lapin : Je ne peux pas avancer\n");
    else
      lapin->y = lapin->x - 1;
    break;
  case RECULER:
    if (lapin->derriere == MUR)
      printf("Lapin : Je ne peux pas avancer\n");
    else
      lapin->y = lapin->y + 1;
    break;
  case DROITE:
    if (lapin->droite == MUR)
      printf("Lapin : Je ne peux pas avancer\n");
    else
      lapin->y = lapin->x + 1;
    break;
  }

  map[lapin->x][lapin->y] = LAPIN;
}

int lapin(int **map, joueur_t *lapin, int taille, ruleSet_t *rules) {
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  initSDL(&window, &renderer);
  while (lapin->x != 2 && lapin->y != 2) {
    deplacement_lapin(map, taille, rules, lapin);
    SDL_RenderClear(renderer);
    affichefond(renderer, window, map, taille + 2);
    SDL_RenderPresent(renderer);
    SDL_Delay(20);
  }
  return 0;
}

int main() {
  int n = 17;
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  initSDL(&window, &renderer);
  int nombre_obstacle_max = pow((n - 3), 2);

  int **maze;
  maze = init_map(n);

  generateMaze(maze, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
  joueur_t *joueur_lapin = malloc(sizeof(joueur_t));
  joueur_lapin->x = n - 2;
  joueur_lapin->y = n - 2;
  joueur_lapin->devant = maze[joueur_lapin->x][joueur_lapin->y - 1];
  joueur_lapin->derriere = maze[joueur_lapin->x][joueur_lapin->y + 1];
  joueur_lapin->gauche = maze[joueur_lapin->x - 1][joueur_lapin->y];
  joueur_lapin->droite = maze[joueur_lapin->x + 1][joueur_lapin->y];
  joueur_lapin->direction_predateur = NORD;
  joueur_lapin->direction_terrier = NORD;
  joueur_lapin->distance_predateur = LOIN;
  joueur_lapin->distance_terrier = LOIN;
  ruleSet_t *rules = generateRuleSet();
  lapin(maze, joueur_lapin, n, rules);

  afficher_map(maze, n);
  liberer_map(maze, n);
  return 0;
}