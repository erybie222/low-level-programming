#include <stdio.h>
#include <math.h>

int main()
{
    unsigned long n;
    int d;
    int digit;
    printf("Enter n and d: \n");
    scanf("%lu %d", &n, &d);
    unsigned long original_n = n;
    int counter = 0;
    while (n > 0)
    {
        digit = n % 10;
        n = n / 10;

        if (d == digit)
        {
            counter += 1;
        }
    }
    print("Digit %d occurs %d times in number %lu", d, counter, original_n);
}