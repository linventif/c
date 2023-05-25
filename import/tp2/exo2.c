#include <stdio.h>

void test_pointeur(void);

int plus_egal(int *pt_a, int b);

int fois_egal(int *pt_a, int b);

int main(void)
{
    test_pointeur();

    // Test
    int a = 5;
    int b = 3;
    int *pt_a = &a;
    int *pt_b = &b;

    printf("a = %d, b = %d\n", a, b);
    plus_egal(pt_a, b);
    printf("a = %d, b = %d\n", a, b);
    fois_egal(pt_b, a);
    printf("a = %d, b = %d\n", a, b);

    printf("\n");
    return 0;
}

void test_pointeur(void)
{
    int a = 5;
    int *pt_a = &a;
    printf("a = %d (%p)", a, pt_a);
}

int plus_egal(int *pt_a, int b)
{
    *(pt_a) = *(pt_a) + b;
    return 0;
}

int fois_egal(int *pt_a, int b)
{
    *(pt_a) = *(pt_a)*b;
    return 0;
}