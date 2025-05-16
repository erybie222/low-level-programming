#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *input = NULL;
    char *prefix = NULL;
    int prefix_length;

    input = (char *)malloc(19 * sizeof(char) + 1);
    if (input == NULL)
    {
        printf("malloc failed\n");
        return 1;
    }

    printf("Enter the string (max. 19 chars) > ");
    scanf("%19s", input);
    printf("\n");

    printf("Enter the prefix length (max. 19) > ");
    scanf("%d", &prefix_length);

    if (prefix_length < 0 || prefix_length > strlen(input))
    {
        printf("Invalid prefix length.\n");
        free(input);
        return 1;
    }

    prefix = (char *)malloc((prefix_length + 1) * sizeof(char));
    if (prefix == NULL)
    {
        printf("malloc failed\n");
        free(input);
        return 1;
    }

    strncpy(prefix, input, prefix_length);
    prefix[prefix_length] = '\0';

    printf("Prefix (%d-character) of the word \"%s\" is \"%s\".\n",
           prefix_length, input, prefix);

    free(input);
    free(prefix);

    return 0;
}