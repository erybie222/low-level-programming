#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *infile1 = fopen("./data/numbers1.bin", "r");
    FILE *infile2 = fopen("./data/numbers2.bin", "r");
    FILE *outfile = fopen("./data/nums_out.bin", "w");

    if (!infile1 || !infile2 || !outfile)
    {
        printf("Could not open one of the files.\n");
        return 1;
    }

    int a, b;

    printf("The input file 0:\n");
    fseek(infile1, 0, SEEK_SET);
    while (fscanf(infile1, "%d", &a) == 1)
    {
        printf("%d ", a);
    }

    printf("\n\nThe input file 1:\n");
    fseek(infile2, 0, SEEK_SET);
    while (fscanf(infile2, "%d", &b) == 1)
    {
        printf("%d ", b);
    }

    fseek(infile1, 0, SEEK_SET);
    fseek(infile2, 0, SEEK_SET);

    printf("\n\nThe output file:\n");
    while (fscanf(infile1, "%d", &a) == 1 && fscanf(infile2, "%d", &b) == 1)
    {
        fprintf(outfile, "%d %d ", a, b);
        printf("%d %d ", a, b);
    }

    fclose(infile1);
    fclose(infile2);
    fclose(outfile);

    printf("\n");
    return 0;
}