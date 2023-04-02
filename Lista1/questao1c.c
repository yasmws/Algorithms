#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "math.h"

typedef struct link
{
    char element;
    struct link *next;
} Link;

typedef struct list
{
    Link *head;
    Link *tail;
    Link *curr;
    int cnt;
} List;

Link *create_link2(char it, Link *nextvalue)
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

List *create_list()
{

    List *l = (List *)malloc(1 * sizeof(List));
    if (l == NULL)
    {
        printf("\nTudo errado na lista");
    }

    l->head = create_link(NULL); // header node
    l->tail = l->head;
    l->curr = l->tail;
    l->cnt = 0;
    return l;
}

void insert(List *l, char it)
{
    l->curr->next = create_link2(it, l->curr->next);
    if (l->tail == l->curr)
    {
        l->tail = l->curr->next;
    }
    l->cnt++;
}

void moveToStart(List *l)
{
    l->curr = l->head;
}

void moveToEnd(List *l)
{
    l->curr = l->tail;
}

void next(List *l)
{
    if (l->curr->next != l->tail)
    {
        l->curr = l->curr->next;
    }
}

List* beijuText(List* l, char* entrada){
    
    int i=0; int tam=strlen(entrada);
    while (i<tam)
    {
        if(entrada[i]==']'){
            moveToStart(l);
        }else if(entrada[i]=='['){
            moveToEnd(l);
        }else{
            insert(l, entrada[i]);
        }
        i++;
    }

    return l;
}

void printText(List *l)
{ // ok

    moveToStart(l);
    char saida[100001];
    int i; 

    for (i = 0; i < l->cnt; i++)
    {
        saida[i] = l->curr->next->element;
        next(l);
    }

    while (i > 0)
    {
        i--;
        printf("%c", saida[i]);
    }

    printf("\n");
}

void painelDeControle()
{

    int flag = 1;
    char entrada[100001];

    do
    {
        List *l = create_list();
        if (scanf("%s", entrada) != EOF)
        {
            l = beijuText(l, entrada);
            printText(l);
            free(l);
        }
        else
            flag = -1;

    } while (flag > 0);
}

int main()
{

    painelDeControle();

    return 0;
}