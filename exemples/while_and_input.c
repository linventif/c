#include <stdio.h>
#include <stdlib.h>

#define MAX_TEXT_LENGTH 100

int main(void)
{
    char text[MAX_TEXT_LENGTH];
    int i = 0;

    while (1)
    {
        printf("Enter a text: ");
        scanf("%99s", text); // Limite la lecture à MAX_TEXT_LENGTH - 1 caractères pour éviter le dépassement de mémoire

        printf("You entered: %s\n", text);

        if (strcmp(text, "exit") == 0)
        {
            printf("Exiting...\n");
            break;
        }

        if (i == 10)
        {
            printf("You entered 10 texts, exiting...\n");
            break;
        }

        i++;
        // Vider le tampon d'entrée
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
    }

    return 0;
}