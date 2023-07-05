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
  else if (((int)2 * taille) / 3 < diff_x + diff_y &&
           diff_x + diff_y < (int)taille / 2)
    lapin->distance_predateur = MOYEN;
  else
    lapin->distance_predateur = LOIN;
}

void recherche_terrier(int **map, int taille, joueur_t *lapin) {
  position *terrier = malloc(sizeof(position));
  for (int i = 0; i < taille; i++) {
    for (int j = 0; j < taille; j++) {
      if (map[i][j] == TERRIER) {
        terrier->x = i;
        terrier->y = j;
      }
    }
  }
  int diff_x = terrier->x - lapin->x;
  int diff_y = terrier->y - lapin->y;
  if (abs(diff_x) > abs(diff_y)) {
    if (diff_x > 0) {
      lapin->direction_terrier = EST;
    } else {
      lapin->direction_terrier = OUEST;
    }
  } else {
    if (diff_y > 0) {
      lapin->direction_terrier = SUD;
    } else {
      lapin->direction_terrier = NORD;
    }
  }
  if (diff_x + diff_y < (int)taille / 3)
    lapin->distance_terrier = PROCHE;
  else if (((int)2 * taille) / 3 < diff_x + diff_y &&
           diff_x + diff_y < (int)taille / 2)
    lapin->distance_terrier = MOYEN;
  else
    lapin->distance_terrier = LOIN;
}

void deplacement_lapin(int **map, int taille, ruleSet_t *rules,
                       joueur_t *lapin) {
  action_t action;
  srand(time(NULL) * rand());
  action = choixRule(rules, lapin);
  map[lapin->x][lapin->y] = VIDE;
  //printf("Action : %d\n", action);
  switch (action) {
  case GAUCHE:
    if (map[lapin->x][lapin->y - 1] == 1);
      //printf("Lapin : Je ne peux pas avancer\n");
    else
      lapin->y = lapin->y - 1;
    break;
  case AVANCER:
    if (map[lapin->x - 1][lapin->y] == 1);
      //printf("Lapin : Je ne peux pas avancer\n");
    else
      lapin->x = lapin->x - 1;
    break;
  case DROITE:
    if (map[lapin->x][lapin->y + 1] == 1);
      //printf("Lapin : Je ne peux pas avancer\n");
    else
      lapin->y = lapin->y + 1;
    break;
  case RECULER:
    if (map[lapin->x + 1][lapin->y] == 1);
      // printf("Lapin : Je ne peux pas avancer\n")
    else
      lapin->x = lapin->x + 1;
    break;
  }

  map[lapin->x][lapin->y] = LAPIN;
  cherche_chasseur(map, taille, lapin);
  recherche_terrier(map, taille, lapin);
}

int lapin_main(int **map, joueur_t *lapin, int taille, ruleSet_t *rules) {
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  initSDL(&window, &renderer);
  int nb_iteration = 0;
  while (lapin->x != 1 || lapin->y != 1) {
    printf("Lapin : Je suis en %d %d\n", lapin->x, lapin->y);
    deplacement_lapin(map, taille, rules, lapin);
    afficher_map(map, taille + 2);
    SDL_RenderClear(renderer);
    affichefond(renderer, window, map, taille + 2);
    SDL_RenderPresent(renderer);
    //SDL_Delay(10);
    nb_iteration ++;
    printf("Nombre d'itération : %d\n", nb_iteration);
  }
  return 0;
}


void deplacement_lapin_clavier(int **map, int taille, joueur_t *lapin) {
  SDL_PumpEvents(); 
  const Uint8 *state = SDL_GetKeyboardState(NULL);
  
  if (state[SDL_SCANCODE_UP] && map[lapin->x - 1][lapin->y] != 1) {
      map[lapin->x][lapin->y] = VIDE;
      lapin->x -= 1;
      map[lapin->x][lapin->y] = LAPIN;
  }
  
  if (state[SDL_SCANCODE_DOWN] && map[lapin->x + 1][lapin->y] != 1) {
      map[lapin->x][lapin->y] = VIDE;
      lapin->x += 1;
      map[lapin->x][lapin->y] = LAPIN;
  }
  
  if (state[SDL_SCANCODE_LEFT] && map[lapin->x][lapin->y - 1] != 1) {
      map[lapin->x][lapin->y] = VIDE;
      lapin->y -= 1;
      map[lapin->x][lapin->y] = LAPIN;
  }
  
  if (state[SDL_SCANCODE_RIGHT] && map[lapin->x][lapin->y + 1] != 1) {
      map[lapin->x][lapin->y] = VIDE;
      lapin->y += 1;
      map[lapin->x][lapin->y] = LAPIN;
  }
}





/*
int main() {
  int n = 15;
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  initSDL(&window, &renderer);

  int **maze;
  maze = init_map(n);

  generateMaze(maze, n + 2);
  for (int i = 0; i < n + 2; i++) {
    for (int j = 0; j < n + 2; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
  afficher_map(maze, n);
  joueur_t *joueur_lapin = malloc(sizeof(joueur_t));
  joueur_lapin->x = n;
  joueur_lapin->y = n;
  joueur_lapin->devant = maze[joueur_lapin->x][joueur_lapin->y - 1];
  joueur_lapin->derriere = maze[joueur_lapin->x][joueur_lapin->y + 1];
  joueur_lapin->gauche = maze[joueur_lapin->x - 1][joueur_lapin->y];
  joueur_lapin->droite = maze[joueur_lapin->x + 1][joueur_lapin->y];
  joueur_lapin->direction_predateur = NORD;
  joueur_lapin->direction_terrier = NORD;
  joueur_lapin->distance_predateur = LOIN;
  joueur_lapin->distance_terrier = LOIN;
  printf("Distance %d\n", (int)joueur_lapin->distance_terrier);
  ruleSet_t *rules = malloc(sizeof(ruleSet_t));
  rules->rules = malloc(sizeof(rule_t) * NB_RULES);
  readRulesFromFile("../initRegle.txt", &(rules->rules));
  rules->energy = INT_MAX;

  lapin(maze, joueur_lapin, n, rules);

  afficher_map(maze, n);
  liberer_map(maze, n);
  return 0;
}*/