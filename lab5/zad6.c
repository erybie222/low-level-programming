#include <stdio.h>
#include <stdlib.h>

typedef struct Elem
{
    int value;
    struct Elem *next;
} Elem;

void append(Elem **head, int value)
{
    Elem *new_elem = malloc(sizeof(Elem));
    new_elem->value = value;
    new_elem->next = NULL;

    if (*head == NULL)
    {
        *head = new_elem;
    }
    else
    {
        Elem *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_elem;
    }
}

Elem *reverse_recursive(Elem *list)
{
    if (list == NULL || list->next == NULL)
        return list;
    Elem *new_head = reverse_recursive(list->next);

    list->next->next = list;
    list->next = NULL;
    return new_head;
}
void printList(Elem *head)
{
    Elem *current = head;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Elem *list = NULL;

    int x;

    printf("Entering the list:\n");
    do
    {
        printf("Enter an element (0=end) => ");
        scanf("%d", &x);
        if (x != 0)
        {
            append(&list, x);
        }
    } while (x != 0);

    printf("\nInput list 1: ");
    printList(list);

    list = reverse_recursive(list);

    printf("Output list: ");
    printList(list);

    while (list != NULL)
    {
        Elem *temp = list1;
        list = list1->next;
        free(temp);
    }
    return 0;
}
