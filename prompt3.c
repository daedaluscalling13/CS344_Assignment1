#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prompt3.h"
#include "movie.h"

// PROMPT 3
// Get the specified language
char* getSpecifiedLanguage(void)
{
    char* language = calloc(sizeof(char), 20);
    printf("Enter the language for which you want to see movies: ");
    scanf("%s", language);
    return language;
}

// Print movies for the specified language (prompt 3)
void printMovieFromLanguage(char* language, struct movie* list)
{
    int count = 0;
    while (list != NULL)
    {
        for (int i = 0; i < 5; i++){
            if(strcmp(list->languages[i], language) == 0)
            {
                printf("%s %s\n", list->year, list->title);
                count++;
                break;
            }
        }
        list = list->next;
    }

    if (count == 0)
    {
        printf("No data about movies released in %s.\n", language);
    }
}