#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Output prompt options and receive a prompt input.
int receivePrompt(void)
{
    printf("\n");
    printf("1. Show movies released in the specified year\n");
    printf("2. Show highest rate movie for each year\n");
    printf("3. Show the title and year of release of all movies in a specific language\n");
    printf("4. Exit the program\n");
    printf("\n");
    printf("Enter a choice from 1 to 4: ");
    
    char* prompt = calloc(sizeof(char), 16);
    scanf("%s", prompt);
    int iPrompt = atoi(prompt);
    free(prompt);
    return iPrompt;
}

// Prompt was not a valid choice, notify user.
void invalidPrompt(void)
{
    printf("You entered an incorrect choice. Try again.\n");
    return;
}