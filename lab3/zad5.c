#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int length_of_array = 0;

    printf("Enter the length (greater than zero) of the array A > ");
    scanf("%d", &length_of_array);
    printf("\n");

    if (length_of_array <= 0)
    {
        printf("Invalid length.\n");
        return 1;
    }

    printf("Maximal length of every string in the array A is 19.\n");

    char **A = (char **)malloc(length_of_array * sizeof(char *));
    if (A == NULL)
    {
        printf("Malloc failed.\n");
        return 1;
    }

    for (int i = 0; i < length_of_array; i++)
    {
        A[i] = (char *)malloc(19 * sizeof(char) + 1);
        if (A[i] == NULL)
        {
            printf("Malloc failed.\n");
            return 1;
        }
        printf("Enter A[%d] > ", i);
        scanf("%19s", A[i]);
    }

    int total_length = 3;
    for (int i = 0; i < length_of_array; i++)
    {
        total_length += strlen(A[i]);
        if (i < length_of_array - 1)
        {
            total_length += 2;
        }
    }

    char *output = (char *)malloc((total_length + 1) * sizeof(char));
    if (output == NULL)
    {
        printf("malloc failed\n");
        return 1;
    }

    output[0] = '\0';

    for (int i = 0; i < length_of_array; i++)
    {
        strcat(output, A[i]);
        if (i < length_of_array - 1)
        {
            strcat(output, ", ");
        }
    }

    printf("\nThe output string: \"%s\".\n", output);

    for (int i = 0; i < length_of_array; i++)
    {
        free(A[i]);
    }
    free(A);
    free(output);

    return 0;
}