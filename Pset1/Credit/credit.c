#include <stdio.h>

int main()
{
    long int digits;
    scanf("%ld", &digits);
    int index = 0, sum_ev = 0, sum_odd2 = 0, credit_type, total_sum;
    while (digits != 0)
    {
        if (index % 2 == 0 || index == 0)
        {
            sum_ev += digits % 10;
        }
        else if (index % 2 != 0 && index != 0)
        {
            sum_odd2 += (2 * (digits % 10));
        }
        digits /= 10;
        index++;
    }
    total_sum = sum_ev + sum_odd2;
    printf("sum even : %i , sum odd = %i  \n", sum_ev, sum_odd2);
    if (total_sum % 10 == 0)
    {
        printf("Valid!\n");
    }
    else
        printf("invalid\n");
}