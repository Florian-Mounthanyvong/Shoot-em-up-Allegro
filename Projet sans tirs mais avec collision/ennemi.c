#include "jeu.h"

t_ennemi* creerBoss()
{
    t_ennemi* nouveau;

    nouveau=(t_ennemi *)malloc(1*sizeof(t_ennemi));

    nouveau->image=load_bitmap("boss.bmp",NULL);
    if (!nouveau->image)
    {
        allegro_message("pas pu trouver ");
        exit(EXIT_FAILURE);
    }
    nouveau->tx=nouveau->image->w;
    nouveau->ty=nouveau->image->h;

    nouveau->x=3*SCREEN_W/4-nouveau->tx/2;
    nouveau->y=SCREEN_H/2-nouveau->ty/2;

    nouveau->dx=0;
    nouveau->dy=0;

    return nouveau;
}

t_ennemi* creerEnnemi()// creer et alloue les ennemis
{
    t_ennemi*nouveau;

    nouveau=(t_ennemi *)malloc(1*sizeof(t_ennemi));

    nouveau->image=load_bitmap("ennemi4.bmp",NULL);
    if (!nouveau->image)
    {
        allegro_message("pas pu trouver ");
        exit(EXIT_FAILURE);
    }

    nouveau->tx=nouveau->image->w;
    nouveau->ty=nouveau->image->h;

    nouveau->x=3*SCREEN_W/4-nouveau->tx/2;
    nouveau->y=SCREEN_H/2-nouveau->ty/2;

    nouveau->dx=0;
    nouveau->dy=0;

    return nouveau;

}

void actualiserBoss(t_ennemi *ennemi) // permet d'actualiser la position des ennemis
{
          if ( rand()%30==0 ){

        ennemi->dx = rand()%10;
        ennemi->dy = rand()%8;
    }

    if  (  ( ennemi->x < SCREEN_W/2 && ennemi->dx < 0 ) ||( ennemi->x + ennemi->tx > SCREEN_W && ennemi->dx > 0) )// controle des bords
        ennemi->dx = -ennemi->dx;

    if  (  ( ennemi->y < 0 && ennemi->dy < 0 ) ||( ennemi->y + ennemi->ty > SCREEN_H && ennemi->dy > 0) )
        ennemi->dy = -ennemi->dy;

    ennemi->x = ennemi->x + ennemi->dx;
    ennemi->y = ennemi->y + ennemi->dy;

}


void actualiserEnnemi(t_ennemi *ennemi) // permet d'actualiser la position des ennemis
{
          if ( rand()%70==0 ){

        ennemi->dx = rand()%6;
        ennemi->dy = rand()%6;
    }

    if  (  ( ennemi->x < SCREEN_W/2 && ennemi->dx < 0 ) ||( ennemi->x + ennemi->tx > SCREEN_W && ennemi->dx > 0) )// controle des bords
        ennemi->dx = -ennemi->dx;

    if  (  ( ennemi->y < 0 && ennemi->dy < 0 ) ||( ennemi->y + ennemi->ty > SCREEN_H && ennemi->dy > 0) )
        ennemi->dy = -ennemi->dy;

    ennemi->x = ennemi->x + ennemi->dx;
    ennemi->y = ennemi->y + ennemi->dy;

}

void dessinerEnnemi(BITMAP*bmp, t_ennemi * ennemi,BITMAP*collision)
{
    draw_sprite(bmp,ennemi->image,ennemi->x,ennemi->y);
    draw_sprite(collision,ennemi->image,ennemi->x,ennemi->y);


}
