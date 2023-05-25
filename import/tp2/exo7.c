#include <stdio.h>

void demande_valeur(char *entree, int taille);
int numero_colonne(char *entree, int taille);
int numero_ligne(char *entree, int taille);
char valeur_demande_tableau_2d(char *tableau, int nb_ligne, int nb_colonne);

int main(void)
{
    char tab[] = "abcdefghijklmnop";
    printf("%c\n", valeur_demande_tableau_2d(tab, 4, 4));
    return 0;
}

void demande_valeur(char *entree, int taille)
{
    printf("Entrez une valeur: ");
    scanf("%s", entree);
}

int numero_colonne(char *entree, int taille)
{
    return entree[taille - 2] - 'a';
}

int numero_ligne(char *entree, int taille)
{
    return entree[taille - 1] - '0';
}

char valeur_demande_tableau_2d(char *tableau, int nb_ligne, int nb_colonne)
{
    char entree[2];
    demande_valeur(entree, 2);
    return tableau[numero_ligne(entree, 2) * nb_colonne + numero_colonne(entree, 2)];
}