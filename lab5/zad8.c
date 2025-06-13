#include <stdio.h>
#include <stdlib.h>

typedef struct Elem
{
    int val;
    struct Elem *next;
} Elem;

Elem *input_list();
void print_list(Elem *lst);
void add_to_end(Elem *lst, int v);
void free_list(Elem *lst);
Elem *transpose(Elem *lst);

int main(void)
{
    Elem *list = NULL;
    int v;
    int len = 0;

    printf("Entering the list...\n");

    while (1)
    {
        printf("Enter an element (0-end) > ");
        scanf("%d", &v);
        if (v == 0)
            break;

        if (list == NULL)
        {
            list = (Elem *)malloc(sizeof(Elem));
            list->val = v;
            list->next = NULL;
        }
        else
        {
            add_to_end(list, v);
        }
        len++;
    }

    if (len == 0 || len % 2 != 0)
    {
        printf("\nError: The list must be non-empty and contain an even number of elements!\n");
        free_list(list);
        return 1;
    }

    printf("\nThe input list: ");
    print_list(list);

    list = transpose(list);

    printf("\n\nThe modified list: ");
    print_list(list);

    printf("\n");

    free_list(list);

    return 0;
}

void print_list(Elem *lst)
{
    while (lst != NULL)
    {
        printf("%d ", lst->val);
        lst = lst->next;
    }
}

void add_to_end(Elem *lst, int v)
{
    while (lst->next != NULL)
    {
        lst = lst->next;
    }
    Elem *new_elem = (Elem *)malloc(sizeof(Elem));
    new_elem->val = v;
    new_elem->next = NULL;
    lst->next = new_elem;
}

void free_list(Elem *lst)
{
    Elem *tmp;
    while (lst != NULL)
    {
        tmp = lst;
        lst = lst->next;
        free(tmp);
    }
}

Elem *transpose(Elem *lst)
{
    if (lst == NULL || lst->next == NULL)
    {
        return lst;
    }

    Elem *first = lst;
    Elem *second = lst->next;

    first->next = transpose(second->next);

    second->next = first;

    return second;
}