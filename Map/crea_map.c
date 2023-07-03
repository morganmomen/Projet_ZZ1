#include "./crea_map.h"


int ** creation_map (int taille)
{
    int ** map=malloc((taille+1)*sizeof(int*));
    for (int i=0;i<(taille+1);i++)
    {
        *map=malloc((taille+1)*sizeof(int));
    }

}