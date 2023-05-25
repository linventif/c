#include <stdio.h>

void affiche_tableau(char *tableau, int taille);

void affiche_tableau_pointeur(char *tableau, int taille);

void change_lettre(char *pt_lettre, char nouvelle_lettre);

int main(void)
{
    char tab[6] = {'a', 'z', 'e', 'r', 't', 'y'};
    char *pt_tab = &tab[0];

    affiche_tableau(tab, 6);
    affiche_tableau_pointeur(pt_tab, 6);
    change_lettre(pt_tab, 'b');
    affiche_tableau(tab, 6);

    printf("\n");
    return 0;
}

void affiche_tableau(char *tableau, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        printf("%c ", tableau[i]);
    }
    printf("\n");
}

void affiche_tableau_pointeur(char *tableau, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        printf("%c ", *(tableau + i));
    }
    printf("\n");
}

void change_lettre(char *pt_lettre, char nouvelle_lettre)
{
    *pt_lettre = nouvelle_lettre;
}