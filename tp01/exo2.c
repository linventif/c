#include <stdio.h>

int main(void)
{
    const float devise = 60;
    float taux = 1.1226;

    taux = 1.09;

    float montant = devise * taux;
    montant = montant / 2;

    printf("Montant : %.2f\n", montant);

    return 0;
}
