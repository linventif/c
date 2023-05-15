#include <stdio.h>

int main (void){
    int a, b, c;

    a = 8;
    b = 5;
    c = 4;

    if (a < b && a < c){
        printf("a est le plus petit\n");
            }
    else if (b < a && b < c){
        printf("b est le plus petit\n");
    }
    else if (c < a && c < b){
        printf("c est le plus petit\n");
    }
    else {
        printf("il y a une égalité\n");
    }

    return 0;
}