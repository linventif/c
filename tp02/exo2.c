#include <stdio.h>

int plus_egal(int *pt_a, int b)
{
    *pt_a = *pt_a + b;
    return 0;
}

int fois_egal(int *pt_a, int b)
{
    *pt_a = *pt_a * b;
    return 0;
}

int main(void)
{
    int a = 5;
    int *pt_a = &a;

    // print the value of a
    printf("a = %d\n", a);

    // print the address of a
    printf("pt_a = %p\n", pt_a);

    // get the value pointed by pt_a
    printf("*pt_a = %d\n", *pt_a);

    int b = 10;
    int *pt_b = &b;

    // print the value of b
    printf("\nb = %d\n", b);

    // print the adition of a and b
    printf("a + b = %d\n", a + b);
    printf("*pt_a + *pt_b = %d\n", *pt_a + *pt_b);

    printf("\n");

    printf("a : %d ; b : %d\n", a, b);

    printf("\n");

    printf("plus_egal(pt_a, b) = %d\n", plus_egal(pt_a, b));
    printf("a : %d ; b : %d\n", a, b);

    printf("\n");

    printf("fois_egal(pt_a, b) = %d\n", fois_egal(pt_a, b));
    printf("a : %d ; b : %d\n", a, b);
}