#include "apprentissagev1.h"
#include "apprentissage_multithreading.h"

int lancer_jeu_sans_graphisme_apprentissage_multithreading(int taille, int *nb_iterations,ruleSet_t *rules)
{
    int ** map = NULL;
    map = init_map(taille+2);
    position * position_chasseur = generateMaze(map, taille+2);

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
    position_terrier.x=1;
    position_terrier.y=1;

    int drapeau_chasse=1;
    *nb_iterations = 0;
    while (drapeau_chasse == 1)
    {
        *nb_iterations = *nb_iterations + 1;
        deplacement_lapin(map,taille,rules,&lapin);
        position_lapin.x = lapin.x;
        position_lapin.y = lapin.y;
        if (deplacement_chasseur (map,taille,position_chasseur,&position_lapin)==1)
        {
            drapeau_chasse = 0;
        }
        if ((position_terrier.x==lapin.x)&&(position_terrier.y==lapin.y))
        {
            drapeau_chasse = 2;
        }

    }

    liberer_map(map,taille);
    free(position_chasseur);

    return(drapeau_chasse);
    
}
void energy_multithreading(ruleSet_t *attempt_rules,int nb_threads, int taille, int coef_chasseur, int coef_terrier)
{
    pthread_t threads[nb_threads];
    thread_args_t struct_thread_args;
    thread_args_t thread_args[nb_threads];
    for(int i = 0; i < nb_threads; i++)
    {
        thread_args[i] = struct_thread_args;
    }   

    for(int i = 0; i < nb_threads; i++)
    {
        if (pthread_create(&threads[i], NULL, thread_jeu, &thread_args[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(1);
        }
    }

    for(int i = 0; i < nb_threads; i++)
    {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread %d\n", i);
            exit(1);
        }
    }

}
void *thread_jeu(void*arg)
{
    thread_args_t *struct_thread_args = (thread_args_t*)arg;
    int nb_iterations=0;
    int tabenergy[100];
    int energy_min = INT_MAX;
    int energy_max = 0;
    int drapeau_chasseur;
    int energy =0;
    for (int i=0;i<100;i++)
    {
    drapeau_chasseur = lancer_jeu_sans_graphisme_apprentissage_multithreading(struct_thread_args->taille, &nb_iterations, &(struct_thread_args->rules));
    if (drapeau_chasseur == 0)
    {
        tabenergy[i] = INT_MAX * struct_thread_args->coef_chasseur;
    }
    else if (drapeau_chasseur == 2)
    {
        tabenergy[i] = nb_iterations * struct_thread_args->coef_terrier;
    }
    if (tabenergy[i] < energy_min) energy_min = tabenergy[i];
    if (tabenergy[i] > energy_max) energy_max = tabenergy[i];
    //printf("Progression d'une itération : %d%%\n", i);
    }
    for (int j =0; j<100; j++)
    {
        tabenergy[j] = (tabenergy[j] - energy_min)/ (energy_max - energy_min);
        energy = energy + tabenergy[j]/100;
    }
    struct_thread_args->rules.energy = energy;
}


void shuffle(int *array, int n)
{
    for (int k = 0; k<n; k++)
    {
        int i = rand() % n;
    int j = rand() % n;
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    }
}
