#include <stdio.h>
#include <stdlib.h>

void demande_valeur(char *entree, int taille)
{
    printf("Entrez une valeur: ");
    scanf("%s", entree);
}

int numero_colonne(char *entree, int taille)
{
    return entree[0] - 'a';
}

int numero_ligne(char *entree, int taille)
{
    return entree[1] - '1';
}

char getrandom()
{
    // generate random alpha num (a-z, A-Z, 0-9)
    int r = rand() % 62;
    if (r < 26)
    {
        return 'a' + r;
    }
    else if (r < 52)
    {
        return 'A' + r - 26;
    }
    else
    {
        return '0' + r - 52;
    }
}

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

void randomtbl(char *tableau, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        tableau[i] = getrandom();
    }
}

int main(void)
{
    char tableau[4][4];
    for (int i = 0; i < 4; i++)
    {
        randomtbl(tableau[i], 4);
    }

    char entree[2];

    demande_valeur(entree, 2);
    printf("Vous avez entré: %s\n", entree);

    printf("\n");

    const char num_ligne = numero_ligne(entree, 2);
    const char num_colonne = numero_colonne(entree, 2);

    printf("La colonne est: %d\n", num_colonne);
    printf("La ligne est: %d\n", num_ligne);

    printf("\n");

    printf("tableau[%d][%d] = %c\n", num_colonne, num_ligne, valeur_tableau_2d(*tableau, 4, 4, num_ligne, num_colonne));
    printf("\n");

    affiche_tableau_2d(*tableau, 4, 4);
}