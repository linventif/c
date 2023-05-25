#include <stdio.h>
#include <stdlib.h>

char getrandom()
{
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

void randomtbl(char *tableau, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        tableau[i] = getrandom();
    }
}

void affiche_tbl(char *tableau, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        printf("%c ", tableau[i]);
    }
    printf("\n");
}

// create a new type (super_tab) with a method size() and a atribut size and a pointer to the array
typedef struct // type definition of super_tab
{
    int size;  // size of the array
    char *tab; // pointer to the array
} super_tab;   // name of the type

super_tab *nouveau_tableau(int taille)
{
    super_tab *tab = malloc(sizeof(super_tab));
    tab->size = taille;
    tab->tab = malloc(taille * sizeof(char));
    return tab; // return the pointer to the array
}

void initialise_tableau(super_tab *tableau, char car)
{
    for (int i = 0; i < tableau->size; i++)
    {
        tableau->tab[i] = car;
    }
}

void affiche_tableau(super_tab *tableau)
{
    for (int i = 0; i < tableau->size; i++)
    {
        printf("tab[%d] = %c\n", i, tableau->tab[i]);
    }
    printf("\n");
}

void liberation_du_tableau(super_tab *tableau)
{
    free(tableau->tab);
    free(tableau);
}

void place_dans_tableau(super_tab *tableau, int indice, char car)
{
    if (indice < tableau->size)
    {
        tableau->tab[indice] = car;
    }
    else
    {
        printf("Error: indice is out of bounds\n");
        exit(1);
    }
}

char lecture_du_tableau(super_tab *tableau, int indice)
{
    if (indice < tableau->size)
    {
        return tableau->tab[indice];
    }
    else
    {
        printf("Error: indice is out of bounds\n");
        exit(1);
    }
}

void affiche_size(super_tab *tableau)
{
    printf("size = %d\n", tableau->size);
}

int main(void)
{
    // char *super_tab = malloc(4 * sizeof(char));
    // randomtbl(super_tab, 4);
    // affiche_tbl(super_tab, 4);
    // printf("getrandom() = %c\n", getrandom());

    super_tab *tab = nouveau_tableau(4);
    affiche_size(tab);
    initialise_tableau(tab, 'a');
    affiche_tableau(tab);
    place_dans_tableau(tab, 2, 'b');
    affiche_tableau(tab);
    printf("lecture_du_tableau(tab, 2) = %c\n", lecture_du_tableau(tab, 2));
    liberation_du_tableau(tab);
    return 0;
}