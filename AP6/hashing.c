#include "stdio.h"
#include "stdlib.h"
#include "math.h"

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

int h(int x){
    return (x%10);
}

typedef struct dictionary 
{
    int m;              //size of the hash table
    int cnt;            //number of elem. in the dictionary
    List* H;            //hash table as an array of lists
    int (*h)(int);      //hash function
}Dictionary;


void clear(Dictionary* d){

}

int remove(Dictionary* d, int(*h)()){

}

int removeAny(Dictionary* d){

}

int find(Dictionary* d, int(*h)()){

}

int size(Dictionary* d){

}


void insert(Dictionary d, , int e){
    List* l = create_list();

    if (find(d, k) == NULL)
    {
        pos = d.h(k); //h is the pash function
        l = d.H[pos]; //H is the hash table
        entry = create_entry(k, e);
        append(l, entry);
    }
    
}

Dictionary* create_dict(int size,  int(*h)()){

    Dictionary* d = (Dictionary*) malloc(sizeof(Dictionary)*1);
    if(d==NULL){printf("Tudo errado no malloc");}

    d.m = size;
    d.cnt = 0;
    d.H = create_list(size);
    for (int i = 0; i <size-1; i++)
    {
        d.H[i] = create_list();//lista de entradas, entradas é um tipo feito de chaves e valores, pares
    }
    d.h = int(*h)();
    
    return d;
}


int main(){

    int n;
    scanf("%d", n);
    Dictionary* d = create_dict(n, h);


    return 0;
}