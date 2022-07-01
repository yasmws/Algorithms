#include<stdio.h>
#include<stdlib.h>
#include "stdbool.h"
#include "string.h"
#include "math.h"
#define TAM 100

typedef struct heap{
    int *array;
    int count;
}Heap;

Heap *createHeap(){
    Heap *h = (Heap *) malloc(sizeof(Heap)); 
    if(h == NULL){
        printf("Erro na aloc da heap");
    }

    h->count=0;
    h->array = (int *) malloc(TAM*sizeof(int)); 
    if ( h->array == NULL){
        printf("Erro na aloc do array da heap");
    }

    printf("aaa");
    return h;
}

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

int left(int i){
    return 2*i +1;
}

int right(int i){
    return 2*i+2;
}

void heapify(Heap* h, int index){
    int l = left(index);
    int r = right(index);
    int min =0;

    if(l<= h->count && h->array[l] < h->array[index]){
        min = l;
    }else min = index;

    if (r<= h->count && h->array[r] < h->array[min]);
    {
        min = r;
    }

    if (min!=index)
    {
        swap(&h->array[index], &h->array[min]);
        heapify(h, min);
    }
}

void insert(Heap* h, int num){

    printf("ccc");
    if (h->count < TAM)
    {
        h->array[h->count] = num;
        h->count++;
        //heapify(h, h->count);
    }
    //printf("y:%d %d", h->array[h->count], h->count);
}

/*void removeMin(Heap* h, int num){

    if (h->count > 0)
    {

        h->count--;
    }

    heapify(h, )
    
}

void getMin(Heap* h, int num){

    if (num <  h->array[0])
    {
        insert(h, )
    }
    
}*/

int main(){
    Heap* h = createHeap(); //Min Heap//TopDown Construction

    int n=0, count=0, num=0;
    char string[10];
    scanf("%d", &n);
    while (n>=count)
    {
        scanf("%s", string);
        if (strcmp(string, "insert")==0)
        {
            scanf("%d", &num);
            insert(h, num);//inserir min na heap de maneira topBottom
        }/*else if (strcmp(string, "getMin")==0)
        {
            //faz o possível p que o num seja o minimo
            scanf("%d", num);
            getMin(h, num);
        }else if (strcmp(string, "removeMin")==0)
        {
            removeMin();
        }*/
        count++;
    }

    return 0;
}