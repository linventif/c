#include <stdio.h>

int produit(int a, int b)
{
    return a * b;
}

void afficher_lentier(int n)
{
    printf("La fonction vous affiche l’entier : %d\n", n - 1);
}

void modifie_a(int a)
{
    a = a + 1;
    // Réafection de la valeur de a dans la fonction main
    // a une autre case mémoire que celle de la fonction main
    printf("La fonction modifie_a vous affiche l’entier : %d\n", a);
}

int main(void)
{
    int i = 5;
    afficher_lentier(i);
    printf("Le produit de 3 et 4 est : %d\n", produit(3, 4));
    int a = 0;
    modifie_a(a);
    printf("La fonction main vous affiche l’entier : %d\n", a);
    return 0;
}