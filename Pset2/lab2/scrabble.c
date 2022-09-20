#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int score(char* arr, int* points);

int main()
{
    char word1[100], word2[100];
    int points[] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };
    printf("Enter word 1 : ");
    scanf("%s", word1);
    printf("Enter word 2 : ");
    scanf("%s", word2);
    int score1 = 0, score2 = 0;
    score1 = score(word1, points);
    score2 = score(word2, points);
    if (score1 > score2)
        printf("Player 1 wins!\n");
    else if (score2 > score1)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");

}
int score(char* arr, int* points)
{
    int val = 0;
    //char temp;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        //temp = tolower(arr[i]);
        if (isalpha(arr[i]))
        {
            val += points[tolower(arr[i]) - 'a'];
        }
    }
    return val;
}
