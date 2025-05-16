#include <stdio.h>
#include <string.h>
#include "movies.h"

int main()
{
    int newest = 0;
    int movie_index;
    for (int i = 0; i < ActualMoviesNo; i++)
    {
        if (Movies[i].Year > newest)
        {
            newest = Movies[i].Year;
            movie_index = i;
        }
    }
    printf("The newest movie: %s, %s, %d \n", Movies[movie_index].Title, Movies[movie_index].Director, Movies[movie_index].Year);
}
