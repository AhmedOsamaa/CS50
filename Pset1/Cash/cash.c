
#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    float change;
    do
    {
        //printf("Change owed : " );
        //scanf("%f",&change);
        change = get_float("Change owed : ");
        //cents = round(change*100);
    }     while (change < 0);
    int cents = round(change * 100);
    int coins = 0;

    int q = cents / 25; //so that the result of the divison is the number of coins needed
    cents %= 25;  //the remainder of the division is the chnage needed to be formed with other coins

    int d = cents / 10;
    cents %= 10;

    int c = cents / 5;
    cents %= 5;

    int n = cents;
    coins = q + d + c + n;
    printf("%i\n", coins);
}