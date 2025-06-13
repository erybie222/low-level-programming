#include <stdio.h>
#include <stdlib.h>

typedef struct Elem
{
    int val;
    struct Elem *next;
} Elem;

Elem *input_list(int len);
void print_list(Elem *lst);
void add_to_end(Elem *lst, int v);
void free_list(Elem *lst);

int main(void)
{
    int len = 0;
    int v;

    printf("Entering the list...\n");

    Elem *list = NULL;

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

    printf("\n\nThe length of the list is %d.\n", len);

    free_list(list);

    return 0;
}

Elem *input_list(int len)
{

    Elem *list = NULL;
    int v;
    for (int i = 0; i < len; i++)
    {
        printf("Enter an element > ");
        scanf("%d", &v);
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
    }
    return list;
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