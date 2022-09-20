#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    char str[100];
    int key = atoi(argv[1]);
    if (key < 0 || key > 100)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    printf("plaintext: ");
    scanf("%[^\n]", str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
        {
            if (isupper(str[i]))
            {
                str[i] = (str[i] + key - 'A') % 26 + 'A';
                //str[i]  = toupper(str[i]);
            }
            else
            {
                str[i] = (str[i] + key - 'a') % 26 + 'a';
            }
        }
    }
    printf("ciphertext: %s\n", str);
}