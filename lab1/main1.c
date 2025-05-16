#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Input lengths of three sides of a triangle (a, b, c): ");
    scanf("%d %d %d", &a, &b, &c);
    if (a < b + c && b < a + c && c < a + b)
    {
        printf("A triangle with sides %d, %d, and %d can be constructed.\n", a, b, c);
    }
    else
    {
        printf("A triangle with sides %d, %d, and %d cannot be constructed.\n", a, b, c);
    }
    return 0;
}