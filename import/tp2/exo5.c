#include <stdio.h>

void affiche_caractere(char car);

void alphabet(char *tableau, int taille);

void alphabet_renverse(char *tableau, int taille);

int main(void)
{
    /*
     * char tab[6] = {'a', 'z', 'e', 'r', 't', 'y'};
     * --> revient aussi à
     * char tab[6] = "azerty";
     */
    affiche_caractere('a');
    printf("\n");
    alphabet("abcdefghijklmnopqrstuvwxyz", 26);
    alphabet_renverse("abcdefghijklmnopqrstuvwxyz", 26);
    alphabet("azertyuiopq\0sdfghjklmwxcvbn", 27);
    return 0;
}

void affiche_caractere(char car)
{
    printf("%c", car);
}

void alphabet(char *tableau, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        affiche_caractere(*(tableau + i));
    }
    printf("\n");
}

void alphabet_renverse(char *tableau, int taille)
{
    for (int i = taille - 1; i >= 0; i--)
    {
        affiche_caractere(*(tableau + i));
    }
    printf("\n");
}