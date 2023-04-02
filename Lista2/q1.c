#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int binary(double *a, int left, int right, double k, int aux){
    int middle;
    //printf("%d%d\n", right, left);

    if(right>=left){
        middle = floor((left + right)/2);
        //printf("%lf%lf%d", k, a[middle], middle);
        if(k == a[middle]){
            aux = middle; 
            binary(a, left, middle-1, k, aux);
        }else if(k < a[middle]) 
            binary(a, left, middle-1, k, aux);
        else{                          
            binary(a, middle+1, right, k, aux);
        }
    }else return aux;
}

double* create(int n){

    double* a= (double*) malloc(n*sizeof(double));
    if(a == NULL){
        printf("PROBLEMA NA ALOCACAO");
    }
    return a;
}

int main(){
    int n, m, i, aux=-1; 
    int pos=0;

    scanf("%d%d", &n, &m);

    double *a = create(n);
    double *b = create(m);
    double *temp = create(n);

    for (i = 0; i < n; i++)
    {
        scanf(" %lf", &a[i]);
        //printf("%lf", a[i]);
    }

    for (int j = 0; j < m; j++)
    {
        scanf("%lf", &b[j]);
        //printf("%lf", b[j]);
        pos = binary(a, 0, i-1, b[j], aux);
        printf("%d\n", pos);
    }

    return 0;
}