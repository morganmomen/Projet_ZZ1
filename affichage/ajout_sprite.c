#include "./ajout_sprite.h"


void Draw_Lapin(SDL_Window * window,SDL_Renderer * renderer,SDL_Rect * lapin,SDL_Texture * lapintexture,int offset_x_lapin,int offset_y_lapin)
{
    int window_w, window_h ;
    SDL_GetWindowSize(window, &window_w, &window_h);
    SDL_Rect source={0};
    SDL_Rect destination={0};

    if(lapintexture == NULL)lapintexture = loadTexture("../img/lapin.png", renderer);
    SDL_QueryTexture(lapintexture,NULL, NULL,&source.w, &source.h);
    
    int nb_images_w = 8, nb_images_h=4;


    offset_x_lapin= source.w/nb_images_w;
    offset_y_lapin = source.h/nb_images_h; 

    for(int i=0; i<nb_images_h; i++)
    {
        for (int j=0; j<nb_images_w;j++)
        {
            lapin[i +j].x = j*offset_x_lapin;
            lapin[i +j].y = i*offset_y_lapin;
            lapin[i+j].w = offset_x_lapin;
            lapin[i+j].h = offset_y_lapin;
        }
    }

}

void Draw_Chasseur(SDL_Window * window,SDL_Renderer * renderer,SDL_Rect * chasseur,SDL_Texture * chasseurtexture,int offset_x_chasseur,int offset_y_chasseur)
{
    int window_w, window_h ;
    SDL_GetWindowSize(window, &window_w, &window_h);
    SDL_Rect source={0};
    SDL_Rect destination={0};

    if(chasseurtexture == NULL)chasseurtexture = loadTexture("../img/chasseur_mouvement.png", renderer);
    SDL_QueryTexture(chasseurtexture,NULL, NULL,&source.w, &source.h);
    
    int nb_images_w = 8, nb_images_h=4;


    offset_x_chasseur= source.w/nb_images_w;
    offset_y_chasseur = source.h/nb_images_h; 

    for(int i=0; i<nb_images_h; i++)
    {
        for (int j=0; j<nb_images_w;j++)
        {
            chasseur[i+j].x = j*offset_x_chasseur;
            chasseur[i+j].y = i*offset_y_chasseur;
            chasseur[i+j].w = offset_x_chasseur;
            chasseur[i+j].h = offset_y_chasseur;
        }
    }

}

