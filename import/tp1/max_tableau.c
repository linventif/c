#include <stdio.h>

int main(void)
{

    int tableau[6] = {5, 4, 7, 14, 2, 3};
    int max_idx, actual_idx;

    max_idx = 0;
    for (actual_idx = 1; actual_idx < 6; actual_idx++)
    {
        if (tableau[actual_idx] > tableau[max_idx])
        {
            max_idx = actual_idx;
        }
    }

    printf("La valeur maximale est %d.\n", tableau[max_idx]);
    printf("Elle se trouve en position %d.\n", max_idx);

    return 0;
}