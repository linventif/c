#include <stdio.h>

int main(void)
{

    int idx;

    for (idx = 1; idx <= 30; idx++)
    {
        if (idx % 3 == 0)
        {
            printf("Fizz");
        }
        if (idx % 5 == 0)
        {
            printf("Buzz");
        }
        else if (idx % 3 != 0 && idx % 5 != 0)
        {
            printf("%d", idx);
        }
        printf("\n");
    }

    return 0;
}