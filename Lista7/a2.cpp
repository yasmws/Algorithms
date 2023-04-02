#include<iostream>
using namespace std;
#define MAX 16
#define UNVISITED 0
#define VISITED 1

bool itsPrime(int soma){

    int flag = 0;
    int primos[6] = {2, 3, 5, 7, 11, 13};

    for (int i = 0; flag == 0; i++)
    {   
        if (soma == primos[i])
        {
            return true;
        }else if(soma < primos[i]){
            return false;
        }
    }
    return false;
}

/*void DFS(int pares[MAX][MAX], int marked[MAX], int n, int v){//problema

    marked[v] = VISITED;
    printf("%d ", v);
    for (int i = 0; i <n; i++)
    {
        if(pares[v][i]== 1 && marked[i]==UNVISITED){
            
            DFS(pares, marked, n, i);
        }
    }
}

void graphTransverse(int pares[MAX][MAX], int n){
    
    int marked[MAX], v;
    for (v = 1; v <n; v++)
    {
        marked[v] = UNVISITED;
    }

    for (v = 1; v <n; v++)
    {
        if (marked[v]==UNVISITED)
        {
            DFS(pares, marked, n, v);
        }     
    }
}*/

void ring_f(int pares[MAX][MAX], int marked[MAX], int n, int v, int ring[MAX]){

    if( v == n && pares[1][ring[n]]==1)
    {
        printf("entrei");
        for (int i = 1; i < n+1; i++)
        {
            printf("%d", ring[i]);
        }
        printf("\n");
        
    }else{

        for (int i = 2; i <= n; i++)
        {
            if (marked[i]==0 && pares[v][i])
            {
                marked[i] = 1; ring[v+1] = i;
                ring_f(pares, marked, n, v+1, ring);
                marked[i] = 0;
            }
            
        }
        
    }
}

void printPares(int pares[MAX][MAX], int n){

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            printf("%d", pares[i][j]);
        }cout << endl;
        
    }
}

void limparPares(int pares[MAX][MAX], int n){

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pares[i][j] = 0;
        } 
    }cout << endl;
}

void limparRing(int ring[MAX], int n){

    for (int i = 0; i < n; i++)
    {
        ring[i] = 0;
    }
    
}

int main(){

    int n, count=0;
    int soma=0
    int pares[MAX][MAX];
    int marked[MAX];
    int ring[MAX];
    
    while(scanf("%d", &n)==true){

        count++;
        printf("Case %d:\n", count);

        limparPares(pares, n);
        limparRing(ring, n);

        for (int i = 1; i< n+1; i++)
        {
            for (int j = 1; j< n+1; j++)
            {
                soma = i+j; marked[i] = 0;
                if(itsPrime(soma)==true){
                    pares[i][j] = 1;
                    pares[j][i] = 1; 
                }
            }
        }

        printPares(pares, n);//ok
        ring_f(pares, marked, n, 1, ring);
        
    }
    
    return 0;

}