#include "gestion_jeu.h"


void* thread_jeu(void*arg){
    int taille =  *((int*)arg);
    int nbLancer = 500;
    int resultat[nbLancer];
    int nb_iterations[nbLancer];
    for(int i = 0; i < nbLancer; i++)
    {
        resultat[i] = lancer_jeu_sans_graphisme(taille, &nb_iterations[i]);
        //printf("Iteration %d\n", i);
    }

    int nb_victoire_chasseur = 0;
    int nb_victoire_lapin = 0;
    int nb_iterations_total = 0;
    for(int i = 0; i < nbLancer; i++)
    {
        if(resultat[i] == 0)
        {
            nb_victoire_chasseur++;
        }
        else
        {
            nb_victoire_lapin++;
        }
        nb_iterations_total += nb_iterations[i];
    }

    printf("Le chasseur a gagné %d fois\n", nb_victoire_chasseur);
    printf("Le lapin a gagné %d fois\n", nb_victoire_lapin);
    printf("Le nombre moyen d'itérations est de %d\n", nb_iterations_total/nbLancer);

    pthread_exit(NULL);
}



int main(int argc, char **argv) 
{
    (void)argc;
    (void)argv;
    int taille = 50;

    /*Avec direction fleches*/

    int nbiterations;
    int resultat = lancer_jeu_avec_graphisme_avec_control_lapin(taille, &nbiterations);
    if(resultat == 0)
    {
        printf("Le chasseur a gagné\n");
    }
    else
    {
        printf("Le lapin a gagné\n");
    }
    
    printf("Le nombre d'itérations est de %d\n", nbiterations);
    


    // /*SANS GRAPHISME*/
    // printf("Bienvenue dans le jeu du chasseur et du lapin\n");
    // int nbLancer = 100;
    // int resultat[nbLancer];
    // int nb_iterations[nbLancer];
    // for(int i = 0; i < nbLancer; i++)
    // {
    //     resultat[i] = lancer_jeu_sans_graphisme(taille, &nb_iterations[i]);
    //     printf("Iteration %d\n", i);
    // }

    // int nb_victoire_chasseur = 0;
    // int nb_victoire_lapin = 0;
    // int nb_iterations_total = 0;
    // for(int i = 0; i < nbLancer; i++)
    // {
    //     if(resultat[i] == 0)
    //     {
    //         nb_victoire_chasseur++;
    //     }
    //     else
    //     {
    //         nb_victoire_lapin++;
    //     }
    //     nb_iterations_total += nb_iterations[i];
    // }

    // printf("Le chasseur a gagné %d fois\n", nb_victoire_chasseur);
    // printf("Le lapin a gagné %d fois\n", nb_victoire_lapin);
    // printf("Le nombre moyen d'itérations est de %d\n", nb_iterations_total/nbLancer);

    /*AVEC GRAPHISME*/
    // int nbiterations;
    // int resultat = lancer_jeu_avec_graphisme(taille, &nbiterations);
    // if(resultat == 0)
    // {
    //     printf("Le chasseur a gagné\n");
    // }
    // else
    // {
    //     printf("Le lapin a gagné\n");
    // }
    
    // printf("Le nombre d'itérations est de %d\n", nbiterations);
    // return 0;

    /*THREAD*/
    // int nbThread = 1;
    // pthread_t threads[nbThread];
    // int thread_args[nbThread];
    // for(int i = 0; i < nbThread; i++)
    // {
    //     thread_args[i] = taille;
    // }   

    // for(int i = 0; i < nbThread; i++)
    // {
    //     if (pthread_create(&threads[i], NULL, thread_jeu, &thread_args[i]) != 0) {
    //         fprintf(stderr, "Error creating thread %d\n", i);
    //         exit(1);
    //     }
    // }

    // for(int i = 0; i < nbThread; i++)
    // {
    //     if (pthread_join(threads[i], NULL) != 0) {
    //         fprintf(stderr, "Error joining thread %d\n", i);
    //         exit(1);
    //     }
    // }

    //thread_jeu(&taille);

    // if (pthread_create(&threads[0], NULL, thread_jeu, &thread_args[0]) != 0) {
    //     fprintf(stderr, "Error creating thread %d\n", 0);
    //     exit(1);
    // }

    // if (pthread_create(&threads[1], NULL, thread_jeu, &thread_args[1]) != 0) {
    //     fprintf(stderr, "Error creating thread %d\n", 1);
    //     exit(1);
    // }

    // if (pthread_join(threads[0], NULL) != 0) {
    //     fprintf(stderr, "Error joining thread %d\n", 0);
    //     exit(1);
    // }

    // if (pthread_join(threads[1], NULL) != 0) {
    //     fprintf(stderr, "Error joining thread %d\n", 1);
    //     exit(1);
    // }

    printf("FIN DES THREADS\n");
    return 0;
}



