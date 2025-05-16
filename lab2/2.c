#include <stdio.h>
#include "movies.h"
#include <string.h>
int main()
{
    char director[MaxStrLen];
    int result;
    printf("Director >");
    scanf("%[^\n]", &director);
    printf("\n");

    for (int i = 0; i < ActualMoviesNo; i++)
    {
        result = strcmp(director, Movies[i].Director);
        if (result == 0)
        {
            printf("%s , %s , %d \n", Movies[i].Director, Movies[i].Title, Movies[i].Year);
        }
    }
}