#include <stdio.h>
#include <stdlib.h>
#define NB_LIGNE 10
#define NB_COLONNE 10
#define IN_DEBUG 0
#define NB_MINES 10

int save_debug_info(char *message)
{
    FILE *fichier = fopen("demineur.log", "a");
    fprintf(fichier, "%s\n", message);
    fclose(fichier);
    return 0;
}

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

void clear_arround_case(char *affichage, char *mines, int pos_x, int pos_y, int ligne, int colonne)
{
    // save in the file demineur.log the position of the case and the number of mines around
    int new_pos_y = pos_y;
    int new_pos_x = pos_x;

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
            new_pos_x = pos_x + i - 1;
            new_pos_y = pos_y + k - 1;

            // skip out of bounds
            if (out_of_bounds(new_pos_x, new_pos_y, ligne, colonne))
            {
                continue;
            }
            // check if mine
            char case_value = mines[new_pos_y * colonne + new_pos_x];
            if (case_value == 'M')
            {
                continue;
            }
            int mines_found = combient_de_mine_autour(mines, new_pos_x, new_pos_y, ligne, colonne);
            affichage[new_pos_y * colonne + new_pos_x] = mines_found + '0';
            if (mines_found == 0)
            {
                char message[100];
                sprintf(message, "clear_arround_case: %d %d = %c", new_pos_x, new_pos_y, mines_found + '0');
                save_debug_info(message);
                clear_arround_case(affichage, mines, 2, 2, ligne, colonne);
            }
        }
    }
}

char revelation_du_terrain(char *terrain, char *mines, int nb_lignes, int nb_colonnes, int pos_x, int pox_y)
{
    char case_value = mines[pox_y * nb_colonnes + pos_x];

    // check if already revealed
    if (terrain[pox_y * nb_colonnes + pos_x] != '?')
    {
        return -1;
    }

    // check if mine
    if (case_value == 'M')
    {
        terrain[pox_y * nb_colonnes + pos_x] = '@';
        return '@';
    }
    else
    {
        int mines_found = combient_de_mine_autour(mines, pos_x, pox_y, nb_lignes, nb_colonnes);
        terrain[pox_y * nb_colonnes + pos_x] = mines_found + '0';
        if (mines_found == 0)
        {
            clear_arround_case(terrain, mines, pos_x, pox_y, nb_lignes, nb_colonnes);
        }
        return mines_found + '0';
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

void init_mines(char *mines, int nb_lignes, int nb_colonnes, int nb_mines, int seed)
{
    // clear mines
    clear_tableau_2d(mines, nb_lignes, nb_colonnes, 'V');

    // set seed for random number generator
    srand(seed);

    // set mines
    for (int i = 0; i < nb_mines; i++)
    {
        int pos_x = rand() % nb_colonnes;
        int pos_y = rand() % nb_lignes;
        set_valeur(mines, pos_x, pos_y, 'M');
    }
}

int main(void)
{
    char *mines = malloc(NB_LIGNE * NB_COLONNE * sizeof(char));
    clear_tableau_2d(mines, NB_LIGNE, NB_COLONNE, 'V');

    char *affichage = malloc(NB_LIGNE * NB_COLONNE * sizeof(char));
    clear_tableau_2d(affichage, NB_LIGNE, NB_COLONNE, '?');

    // set_valeur(mines, 1, 3, 'M');
    // set_valeur(mines, 2, 0, 'M');
    // set_valeur(mines, 3, 2, 'M');

    printf("Enter a seed: ");
    int seed;
    scanf("%d", &seed);

    system("clear");

    init_mines(mines, NB_LIGNE, NB_COLONNE, NB_MINES, seed);

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

    int num1, num2;
    int fini = 0;
    int win = 0;
    int nb_t = 0;
    char reveal_case;

    while (!fini)
    {
        while (1)
        {
            printf("Enter two numbers separated by a space: ");
            int result = scanf("%d %d", &num1, &num2);

            if (result == 2)
            {
                reveal_case = revelation_du_terrain(affichage, mines, NB_LIGNE, NB_COLONNE, num1, num2);
                if (reveal_case == '@')
                {
                    printf("Vous avez perdu!\n");
                    fini = 1;
                    win = 0;
                }
                break;
            }
            else
            {
                printf("Invalid input. Please try again.\n");

                // Vider le tampon d'entrée pour éviter le dépassement de mémoire
                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                {
                }
            }
        }
        nb_t++;
        system("clear");
        affiche_tableau_2d(affichage, NB_LIGNE, NB_COLONNE);
        if (est_ce_fini(mines, affichage, NB_LIGNE, NB_COLONNE) == 1)
        {
            fini = 1;
            printf("Vous avez gagné en %d coups!\n", nb_t);
        }
        if (nb_t > 10)
        {
            fini = 1;
            printf("Vous avez perdu!\n");
        }
    }
    system("clear");
    if (win == 1)
    {
        printf("Vous avez gagné en %d coups!\n", nb_t);
    }
    else
    {
        printf("Vous avez perdu!\n");
    }
    affiche_tableau_2d(mines, NB_LIGNE, NB_COLONNE);
    return 0;
}