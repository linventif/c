#include <stdio.h>

char valeur_tableau_2d(char *tableau, int nb_ligne, int nb_colonne, int pos_ligne, int pos_colonne);
void affiche_tableau_2d(char *tableau, int nb_ligne, int nb_colonne);
void place_valeur_tableau_2d(char *tableau, int nb_ligne, int nb_colonne, int pos_ligne, int pos_colonne, char car);

int main(void)
{
    char tab[] = "abcdefghijklmnop";
    affiche_tableau_2d(tab, 4, 4);
    place_valeur_tableau_2d(tab, 4, 4, 0, 0, 'z');
    affiche_tableau_2d(tab, 4, 4);
    return 0;
}

char valeur_tableau_2d(char *tableau, int nb_ligne, int nb_colonne, int pos_ligne, int pos_colonne)
{
    return *(tableau + pos_ligne * nb_colonne + pos_colonne);
}

void affiche_tableau_2d(char *tableau, int nb_ligne, int nb_colonne)
{
    for (int i = 0; i < nb_ligne; i++)
    {
        for (int j = 0; j < nb_colonne; j++)
        {
            printf("%c ", valeur_tableau_2d(tableau, nb_ligne, nb_colonne, i, j));
        }
        printf("\n");
    }
}
void place_valeur_tableau_2d(char *tableau, int nb_ligne, int nb_colonne, int pos_ligne, int pos_colonne, char car)
{
    *(tableau + pos_ligne * nb_colonne + pos_colonne) = car;
}