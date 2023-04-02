#include "stdio.h"
#include "stdlib.h"
#include "math.h"

void swap(long long int *a, long long int *b){

    long long int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


long long int partition(long long int *a, long long int l, long long int r) {
  
  long long int p = a[l]; //p - pivot
  long long int i = l;
  long long int j = r+1;
    
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


void quicksort(long long int *a, long long int l, long long int r){

    if (l<r)
    {
        long long int s = partition(a, l, r);
        quicksort(a, l, s-1);
        quicksort(a, s+1, r);
    }
}

long long int* create(long long int n){

    long long int* a= (long long int*) malloc(n*sizeof(long long int));
    if(a == NULL){
        printf("PROBLEMA NA ALOCACAO");
    }
    return a;
}

int main(){

long long int total=0;    

long long int n, i; scanf("%lld", &n);//numero de chocolates
long long int *a = create(n);  long long int *temp = create(n);

for (i = 0; i <n; i++)
{
    scanf("%lld", &a[i]);
    total += a[i]; 
}quicksort(a, 0, i-1);

long long int m; scanf("%lld", &m);//numero de cupons
long long int *q= create(m);

for (long long int j = 0; j <m; j++)
{
    scanf("%lld", &q[j]);
    if(q[j]<=n){
    printf("%lld\n", total - a[ i - q[j] ]);
    }else printf("%lld\n", total);

}

free(a); 
free(temp); 
free(q);

    return 0;
}