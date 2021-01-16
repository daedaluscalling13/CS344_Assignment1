// If you are not compiling with the gcc option --std=gnu99, then
// uncomment the following line or you might get a compiler warning
//#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "process.h"
#include "prompt.h"
#include "prompt1.h"
#include "prompt2.h"
#include "prompt3.h"

// Gets lenght of the movie linked list created after file processing
int getListLength(struct movie* list)
{
    int movieCount = 0;
    while (list != NULL)
    {
        movieCount++;
        list = list->next;
    }
    return movieCount;
}

/*
*   Process the file provided as an argument to the program to
*   create a linked list of student structs and print out the list.
*   Compile the program as follows:
*       gcc --std=gnu99 -o movies movies.c
*/

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("You must provide the name of the file to process\n");
        printf("Example usage: ./movies movies_info.txt\n");
        return EXIT_FAILURE;
    }

    struct movie* list = processFile(argv[1]);
    int movieCount = getListLength(list);
    printf("Processed file %s and parsed data for %d movies.\n", argv[1], movieCount);

    int prompt;
    char* year = NULL;
    char* language = NULL;
    do{
        prompt = receivePrompt();
        switch(prompt){
            case 1:
                year = getSpecifiedYear();
                printMovieFromYear(year, list);
                free(year);
                break;
            case 2:
                printYearHighestRatedMovie(list);
                break;
            case 3:
                language = getSpecifiedLanguage();
                printMovieFromLanguage(language, list);
                free(language);
                break;
            case 4:
                break;
            default:
                invalidPrompt();
        }
    } while(prompt != 4);   

    return EXIT_SUCCESS;
}