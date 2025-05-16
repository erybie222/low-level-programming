#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *input = NULL;
    char *substring = NULL;
    int start, end;

    input = (char *)malloc(19 * sizeof(char) + 1);
    if (input == NULL)
    {
        printf("malloc failed\n");
        return 1;
    }

    printf("Enter the string (max. 19 chars) > ");
    scanf("%19s", input);
    printf("\n");

    printf("Enter the starting position (max. 19) > ");
    scanf("%d", &start);

    printf("Enter the ending position (max. 19) > ");
    scanf("%d", &end);
    printf("\n");

    int input_length = strlen(input);

    if (start < 0 || start >= input_length)
    {
        printf("Invalid starting position.\n");
        free(input);
        return 1;
    }

    if (end < 0 || end > input_length || end < start)
    {
        printf("Invalid ending position.\n");
        free(input);
        return 1;
    }

    int substring_length = end - start;

    substring = (char *)malloc((substring_length + 1) * sizeof(char));
    if (substring == NULL)
    {
        printf("malloc failed\n");
        free(input);
        return 1;
    }

    for (int i = 0; i < substring_length; i++)
    {
        substring[i] = input[start + i];
    }
    substring[substring_length] = '\0';

    printf("Substring (%d,%d) of the string \"%s\" is \"%s\".\n", start, end, input, substring);

    free(input);
    free(substring);

    return 0;
}