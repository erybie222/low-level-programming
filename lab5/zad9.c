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

void fold(Elem *lst)
{
    if (lst == NULL || lst->next == NULL)
    {
        return;
    }
    if (lst->value == lst->next->value)
    {
        Elem *temp = lst->next;
        lst->next = lst->next->next;
        free(temp);
        fold(lst);
    }
    else
    {
        fold(lst->next);
    }
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

    printf("\nInput list: ");
    printList(list);
    fold(list);

    printf("Output list: ");
    printList(list);

    while (list != NULL)
    {
        Elem *temp = list;
        list = list->next;
        free(temp);
    }
    return 0;
}
