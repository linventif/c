#include <stdio.h>

void affiche_entier(int n);

int produit(int a, int b);

void modifie_a(int a);

int main(void)
{
    affiche_entier(50);
    printf("\n");
    affiche_entier(produit(3, 4));
    return 0;
}

void affiche_entier(int n) { printf("%d", n); }

int produit(int a, int b) { return a * b; }

void modifie_a(int a) { a += 1; }