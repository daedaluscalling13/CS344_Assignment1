// If you are not compiling with the gcc option --std=gnu99, then
// uncomment the following line or you might get a compiler warning
//#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* struct for movie information */
struct movie
{
    char* title;
    char* year;
    char languages[5][20];
    char* rating;
    struct movie *next;
};

/* Parse the current line which is space delimited and create a
*  student struct with the data in this line
*/
struct movie* createMovie(char *currLine)
{
    char* languagesBuffer;
    struct movie* currMovie = malloc(sizeof(struct movie));

    // For use with strtok_r
    char* saveptr;

    // The first token is the Title
    char* token = strtok_r(currLine, ",", &saveptr);
    currMovie->title = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currMovie->title, token);

    // The next token is the Year
    token = strtok_r(NULL, ",", &saveptr);
    currMovie->year = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currMovie->year, token);

    // The next token is the Languages
    token = strtok_r(NULL, ",", &saveptr);
    languagesBuffer = calloc(strlen(token) + 1, sizeof(char));
    strcpy(languagesBuffer, token);

    // The last token is the Rating
    token = strtok_r(NULL, "\n", &saveptr);
    currMovie->rating = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currMovie->rating, token);

    // Languages need to be correctly formatted and parsed further
    // Formatting
    // Remove the bracket from the beginning
    strncpy(languagesBuffer, languagesBuffer+1, strlen(languagesBuffer)-1);

    // Parse String
    int arrayIndex = 0;
    token = strtok_r(languagesBuffer, ";]", &saveptr);
    while(token != NULL){
        strcpy(currMovie->languages[arrayIndex], token);
        token = strtok_r(NULL, ";]", &saveptr);
        arrayIndex++;
    }
    free(languagesBuffer);

    // Set the next node to NULL in the newly created student entry
    currMovie->next = NULL;

    return currMovie;
}

/*
* Return a linked list of movies by parsing data from
* each line of the specified file.
*/
struct movie* processFile(char *filePath)
{
    // Open the specified file for reading only
    FILE* movieFile = fopen(filePath, "r");

    char* currLine = NULL;
    size_t len = 0;
    ssize_t nread;
    char* token;

    // Flag to avoid processing the table's header line
    int headerLine = 0;

    // The head of the linked list
    struct movie* head = NULL;
    // The tail of the linked list
    struct movie* tail = NULL;

    // Read the file line by line
    while ((nread = getline(&currLine, &len, movieFile)) != -1)
    {
        if (headerLine)
        {
            // Get a new student node corresponding to the current line
            struct movie* newNode = createMovie(currLine);

            // Is this the first node in the linked list?
            if (head == NULL)
            {
                // This is the first node in the linked link
                // Set the head and the tail to this node
                head = newNode;
                tail = newNode;
            }
            else
            {
                // This is not the first node.
                // Add this node to the list and advance the tail
                tail->next = newNode;
                tail = newNode;
            }
        }
        else
        {
            headerLine = 1;
        }
    }
    free(currLine);
    fclose(movieFile);
    return head;
}

/*
* Print data for the given student
*/
void printMovie(struct movie* aMovie){
  printf("%s %s %s %s\n", aMovie->title,
               aMovie->year,
               aMovie->languages,
               aMovie->rating);
}
/*
* Print the linked list of movies
*/
void printMovieList(struct movie* list)
{
    while (list != NULL)
    {
        printMovie(list);
        list = list->next;
    }
}

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
    return atoi(prompt);
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
    // printMovieList(list);
    int movieCount = getListLength(list);
    printf("Processed file %s and parsed data for %d movies.\n", argv[1], movieCount);
    int prompt;
    do{
        prompt = receivePrompt();
        printf("You entered %d.\n", prompt);
    } while(prompt != 4);   

    return EXIT_SUCCESS;
}