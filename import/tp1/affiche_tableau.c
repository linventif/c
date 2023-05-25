#include <stdio.h>

int main(void)
{

    int tableau[3] = {5, 4, 7};
    int idx;
    for (idx = 0; idx < 3; idx++)
    {
        printf("tableau[%d] contient ", idx);
        printf("%d\n", tableau[idx]);
    }
    return 0;
}