#include <stdio.h>

int main()
{

    printf("for\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", i);
    }

    printf("\n\n");
    printf("while\n");

    int count = 0;
    while (count < 5)
    {
        printf("%d\n", count);
        count++;
    }

    return 0;
}