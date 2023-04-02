#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "math.h"

void merge(int a[1000], int temp[1000], int l, int r){
    
    for (int i = l; i <=r; i++)
    {
        temp[i]=a[i];
    }
    int m = floor((l+r)/2);
    int i1 = l; int i2 = m+1; 
    for (int curr = l; curr<=r; curr++)
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

void mergesort2(int a[1000], int temp[1000], int l, int r){
    
    int mid;
    if(l<r){
        mid = floor((l+r)/2);
        mergesort2(a, temp, l, mid);//left side
        mergesort2(a, temp, mid+1, r);//right side
        merge(a, temp, l, r);
    }
}

int main()
{   
    int a[1000]={},b[1000]={};
    int n, i=0;
    scanf("%d", &n);
    do
    {
        int m, j=0;
        scanf("%d", &m);
        while (j<m)
        {
            scanf("%d", &a[j]);
            j++;
        }mergesort2(a, b, 0, j-1);

        int k;
        for (k = 0; k <m; k++)
        {
            printf("%d\n", a[k]);
        }

       i++;
    } while (i<n);
    

    return 0;
}