#include "apprentissage_multithreading.h"
#include "apprentissagev1.h"

thread_args_t *setup_thread_args(int nb_thread, int taille) {
  thread_args_t *thread_args = malloc(nb_thread * sizeof(thread_args_t));
  for (int i = 0; i < nb_thread; i++) {
    thread_args[i].rules = malloc(sizeof(ruleSet_t));
    thread_args[i].rules->rules = malloc(sizeof(rule_t) * NB_RULES);
    thread_args[i].taille = taille;
  }
  return thread_args;
}
int lancer_jeu_sans_graphisme_apprentissage_multithreading(int taille,
                                                           int *nb_iterations,
                                                           ruleSet_t *rules) {
  int **map = NULL;
  map = init_map(taille + 2);
  position *position_chasseur = generateMaze(map, taille + 2);

  joueur_t lapin;
  lapin.x = taille;
  lapin.y = taille;
  lapin.devant = map[lapin.x][lapin.y - 1];
  lapin.derriere = map[lapin.x][lapin.y + 1];
  lapin.gauche = map[lapin.x - 1][lapin.y];
  lapin.droite = map[lapin.x + 1][lapin.y];
  lapin.direction_predateur = NORD;
  lapin.direction_terrier = NORD;
  lapin.distance_predateur = LOIN;
  lapin.distance_terrier = LOIN;

  position position_lapin;
  position_lapin.x = lapin.x;
  position_lapin.y = lapin.y;
  position position_terrier;
  position_terrier.x = 1;
  position_terrier.y = 1;

  int drapeau_chasse = 1;
  *nb_iterations = 0;
  while (drapeau_chasse == 1) {
    *nb_iterations = *nb_iterations + 1;
    deplacement_lapin(map, taille, rules, &lapin);
    position_lapin.x = lapin.x;
    position_lapin.y = lapin.y;
    if (deplacement_chasseur(map, taille, position_chasseur, &position_lapin) ==
        1) {
      drapeau_chasse = 0;
    }
    if ((position_terrier.x == lapin.x) && (position_terrier.y == lapin.y)) {
      drapeau_chasse = 2;
    }
  }
  int score_lapin = score(lapin, position_terrier, drapeau_chasse,taille);

  liberer_map(map, taille);
  free(position_chasseur);

  return score_lapin;
}
void energy_multithreading(ruleSet_t *attempt_rules, int nb_threads, int taille,
                           int coef_chasseur, int coef_terrier) {
  pthread_t threads[nb_threads];
  thread_args_t *thread_args = setup_thread_args(nb_threads, taille);
  for (int i = 0; i < nb_threads; i++) {
    copyRuleSet(attempt_rules[i], thread_args[i].rules);
  }
  for (int i = 0; i < nb_threads; i++) {
    if (pthread_create(&threads[i], NULL, thread_jeu, &thread_args[i]) != 0) {
      fprintf(stderr, "Error creating thread %d\n", i);
      exit(1);
    }
  }

  for (int i = 0; i < nb_threads; i++) {
    if (pthread_join(threads[i], NULL) != 0) {
      fprintf(stderr, "Error joining thread %d\n", i);
      exit(1);
    }
  }
  for (int i = 0; i < nb_threads; i++)
  {
    attempt_rules[i].energy = thread_args[i].rules->energy;
  }
    for (int i = 0; i < nb_threads; i++) {
        free(thread_args[i].rules->rules);
        free(thread_args[i].rules);
    }
    free(thread_args);
  
  
}
void *thread_jeu(void *arg) {
  thread_args_t *struct_thread_args = (thread_args_t *)arg;
  // printf("coucou %d\n", struct_thread_args->taille);
  int nb_iterations = 0;
  int compteur_lapin = 0;
  int score;

  for (int i = 0; i < 100; i++) {
    score = lancer_jeu_sans_graphisme_apprentissage_multithreading(
        struct_thread_args->taille, &nb_iterations, struct_thread_args->rules);
    compteur_lapin += score;
  }
  compteur_lapin /= 100;
  printf("Le lapin a un score de %d\n", compteur_lapin);
  struct_thread_args->rules->energy = compteur_lapin;
  pthread_exit(NULL);
}
void shuffle(int *array, int n) {
  for (int k = 0; k < n; k++) {
    int i = rand() % n;
    int j = rand() % n;
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}
int score(joueur_t lapin, position terrier, int drapeau_chasseur,int taille) {
  int score_joueur = 100*(abs(lapin.x - taille) + abs(lapin.y - taille));
  if (drapeau_chasseur == 2) {
    score_joueur += 10000;
  }
  return score_joueur;
}
