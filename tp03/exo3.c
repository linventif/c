#include <stdio.h>
#include <stdlib.h>

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

typedef super_tab chaine_t; // type definition of chaine_t

int main(void)
{
    chaine_t *chaine = nouveau_tableau(10);
    initialise_tableau(chaine, 'a');
    affiche_tableau(chaine);
    liberation_du_tableau(chaine);
    return 0;
}