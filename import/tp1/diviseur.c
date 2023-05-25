#include <stdio.h>

int main(void)
{
    int n, actual;
    n = 10;

    for (actual = 1; actual < +n; actual++)
    {
        if (n % actual == 0)
        {
            printf("%d\n", actual);
        }
    }

    for (actual = 0; actual < +n; actual++)
    {
        printf("%d", actual);
    }
    printf("\n");

    return 0;
}