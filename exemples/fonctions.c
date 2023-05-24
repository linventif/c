/* Ajout des librairies standards */
#include <stdio.h>

/* Déclarations des fonctions définies dans le fichier */
/* C'est une copie de la première ligne de la fonction avec en plus un ';' à la fin */
int plus_un(int n);
int addition(int a, int b);

/* Notre fonction main, comme d'habitude */
int main(void)
{
    int i = 0;
    int j = 0;

    /* Appel à la fonction plus_un définie plus bas */
    /* j prend la valeur de retour de plus_un, c'est-à-dire celle qui est renvoyée par le return */
    j = plus_un(i);

    /* On regarde les valeurs */
    printf("i = %d\n", i);
    printf("j = %d\n", j);

    /* On test aussi une fonction à deux arguments */
    printf("3 + 4 = %d\n", addition(3, 4));

    return 0;
}

/* Pour cet exemple on prend un cas extrêmement simple */
/* plus_un prend un entier en argument (ici n) et retourne un entier correspondant à n+1 */
/* le "int" de "int n" annonce que la fonction attend un entier comme argument */
/* le "int" de "int plus_un" annonce que la fonction "plus_un" retourne un entier */

int plus_un(int n)
{
    return n + 1;
}

/* Si l'on veut plusieurs arguments, on les sépare simplement par une virgule */

int addition(int a, int b)
{
    return a + b;
}
