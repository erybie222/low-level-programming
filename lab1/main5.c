#include <stdio.h>
#include <math.h>

int main()
{
    double pi;
    double a;
    double sum = 0.0;
    int n;
    printf("Enter n: \n");
    scanf("%d", &n);
    for (int i = 1; i < n + 1; i += 2)
    {

        a = 1.0 / i;
        if (i % 2 == 1)
        {
            sum += a;
        }
        else
        {
            sum -= a;
        }
    }
    pi = 4 * sum;
    printf("pi is equal to: %lf", pi);
}