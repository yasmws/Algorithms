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

int find(List* l, int it){

    int contador=0, i=0;

    Link* temp = (Link *) malloc (1*sizeof(Link));
    temp = l->curr;

    printf("preparação...");

    moveToStart(l);
    for (i = 0; i < (l->cnt); i++)
    {
        if(it == l->curr->next->element){
            contador++;
        }
        next(l);
    }

    l->curr=temp;

    printf("elementos: %d %d", l->curr->next->element, temp->next->element);

    return contador;
} 

void painelDeControle(){        //chamada de funções
   
    int it, i=0;
    int n, c;
    int count=0, count2=0;

    printf("Entrei");

    List* l= create_list();

    printf("\nCriei a lista...");
    
    scanf("%d", &c);
    
    do{

    scanf("%d", &n);
    printf("Caso %d:", count2+1);

        do{
            char instruction[10]; int number;
            scanf("%s", instruction);
            
            if(strcmp(instruction, "insert")==0){
                scanf("%d", &it);
                insert(l, it);
               
            }else if (strcmp(instruction, "remove")==0)
            {
               int removido = removed(l);
               printf("%d", removido);
               
            }else if(strcmp(instruction, "count")==0)
            {   
                scanf("%d", &it);
                printf("contando...");
                int contador = find(l, it);
                printf("\n%d", contador);

            }else if (strcmp(instruction, "prev")==0)
            {
                prev(l);
            }else if (strcmp(instruction, "next")==0)
            {
                next(l);
            }else if (strcmp(instruction, "exit")==0)
            {
                count = n+1; count2 = c+1;
            }

            count++;

        }while(count<n);

        count2++;

    } while ((count2)<c);

    free(l);

}

int main(){

    painelDeControle();

    return 0;
}