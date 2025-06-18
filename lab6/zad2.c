#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *infile, *outfile;
    int a, b;

    infile = fopen("./data/input.dat", "r");
    if (infile == NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    outfile = fopen("sum_pairs.dat", "w");
    if (outfile == NULL)
    {
        printf("Could not open output file.\n");
        fclose(infile);
        return 1;
    }

    printf("The input file:\n");
    while (fscanf(infile, "%d %d", &a, &b) == 2)
    {
        printf("%d %d ", a, b);
        fprintf(outfile, "%d ", a + b);
    }

    fclose(infile);
    fclose(outfile);

    printf("\n\nThe output file:\n");
    outfile = fopen("sum_pairs.dat", "r");
    if (outfile == NULL)
    {
        printf("Could not reopen output file.\n");
        return 1;
    }

    int sum;
    while (fscanf(outfile, "%d", &sum) == 1)
    {
        printf("%d ", sum);
    }

    printf("\n");
    fclose(outfile);

    return 0;
}