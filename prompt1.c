#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prompt1.h"
#include "movie.h"

// PROMPT 1
// Get the specified year
char* getSpecifiedYear(void)
{
    char* year = calloc(sizeof(char), 4);
    printf("Enter the year for which you want to see movies: ");
    scanf("%s", year);
    return year;
}

// Print movies for the specified year (prompt 1)
void printMovieFromYear(char* year, struct movie* list)
{
    int count = 0;
    while (list != NULL)
    {
        if(strcmp(list->year, year) == 0)
        {
            printf("%s\n", list->title);
            count++;
        }
        list = list->next;
    }

    if (count == 0)
    {
        printf("No data about movies released in the year %s.\n", year);
    }
}