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
int last_but_one(Elem *lst);

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

    printf("\nThe list: ");
    print_list(list);

    if (len >= 2)
    {
        int result = last_but_one(list);
        printf("\nThe last but one element of the list: %d.\n", result);
    }
    else
    {
        printf("\nThe list must contain at least two elements!\n");
    }

    free_list(list);

    return 0;
}

Elem *input_list()
{
    return NULL;
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

int last_but_one(Elem *lst)
{
    if (lst->next != NULL && lst->next->next == NULL)
    {
        return lst->val;
    }
    else
    {
        return last_but_one(lst->next);
    }
}