#include "jeu.h"

void Play(int niveau)
{
    BITMAP* image;
    BITMAP* image1;
    BITMAP* image1c;
    BITMAP* imagec;
    BITMAP* imageniveau3;
    BITMAP* buffer;
    BITMAP* buffer_collision;
    BITMAP* fond;
    BITMAP* fondboss;

    t_vaisseau vaisseau;
    t_ennemi* tab[NBRE]; // tableau de structure pour ennemi 2
    t_ennemi* tab2 [NBRE2]; // tableau de structure pour ennemi pour niveau 3
    t_ennemi* boss;// variable pour le boss


    initialisation_vaisseau(&vaisseau);


    //Tout remplacer quand on aura le sprite
    int Bleu=250;
    int Vert=250;
    int Rouge=0;
    int radius =0;
    //

    int xb,yb;
    int x,y;
    int i;
    int contact;

    int Game_Over=0;

    int Pause=0;//Blindage menu Pause


    int xfc=0;//Scroll infini collision?

    int screenx=0;//scroll infini
    int screenx2=800;
    int screenx3=0;
    int dep=5;//deplacement ecran



    (vaisseau.image)=load_bitmap("spaceship.bmp",NULL);
    //(tir.image)=load_bitmap("tir.bmp",NULL);
    image=load_bitmap("Background.bmp",NULL);
    image1=load_bitmap("Level_1.bmp",NULL);
    image1c=load_bitmap("Level_1_collision.bmp",NULL);
    imagec=load_bitmap("Level_collision.bmp",NULL);
    fond=load_bitmap("decor1.bmp",NULL);
    imageniveau3=load_bitmap("niveau3.bmp",NULL);
    fondboss=load_bitmap("fondboss.bmp",NULL);
    buffer=create_bitmap(SCREEN_W,SCREEN_H);
    buffer_collision=create_bitmap(SCREEN_W,SCREEN_H);
    //Vérifications
    if (!(vaisseau.image))
    {
        allegro_message("Unable to load spaceship.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!image)
    {
        allegro_message("Unable to load Background.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!image1)
    {
        allegro_message("Unable to load Level_1.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!image1c)
    {
        allegro_message("Unable to load Level_1_collision.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

        for(i=0;i<NBRE;i++)
        {
            tab[i]=creerEnnemi();

        }

        for(i=0;i<NBRE2;i++)
        {
            tab2[i]=creerEnnemi();
        }

        boss=creerBoss();



//Boucle Jeu
    while (!key[KEY_ESC])
    {
        while(Game_Over==0)
        {
            if(key[KEY_ESC])
            {
                Game_Over=1;
            }
        clear_bitmap(buffer);
        clear_bitmap(buffer_collision);


//Génération du niveau choisi
        if(niveau==1)
        {
        clear_bitmap(buffer);

        screenx=screenx-dep;
        screenx2=screenx2-dep;
        screenx3=screenx3-(2*dep);


        if(screenx<-800)
        {
            screenx=800;
        }
        if(screenx2<-800)
        {
            screenx2=800;
        }
        if(screenx3<-1200)
        {
            screenx3=0;
        }
            blit(image1,buffer,0,0,screenx, 0, image1->w, image1->h);
            blit(image1,buffer,0,0,screenx2,0, image1->w, image1->h);
            blit(image1c,buffer_collision,0,0,screenx, 0, image1c->w, image1c->h);
            blit(image1c,buffer_collision,0,0,screenx2,0, image1c->w, image1c->h);

        }
        else if (niveau==2)
        {
        screenx=screenx-dep;
        screenx2=screenx2-dep;
        screenx3=screenx3-(2*dep);



        if(screenx<-800)
        {
            screenx=800;
        }
        if(screenx2<-800)
        {
            screenx2=800;
        }
        if(screenx3<-1200)
        {
            screenx3=0;
        }
            blit(image,buffer,0,0, screenx, 0, image->w, image->h);
            blit(image,buffer,0,0,screenx2,0,image->w,image->h);
            blit(imagec,buffer_collision,0,0,screenx, 0, imagec->w, imagec->h);
            blit(imagec,buffer_collision,0,0,screenx2,0, imagec->w, imagec->h);
            masked_blit(fond,buffer,0,0,screenx3,0,fond->w,fond->h);
            masked_blit(fond,buffer_collision,0,0,screenx3,0,fond->w,fond->h);
        for(i=0;i<NBRE;i++)
        {
           dessinerEnnemi(buffer,tab[i],buffer_collision);
        }

        for(i=0;i<NBRE;i++)
        {
            actualiserEnnemi(tab[i]);
        }

        }

        else if(niveau==3)
        {
        screenx=screenx-dep;
        screenx2=screenx2-dep;



        if(screenx<-1500)
        {
            screenx=800;
        }
        if(screenx2<-1500)
        {
            screenx2=800;
        }

            blit(imageniveau3,buffer,0,0, screenx, 0, image->w, image->h);
            blit(imageniveau3,buffer,0,0,screenx2,0,image->w,image->h);
            blit(imagec,buffer_collision,0,0,screenx, 0, imagec->w, imagec->h);
            blit(imagec,buffer_collision,0,0,screenx2,0, imagec->w, imagec->h);


            for(i=0;i<NBRE2;i++)
            {
                dessinerEnnemi(buffer,tab2[i],buffer_collision);
            }

            for(i=0;i<NBRE2;i++)
            {
                actualiserEnnemi(tab2[i]);
            }


        }

        else if(niveau==4)
        {


        //screenx=screenx-dep/2;
       // screenx2=screenx2-dep/2;




        if(screenx<-800)
        {
            screenx=800;
        }
        if(screenx2<-800)
        {
            screenx2=800;
        }

            blit(fondboss,buffer,0,0, screenx, 0, image->w, image->h);
            blit(fondboss,buffer,0,0,screenx2,0,image->w,image->h);
            blit(imagec,buffer_collision,0,0,screenx, 0, imagec->w, imagec->h);
            blit(imagec,buffer_collision,0,0,screenx2,0, imagec->w, imagec->h);

            dessinerEnnemi(buffer,boss,buffer_collision);
            actualiserBoss(boss);

        }

//On rajoute le sprite du vaisseau sur le buffer contenant le fond du niveau choisi
        draw_sprite(buffer, (vaisseau.image), (vaisseau.x), (vaisseau.y));
        textprintf_ex(buffer, font, 10, 10, makecol(255, 255, 255), -1, "Life: %d",vaisseau.vie);


//On affiche le buffer complet sur l'écran
        blit(buffer,screen,0,0, 0, 0, buffer->w, buffer->h);

        rest(10);

        //Collision décor
            for (yb=0; yb<(vaisseau.image->h); yb++)
            {
                if ( getpixel(buffer_collision, vaisseau.x, vaisseau.y+yb) != makecol(255,255,255) )
                    contact=1;
                if ( getpixel(buffer_collision, vaisseau.x+vaisseau.image->w, vaisseau.y+yb) != makecol(255,255,255) )
                    contact=1;
            }

            for (xb=0; xb<(vaisseau.image->w); xb++)
            {
                if ( getpixel(buffer_collision, vaisseau.x+xb, vaisseau.y) != makecol(255,255,255) )
                    contact=1;
                if ( getpixel(buffer_collision, vaisseau.x+xb, vaisseau.y+(vaisseau.image->h)) != makecol(255,255,255) )
                    contact=1;
            }
            if(contact==1)
            {
                vaisseau.vie-=1;
                vaisseau.x=5;
                vaisseau.y=SCREEN_H/2;
                contact=0;
            }

        //Game Over
            if(vaisseau.vie<=0)
            {
                //A remplacer par un écran Game Over
                allegro_message("\t            Game Over\n   Press Esc to return to the main menu");
                Game_Over=1;
            }

//Commandes/Touches
        if(mouse_b&1)
        {
            t_tir*tir;
            tir=creerTir(((vaisseau.image)->w),((vaisseau.y)+47));
            dessinerTir(buffer,tir);
            actualiserTir(tir);

        }
        //Tir chargé avec le clic droit de la souris
        if(mouse_b&2)
        {
            while(mouse_b&2)
            {
                clear_bitmap(buffer);
                //Tout remplacer quand on aura le sprite
                screenx=screenx-dep;
                screenx2=screenx2-dep;
                screenx3=screenx3-(2*dep);

                printf("%d\n",screenx);

                if(screenx<-800)
                {
                    screenx=800;
                }
                if(screenx2<-800)
                {
                    screenx2=800;
                }

                if(screenx3<-1200)
                {
                    screenx3=0;
                }

                if(niveau==1)
                {
                blit(image1,buffer,0,0,screenx, 0, image1->w, image1->h);
                blit(image1,buffer,0,0,screenx2, 0, image1->w, image1->h);
                }
                else
                {
                blit(image,buffer,0,0,screenx, 0, image1->w, image1->h);
                blit(image,buffer,0,0,screenx2, 0, image1->w, image1->h);
                }

                 masked_blit(fond,buffer,0,0,screenx3,0,fond->w,fond->h);
                circlefill(buffer,(vaisseau.x)+((vaisseau.image)->w),(vaisseau.y)+47,radius,makecol(Rouge,Vert,Bleu));
                mouvement_vaisseau(&vaisseau,buffer);
                draw_sprite(buffer, (vaisseau.image), (vaisseau.x), (vaisseau.y));

                for(i=0;i<NBRE;i++)
                {
                 dessinerEnnemi(buffer,tab[i],buffer_collision);
                }




                blit(buffer,screen,0,0, 0, 0, buffer->w, buffer->h);


                radius++;
                mouvement_vaisseau(&vaisseau,buffer);

                for(i=0;i<NBRE;i++)
                {
                    actualiserEnnemi(tab[i]);
                }

                rest(10);
                Bleu=Bleu-3;
                if(Bleu<100)
                {
                    Bleu=100;
                }
                Vert=Vert-3;
                if(Vert<100)
                {
                    Vert=100;
                }
                Rouge=Rouge+1;
                if(Rouge>20)
                {
                    Rouge=20;
                }
                if(radius>25)
                {
                    radius=25;
                }

            }
            radius=0;
            Rouge=0;
            Bleu=250;
            Vert=250;

            //

        }
        //PAUSE
        if(key[KEY_P])
        {
            //Remplacer par un assombrissement de l'écran, centrer le "PAUSE" et le "3,2,1"

            textprintf_ex(buffer, font, SCREEN_W/2, SCREEN_H/2, makecol(255, 255, 255), -1, "PAUSE");
            blit(buffer,screen,0,0,0,0,buffer->w,buffer->h);
            rest(500);
            Pause=1;
            while(Pause==1)
            {

                if(key[KEY_P])
                {
                    Pause=0;
                }
            }
            textprintf_ex(screen,font,SCREEN_W/2-25,(SCREEN_H/2)+50,makecol(250,0,0),-1, "3");
            rest(500);
            textprintf_ex(screen,font,SCREEN_W/2+15,(SCREEN_H/2)+50,makecol(250,0,0),-1, "2");
            rest(500);
            textprintf_ex(screen,font,SCREEN_W/2+55,(SCREEN_H/2)+50,makecol(250,0,0),-1, "1");
            rest(500);

        }

    mouvement_vaisseau(&vaisseau,buffer);

    }
    }
}
