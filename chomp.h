#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "MLV/MLV_all.h"
#define N 8
#define M 16
#define CHOCOLAT 1
#define MANGE 0
#define TAILLE_CASE 49

typedef struct tablette
{
    int n;
    int m;
    int grille[N][M];
}Tablette;

typedef enum joueur
{
    JOUEUR1,
    JOUEUR2
}Joueur;

typedef struct position
{
    Tablette chocolat;
    Joueur j;
}Position;

typedef struct coup
{
    int x;
    int y;
}Coup;

/****************Prototype*****************/
void error_allocation(void);
//Tablette creer_tablette(int n,int m);
Tablette creer_tablette(void);
void manger(Tablette *t, int x, int y);
int est_legal(Position *pos,Coup *coup);
int est_jeu_terminer(Position *pos,Joueur *joueur_gagnant);
void jouer_coup(Position *pos, Coup coup);
void afficher_position(Position *pos);
Coup lire_coup(Position *pos);
int saisie(void);
void affichage_graphique(int longueur, int largeur);
void fin_affichage_graphique(void);
void affichage_graphique_grille(int longueur, int largeur);
void saisiePoint(Coup *coup);
void conversion_graph_tableau(Coup *coup);