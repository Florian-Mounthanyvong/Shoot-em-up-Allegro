#include "jeu.h"

void menu()
{
    BITMAP*menu;
    BITMAP*menu_niveaux;
    BITMAP*souris;
    BITMAP*bufferm;
    initialiation_allegro();
    int choix=0;
    int niveau;
    menu = load_bitmap("Menu.bmp", NULL);
    menu_niveaux = load_bitmap("Menu_Niveaux.bmp", NULL);
    souris = load_bitmap("Souris.bmp", NULL);

    bufferm = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(bufferm);

    if((!menu)||(!menu_niveaux)||(!souris))
    {
        allegro_message("Erreur de chargement des images");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    while(choix!=3)
    {
        if(choix==0)
        {
            blit(menu, bufferm, 0, 0, 0, 0, menu->w, menu->h);
            draw_sprite(bufferm, souris, mouse_x, mouse_y);
            if((mouse_b&1)&&(mouse_x<779)&&(mouse_x>536)&&(mouse_y<408)&&(mouse_y>350)) // nouvelle partie
            {
                choix=1;//Nouvelle partie
            }

            if((mouse_b&1)&&(mouse_x<779)&&(mouse_x>536)&&(mouse_y<477)&&(mouse_y>419)) // menu niveaux
            {
                choix=2;// menu niveaux
            }
            if((mouse_b&1)&&(mouse_x<779)&&(mouse_x>536)&&(mouse_y<546)&&(mouse_y>489))
            {
                choix=3;//Quitter
            }
        }

        if(choix==1||choix==4)//Nouvelle partie / Niveau 1
        {
            clear_bitmap(bufferm);
            niveau=1;
            Play(niveau);
            if(key[KEY_ESC])
            {
                choix=0;
            }
        }

        if(choix==5)//Niveau 2
        {
            clear_bitmap(bufferm);
            niveau=2;
            Play(niveau);
            if(key[KEY_ESC])
            {
                choix=0;
            }
        }

        if(choix==6)//Niveau 3
        {
            clear_bitmap(bufferm);
            niveau=3;
            Play(niveau);
            if(key[KEY_ESC])
            {
                choix=0;
            }
        }

        if(choix==7)//BOSS
        {
            clear_bitmap(bufferm);
            niveau=4;
            Play(niveau);
            if(key[KEY_ESC])
            {
                choix=0;
            }
        }

        if(choix==2)//Accès menu niveaux
        {
            clear_bitmap(bufferm);
            blit(menu_niveaux, bufferm, 0, 0, 0, 0, menu_niveaux->w, menu_niveaux->h);
            draw_sprite(bufferm, souris, mouse_x, mouse_y);
            if((mouse_b&1)&&(mouse_x<674)&&(mouse_x>439)&&(mouse_y<205)&&(mouse_y>146)) // niveau 1
            {
                choix=4;
            }

            if((mouse_b&1)&&(mouse_x<790)&&(mouse_x>539)&&(mouse_y<276)&&(mouse_y>217)) // niveau 2
            {
                choix=5;
            }

            if((mouse_b&1)&&(mouse_x<674)&&(mouse_x>439)&&(mouse_y<348)&&(mouse_y>288)) // niveau 3
            {
                choix=6;
            }

            if((mouse_b&1)&&(mouse_x<790)&&(mouse_x>539)&&(mouse_y<418)&&(mouse_y>359)) // boss
            {
                choix=7;
            }
            if(key[KEY_ESC])
            {
                choix=0;
            }
        }

        blit(bufferm, screen, 0, 0, 0, 0, bufferm->w, bufferm->h);
    }
}
