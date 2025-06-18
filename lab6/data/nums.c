#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("numbers1.bin", "w");
    if (file == NULL)
    {
        printf("Could not create the file.\n");
        return 1;
    }

    // Dane do zapisania
    int data[] = {480, 621, 918, 462, 943};
    int n = sizeof(data) / sizeof(data[0]);

    // Zapis danych jako tekst oddzielony spacjami
    for (int i = 0; i < n; ++i)
    {
        fprintf(file, "%d ", data[i]);
    }

    fclose(file);
    printf("File 'numbers1.bin' has been created.\n");
    return 0;
}