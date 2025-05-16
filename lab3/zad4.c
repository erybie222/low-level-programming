#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *input = NULL;
    char *substring = NULL;
    int position = 0;
    char *output = NULL;

    input = (char *)malloc(20 * sizeof(char));
    if (input == NULL)
    {
        printf("Malloc failed.\n");
        return 1;
    }

    substring = (char *)malloc(20 * sizeof(char));
    if (substring == NULL)
    {
        printf("Malloc failed.\n");
        free(input);
        return 1;
    }

    printf("Enter the string (max. 19 chars) > ");
    scanf("%19s", input);

    printf("Enter the substring (max. 19 chars) > ");
    scanf("%19s", substring);

    printf("Enter the position before the substring is inserted (max. 9) > ");
    scanf("%d", &position);

    int len_input = strlen(input);
    int len_substring = strlen(substring);
    int len_output = len_input + len_substring;

    output = (char *)malloc(sizeof(char) * (len_output + 1));
    if (output == NULL)
    {
        printf("Malloc failed.\n");
        free(input);
        free(substring);
        return 1;
    }

    int i = 0;
    for (; i < position && input[i] != '\0'; i++)
    {
        output[i] = input[i];
    }

    int j = 0;
    for (; substring[j] != '\0'; j++)
    {
        output[i + j] = substring[j];
    }

    int k = 0;
    for (; input[position + k] != '\0'; k++)
    {
        output[i + j + k] = input[position + k];
    }

    output[i + j + k] = '\0';

    printf("Output string: \"%s\"\n", output);

    free(input);
    free(substring);
    free(output);
    return 0;
}