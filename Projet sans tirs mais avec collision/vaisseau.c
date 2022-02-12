#include "jeu.h"

void initialiation_allegro()
{
    allegro_init();
    install_keyboard();
    install_mouse() ;

    set_color_depth(desktop_color_depth());

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        // message et sortie de prog. si échec
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}

void initialisation_vaisseau(t_vaisseau*vaisseau)
{
    vaisseau->x=100;
    vaisseau->y=300;
    vaisseau->b=1;
    vaisseau->vie=3;
    vaisseau->score=0;
}

void mouvement_vaisseau(t_vaisseau*v,BITMAP*bmp)
{


    t_tir*tir;
    tir=creerTir(v->x,v->y);
    if (key[KEY_A])
    {
        (v->x)=(v->x)-6*(v->b);
        if((v->x)<0)
        {
            (v->x)=0;
        }
    }
    if (key[KEY_D])
    {
        (v->x)=(v->x)+6*(v->b);
        if((v->x)>SCREEN_W-((v->image)->w))
        {
            (v->x)=SCREEN_W-((v->image)->w);
        }
    }
    if (key[KEY_W])
    {
        (v->y)=(v->y)-6*(v->b);
        if((v->y)<0)
        {
            (v->y)=0;
        }
    }
    if (key[KEY_S])
    {
        (v->y)=(v->y)+6*(v->b);
        if((v->y)>SCREEN_H-((v->image)->h))
        {
            (v->y)=SCREEN_H-((v->image)->h);
        }
    }
    if(key[KEY_B])
    {
        (v->b)++;
        rest(10);
    }

    if (key[KEY_SPACE])
    {

        dessinerTir(bmp,tir);
        actualiserTir(tir);

    }

}
