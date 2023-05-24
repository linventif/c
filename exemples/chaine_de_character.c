/* Ajout des librairies standards */
#include <stdio.h>

int main(void)
{
    /* Déclaration des variables */

    int i = 0;

    /* Ici on déclare une chaine de caractère "char chaine[]" que l'on initialise */
    /* et un tableau de caractère "char tableau[6]" que l'on initialisera à l'étape d'après */
    char chaine[] = "Ce cours est génial !";
    char tableau[6];

    /* Initialisation de tableau */
    tableau[0] = 'R';
    tableau[1] = '2';
    tableau[2] = '.';
    tableau[3] = '0';
    tableau[4] = '4';
    /* Notez qu'une chaine de caractères finie par le caractère '\0' (qui veut dire fin de chaine) */
    tableau[5] = '\0';

    /* Dans les deux cas on peut les afficher avec %s */

    printf("Ma chaine contient : %s\n", chaine);
    printf("Mon tableau contient : %s\n", tableau);

    /* On saute une ligne, c'est plus joli */
    printf("\n");

    /* Notez que chaine est aussi un tableau dont la taille est définie à l'initialisation par la taille de "Ce cours est génial !" */
    /* Il est donc tout à fait possible de le parcourir comme un tableau (cf. code sur les tableaux) */

    for (i = 0; i < 22; i++)
    {
        printf("La case n°%d de la chaine contient le caractère %c\n", i, chaine[i]);
    }
    /* À l'exécution le 'é' ne passe pas, car %c ne convertit qu'un octet en char */
    /* NOTE : Autant que possible, évitez les caractères non-ASCII lorsque vous programmez */
    /* Le dernier caractère (n°20) n'est pas imprimable : C'est le fameux '\0' */

    /* On saute une ligne, c'est plus joli */
    printf("\n");

    /* Notez qu'il est possible de couper la chaine plus tôt en insérant '\0' au milieu */
    chaine[12] = '\0';
    printf("Ma chaine s'affiche maintenant comme : %s\n", chaine);

    return 0;
}
