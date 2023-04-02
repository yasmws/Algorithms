#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

typedef struct link
{
    int element;
    struct link *next;
} Link;

typedef struct stack
{
    Link *top;
    int size;

} Stack;

Link *create_link2(int it, Link *nextvalue)
{
    Link *n = (Link *)malloc(1 * sizeof(Link));
    n->element = it;
    n->next = nextvalue;
    return n;
}

Link *create_link(Link *nextvalue)
{
    Link *n = (Link *)malloc(1 * sizeof(Link));
    if (n == NULL)
    {
        printf("Tudo errado no link");
    }

    n->next = nextvalue;
    return n;
}

Stack *create_stack()
{

    Stack *s = (Stack *)malloc(1 * sizeof(Stack));
    if (s == NULL)
    {
        printf("\nTudo errado na lista");
    }

    s->top = create_link(NULL);
    s->size = 0;
    return s;
}

void clear(Stack *s)
{
    free(s);
}

void push(Stack *s, int it)
{
    s->top = create_link2(it, s->top);
    s->size++;
}

int pop(Stack *s)
{

    if (s->top == NULL)
    {
        printf("Error");
        return -1;
    }
    int it = s->top->element;
    s->top = s->top->next;
    s->size--;
    return it;
}

void imprimirStack(Stack *s)
{
    int tam = s->size;
    for (int i = 0; i < tam; i++)
    {
        printf("%d", s->top->element);
        pop(s);
    }
}

void painelDeControle(int *a, int n)
{
    /*Thus, the love mobile that enters
    the side street last must necessarily
    leave the side street first(stack). Because
    the trucks and the ravers move up closely,
    a truck cannot drive back and re-enter the
    side street or the approach street.*/

    Stack *s = create_stack();
    int flag = 0, i = 0, j = 0;

    for (i = 0; i<n; i++)
    {
       flag=0;
       for (j = 0; j<n || flag>0; j++)
       {
           /*if(s->top->element == i){
               pop(s);
           }else if(a[j]==i){
               push(s, a[j]);
               flag = 1;
           }*/
       }
    }

    if (flag == 1)
    {
        printf("no\n");
    }
    else
        printf("yes\n");

    imprimirStack(s);

    clear(s);
}

int main()
{

    int flag = 0, i;

    while (flag == 0)
    {
        int n, m, a[1001];
        scanf("%d\n", &n);
        if (n != 0)
        {
            for (i = 0; i < n; i++)
            {
                scanf(" %d", &m);
                a[i] = m;
            }
            painelDeControle(a, n);
        }
        else
            flag = 1;
    }

    return 0;
}
