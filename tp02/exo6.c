#include <stdio.h>

char valeur_tableau_2d(char *tableau, int nb_ligne, int nb_colonne, int pos_ligne, int pos_colonne)
{
    return tableau[pos_ligne * nb_colonne + pos_colonne];
}

void affiche_tableau_2d(char *tableau, int nb_ligne, int nb_colonne)
{
    for (int i = 0; i < nb_ligne; i++)
    {
        for (int j = 0; j < nb_colonne; j++)
        {
            printf("%c ", tableau[i * nb_colonne + j]);
        }
        printf("\n");
    }
}

void place_valeur_tableau_2d(char *tableau, int nb_ligne, int nb_colonne, int pos_ligne, int pos_colonne, char car)
{
    tableau[pos_ligne * nb_colonne + pos_colonne] = car;
}

void alphabet(char *tableau, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        tableau[i] = 'a' + i;
    }
}

int main(void)
{
    char tableau[4][4];
    for (int i = 0; i < 4; i++)
    {
        alphabet(tableau[i], 4);
    }

    affiche_tableau_2d(*tableau, 4, 4);

    printf("\n");

    printf("tableau[2][3] = %c\n", valeur_tableau_2d(*tableau, 4, 4, 2, 3));

    printf("\n");

    place_valeur_tableau_2d(*tableau, 4, 4, 2, 3, 'z');

    affiche_tableau_2d(*tableau, 4, 4);
}