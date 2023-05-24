#include <stdio.h>

int main(void)
{
    /* Déclaration d'un int */
    int entier = 10;

    /* Déclaration d'un pointeur vers un entier */
    /* Pour cela on écrit que c'est vers un int (int) et pour dire que c'est un pointeur vers, on rajoute une "*" */
    int *pointeur;

    /* &entier est l'adresse de la variable entier. Cette adresse devient le contenu de la variable pointeur */
    pointeur = &entier;

    /* Pour afficher une adresse/un pointeur, il faut utiliser %p */

    /* On voit que pointeur a bien la valeur de l'adresse d'entier */
    printf("adresse de entier      : %p\n", &entier);
    printf("pointeur vaut          : %p\n\n", pointeur);

    /* Et on peut acceder à la valeur de deux manières différentes */
    /* Soit on va récupère la valeur d'entier, comme on sait déjà faire */
    printf("entier vaut                        : %d\n", entier);
    /* Soit on "déréférence" le pointeur */
    /* C'est à dire que l'on va chercher le contenu de la case mémoire ciblée par le pointeur */
    printf("Me déréférençement de pointeur est : %d\n", *pointeur);

    /* On peut aussi modifier le contenu de la case mémoire ciblée par le pointeur */
    *pointeur = 12;
    printf("\n&pointeur = 12;\n");

    /* Cela modifie en même temps "entier" puisque c'est lui qui est à l'adresse de pointeur */
    printf("entier vaut                        : %d\n", entier);
    printf("Me déréférençement de pointeur est : %d\n", *pointeur);
    return 0;
}
