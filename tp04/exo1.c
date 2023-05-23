#include <stdio.h>
#include <stdlib.h>

void ajoute_element_a_la_fin(liste_t *liste, char car)
{
    liste_t *nouveau = malloc(sizeof(liste_t));
    nouveau->car = car;
    nouveau->queue = NULL;

    if (liste == NULL)
    {
        liste = nouveau;
    }
    else
    {
        liste_t *courant = liste;
        while (courant->queue != NULL)
        {
            courant = courant->queue;
        }
        courant->queue = nouveau;
    }
}

int main(void)
{
    // Q1. Définissez le type liste_t et créez une variable liste de ce type représentant une liste vide

    typedef struct liste_t
    {
        char car;
        struct liste_t *queue;
    } liste_t;

    // Q2. Pour commencer, écrivez une fonction liste_t* ajoute_element_a_la_fin (liste_t* liste, char car); qui ajoute le caractère car à la fin de votre liste. Attention si liste vaut NULL alors cette fonction va devoir modifier la valeur de la variable liste. C’est pourquoi on se servira de cette fonction de la manière suivante : liste = ajoute_element_a_la_fin(liste,'a');

    liste_t = ajoute_element_a_la_fin(liste, 'a');
}