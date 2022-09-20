#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

#define MAX 20


bool vote(char* voted);
void print_winner();



typedef struct
{
    string name;
    int votes;

} candidate;
candidate candidates[MAX];
int candidate_count;


int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./plurality name name\n");
        return 1;
    }
    candidate_count = argc - 1;
    //-1 because ./plurality counts, so if we want to know how many elements the user entered,  we have to subtract by 1.
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    int voter_count;
    printf("Number of voters: ");
    scanf("%i", &voter_count);

    int i = 0;
    while (i < voter_count)
    {
        char name[20];
        printf("Vote: ");
        scanf("%s", name);
        if (!vote(name))
        {
            printf("not found\n");
            continue;
        }
        i++;
    }
    print_winner();
    return 0;
}

bool vote(char* voted_)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, voted_) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner()
{
    //printf("number : %i\n",num_);
    int grt = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (grt < candidates[i].votes)
        {
            grt = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == grt)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}
