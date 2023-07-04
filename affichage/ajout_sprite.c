#include "./ajout_sprite.h"


SDL_Rect lapin[8][4];
SDL_Texture * lapintexture = NULL;
int offset_x_lapin,offset_y_lapin;
int lapinIndex []= {0;0};


SDL_Rect chasseur[9][4];
SDL_Texture * chasseurtexture = NULL;
int offset_x_chasseur,offset_y_chasseur;
int chasseurIndex []= {0;0};

int nbframe = 0;


void Draw_Lapin(SDL_Window * window,SDL_Renderer * renderer)
{
    int window_w, window_h ;
    SDL_GetWindowSize(window, &window_w, &window_h);
    SDL_Rect source={0};
    SDL_Rect destination={0};

    if(persoTexture == NULL)lapintexture = loadTexture("../img/lapin.png", renderer);
    SDL_QueryTexture(lapintexture,NULL, NULL,&source.w, &source.h);
    
    int nb_images_w = 8, nb_images_h=4;


    offset_x_lapin= source.w/nb_images_w;
    offset_y_lapin = source.h/nb_images_h; 

    for(int i=0; i<nb_images_w; i++)
    {
        for (int j=0; j<nb_images_h;j++)
        {
            lapin[i][j].x = i*offset_x_lapin;
            lapin[i][j].y = j*offset_y_lapin;
            lapin[i][j].w = offset_x_lapin;
            lapin[i][j].h = offset_y_lapin;
        }
    }

}

void Draw_Chasseur(SDL_Window * window,SDL_Renderer * renderer)
{
    int window_w, window_h ;
    SDL_GetWindowSize(window, &window_w, &window_h);
    SDL_Rect source={0};
    SDL_Rect destination={0};

    if(persoTexture == NULL)chasseurtexture = loadTexture("../img/chasseur_mouvement.png", renderer);
    SDL_QueryTexture(chasseurtexture,NULL, NULL,&source.w, &source.h);
    
    int nb_images_w = 8, nb_images_h=4;


    offset_x_chasseur= source.w/nb_images_w;
    offset_y_chasseur = source.h/nb_images_h; 

    for(int i=0; i<nb_images_w; i++)
    {
        for (int j=0; j<nb_images_h;j++)
        {
            chasseur[i][j].x = i*offset_x_chasseur;
            chasseur[i][j].y = j*offset_y_chasseur;
            chasseur[i][j].w = offset_x_chasseur;
            chasseur[i][j].h = offset_y_chasseur;
        }
    }

}

