#include <stdio.h>
#include <math.h>

int main()
{
    int a0;
    printf("Input the first element of the sequence (positive integer):\n");
    scanf("%d", &a0);
    if (a0 <= 0)
    {
        printf("ERROR, The first element of the sequence must be a positive integer\n");
        return 1;
    }
    while (a0 != 1)
    {
        if (a0 % 2 == 1)
        {
            a0 = 3 * a0 + 1;
        }
        else if (a0 % 2 == 0)
        {
            a0 = a0 / 2;
        }
    }
}