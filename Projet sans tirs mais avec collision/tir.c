#include "jeu.h"

t_tir* creerTir(int x,int y)
{
    t_tir* nouveau;

    nouveau=(t_tir*)malloc(1*sizeof(t_tir));

    nouveau->image=load_bitmap("tir.bmp",NULL);
    if (!nouveau->image)
    {
        allegro_message("pas pu trouver ");
        exit(EXIT_FAILURE);
    }
    nouveau->x=x;
    nouveau->y=y;
    nouveau->d=0;
    return nouveau;

}

void actualiserTir(t_tir*tir)
{

    tir->d=20;

    tir->x=(tir->x)-tir->d;

}

void dessinerTir(BITMAP*bmp, t_tir*tir)
{
    draw_sprite(bmp,tir->image,tir->x,tir->y);
}



