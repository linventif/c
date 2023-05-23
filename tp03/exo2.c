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

int main(void)
{
    char *super_tab = malloc(4 * sizeof(char));
    randomtbl(super_tab, 4);
    affiche_tbl(super_tab, 4);
    printf("getrandom() = %c\n", getrandom());
}