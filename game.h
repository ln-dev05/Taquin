#ifndef LN_GAME
#define LN_GAME 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>


#define VIDE 0
#define DROITE 1
#define GAUCHE (-1)
#define HAUT (-3)
#define BAS 3
#define AUCUNE 0


struct cursor
{
    int pos;
    int valeur;
    int *tab;
};

struct cursor InitCursor(int *c_tab);
int *InitPlateau();
void help();
int LireInstruction();
int LirePosition();
void afficherTableauConsole(struct cursor *cur);
void Jouer();
int posCurseur(struct cursor *cur);
int valeurCurseur(struct cursor *cur);
void changerCuseur(struct cursor *cur, int n_pos);
void mouvoirPanel(struct cursor *cur, int DIR);
int victoire(struct cursor *cur);

#endif