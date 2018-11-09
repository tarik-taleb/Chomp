#include "chomp.h"


/*--------------------------------------------------------------------------------------------------------------------*/

Tablette creer_tablette(void){
    Tablette t;
    int i = 0;
    int j = 0;

    for (i = 0; i < N; ++i)
    {
		for (j = 0; j < M; ++j)
        {
            t.grille[i][j] = CHOCOLAT; 
        }
    }

    t.n = N;
    t.m = M;

    return t;
}

/*--------------------------------------------------------------------------------------------------------------------*/
void affiche(Tablette t){
    int i,j;
    printf("%d\n",t.n );
    printf("%d\n",t.m );
    for (i = 0; i < t.n; ++i)
    {
        for (j = 0; j < t.m; ++j)
        {
            printf("%d",t.grille[i][j] );
        }
        printf("\n");
    }
}
/*--------------------------------------------------------------------------------------------------------------------*/

void manger(Tablette *t, int x, int y){
    assert(NULL != t);
    int i = 0;
    int j = 0;

    for (i = x; i < (*t).n; ++i)
    {
        for (j = y; j < (*t).m; ++j)
        {
            t -> grille[i][j] = MANGE;
        }
    }
}

/*--------------------------------------------------------------------------------------------------------------------*/
int est_legal(Position *pos,Coup *coup){
    assert(NULL != pos);
    assert(NULL != coup);
    if (pos -> chocolat.grille[coup -> x][coup -> y] == MANGE)
    {
        return 1;
    }
    return 0;
}
/*--------------------------------------------------------------------------------------------------------------------*/
int est_jeu_terminer(Position *pos,Joueur *joueur_gagnant){
    assert(NULL != pos);
    assert(joueur_gagnant != NULL);
    if (pos -> chocolat.grille[0][0] == MANGE)
    {   
        *joueur_gagnant = pos -> j;
        return 1;
    }
    return 0;
}
/*--------------------------------------------------------------------------------------------------------------------*/
void jouer_coup(Position *pos, Coup coup){
    assert(NULL != pos);
    if (pos -> j == JOUEUR1 )
    {
        pos -> j = JOUEUR2;
    }
    else if (pos -> j == JOUEUR2 )
    {
        pos -> j = JOUEUR1;
    } 
}
/*--------------------------------------------------------------------------------------------------------------------*/
void afficher_position(Position *pos){
    assert(NULL != pos);
    int i;
    int j ;
    int x1 = 0;
    int y1 = 0;
    MLV_clear_window(MLV_COLOR_BLACK);
    for (i = 0; i < pos -> chocolat.n; ++i)
    {
        for (j = 0; j < pos -> chocolat.m ; ++j)
        {
            if (pos -> chocolat.grille[i][j] == CHOCOLAT){
                 MLV_draw_filled_rectangle(x1,y1,TAILLE_CASE,TAILLE_CASE,MLV_COLOR_WHITE);
                x1 = x1 + TAILLE_CASE + 1 ;
            }
            if (pos -> chocolat.grille[i][j] == MANGE){
                MLV_draw_filled_rectangle(x1,y1,TAILLE_CASE,TAILLE_CASE,MLV_COLOR_BLACK);
                x1 = x1 + TAILLE_CASE + 1 ;
            }
            
        }
        x1 = 0;
        y1 = y1 + TAILLE_CASE + 1 ;
    }
    MLV_actualise_window();
}
/*--------------------------------------------------------------------------------------------------------------------*/
/**
 * fonction qui renvoi les coordonnées de la case selectionner par le joueur
 * @param  pos contient la tablette de la chocolat
 * @return     des coordonnées
 */ 
Coup lire_coup(Position *pos){
    assert(NULL != pos);
    Coup coup;
    int tmp;

    do{

        saisiePoint(&coup);
        conversion_graph_tableau(&coup);
        tmp = coup.x;
        coup.x = coup.y;
        coup.y = tmp;

    }while(est_legal(pos,&coup) != 0);

    return coup;

}
/*--------------------------------------------------------------------------------------------------------------------*/
/**
 * Fonction qui permet d'initialiser le plateau en graphique
 * @param pos contient la tablette de la chocolat
 */ 
void initialisation_plateau(Position pos)
{
    int i;
    int j ;
    int x1 = 0;
    int y1 = 0;

    for (i = 0; i < pos.chocolat.n; ++i)
    {
        for (j = 0; j < pos.chocolat.m ; ++j)
        {
            MLV_draw_filled_rectangle(x1,y1,TAILLE_CASE,TAILLE_CASE,MLV_COLOR_WHITE);
            x1=x1+TAILLE_CASE+1;
        }
        x1 = 0;
        y1 = y1 + TAILLE_CASE+1;
    }
    MLV_actualise_window();
}

/*--------------------------------------------------------------------------------------------------------------------*/

/**
 * fonction qui permet de la transition entre la partie graphique et le tableau 
 * @param coup pointeur de type coups
 */
void conversion_graph_tableau(Coup *coup){
    assert(NULL != coup);
    coup->x = coup->x / 50;
    coup->y = coup->y / 50;
}

/*--------------------------------------------------------------------------------------------------------------------*/

/*FONCTION DE SAISIE DES POINT DE CLICK DE LA SOURIS*/

void saisiePoint(Coup *coup){
    assert(NULL != coup);
    MLV_wait_mouse(&coup->x,&coup->y);
    MLV_actualise_window();
}
/*--------------------------------------------------------------------------------------------------------------------*/
void affichage_graphique(int longueur, int largeur){
    MLV_create_window( "Mot", "mot",longueur, largeur);
    MLV_clear_window(MLV_COLOR_BLACK);
    MLV_actualise_window();

}

void fin_affichage_graphique(void){
    MLV_wait_seconds(1);
    MLV_free_window();
}

/*--------------------------------------------------------------------------------------------------------------------*/

void affiche_joueur_gagnant(Position pos,int longueur, int largeur){
    MLV_clear_window(MLV_COLOR_BLACK);
    if (pos.j == JOUEUR1)
        MLV_draw_text(longueur,largeur,"Joueur 1 gagne",MLV_COLOR_WHITE);
    else
        MLV_draw_text(longueur,largeur,"Joueur 2 gagne",MLV_COLOR_WHITE);

    MLV_actualise_window();
}