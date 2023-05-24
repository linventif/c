#include <stdio.h>
#include <stdlib.h>
#define NB_LIGNE 10
#define NB_COLONNE 10
#define IN_DEBUG 0

char valeur_tableau_2d(char *tableau, int nb_ligne, int nb_colonne, int pos_ligne, int pos_colonne)
{
    return tableau[pos_ligne * nb_colonne + pos_colonne];
}

void affiche_tableau_2d(char *tableau, int nb_ligne, int nb_colonne)
{
    // print column headers
    printf("  ");
    for (int i = 0; i < nb_colonne; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < nb_ligne; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < nb_colonne; j++)
        {
            printf("%c ", tableau[i * nb_colonne + j]);
        }
        printf("\n");
    }
}

void clear_tableau_2d(char *tableau, int nb_ligne, int nb_colonne, char valeur)
{
    for (int i = 0; i < nb_ligne; i++)
    {
        for (int j = 0; j < nb_colonne; j++)
        {
            tableau[i * nb_colonne + j] = valeur;
        }
    }
}

int out_of_bounds(int pos_x, int pos_y, int nb_ligne, int nb_colonne)
{
    // check if pos_? is out of bounds
    if (pos_x >= nb_colonne || pos_y >= nb_ligne)
    {
        if (IN_DEBUG)
        {
            printf("Erreur: %c%c est hors des limites du tableau\n", pos_x, pos_y);
        }
        return 1;
    }
    // return 0 if successful
    return 0;
}

int set_valeur(char *tableau, int pos_x, int pos_y, char valeur)
{
    if (out_of_bounds(pos_x, pos_y, NB_LIGNE, NB_COLONNE) == 1)
    {
        return -1;
    }
    // set value
    tableau[pos_y * NB_COLONNE + pos_x] = valeur;
    // return 0 if successful
    return 0;
}

int combient_de_mine_autour(char *mines, int pos_x, int pos_y, int ligne, int colonne)
{
    // get neighbors
    // 1 2 3
    // 4 X 5
    // 6 7 8

    int mines_found = 0;

    // parcourir les 8 cases autour de la case
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            // skip the center
            if (i == 1 && k == 1)
            {
                continue;
            }
            // skip out of bounds
            if (out_of_bounds(pos_x + i - 1, pos_y + k - 1, ligne, colonne))
            {
                continue;
            }
            // check if mine
            char case_value = mines[(pos_y + k - 1) * colonne + (pos_x + i - 1)];
            if (case_value == 'M')
            {
                mines_found++;
            }
        }
    }

    return mines_found;
}

void revelation_du_terrain(char *terrain, char *mines, int nb_lignes, int nb_colonnes, int pos_x, int pox_y)
{
    char case_value = mines[pox_y * nb_colonnes + pos_x];

    // check if already revealed
    if (terrain[pox_y * nb_colonnes + pos_x] != '?')
    {
        return;
    }

    // check if mine
    if (case_value == 'M')
    {
        terrain[pox_y * nb_colonnes + pos_x] = '@';
    }

    // else reveal number of mines around
    else
    {
        int mines_found = combient_de_mine_autour(mines, pos_x, pox_y, nb_lignes, nb_colonnes);
        terrain[pox_y * nb_colonnes + pos_x] = mines_found + '0';
    }
}

int est_ce_fini(char *mines, char *terrain, int nb_lignes, int nb_colonnes)
{
    for (int i = 0; i < nb_lignes; i++)
    {
        for (int j = 0; j < nb_colonnes; j++)
        {
            if (terrain[i * nb_colonnes + j] == '?' && mines[i * nb_colonnes + j] != 'M')
            {
                return 0;
            }
        }
    }
    return 1;
}

int main(void)
{
    char *mines = malloc(NB_LIGNE * NB_COLONNE * sizeof(char));
    clear_tableau_2d(mines, NB_LIGNE, NB_COLONNE, 'V');

    char *affichage = malloc(NB_LIGNE * NB_COLONNE * sizeof(char));
    clear_tableau_2d(affichage, NB_LIGNE, NB_COLONNE, '?');

    set_valeur(mines, 1, 3, 'M');
    set_valeur(mines, 2, 0, 'M');
    set_valeur(mines, 3, 2, 'M');

    // printf("Tableau des mines:\n");
    // affiche_tableau_2d(mines, NB_LIGNE, NB_COLONNE);

    // printf("Tableau de l'affichage:\n");
    affiche_tableau_2d(affichage, NB_LIGNE, NB_COLONNE);

    // printf("Nombre de mines autour de 1, 1: %d\n", combient_de_mine_autour(mines, 1, 1, NB_LIGNE, NB_COLONNE));
    // printf("Nombre de mines autour de 2, 2: %d\n", combient_de_mine_autour(mines, 2, 2, NB_LIGNE, NB_COLONNE));
    // printf("Nombre de mines autour de 3, 3: %d\n", combient_de_mine_autour(mines, 3, 3, NB_LIGNE, NB_COLONNE));

    // system("clear");
    // revelation_du_terrain(affichage, mines, NB_LIGNE, NB_COLONNE, 1, 1);
    // revelation_du_terrain(affichage, mines, NB_LIGNE, NB_COLONNE, 2, 2);
    // affiche_tableau_2d(affichage, NB_LIGNE, NB_COLONNE);

    // while (est_ce_fini(mines, affichage, NB_LIGNE, NB_COLONNE) == 0)
    // {
    //     // get input
    //     int pos_x, pos_y;
    //     printf("Entrez une position (x, y): ");
    //     scanf("%d %d", &pos_x, &pos_y);
    //     revelation_du_terrain(affichage, mines, NB_LIGNE, NB_COLONNE, pos_x, pos_y);
    //     system("clear");
    //     affiche_tableau_2d(affichage, NB_LIGNE, NB_COLONNE);
    // }
}