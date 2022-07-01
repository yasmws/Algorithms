#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

typedef struct list
{
    int maxSize;
    int listSize;
    int curr;
    int* listArray;

}List;

List* create_list(int size){
    List* l = (List*) malloc(sizeof(List));
        if (l==NULL)
        {
        printf("Problema na alocação de l");
        }
    l->maxSize = size;
    l->curr = 0;
    l->listSize = l->curr;
    l->listArray = (int*) malloc (size*sizeof(int));
        if ((l->listArray)==NULL)
        {
            printf("Probelma na analocação de l->listArray");
        }
    return l;
}

List* realloc_list(List* l, int size){

    l->maxSize = size;
    l->listArray = (int*) malloc ((size*2)*sizeof(int));
        if ((l->listArray)==NULL)
        {
            printf("Probelma no realloc de l->listArray");
        }
    return l;
}


void insert(List* l, int size, int item){
    int i=0;

    l= realloc_list(l, size);

    if(l->listSize >= l->maxSize){
        printf("Error");
    }

    i = l->listSize;

    while (i>l->curr) 
    {
        l->listArray[i] = l->listArray[i-1]; 
        i--;
    }
    l->listArray[l->curr]=item;
    l->listSize++;
}

void moveToStart(List* l){
    l->curr = 0;
}

void moveToEnd(List* l){
    l->curr = l->listSize;
}

void prev(List* l){
    if (l->curr != 0)
    {
        l->curr--;
    }
}

void next(List* l){
    if (l->curr < l->listSize)
    {
        l->curr++;
    }
}

int length(List* l){

    return l->maxSize;
}

int getValue(List* l){
    
    return l->listArray[l->curr];
}

int currPos(List* l){

    int currPos = (l->curr)+1;

    return currPos;
}

int find(List* l, int k ){
    int countingK=0;

    moveToStart(l);
    while(currPos(l)<length(l)){
        if (k==getValue(l))
        {
           countingK++;
        }
        next(l);
    }
    return countingK;
}

int remover(List* l){

    moveToStart(l);

    if(l->curr<0 || l->curr>= l->listSize){
        return 0;
    }
    int it = l->listArray[l->curr];
    int i=0;
    for(i = l->curr; i < ((l->listSize)-1) ; i++)
    {
         l->listArray[i]=l->listArray[i+1];
    }
    l->listSize--;
    return it;
}


int main(){
    int size = 10;
    List* l= create_list(size); //criando lista com size=1
    int n, c;
    int count=0, count2=0;

    scanf("%d", &c);

    do{

    scanf("%d", &n);
    printf("Caso %d:", count2+1);

        do{
            char instruction[10]; int number;
            scanf("%s %d", instruction, &number);
            
            if(strcmp(instruction, "insert")==0){
                insert(l, size, number);
                size++;
                printf("%d", size);
            }else if (strcmp(instruction, "remove")==0)
            {
                int removido = remover(l);
            }else if(strcmp(instruction, "count")==0)
            {
                printf("%d", find(l, number));//???
            }else if (strcmp(instruction, "prev")==0)
            {
                prev(l);
            }else if (strcmp(instruction, "next")==0)
            {
                next(l);
            }

            count++;

        }while(count<n);

        count2++;

    } while ((count2)<c);

    return 0;

}