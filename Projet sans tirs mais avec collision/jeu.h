#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <time.h>

#define NBRE 5 //nombre d'ennemis niveau 2
#define NBRE2 10 //nombres d'ennemis niveau 3

///STRUCTURES

typedef struct ///Structure pour le vaisseau
{
    int x, y; // position
    int b; //vitesse
    int vie; // vivant ou pas, actif ou pas
    int score; // les points obtenus
    BITMAP*image; // une image pour le vaisseau
} t_vaisseau;

typedef struct ennemi ///Structure ennemi
{
    int x,y; //position
    int dx,dy; //deplacement
    int tx,ty; //taille des ennemis
    int vie;
    BITMAP*image; // image pour ennemi
}t_ennemi;

typedef struct tir///Structure tir
{
    int x,y;
    int vie;
    int d;
    BITMAP*image;
}t_tir;

///Prototypes

// Tir (ne marche pas)
t_tir* creerTir(int x,int y);
void actualiserTir(t_tir*tir);
void dessinerTir(BITMAP*bmp, t_tir*tir);

//Ennemi
t_ennemi* creerBoss();//creer et alloue le boss
t_ennemi* creerEnnemi();// creer et alloue les ennemis
void actualiserBoss(t_ennemi *ennemi);// actualise les deplacements du boss
void actualiserEnnemi(t_ennemi *ennemi); // permet d'actualiser la position des ennemis
void dessinerEnnemi(BITMAP*bmp, t_ennemi * ennemi,BITMAP*collision);//dessine les ennemis et le boss

//Allegro
void initialiation_allegro();//initialisation d'allegro

//Vaisseau
void initialisation_vaisseau(t_vaisseau*vaisseau);
void mouvement_vaisseau(t_vaisseau*v,BITMAP*bmp);

//Jeu
void Play(int niveau);//Sous programme de jeu

//Menu
void menu();

int main();



#endif // JEU_H_INCLUDED
