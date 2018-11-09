#include "chomp.c"

int main(int argc, char const *argv[])
{
    Position pos;
    Coup cp_joue;
    Joueur jr = JOUEUR1 ;
    pos.chocolat = creer_tablette();
    pos.j = jr;
    int largeur = pos.chocolat.m * (TAILLE_CASE + 1);
    int hauteur = pos.chocolat.n * (TAILLE_CASE + 1);

    affiche(pos.chocolat);
    affichage_graphique(largeur,hauteur);
    afficher_position(&pos);
	initialisation_plateau(pos);
    while(est_jeu_terminer(&pos,&jr) == 0){
        cp_joue = lire_coup(&pos);
        manger(&(pos.chocolat), cp_joue.x, cp_joue.y); 
        afficher_position(&pos); 
        jouer_coup(&pos, cp_joue);
    }
    affiche_joueur_gagnant(pos,largeur/3, hauteur/3);
    fin_affichage_graphique();

    return 0;
}