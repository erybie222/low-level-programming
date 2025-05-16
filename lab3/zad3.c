#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *input = NULL;
    char *output = NULL;
    int count = 0;

    input = (char *)(malloc(19 * sizeof(char) + 1));

    if (input == NULL)
    {
        printf("malloc failed \n");
        return 1;
    }

    printf("Enter the string (max. 19 chars) > ");
    scanf("%19s", input);
    printf("\n");

    for (int i = '0'; input[i] != '\0'; i++)
    {
        if (!(input[i] >= '0' && input[i] <= '9'))
        {
            count += 1;
        }
    }

    output = (char *)(malloc(sizeof(char) * count + 1));
    if (output == NULL)
    {
        printf("malloc failed\n");
        free(input);
        return 1;
    }

    int j = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (!(input[i] >= '0' && input[i] <= '9'))
        {
            output[j] = input[i];
            j++;
        }
    }

    output[j] = '\0';

    printf("Output string: %s\n", output);

    free(input);
    free(output);

    return 0;
}