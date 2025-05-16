#include <stdio.h>
#include <math.h>

int main()
{
    unsigned long n;
    int digit;
    int sum = 0;
    printf("Enter n : \n");
    scanf("%lu", &n);

    for (int i = 0; n > 0; i++)
    {
        digit = n % 10;
        n = n / 10;
        sum += digit * pow(3, i);
    }
    printf("In decimal it is: %d", sum);
}