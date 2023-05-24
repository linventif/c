#include <stdio.h>

/* Ici on regarde la différence entre passé un entier en argument et passer un pointeur vers un entier */

/* par_valeur passe un entier */
int par_valeur(int a);
/* par_pointeur passe le pointeur vers un entier */
int par_pointeur(int *pt_b);

int main(void)
{
    /* On défini deux entiers */
    int a = 0;
    int b = 0;
    /* et on défini pt_b qui est un pointeur vers b */
    int *pt_b = &b;

    /* On teste deux manières d'incrémenter a et b en utilisant une fonction */
    par_valeur(a);
    par_pointeur(pt_b);

    /* Quand l'entier est passé par valeur, il n'est pas incrémenté dans le programme principal */
    printf("Dans le main,         a vaut : %d\n", a); // Valeur affichée : 0
    /* Alors que lorsqu'il est passé par pointeur, il est bien incrémenté */
    printf("Dans le main,         b vaut : %d\n", b); // Valeur affichée : 1
    return 0;
}

int par_valeur(int a)
{
    a = a + 1;
    /* Pourtant a est bien incrémenté dans la fonction par_valeur */
    /* La raison c'est que c'est une copie de a qui est incrémenté */
    printf("Dans la fonction,     a vaut : %d\n", a); // Valeur affichée : 1
    return 0;
}

int par_pointeur(int *pt_b)
{
    /* Pour se servir du contenu de la case ciblé par le pointeur, on oubli pas de le déréférencer */
    *(pt_b) = *(pt_b) + 1;
    printf("Dans la fonction, *pt_b vaut : %d\n", *pt_b); // Valeur affichée : 1
    return 0;
}
