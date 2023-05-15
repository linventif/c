#include <stdio.h>

int main (void){
    const int tab[6] = {5, 4, 7, 14, 2, 3};
    int highest = tab[0];

    for (int i = 0; i < 6; i++){
        if (tab[i] > highest){
            highest = tab[i];
        }
    }

    printf("le plus grand nombre du tableau est %d\n", highest);

    return 0;
}