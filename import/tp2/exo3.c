#include <stdio.h>

void somme_et_produit(int a, int b, int *pt_somme, int *pt_produit);

int main(void)
{
    int a = 5;
    int b = 3;
    int somme = 0;
    int produit = 0;

    int *pt_somme = &somme;
    int *pt_produit = &produit;

    somme_et_produit(a, b, pt_somme, pt_produit);
    printf("a = %d, b = %d\n", a, b);
    printf("somme = %d, produit = %d\n", somme, produit);

    printf("\n");
    return 0;
}

void somme_et_produit(int a, int b, int *pt_s, int *pt_p)
{
    *pt_s = a + b;
    *pt_p = a * b;
}