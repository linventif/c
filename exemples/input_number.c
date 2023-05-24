#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num1, num2;
    int success = 0;

    while (!success)
    {
        printf("Enter two numbers separated by a space: ");
        int result = scanf("%d %d", &num1, &num2);

        if (result == 2)
        {
            success = 1;
            printf("You entered: %d and %d\n", num1, num2);
        }
        else
        {
            printf("Invalid input. Please try again.\n");

            // Vider le tampon d'entrée pour éviter le dépassement de mémoire
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
        }
    }
    return 0;
}