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

void primeRing(int pares[MAX][MAX], int ring[MAX], int marked[MAX], int n, int v)
{
    if(pares[ring[1]][ring[n]]==1  && v==n)//se há ligação entre o primeiro e o último, ent ok
    {
        for(int i=1; i< n+1; i++)
        {
            printf("%d ", ring[i]);
        }
        cout << endl;
       
    }else{
        
        for(int i=1; i< n+1; i++){

            if(marked[i]==UNVISITED && pares[ring[v]][i]==1 && i!=1)//tipo um dfs
            {//se há ligação e aquele numero ainda n foi visitado, podemos add ele na ring
                marked[i]= VISITED;
                ring[v+1]=i;
                primeRing(pares, ring, marked, n, v+1);
                marked[i]= UNVISITED;
            }
        }
    }
}

void limparPares(int pares[MAX][MAX], int n){

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            pares[i][j] = 0;
        } 
    }cout << endl;
}

void printPares(int pares[MAX][MAX], int n){

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            printf("%d", pares[i][j]);
        }cout << endl << endl;
        
    }
}

int main()
{   
    int n=0, count=1, soma=0;
    int pares[MAX][MAX];
    int ring[MAX];
    int marked[MAX];

    while(scanf("%d", &n)==true){

        printf("Case %d:\n", count);
        
        for (int i = 1; i < n+1; i++)
        {
            marked[i] = UNVISITED; ring[i] = i;
            //inicialmente
        }

        limparPares(pares, n);
        //printPares(pares, n);

        for (int i = 1; i < n+1; i++)
        {
            for (int j = 1; j < n+1; j++)
            {
                soma = i+j;
                if(itsPrime(soma)==true){
                    pares[i][j] = 1;
                    pares[j][i] = 1; 
                }
            }
        }
        
        //printPares(pares, n);
        primeRing(pares, ring, marked, n, 1);//começa no 1, sempre
        cout << endl;

        count++;
    }

    return 0;
}