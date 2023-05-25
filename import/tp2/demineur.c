#include <stdio.h>
#include <stdlib.h>

#define NB_LIGNES 8
#define NB_COLONNES 8
#define NB_MINES 0

int demineur(void);
int combien_de_mines_autour(char *mines, int nb_lignes, int nb_colonnes, int ligne, int colonne);
void revelation_du_terrain(char *terrain, char *mines, int nb_lignes, int nb_colonnes, int ligne, int colonne);
void place_valeur_tableau_2d(char *tableau, int nb_ligne, int nb_colonne, int pos_ligne, int pos_colonne, char car);
int est_ce_fini(char *mines, char *terrain, int nb_lignes, int nb_colonnes);
void demande_valeur(char *entree, int taille);
int numero_colonne(char *entree, int taille);
int numero_ligne(char *entree, int taille);
char valeur_demande_tableau_2d(char *tableau, int nb_ligne, int nb_colonne);
void affiche_tableau(char *tableau, int ligne, int colonne);
int demande_entier(void);
int place_random_mines(char *mines, int nb_lignes, int nb_colonnes, int nb_mines);
void affichage_autour(char *mines, char *terrain, int nb_lignes, int nb_colonnes, int ligne, int colonne);
int demande_poser_drapeau(char *entree, int taille);

int main(void) { return demineur(); }

int demineur(void)
{
    printf("Bienvenue dans le DéminBaste !\nDonner un nombre aléatoire (graine du jeu):");
    srand(demande_entier());
    char mines[NB_LIGNES * NB_COLONNES];
    char terrain[NB_LIGNES * NB_COLONNES];
    for (int i = 0; i < NB_LIGNES * NB_COLONNES; i++)
    {
        mines[i] = 'V';
        terrain[i] = '?';
    }
    printf("Combien de mines voulez-vous ? ");
    place_random_mines(mines, NB_LIGNES, NB_COLONNES, demande_entier());
    int ligne, colonne, set_drapeau;
    affiche_tableau(terrain, NB_LIGNES, NB_COLONNES);
    do
    {
        printf("Entrez une ligne et une colonne : ");
        char entree[3];
        demande_valeur(entree, 2);
        ligne = numero_ligne(entree, 3);
        colonne = numero_colonne(entree, 3);
        set_drapeau = demande_poser_drapeau(entree, 3);
        if (set_drapeau)
        {
            place_valeur_tableau_2d(terrain, NB_LIGNES, NB_COLONNES, ligne, colonne, 'P');
        }
        else
        {
            revelation_du_terrain(terrain, mines, NB_LIGNES, NB_COLONNES, ligne, colonne);
        }
        printf("\n");
        affiche_tableau(terrain, NB_LIGNES, NB_COLONNES);
    } while (!est_ce_fini(mines, terrain, NB_LIGNES, NB_COLONNES) && terrain[ligne * NB_COLONNES + colonne] != '@');
    if (terrain[ligne * NB_COLONNES + colonne] == '@')
    {
        printf("Vous avez perdu !\n");
    }
    else
    {
        printf("Vous avez gagne !\n");
    }
    return 0;
}

int combien_de_mines_autour(char *mines, int nb_lignes, int nb_colonnes, int ligne, int colonne)
{
    int nb_mines = 0;
    for (int i = ligne - 1; i <= ligne + 1; i++)
    {
        for (int j = colonne - 1; j <= colonne + 1; j++)
        {
            if (i >= 0 && i < nb_lignes && j >= 0 && j < nb_colonnes && mines[i * nb_colonnes + j] == 'M')
            {
                nb_mines++;
            }
        }
    }
    return nb_mines;
}

void place_valeur_tableau_2d(char *tableau, int nb_ligne, int nb_colonne, int pos_ligne, int pos_colonne, char car)
{
    *(tableau + pos_ligne * nb_colonne + pos_colonne) = car;
}

void revelation_du_terrain(char *terrain, char *mines, int nb_lignes, int nb_colonnes, int ligne, int colonne)
{
    if (terrain[ligne * nb_colonnes + colonne] == '?')
    {
        if (mines[ligne * nb_colonnes + colonne] == 'P')
        {
            place_valeur_tableau_2d(terrain, nb_lignes, nb_colonnes, ligne, colonne, '?');
            return;
        }
        if (mines[ligne * nb_colonnes + colonne] == 'M')
        {
            place_valeur_tableau_2d(terrain, nb_lignes, nb_colonnes, ligne, colonne, '@');
            return;
        }
        char valeur = '0' + combien_de_mines_autour(mines, nb_lignes, nb_colonnes, ligne, colonne);
        place_valeur_tableau_2d(terrain, nb_lignes, nb_colonnes, ligne, colonne, valeur);
        if (valeur == '0')
        {
            affichage_autour(mines, terrain, nb_lignes, nb_colonnes, ligne, colonne);
        }
    }
}

int est_ce_fini(char *mines, char *terrain, int nb_lignes, int nb_colonnes)
{
    for (int i = 0; i < nb_lignes * nb_colonnes; i++)
    {
        if ((mines[i] == 'M' && terrain[i] != '@') && (mines[i] == 'M' && terrain[i] != 'P'))
        {
            return 0;
        }
    }
    return 1;
}

void demande_valeur(char *entree, int taille)
{
    scanf("%s", entree);
}

int numero_colonne(char *entree, int taille)
{
    return entree[taille - 3] - 'a';
}

int numero_ligne(char *entree, int taille)
{
    return entree[taille - 2] - '0';
}

char valeur_demande_tableau_2d(char *tableau, int nb_ligne, int nb_colonne)
{
    char entree[2];
    demande_valeur(entree, 2);
    return tableau[numero_ligne(entree, 2) * nb_colonne + numero_colonne(entree, 2)];
}

void affiche_tableau(char *tableau, int ligne, int colonne)
{
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            printf("%c ", tableau[i * colonne + j]);
        }
        printf("\n");
    }
}

int demande_entier(void)
{
    int entier;
    scanf("%d", &entier);
    return entier;
}

int place_random_mines(char *mines, int nb_lignes, int nb_colonnes, int nb_mines)
{
    int nb_mines_placees = 0;
    while (nb_mines_placees < nb_mines)
    {
        int ligne = rand() % nb_lignes;
        int colonne = rand() % nb_colonnes;
        if (mines[ligne * nb_colonnes + colonne] != 'M')
        {
            mines[ligne * nb_colonnes + colonne] = 'M';
            nb_mines_placees++;
        }
    }
    return nb_mines_placees;
}

void affichage_autour(char *mines, char *terrain, int nb_lignes, int nb_colonnes, int ligne, int colonne)
{
    if (combien_de_mines_autour(mines, nb_lignes, nb_colonnes, ligne, colonne) == 0)
    {
        for (int i = ligne - 1; i <= ligne + 1; i++)
        {
            for (int j = colonne - 1; j <= colonne + 1; j++)
            {
                if (i >= 0 && i < nb_lignes && j >= 0 && j < nb_colonnes)
                {
                    revelation_du_terrain(terrain, mines, nb_lignes, nb_colonnes, i, j);
                }
            }
        }
    }
}

int demande_poser_drapeau(char *entree, int taille)
{
    return entree[taille - 1] == 'P' || entree[taille - 1] == 'p';
}