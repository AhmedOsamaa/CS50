#include <stdio.h>

int main()
{
    int start_size, end_size;
    do
    {
        printf("Start size: ");
        scanf("%i", &start_size);
    }     while (start_size < 9);
    do
    {
        printf("End size: ");
        scanf("%i", &end_size);
    }     while (end_size < start_size);
    int years = 0;
    while (start_size < end_size)
    {
        start_size = start_size / 3 + start_size - start_size / 4;
        years++;
    }
    printf("Years: %i\n", years);
}
