#include <stdio.h>
#include <stdlib.h>

typedef struct Elem *ElemRef;
typedef struct Elem
{
    int val;
    ElemRef next;
} Elem;

int main(void);

int main(void)
{
    int i, n;
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
    printf("\nThe list: ");
    while (b)
    {
        printf("%d ", b->val);
        e = b;
        b = b->next;
        free(e);
    }
    return 0;
}