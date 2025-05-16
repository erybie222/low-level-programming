#include <stdio.h>
#include <math.h>

int main()
{
    int n, squared, r, i;
    printf("Input an integer: \n");
    scanf("%d", &n);
    squared = pow(n, 2);
    i = 0;
    for (i = 0;; i++)
    {
        if (pow(10, i) >= n)
        {
            r = pow(10, i);
            break;
        }
    }
    int automorphic = squared % r;
    if (automorphic == n)
    {
        printf("N = %d is automorphic!: \n", n);
    }
    else
    {
        printf("N = %d is  not automorphic!: \n", n);
    }
}