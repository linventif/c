#include <stdio.h>

int main (void){
    int tableau[6] = {5,4,7,14,2,3};

    for (int i = 0; i < 6; i++){
        printf("[%d] : %d\n", i, tableau[i]);
    }

    int tmp;
    for (int i = 0; i < 6; i++){
        for (int j = i+1; j < 6; j++){
            if (tableau[i] > tableau[j]){
                tmp = tableau[i];
                tableau[i] = tableau[j];
                tableau[j] = tmp;
            }
        }
    }

    printf("\n");

    for (int i = 0; i < 6; i++){
        printf("[%d] : %d\n", i, tableau[i]);
    }

    return 0;
}