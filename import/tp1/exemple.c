#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int i = 4;
    sleep(3);
    printf("J'ai mangé %d pommes\n", i);
    return 0;
}