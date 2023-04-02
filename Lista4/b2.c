#include<stdio.h>
#include<stdlib.h>
#define TAM 100

typedef struct heap{
    int *array;
    int count;
}Heap;

Heap *CreateHeap(){
    Heap *h = (Heap *) malloc(sizeof(Heap)); 
    if(h == NULL){
        printf("Erro na aloc da heap");
    }

    h->count=0;
    h->array = (int *) malloc(TAM*sizeof(int)); 
    if ( h->array == NULL){
        printf("Erro na aloc do array da heap");
        return;
    }
    return h;
}

void insert(Heap *h, int k){

    if( h->count < TAM){
        h->array[h->count] = k;
        heapify_bottom_top(h, h->count);
        h->count++;
    }
}

void heapify_top_bottom(Heap *h, int parent_node){
    int left = parent_node*2+1;
    int right = parent_node*2+2;
    int min;
    int temp;

    if(left >= h->count || left <0)
        left = -1;
    if(right >= h->count || right <0)
        right = -1;

    if(left != -1 && h->arr[left] < h->arr[parent_node])
        min=left;
    else
        min =parent_node;
    if(right != -1 && h->arr[right] < h->arr[min])
        min = right;

    if(min != parent_node){
        temp = h->arr[min];
        h->arr[min] = h->arr[parent_node];
        h->arr[parent_node] = temp;

        heapify_top_bottom(h, min);
    }
}

void removeMin(Heap *h){
    int min;

    if(h->count==0){
        printf("Não tem nada na heap");
        return -1;
    }
    
    min = h->arr[0];
    h->arr[0] = h->arr[h->count-1];
    h->count--;
    heapify_top_bottom(h, 0);

    printf("removeMin");
}

int parent(int index){
    return((index-1)/2);
}


Heap* insert(Heap* h, int num){

    if (h->count >= TAM)
    {
        printf("heap cheia");
        return h;
    }

    h->count++;
    h->array[h->count-1] = num;

    int index = h->count-1;
    while (index>0 && h->array[parent(index)]>h->array[index])
    {
        int temp = h->array[parent(index)];
        h->array[parent(index)] = temp;
        index = parent(index);
    }
    return h;    
}

Heap* removeMin(Heap* h){

    if ( !heap )
    {
        /* code */
    }

    return h;
    
} 

Heap* getMin(Heap* h, int num){
    return h;
}

int main(){
    int i;
    Heap* h = create_heap(); //Min Heap

    int n, count=0, num=0;
    char string[10];
    scanf("%d", &n);
    while (n>count)
    {
        scanf("%s", string);
        if (strcmp(string, "insert")==0)
        {
            scanf("%d", num);
            insert(h, num);//inserir min na heap de maneira topBottom
        }else if (strcmp(string, "getMin")==0)
        {
            //faz o possível p que o num seja o minimo
            scanf("%d", num);
            getMin(h, num);
        }else if (strcmp(string, "removeMin")==0)
        {
            removeMin();
        }
        count++;
    }

    return 0;
}