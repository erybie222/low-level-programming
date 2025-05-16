#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;

    printf("Input coefficients of a quadratic equation (a, b, c): \n");
    scanf("%f %f %f", &a, &b, &c);

    float delta, x1, x2;
    delta = (b * b) - (4 * a * c);

    if (delta > 0)
    {
        x1 = (-b - sqrt(delta)) / (2 * a);
        x2 = (-b + sqrt(delta)) / (2 * a);
        printf("The given equation has 2 distinct real roots: x1 =  %f , x2 = %f \n", x1, x2);
    }
    else if (delta == 0)
    {
        x1 = (-b) / (2 * a);
        printf("The given equation has 1 double real root, x1 = %f.\n", x1);
    }
    else
    {
        printf("The given equation has 0 roots.\n");
    }
    return 0;
}