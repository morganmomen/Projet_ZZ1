#include "gestion_jeu.h"



int lancer_jeu_sans_graphisme (int taille, int *nb_iterations)
{
    int ** map = NULL;
    map = init_map(taille+2);
    position * position_chasseur = generateMaze(map, taille+2);

    joueur_t jlapin;
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

    position position_lapin;
    position_lapin.x = jlapin.x;
    position_lapin.y = jlapin.y;
    

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
        deplacement_lapin(map,taille,rules,&jlapin);
        position_lapin.x = jlapin.x;
        position_lapin.y = jlapin.y;
        if (deplacement_chasseur (map,taille,position_chasseur,&position_lapin)==1)
        {
            drapeau_chasse = 0;
        }
        if ((position_terrier.x==jlapin.x)&&(position_terrier.y==jlapin.y))
        {
            drapeau_chasse = 2;
        }

    }

    liberer_map(map,taille);
    free(position_chasseur);
    free(rules->rules);
    free(rules);

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

    joueur_t jlapin;
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

    position position_lapin;
    position_lapin.x = jlapin.x;
    position_lapin.y = jlapin.y;
    
    

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
        deplacement_lapin(map,taille,rules,&jlapin);
        position_lapin.x = jlapin.x;
        position_lapin.y = jlapin.y;
        if (deplacement_chasseur (map,taille,position_chasseur,&position_lapin)==1)
        {
            drapeau_chasse = 0;
        }
        if ((position_terrier.x==jlapin.x)&&(position_terrier.y==jlapin.y))
        {
            drapeau_chasse = 2;
        }
        SDL_RenderClear(renderer);
        affichefond(renderer,window,map,taille+2);
        SDL_RenderPresent(renderer);
        SDL_Delay(1);

    }

    liberer_map(map,taille);
    free(position_chasseur);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    free(rules->rules);
    free(rules);

    return(drapeau_chasse);


        
}


int lancer_jeu_avec_graphisme_avec_control_lapin (int taille, int *nb_iterations)
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

    joueur_t jlapin;
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

    position position_lapin;
    position_lapin.x = jlapin.x;
    position_lapin.y = jlapin.y;

    position position_terrier;
    position_terrier.x=1;
    position_terrier.y=1;

    int drapeau_chasse=1;
    *nb_iterations = 0;
    while (drapeau_chasse == 1)
    {
        *nb_iterations = *nb_iterations + 1;

        deplacement_lapin_clavier(map,taille,&jlapin);

        position_lapin.x = jlapin.x;
        position_lapin.y = jlapin.y;
        if (deplacement_chasseur (map,taille,position_chasseur,&position_lapin)==1)
        {
            drapeau_chasse = 0;
        }
        if ((position_terrier.x==jlapin.x)&&(position_terrier.y==jlapin.y))
        {
            drapeau_chasse = 2;
        }
        SDL_RenderClear(renderer);
        affichefond(renderer,window,map,taille+2);
        SDL_RenderPresent(renderer);
        SDL_Delay(100);

    }

    liberer_map(map,taille);
    free(position_chasseur);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    return(drapeau_chasse);
}