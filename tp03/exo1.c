#include <stdio.h>
#include <stdlib.h>

char *nouveau_tableau(int taille)
{
    char *tab = malloc(taille * sizeof(char));
    for (int i = 0; i < taille; i++)
    {
        tab[i] = 0;
    }
    return tab; // return the pointer to the array
}

void initialise_tableau(char *tableau, int taille, char car)
{
    for (int i = 0; i < taille; i++)
    {
        tableau[i] = car;
    }
}

void affiche_tableau(char *tableau, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        printf("tab[%d] = %c\n", i, tableau[i]);
    }
    printf("\n");
}

void liberation_du_tableau(char *tableau)
{
    free(tableau);
}

void place_dans_tableau(char *tableau, int taille, int indice, char car)
{
    if (indice < taille)
    {
        tableau[indice] = car;
    }
    else
    {
        printf("Error: indice is out of bounds\n");
        exit(1);
    }
}

char lecture_du_tableau(char *tableau, int taille, int indice)
{
    if (indice < taille)
    {
        return tableau[indice];
    }
    else
    {
        printf("Error: indice is out of bounds\n");
        exit(1);
    }
}

int main(void)
{
    // exemple with malloc
    // int *p = malloc(sizeof(int)); // p is a pointer to an int allocated on the heap
    // *p = 42;                      // p points to 42
    // printf("%d\n", *p);           // prints 42
    // free(p);                      // free the memory

    // new tab
    char *tab = nouveau_tableau(10);
    initialise_tableau(tab, 10, 'a');

    place_dans_tableau(tab, 10, 2, 'b'); // place 'b' at index 2

    printf("%c\n", lecture_du_tableau(tab, 10, 2)); // prints 'b'

    affiche_tableau(tab, 10);

    // affiche_tableau(tab, 10);

    // place_dans_tableau(tab, 10, 50, 'c'); // should print an error message and exit the program

    liberation_du_tableau(tab);

    // affiche_tableau(tab, 10); // should print garbage values because the memory has been freed and can be used by other programs

    return 0;
}