#include <stdio.h>

int main(void)
{
    int a, b, c;
    a = 3, b = 5, c = 9;
    int min = c;

    if (a <= b && a <= c)
    {
        min = a;
    }
    else if (b <= a && b <= c)
    {
        min = b;
    }

    printf("Le plus petit est %d !\n", min);
    return 0;
}