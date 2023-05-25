#include <stdio.h>

int main(void)
{

    float devise = 60.0;
    float taux_change = 1.09;

    float total = devise * taux_change;

    printf("Alice et Bob ont %.2f euros après conversion.\n", total);
    printf("Ils gardent donc %.2f euros chacun.\n", total / 2);

    return 0;
}