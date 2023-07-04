#include "gestion_jeu.h"



int lancer_jeu_sans_graphisme (int taille, int *nb_iterations)
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
    

    ruleSet_t *rules = malloc(sizeof(ruleSet_t));
    rules->rules = malloc(sizeof(rule_t) * NB_RULES);
    readRulesFromFile("../initRegle.txt", &(rules->rules));
    rules->energy = INT_MAX;

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


int lancer_jeu_avec_graphisme (int taille, int *nb_iterations)
{
    int ** map = NULL;
    map = init_map(taille+2);
    position * position_chasseur = generateMaze(map, taille+2);

    SDL_Window * window = NULL;
    SDL_Renderer * renderer = NULL;
    initSDL(&window,&renderer);

    affichefond(renderer,window,map,taille+2);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);

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
    

    ruleSet_t *rules = malloc(sizeof(ruleSet_t));
    rules->rules = malloc(sizeof(rule_t) * NB_RULES);
    readRulesFromFile("../initRegle.txt", &(rules->rules));
    rules->energy = INT_MAX;

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
        SDL_RenderClear(renderer);
        affichefond(renderer,window,map,taille+2);
        SDL_RenderPresent(renderer);
        SDL_Delay(50);

    }

    liberer_map(map,taille);
    free(position_chasseur);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    return(drapeau_chasse);


        
}