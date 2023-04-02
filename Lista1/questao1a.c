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

void prev(List *l)
{

    if (l->curr != l->head)
    {
        Link *temp = l->head;
        while (temp->next != l->curr)
        {
            temp = temp->next;
        }
        l->curr = temp;
    }
}

void next(List *l)
{
    if (l->curr->next != l->tail)
    {
        l->curr = l->curr->next;
    }
}

void bei(List *l, char *entrada, int i, int j)//i=[//j=]
{

    int k = 0, p = 0;

    for (k = i+1; k < j; k++)
    {
        if (entrada[k] == '[')
        {
            for (p = k+1; p<j ; p++)
            {
                if (entrada[p] == ']')
                {
                    bei(l, entrada, p, j);
                }
                else if(entrada[p]!=' '){
                    insert(l, entrada[p]); entrada[p]=' '; entrada[k]=' ';
                }
            }
        }
        else if(entrada[k]!=' '){
            insert(l, entrada[k]); entrada[k]=' '; entrada[i]=' '; entrada[j]=' ';
        }
    }
}

void beiju(List *l, char *entrada, int i)
{ // 5

    int j = 0, flag = 1;

    for (j = i + 1; j < strlen(entrada); j++)//encontrando o mais perto
    {
        if (entrada[j] == ']')
        {
            bei(l, entrada, i, j);
        }
    }
}

List *beijuText(List *l, char *entrada)
{

    int i = 0, flag = -1;

    while (i < strlen(entrada)) // pegar o que está dentro do []
    {
        if (entrada[i] == '[')
        {                       
            //printf("%c", entrada[i]);  // tem ]?
            beiju(l, entrada, i); // 5
            flag = 0;
        }
        i++;
    }

    i = 0;
    while (i < strlen(entrada)) // pegar o que está fora do []
    {
        if(entrada[i]!=' '){
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
    int i; // printf("%d", l->cnt);

    for (i = 0; i < l->cnt; i++)
    {
        saida[i] = l->curr->next->element;
        // printf("%c", l->curr->next->element);
        next(l);
    }

    //printf("%d", i);

    while (i > 0)
    {
        i--;
        printf("%c", saida[i]);
    }

    printf("\n");
}

void painelDeControle()
{ // chamada de funções

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