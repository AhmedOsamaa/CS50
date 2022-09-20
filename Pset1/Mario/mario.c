#include <stdio.h>

int main()
{
    int height;
    do
    {
        printf("Height : ");
        scanf("%i", &height);
    }     while ((height <= 0) || (height >= 9));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height - i - 1; j++)
            printf(" ");
        for (int k = 0; k <= i; k++)
            printf("#");
        printf("  ");
        for (int k = 0; k <= i; k++)
            printf("#");
        printf("\n");

    }
}