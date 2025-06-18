#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    int number;
    int max;

    file = fopen("./data/numbers.dat", "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    printf("The input file:\n");

    if (fscanf(file, "%d", &number) != 1)
    {
        printf("File is empty or invalid.\n");
        fclose(file);
        return 1;
    }

    max = number;
    printf("%d ", number);

    while (fscanf(file, "%d", &number) == 1)
    {
        printf("%d ", number);
        if (number > max)
            max = number;
    }

    printf("\n\nThe maximum element: %d.\n", max);

    fclose(file);
    return 0;
}