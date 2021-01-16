#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prompt2.h"
#include "movie.h"

// PROMPT 2
// Gross way to get the max for each year
void printYearHighestRatedMovie(struct movie* list)
{

    // Declaring vars
    struct movie* currMovie = list;
    char* currYear = NULL;
    struct movie* currList = NULL;
    struct movie* maxMovie = NULL;

    // Loop through the list of movies
    // For each movie, find if the current movie is the highest rated for that year.
    // If it is, print the movie.
    while(currMovie != NULL)
    {
        currList = list;
        currYear = currMovie->year;
        maxMovie = NULL;

        // Loop through the list of movies to find other movies from the same year.
        // This is inefficient.
        while (currList != NULL)
        {
            if (strcmp(currList->year, currYear) == 0)
            {
                // No max movie, therefore first one found is max
                if (maxMovie == NULL)
                {
                    maxMovie = currList;
                }

                // Is the max movie higher rated than the current movie?
                else
                {
                    char* ptr;
                    if (strtod(maxMovie->rating, &ptr) < strtod(currList->rating, &ptr))
                    {
                        maxMovie = currList;
                    }
                }
            }
            currList = currList->next;
        }

        if (strcmp(maxMovie->title, currMovie->title) == 0)
        {
            printf("%s %s %s\n", currMovie->year, currMovie->rating, currMovie->title);
        }

        currMovie = currMovie->next;
    }

    return;
}