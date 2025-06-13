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
    int v;
    struct Elem *b = NULL, *p = NULL, *e;

    printf("Entering the list...\n");
    do
    {
        printf("Enter an element (0-end) > ");
        (void)scanf("%d", &v);
        if (v)
        {
            e = (ElemRef)malloc(sizeof(Elem));
            if (e)
            {
                e->val = v;
                e->next = NULL;
                if (p)
                    p->next = e;
                else
                    b = e;
                p = e;
            }
        }
    } while (v);

    // Print original list
    printf("\nThe input list: ");
    for (e = b; e; e = e->next)
        printf("%d ", e->val);
    printf("\n");

    // Modify the list
    struct Elem *curr = b;
    while (curr && curr->next)
    {
        curr->val += curr->next->val;

        struct Elem *to_delete = curr->next;
        curr->next = to_delete->next;
        free(to_delete);

        curr = curr->next;
    }

    // Print modified list
    printf("The modified list: ");
    while (b)
    {
        printf("%d ", b->val);
        e = b;
        b = b->next;
        free(e);
    }
    printf("\n");

    return 0;
}