// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "dictionary.h"
int size_ = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node* table[N] = { NULL };

// Returns true if word is in dictionary, else false
bool check(const char* word)
{
    // TODO
    int hashed = hash(word);
    for (node* tmp = table[hashed]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }

    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char* word)
{
    int hash = 0;
    int n;
    int z = strlen(word);
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
            n = tolower(word[i]) - 'a' + 1;
        else
            n = 27;
        hash = ((hash * 8) + n) % N; //increase the range of the hash
    }
    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char* dictionary)
{
    // TODO
    FILE* dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("failed to open file.\n");
        return false;
    }
    char to_load[LENGTH + 1];
    while (fscanf(dict, "%s", to_load) != EOF)
    {
        node* n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("failed to allocate memory\n");
            return false;
        }
        strcpy(n->word, to_load);
        int hashed = hash(to_load);
        n->next = table[hashed];
        table[hashed] = n;
        size_++;

    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return size_;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < 1000; i++)
    {
        /*        for(node *tmp = NULL; tmp != NULL ; tmp = tmp->next)
                {
                    tmp = table[i]->next;
                    free (table[i]);
                    table[i] = tmp;
                }*/
        node* tmp = table[i];
        while (tmp != NULL)
        {
            node* deleted = tmp;
            tmp = tmp->next;
            free(deleted);
        }
    }
    return true;
}

