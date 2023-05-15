#include <stdio.h>

int main(void)
{
    int div3, div5, i;

    for (i = 1; i <= 30; i++)
    {
        div3 = i % 3;
        div5 = i % 5;

        if (div3 == 0 && div5 == 0)
        {
            printf("FizzBuzz\n");
        }
        else if (div3 == 0)
        {
            printf("Fizz\n");
        }
        else if (div5 == 0)
        {
            printf("Buzz\n");
        }
        else
        {
            printf("%d\n", i);
        }
    }

    return 0;
}