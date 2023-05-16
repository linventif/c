#include <stdio.h>

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

int main(void)
{
    char tableau[5] = {'a', 'b', 'c', 'd', 'e'};
    affiche_tableau(tableau, 5);
    change_lettre(&tableau[0], 'z');
    change_lettre(&tableau[2], 'z');
    affiche_tableau_pointeur(tableau, 5);
    return 0;
}