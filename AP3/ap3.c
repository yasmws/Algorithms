#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

typedef struct link{
    int element;
    struct link *next;
}Link;

typedef struct stack{
    Link* top;
    int size;

}Stack; 

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

Stack* create_stack(){

    Stack* s = (Stack *) malloc (1*sizeof(Stack));
    if(s==NULL){printf("\nTudo errado na lista");}

    s->top = create_link(NULL);
    s->size = 0;
    return s;
}


void clear(Stack* s){
    free(s);
}

void push(Stack* s, int it){
    s->top = create_link2(it, s->top);
    s->size++;

    //printf("%d %d\n", s->top->element, s->top->next->element);
}

int pop(Stack* s){
    
    if (s->top == NULL){
        printf("Error"); return -1;
    }
    int it = s->top->element;
    s->top = s->top->next;
    s->size--;
    return it;
}


int topValue(Stack* s){
    return s->top->element;
}

int lenght(Stack* s){
    return s->size;
}

void painelDeControle(){        //chamada de funções
   
    int it, i=0;
    int c=0;
    int count=1, count2=0;

    printf("Entrei");

    Stack* s= create_stack();

    printf("\nCriei a pilha...");
    
    scanf("%d", &c); 

    do{
        count2++; count = 0;
        printf("Caso %d:", count2);
        
        do{
            char instruction[10];
            scanf("%s", instruction);
            
            if (strcmp(instruction, "pop")==0)
            {   
                int num=0, soma=0;
                scanf("%d", &num);
                for(i=0; i<num; i++)
                {   
                    soma += pop(s);
                }
                printf("%d", soma);

            }else if (strcmp(instruction, "push")==0)
            {   
                scanf("%d", &it);
                push(s, it);
            }else if (strcmp(instruction, "end")==0)
            {   
                printf("%d %d", lenght(s), topValue(s));
                
                count = -1;
            }else if(strcmp(instruction, "exit")==0)
            {
                count=-1; count2 = c;
            }

        }while (count>-1);
        
    }while (count2<c);

    clear(s);

}

int main(){

    painelDeControle();
    return 0;
}