#include <stdio.h>

int main (void){
    // create table of 10 int
    int tab[3] = {1, 2, 3};

    // print table
    // Note : IMPOSSIBLE DE GET LA TAILLE D'UN TABLEAU EN C
    for (int i = 0; i < 3; i++){
        printf("le tableau[%d] vaut %d\n", i, tab[i]);
    }

    // create table of 100 int
    int tab2[100];

    // print table
    // Note : ne clean pas l'adresse mémoire car pas d'affection
    for (int i = 0; i < 100; i++){
        printf("le tableau[%d] vaut %d\n", i, tab2[i]);
    }

    return 0;
}