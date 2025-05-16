#include <stdio.h>
#include "movies.h"
int main()
{
    int start, end;
    printf("Range start > ");
    scanf("%d", &start);
    printf("\n");

    printf("Range end > ");
    scanf("%d", &end);
    printf("\n");

    for (int i = start; i < end; i++)
    {
        printf("%s, %s, %d \n", Movies[i].Title, Movies[i].Director, Movies[i].Year);
    }
    return 0;
}