#include <stdio.h>
#include <string.h>
#include "movies_short.h"

int main()
{
    int movie_index;
    int movieCount = ActualMoviesNo;
    printf("Movies\n");
    printf("-------\n");
    for (int i = 0; i < ActualMoviesNo; i++)
    {
        printf("%s, %s, %d.\n", Movies[i].Title, Movies[i].Director, Movies[i].Year);
    }
    printf("\n");
    printf("Delete a movie\n");
    printf("-------\n");
    printf("Index <0, %d> >", ActualMoviesNo - 1);
    scanf("%d", &movie_index);

    for (int j = movie_index; j < movieCount - 1; j++)
    {
        Movies[j] = Movies[j + 1];
    }
    movieCount -= 1;

    printf("\n");
    printf("Movies\n");
    printf("-------\n");
    for (int i = 0; i < movieCount; i++)
    {
        printf("%s, %s, %d.\n", Movies[i].Title, Movies[i].Director, Movies[i].Year);
    }
    return 0;
}