#include <stdio.h>

/* stdlib utilisée pour malloc et free */
#include <stdlib.h>

/* Une structure est un regroupement de différents types */
/* struct : mot clef pour définir une structure. */
/* "int x;" et "int y;" : éléments qui composent la structure. */
/* typedef : mot clef pour dire que l'on va donner un nom à cette structure. */
/* point_t : nom donné à la structure. */
typedef struct
{
    int x;
    int y;
} point_t;

/* le "_t" est souvent utilisé pour dire que le mot clef désigne un type */

int main(void)
{
    /* On peut définir au choix un élément point de type point_t */
    /* Ou définir pt, un pointeur vers un élément de type point_t */
    point_t point;
    point_t *pt;

    /* Pour utiliser un élément de type point_t */
    /* On peut accéder à la composante "x" en demandant point.x */
    point.x = 4;
    point.y = 5;
    printf("val en x : %d\nval en y : %d\n", point.x, point.y);

    /* En général on utilisera l'approche par pointeur */
    /* Dans ce cas on commence par réserver un espace mémoire de taille adaptée */
    pt = malloc(sizeof(point_t));

    /* Pour accéder à la composante "x" on pourrait utiliser (*pt).x */
    /* L'approche des structures par pointeur étant tellement utilisée */
    /* Il existe un opérateur pour faire la même chose : pt->x */
    /* On utilisera communément cet opérateur */
    /* ATTENTION : Cet opérateur s'applique sur le pointeur ciblant la structure */
    /* Si vous essayez sur autre chose, cela ne fonctionnera pas */
    pt->x = 6;
    pt->y = 7;
    printf("val en x : %d\nval en y : %d\n", pt->x, pt->y);

    /* On oubli pas de libérer la mémoire réservée par malloc */
    free(pt);

    return 0;
}
