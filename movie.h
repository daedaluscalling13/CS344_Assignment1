#ifndef MOVIE_H
#define MOVIE_H

/* struct for movie information */
struct movie
{
    // Cheating and only using strings. Conversions aren't great.
    char* title;
    char* year;
    char languages[5][20];
    char* rating;
    struct movie *next;
};

#endif