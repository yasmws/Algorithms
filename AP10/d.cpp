#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

typedef struct link{
    int element;
    struct link *next;
}Link;

typedef struct list{
    Link* head;
    Link* tail;
    Link* curr;
    int cnt;
}List;

Link* create_link2(int it, Link* nextvalue){
    Link* n = (Link *) malloc (1*sizeof(Link));
    n->element = it;
    n->next = nextvalue;
    return n;
}

Link* create_link(Link* nextvalue){
    Link* n = (Link *) malloc (1*sizeof(Link));
    if(n==NULL){printf("Tudo errado no link");}

    n->next = nextvalue;
    return n;
}

List* create_list(){

    List* l = (List *) malloc (1*sizeof(List));
    if(l==NULL){printf("\nTudo errado na lista");}

    l->head = create_link(NULL); //header node
    l->tail = l->head;
    l->curr = l->tail;
    l->cnt = 0;
    return l;
}

void insert(List* l, int it){
    l->curr->next = create_link2(it, l->curr->next);
    if(l->tail == l->curr){
        l->tail = l->curr->next;
    }
    l->cnt++;

    printf("%d %d", l->cnt, l->curr->next->element);
}

void moveToStart(List* l){
    l->curr = l->head;
}

int getValue(List* l){
}

void prev(List* l){

    if(l->curr != l->head){
        Link* temp = l->head;
        while(temp->next !=l->curr){
            temp = temp->next;
        }
        l->curr = temp;
    }
}

void next(List* l){
    if(l->curr->next !=l->tail){
        l->curr = l->curr->next;
    }
}

int removed(List* l){

    if(l->curr->next == NULL){
        printf("Entrei aqui");
        return 0;
    }
    Link* temp = l->curr->next;
    int it = l->curr->next->element;
    printf("elementos: %d%d", it, l->curr->next->element);
    if(l->tail == l->curr->next){
        l->tail = l->curr;
    }else l->curr->next = l->curr->next->next;
    free(temp);
    l->cnt--;
    return it;
}

int main(){
    int n, m, linhas, colunas;
    scanf("%d %d", &n, &m);
    Graph* g = create_graph(n);

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &linhas, &colunas);
        setEdge(g, linhas, colunas);
    }

    printMatrix(g);//matrix ok

    graphTransverse(g);

    
}