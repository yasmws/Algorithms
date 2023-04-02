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

void painelDeControle(int *a, int n)
{
    Stack *s = create_stack();
    int flag = 0, i = 1, j = 0;
    int b[1001] = {};

    while(i<=n)
    {   
        if(a[j]==i){ //printf("a");
            b[i]=a[j];
            i++; 
            if(j<n){
                j++;
            }
        }else if(s->top->element==i && s->size!=0){ //printf("b");
            b[i] = s->top->element;
            pop(s);
            i++;
        }else if(j<n){ //printf("c");
            push(s, a[j]);
            j++;
        }else i = n+1;
        
    }

    for (i = 1; i<=n; i++)
    {
        if(b[i]!=i){flag=1;}
        //printf("%d", b[i]);
    }//printf("\n");
    

    if (flag == 1)
    {
        printf("no\n");
    }
    else
        printf("yes\n");

    clear(s);
}

int main()
{

    int flag = 0, i;

    while (flag == 0)
    {
        int n, m, a[1001];
        scanf("%d", &n);
        if (n != 0)
        {
            for (i = 0; i < n; i++)
            {
                scanf("%d", &m);
                a[i] = m;
            }
            painelDeControle(a, n);
        }
        else
            flag = 1;
    }

    return 0;
}
