#include "apprentissageRNDM.h"

int taille =15;

void apprentissageAleatoire(int tailleArg, int numthread){

    // int ** map = NULL;
    // joueur_t jlapin;
    // position position_lapin;
    // position position_terrier;
    // position_terrier.x=1;
    // position_terrier.y=1;
    // int energieMax = 0;
    taille = tailleArg;
    pthread_t threads[numthread];
    char** fileNames = (char**)malloc(numthread * sizeof(char*));
    for (int i = 0; i < numthread; i++)
    {
        fileNames[i] = (char*)malloc(255 * sizeof(char));
        sprintf(fileNames[i], "./thread%d.txt", i + 1);
    }

    for(int i = 0; i < numthread; i++){
        printf("%s\n", fileNames[i]);
        if (pthread_create(&threads[i], NULL, thread_jeu, fileNames[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(1);
        }
    }

    for(int i = 0; i < numthread; i++){

        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread %d\n", i);
            exit(1);
        }

    }
        // printf("iteration %d\n", i);
        // // generation de regles
        // ruleSet_t * rules = NULL;
        // rules = generateRuleSet();
        // //printRuleSet(rules);

        // // generation et init de la map


        // // lancement de la simulation
        // int nbreussite_total = 0;
        // int drapeau_chasse;
        // int nbIterationParSimu = 0;
        // for(int nbSimu = 0; nbSimu < 100 ; nbSimu++){

        //     map = init_map(taille+2);
        //     position * position_chasseur = generateMaze(map, taille+2);

        //     jlapin.x = taille;
        //     jlapin.y = taille;
        //     jlapin.devant = map[jlapin.x][jlapin.y - 1];
        //     jlapin.derriere = map[jlapin.x][jlapin.y + 1];
        //     jlapin.gauche = map[jlapin.x - 1][jlapin.y];
        //     jlapin.droite = map[jlapin.x + 1][jlapin.y];
        //     jlapin.direction_predateur = NORD;
        //     jlapin.direction_terrier = NORD;
        //     jlapin.distance_predateur = LOIN;
        //     jlapin.distance_terrier = LOIN;

        //     position_lapin.x = jlapin.x;
        //     position_lapin.y = jlapin.y;


        //     nbIterationParSimu = 0;
        //     drapeau_chasse = 1;
        //     while (drapeau_chasse == 1)
        //     {
        //         nbIterationParSimu++;
        //         //printf("rule nb : %d  Simu: %d  iterationJeu : %d\n",i,nbSimu ,nbIterationParSimu);
        //         deplacement_lapin(map,taille,rules,&jlapin);
        //         position_lapin.x = jlapin.x;
        //         position_lapin.y = jlapin.y;
        //         if (deplacement_chasseur(map,taille,position_chasseur,&position_lapin)==1)
        //         {
        //             drapeau_chasse = 0;
        //         }
        //         if ((position_terrier.x==jlapin.x)&&(position_terrier.y==jlapin.y))
        //         {
        //             printf("Le lapin a gagne\n");
        //             drapeau_chasse = 2;
        //         }

        //     }

        //     if(drapeau_chasse == 2){
        //         nbreussite_total++;
        //     }
        //     free(position_chasseur);
        //     liberer_map(map,taille);

        // }



        // if(nbreussite_total >= energieMax){
        //     energieMax = nbreussite_total;
        //     printf("Nouveau record : %d\n", energieMax);
        //     printRuleSet(rules);
        //     writeRulesToFile(rules->rules, NB_RULES, "./Bestrules.txt");
        // }


        // free(rules->rules);
        // free(rules);
    //}


    for (int i = 0; i < numthread; i++)
    {
        free(fileNames[i]);
    }
    free(fileNames);
}





void* thread_jeu(void*arg)
{


    int ** map = NULL;
    joueur_t jlapin;
    position position_lapin;
    position position_terrier;
    position_terrier.x=1;
    position_terrier.y=1;
    int energieMax = 0;

    char* nom = (char*)arg;
    for(int nbRulesTest = 0; nbRulesTest <100; nbRulesTest++){
        // generation de regles
        ruleSet_t * rules = NULL;
        rules = generateRuleSet();
        //printRuleSet(rules);

        // generation et init de la map


        // lancement de la simulation
        int nbreussite_total = 0;
        int drapeau_chasse;
        int nbIterationParSimu = 0;
        for(int nbSimu = 0; nbSimu < 35 ; nbSimu++){

            map = init_map(taille+2);
            position * position_chasseur = generateMaze(map, taille+2);

            jlapin.x = taille;
            jlapin.y = taille;
            jlapin.devant = map[jlapin.x][jlapin.y - 1];
            jlapin.derriere = map[jlapin.x][jlapin.y + 1];
            jlapin.gauche = map[jlapin.x - 1][jlapin.y];
            jlapin.droite = map[jlapin.x + 1][jlapin.y];
            jlapin.direction_predateur = NORD;
            jlapin.direction_terrier = NORD;
            jlapin.distance_predateur = LOIN;
            jlapin.distance_terrier = LOIN;

            position_lapin.x = jlapin.x;
            position_lapin.y = jlapin.y;


            nbIterationParSimu = 0;
            drapeau_chasse = 1;
            while (drapeau_chasse == 1)
            {
                nbIterationParSimu++;
                //printf("rule nb : %d  Simu: %d  iterationJeu : %d\n",i,nbSimu ,nbIterationParSimu);
                deplacement_lapin(map,taille,rules,&jlapin);
                position_lapin.x = jlapin.x;
                position_lapin.y = jlapin.y;
                if (deplacement_chasseur(map,taille,position_chasseur,&position_lapin)==1)
                {
                    drapeau_chasse = 0;
                }
                if ((position_terrier.x==jlapin.x)&&(position_terrier.y==jlapin.y))
                {
                    printf("Le lapin a gagne thread: %s\n", nom);
                    drapeau_chasse = 2;
                }

            }

            if(drapeau_chasse == 2){
                nbreussite_total++;
            }
            free(position_chasseur);
            liberer_map(map,taille);

        }



        if(nbreussite_total >= energieMax){
            energieMax = nbreussite_total;
            if(nbreussite_total > energieMax) printf("Nouveau record : %d, thread : %s\n", energieMax, nom);

            //printRuleSet(rules);
            writeRulesToFile(rules->rules, NB_RULES, nom);
        }


        free(rules->rules);
        free(rules);
    }

}

void finalTournoiRules(int numthread){

    int ** map = NULL;
    joueur_t jlapin;
    position position_lapin;
    position position_terrier;
    position_terrier.x=1;
    position_terrier.y=1;
    int energieMax = 0;

    char** fileNames = (char**)malloc(numthread * sizeof(char*));
    for (int i = 0; i < numthread; i++)
    {
        fileNames[i] = (char*)malloc(255 * sizeof(char));
        sprintf(fileNames[i], "./thread%d.txt", i + 1);
    }
    for(int i = 0; i < numthread; i++){

        // generation de regles
        ruleSet_t *rules = malloc(sizeof(ruleSet_t));
        rules->rules = malloc(sizeof(rule_t) * NB_RULES);
        readRulesFromFile(fileNames[i], &(rules->rules));
        //printRuleSet(rules);

        // generation et init de la map


        // lancement de la simulation
        int nbreussite_total = 0;
        int drapeau_chasse;
        int nbIterationParSimu = 0;
        for(int nbSimu = 0; nbSimu < 150 ; nbSimu++){

            map = init_map(taille+2);
            position * position_chasseur = generateMaze(map, taille+2);

            jlapin.x = taille;
            jlapin.y = taille;
            jlapin.devant = map[jlapin.x][jlapin.y - 1];
            jlapin.derriere = map[jlapin.x][jlapin.y + 1];
            jlapin.gauche = map[jlapin.x - 1][jlapin.y];
            jlapin.droite = map[jlapin.x + 1][jlapin.y];
            jlapin.direction_predateur = NORD;
            jlapin.direction_terrier = NORD;
            jlapin.distance_predateur = LOIN;
            jlapin.distance_terrier = LOIN;

            position_lapin.x = jlapin.x;
            position_lapin.y = jlapin.y;


            nbIterationParSimu = 0;
            drapeau_chasse = 1;
            while (drapeau_chasse == 1)
            {
                nbIterationParSimu++;
                //printf("rule nb : %d  Simu: %d  iterationJeu : %d\n",i,nbSimu ,nbIterationParSimu);
                deplacement_lapin(map,taille,rules,&jlapin);
                position_lapin.x = jlapin.x;
                position_lapin.y = jlapin.y;
                if (deplacement_chasseur(map,taille,position_chasseur,&position_lapin)==1)
                {
                    drapeau_chasse = 0;
                }
                if ((position_terrier.x==jlapin.x)&&(position_terrier.y==jlapin.y))
                {
                    printf("Le lapin a gagne\n");
                    drapeau_chasse = 2;
                }

            }

            if(drapeau_chasse == 2){
                nbreussite_total++;
            }
            free(position_chasseur);
            liberer_map(map,taille);

        }
        
        if(nbreussite_total >= energieMax){
            energieMax = nbreussite_total;
            printf("Nouveau record : %d\n", energieMax);
            //printRuleSet(rules);
            writeRulesToFile(rules->rules, NB_RULES, "./Bestrules.txt");
        }

    }
        
    
    
    for (int i = 0; i < numthread; i++)
    {
        free(fileNames[i]);
    }
    free(fileNames);

}