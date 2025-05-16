#include <stdio.h>
#include <stdlib.h>

typedef struct Elem *ElemRef;
typedef struct Elem
{
    int val;
    ElemRef next;
} Elem;

int main()
{
    int n, v;
    ElemRef b = NULL, p = NULL, e;

    printf("Enter the length of the list > ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter an element > ");
        scanf("%d", &v);

        e = (ElemRef)malloc(sizeof(Elem));
        if (e == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }
        e->val = v;
        e->next = NULL;

        if (p != NULL)
            p->next = e;
        else
            b = e;
        p = e;
    }

    printf("\nEnter the element to be added > ");
    scanf("%d", &v);

    e = (ElemRef)malloc(sizeof(Elem));
    if (e == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    e->val = v;
    e->next = NULL;
    if (p != NULL)
        p->next = e;
    else
        b = e;

    printf("\nThe list: ");
    ElemRef temp = b;
    int i = 0;
    while (temp != NULL && i < n)
    {
        printf("%d ", temp->val);
        temp = temp->next;
        i++;
    }

    printf("\nThe extended list: ");
    temp = b;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        e = temp;
        temp = temp->next;
        free(e);
    }

    printf("\n");
    return 0;
}