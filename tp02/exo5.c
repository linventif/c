#include <stdio.h>

void affiche_caractere(char car)
{
    // char version
    printf("char -> char: %c\n", car);
    // int version
    printf("char -> int: %d\n", car);
    /*
    Note: the int version is the ASCII code of the character.
    %c -> char
    %d -> int
    %f -> float
    %lf -> double
    %s -> string
    %p -> pointer
    %x -> hexadecimal
    %o -> octal
    %u -> unsigned
    */
}

void alphabet(char *tableau, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        tableau[i] = 'a' + i;
    }
}

void alphabet_renverse(char *tableau, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        tableau[i] = 'z' - i;
    }
}

void afficher_tableau(char *tableau, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        printf("tableau[%d] = %c\n", i, tableau[i]);
    }
}

void clear_tableau(char *tableau, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        tableau[i] = '\0'; // '\0' is the null character
    }
}

int main(void)
{
    char car = 'a';
    const int taille = 10;

    affiche_caractere(car);
    printf("car + 1 = `%c` + 1 = %c\n", car, car + 1);

    printf("\n");

    // create table
    char tableau[taille];
    clear_tableau(tableau, taille);

    alphabet(tableau, 5);

    tableau[5] = 'z';
    tableau[2] = '\0'; // null character
    tableau[3] = 'a';

    afficher_tableau(tableau, taille);

    printf("\n");

    alphabet_renverse(tableau, 5);

    afficher_tableau(tableau, taille);

    printf("\n");

    printf("tableau = %c\n", *tableau);

    return 0;
}