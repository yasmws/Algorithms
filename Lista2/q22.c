#include "stdio.h"
#include "stdlib.h"
#include "math.h"


void merge( int* a,  int* temp,  int l,  int r){
    
    for ( int i = l; i <=r; i++)
    {
        temp[i]=a[i];
    }
     int m = floor((l+r)/2);
     int i1 = l;  int i2 = m+1; 
    for ( int curr = l; curr<=r; curr++)
    {
        if (i1 == m+1)
        {
            a[curr] = temp[i2++];
        }else if (i2>r)
        {
            a[curr] = temp[i1++];
        }else if (temp[i1]<=temp[i2])
        {
            a[curr] = temp[i1++];
        }else a[curr] = temp[i2++];       
        
    }       
}

void mergesort2( int* a,  int* temp,  int l,  int r){
    
     int mid;
    if(l<r){
        mid = floor((l+r)/2);
        mergesort2(a, temp, l, mid);//left side
        mergesort2(a, temp, mid+1, r);//right side
        merge(a, temp, l, r);
    }
    
}

void discount( int* a,  int* q,  int i, int n){

      int total=0,j=0, count = n+1 - q[i];

    //printf("%d %d %d %d\n", q[i], count, n, a[n]);

    for ( int j = n; j>-1; j--)
    {
        if (j != count)
        {   
            total += a[j];
            //printf("%d", a[j]);
        } 
    }
    
    printf("%lld\n", total);

}


 double* create(double n){

     int* a= ( int*) malloc(n*sizeof());
    if(a == NULL){
        printf("PROBLEMA NA ALOCACAO");
    }
    return a;
}

int main(){

 int n, i; scanf("%lld", &n);//numero de chocolates
 int *a = create(n);   int *temp = create(n);

for (i = 0; i <n; i++)
{
    scanf("%lld", &a[i]);
}mergesort2(a, temp, 0, i-1);

 int m; scanf("%lld", &m);//numero de cupons
 int *q= create(m);

for ( int j = 0; j <m; j++)
{
    scanf("%lld", &q[j]);
    discount(a, q, j, i-1);
}

free(a); free(temp); free(q);
    return 0;
}