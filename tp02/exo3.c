#include <stdio.h>

void somme_et_produit(int a, int b, int *pt_somme, int *pt_produit)
{
    *pt_somme = a + b;
    *pt_produit = a * b;
}

int main(void)
{
    int a = 5;
    int b = 10;
    somme_et_produit(a, b, &a, &b);
    printf("a = %d ; b = %d\n", a, b);
    return 0;
}