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

Elem *append_recursive(Elem *lst1, Elem *lst2)
{
    if (lst1 == NULL)
    {
        return lst2;
    }
    lst1->next = append_recursive(lst1->next, lst2);
    return lst1;
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
    Elem *list1 = NULL;
    Elem *list2 = NULL;

    int x;

    printf("Entering the list 1:\n");
    do
    {
        printf("Enter an element (0=end) => ");
        scanf("%d", &x);
        if (x != 0)
        {
            append(&list1, x);
        }
    } while (x != 0);

    printf("Entering the list 2:\n");
    do
    {
        printf("Enter an element (0=end) => ");
        scanf("%d", &x);
        if (x != 0)
        {
            append(&list2, x);
        }
    } while (x != 0);

    printf("\nInput list 1: ");
    printList(list1);

    printf("\nInput list 2: ");
    printList(list2);

    list1 = append_recursive(list1, list2);

    printf("Output list: ");
    printList(list1);

    while (list1 != NULL)
    {
        Elem *temp = list1;
        list1 = list1->next;
        free(temp);
    }
    return 0;
}
