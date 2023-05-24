/* Ajout des librairies standards */
#include <stdio.h>

int main(void)
{
    /* déclaration des variables */
    int i = 0;

    /* Avec l'instruction suivante, nous réservons 6 emplacements pour des éléments de type int */
    /* le premier élément a l'indice 0, le dernier l'indice 5 (ce qui représente bien 6 emplacements) */
    int tableau[6];

    /* Initialisation des variables */

    /* Pour un tableau, l'initialisation est souvant faite après sa déclaration */
    /* Ici on initialise tous les éléments du tableau à 0 */
    /* pour cela on utilise une boucle for pour parcourir le tableau */

    for (i = 0; i < 6; i = i + 1)
    {
        tableau[i] = 0;
    }

    /* Pour comprendre ce qu'il se passe, nous allons afficher le contenu du tableau */
    /* Pour cela nous utilisons la boucle for à nouveau */
    /* L'instruction i++ est équivalente à l'instruction "i=i+1" et plus courte à écrire */

    for (i = 0; i < 6; i++)
    {
        printf("La case n°%d du tableau contient la valeur %d\n", i, tableau[i]);
    }

    printf("\nAffectation de valeurs à certaines cases du tableau\n\n");

    /* Nous pouvons donner des valeurs au cases du tableau avec une grande liberté */

    /* L'approche la plus simple */
    tableau[1] = 5;

    /* Mais l'indice du tableau peut être une expression arithmétique */
    /* ici il y a trois tours de boucle i=0, i=1 et i=2 */
    /* et on effectue les affectation tableau[0] = 0, tableau[2] = 1 et tableau[4] = 2 */
    for (i = 0; i < 3; i++)
    {
        tableau[2 * i] = i;
    }

    /* Ou des choses plus tordue (on rappel que tableau[1] vaut 5, donc tableau[tableau[1]] désigne la case n°5 du tableau */
    tableau[tableau[1]] = 9;

    /* On affiche le résultat comme précédemment */
    for (i = 0; i < 6; i++)
    {
        printf("La case n°%d du tableau contient la valeur %d\n", i, tableau[i]);
    }

    /* On oubli pas la valeur de retour */
    return 0;
}
