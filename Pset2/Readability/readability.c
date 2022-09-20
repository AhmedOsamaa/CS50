#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main()
{
    char arr[400];
    printf("Text : ");
    scanf("%[^\n]", arr);
    int l = 0, s = 0, w = 1;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (isalpha(arr[i]))
        {
            l++;
        }
        else if (arr[i] == '.' || arr[i] == '!' || arr[i] == '?')
        {
            s++;
        }
        else if (arr[i] == ' ')
        {
            w++;
        }
    }
    printf("%i  %i  %i\n", l, s, w);
    float L = (float)l * 100 / w;
    float S = (float)s * 100 / w; //do not forget to use type casting
    float index = round((0.0588 * L) - (0.296 * S) - 15.8);
    //printf("%i\n",index);
    if (index < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)index);
    }
}