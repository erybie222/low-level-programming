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
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

Elem *duplicate(Elem *lst)
{
    if (lst == NULL)
        return NULL;

    Elem *copy = malloc(sizeof(Elem));
    copy->value = lst->value;
    copy->next = duplicate(lst->next);

    Elem *original_next = copy->next;

    Elem *dup = malloc(sizeof(Elem));
    dup->value = copy->value;
    dup->next = original_next;

    copy->next = dup;
    return copy;
}

void freeList(Elem *head)
{
    while (head != NULL)
    {
        Elem *temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    Elem *list = NULL;
    int x;

    printf("Entering the list...\n");
    do
    {
        printf("Enter an element (0=end) => ");
        scanf("%d", &x);
        if (x != 0)
        {
            append(&list, x);
        }
    } while (x != 0);

    printf("\nThe input list: ");
    printList(list);

    Elem *doubled = duplicate(list);

    printf("The \"doubled\" list: ");
    printList(doubled);

    freeList(list);
    freeList(doubled);

    return 0;
}