#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols;

    printf("Enter the number of rows > ");
    scanf("%d", &rows);

    printf("Enter the number of columns > ");
    scanf("%d", &cols);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("\nEntering the input matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter m[%d,%d] > ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nThe input matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int **transpose = (int **)malloc(cols * sizeof(int *));
    for (int i = 0; i < cols; i++)
    {
        transpose[i] = (int *)malloc(rows * sizeof(int));
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("\nThe transpose matrix:\n");
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < cols; i++)
    {
        free(transpose[i]);
    }
    free(transpose);

    return 0;
}