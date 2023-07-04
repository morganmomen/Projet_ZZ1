#include "lapin/mvt_lapin.h"
#include "Chasseur/gere_chasseur.h"

void deplacement_lapin(int **map, int taille, ruleSet_t *rules,
                       joueur_t *lapin) {
  action_t action;
  action = choixRule(rules, lapin);
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
}

