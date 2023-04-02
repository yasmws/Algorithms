#include "stdio.h"
#include "stdlib.h"
#include "math.h"

void swap(int *a, int *b){

    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *a, int l, int r){

    int p = a[l]; //p - pivot
    int i = l;
    int j = r+1;

    do
    {
        do
        {
           i = i+1;
        }while(a[i]<p && i<r);

        do
        {
            j = j-1; 
        }while(a[j]>p);
        
        swap(&a[j], &a[i]); 
    }while(i<j);

    swap(&a[i], &a[j]);
    swap(&a[l], &a[j]);

    return j;

}

void quicksort(int *a, int l, int r){

    if (l<r)
    {
        int s = partition(a, l, r);
        quicksort(a, l, s-1);
        quicksort(a, s+1, r);
    }
}

int* create(int n){

    int* a= (int*) malloc(n*sizeof(int));
    if(a == NULL){
        printf("PROBLEMA NA ALOCACAO");
    }
    return a;
}


int main(){

    int n; scanf("%d", &n);
    int *a = create(n); int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    quicksort(a, 0, i-1);

    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    
    return 0;
}