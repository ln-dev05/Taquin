#include "game.h"

struct cursor InitCursor(int *c_tab)
{
    struct cursor cur;
    cur.pos = 0;
    cur.tab = c_tab;
    cur.valeur = cur.tab[0];
    return cur;
}

int *InitPlateau()
{
    int *tab = malloc(9 * sizeof(int));

    for(int i = 1; i < 9; i++ )
    {
        int end = 0;
        while(!end)
        {
            int pos = (rand() + time(0)) % 9;
            if(*(tab + pos) == VIDE)
            {
                end = 1;
                *(tab + pos) = i;
            }
        }
    }

    return tab;
}

void afficherTableauConsole(struct cursor *cur)
{
    for (int i = 0; i < 9; ++i)
    {
        if (i%3 == 0)
        {
            printf("\n");
        }
        if (i == cur->pos)
        {
            printf(" (%d) ", *(cur->tab + i ));
        }
        else
        {
            printf("  %d  ", *(cur->tab + i ));
        }
    }
    printf("\n" );
}

void help()
{
    printf("\n\n\n-------------------------------\nici l'invite d'aide de commande\n-------------------------------\n");
    printf("Vous avez le choix entre les différentes possiblitées :\n");
    printf("    - haut\n    - bas\n    - gauche\n    - droite\n    - aucune\n    - help\n\n\n");
}

int LireInstruction()
{
    char entre[6];
    while(1)
    {
        printf("Entrez la direction souhaitée : ");
        int res = scanf("%s", entre);
        if(strcmp("droite", entre) == 0)
        {
            return DROITE;
        }
        else if (strcmp("bas", entre) == 0)
        {
            return BAS;
        }
        else if (strcmp("gauche", entre) == 0)
        {
            return GAUCHE;
        }
        else if (strcmp("haut", entre) == 0)
        {
            return HAUT;
        }
        else if (strcmp("aucune", entre) == 0)
        {
            return AUCUNE;
        }
        else if (strcmp("help", entre) == 0)
        {
            help();
        }
        else
        {
            fprintf(stderr,"erreur : vous n'avez pas entrer une direction.\n");
        }
    }
}

int LirePosition()
{
    int entre;
    printf("Entrez la position souhaitée : ");
    int res = scanf("%d", &entre);
    if (res == 1)
        printf("Votre valeur est %d.\n", entre);
    return entre - 1;
}

int posCurseur(struct cursor *cur)
{
    return cur->pos;
}

int valeurCurseur(struct cursor *cur)
{
    return cur->valeur;
}

void changerCuseur(struct cursor *cur, int n_pos)
{
    cur->pos = n_pos;
    cur->valeur = (cur->tab)[n_pos];
}

void mouvoirPanel(struct cursor *cur, int DIR)
{
    if (DIR == AUCUNE)
    {
        
    }
    else{
        if(cur->tab[cur->pos + DIR] != VIDE)
        {
            fprintf(stderr, "La direction souhaitée n'est pas vide\n");
        }
        else
        {
            int tmp = cur->tab[cur->pos];
            cur->tab[cur->pos] = cur->tab[cur->pos + DIR];
            cur->tab[cur->pos + DIR] = tmp;
        }
    }
}

int victoire(struct cursor *cur)
{
    int TOR = 1;
    for(int i = 1; i<9; i++)
    {
        if (cur->tab[i-1] != i)
        {
            TOR = 0;
        }
    }
    return TOR;
}
void Jouer()
{
    int *tab = InitPlateau();
    struct cursor curseur = InitCursor(tab);
    while(!victoire(&curseur))
    {   
        afficherTableauConsole(&curseur);
        changerCuseur(&curseur, LirePosition());
        afficherTableauConsole(&curseur);
        mouvoirPanel(&curseur, LireInstruction());
    }
    printf("Bien jouer à vous !\n");
}