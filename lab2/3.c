#include <stdio.h>
#include "movies.h"
#include <string.h>
int main()
{
    int lentghLimit;
    printf("Title length limit >");
    scanf("%d", &lentghLimit);
    for (int i = 0; i < ActualMoviesNo; i++)
    {
        if (strlen(Movies[i].Title) <= lentghLimit)
        {
            printf("%s, %s , %d \n", Movies[i].Director, Movies[i].Title, Movies[i].Year);
        }
    }
}