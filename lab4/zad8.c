#include <stdio.h>
#include <stdlib.h>

typedef struct Elem *ElemRef;
typedef struct Elem
{
    int val;
    ElemRef next;
} Elem;

int main(void)
{
    int n, value;

    ElemRef head = NULL, tail = NULL, new_elem;

    printf("Enter the length of the list > ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter an element > ");
        scanf("%d", &value);

        new_elem = (ElemRef)malloc(sizeof(Elem));
        new_elem->val = value;
        new_elem->next = NULL;

        if (tail)
            tail->next = new_elem;
        else
            head = new_elem;

        tail = new_elem;
    }

    printf("\nThe input list: ");
    for (ElemRef e = head; e != NULL; e = e->next)
        printf("%d ", e->val);
    printf("\n");

    int new_value, position;
    printf("\nEnter a new element > ");
    scanf("%d", &new_value);

    printf("Enter the position of the element > ");
    scanf("%d", &position);

    ElemRef extended_head = NULL, extended_tail = NULL;
    ElemRef current = head;
    int index = 0;

    while (current != NULL)
    {
        if (index == position)
        {
            ElemRef inserted = (ElemRef)malloc(sizeof(Elem));
            inserted->val = new_value;
            inserted->next = NULL;

            if (extended_tail)
                extended_tail->next = inserted;
            else
                extended_head = inserted;

            extended_tail = inserted;
        }

        ElemRef copy = (ElemRef)malloc(sizeof(Elem));
        copy->val = current->val;
        copy->next = NULL;

        if (extended_tail)
            extended_tail->next = copy;
        else
            extended_head = copy;

        extended_tail = copy;

        current = current->next;
        index++;
    }

    if (position == index)
    {
        ElemRef inserted = (ElemRef)malloc(sizeof(Elem));
        inserted->val = new_value;
        inserted->next = NULL;

        if (extended_tail)
            extended_tail->next = inserted;
        else
            extended_head = inserted;

        extended_tail = inserted;
    }

    printf("\nThe extended list: ");
    for (ElemRef e = extended_head; e != NULL; e = e->next)
        printf("%d ", e->val);
    printf("\n");

    while (head)
    {
        ElemRef temp = head;
        head = head->next;
        free(temp);
    }

    while (extended_head)
    {
        ElemRef temp = extended_head;
        extended_head = extended_head->next;
        free(temp);
    }

    return 0;
}