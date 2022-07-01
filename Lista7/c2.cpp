#include<iostream>
using namespace std;
#define MAX 16
#define UNVISITED 0
#define VISITED 1

bool p(int soma){

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


void primeRing(int ring[MAX], int marked[MAX], int n, int v)
{
    if( v==n && p(ring[1]+ring[n]))
    {
        for(int i=1; i<n+1; i++){
            printf("%d ", ring[i]);
        }
        cout << endl;
       
    }else{
        
        for(int i=2; i< n+1; i++){

            if(marked[i]==UNVISITED && p(ring[v]+i))
            {
                marked[i]= VISITED;
                ring[v+1]=i;
                primeRing(ring, marked, n, v+1);
                marked[i]= UNVISITED;
            }
        }
    }
    return;
}

int main()
{   
    int n=0, count=0, soma=0;
    int ring[MAX];
    int marked[MAX];

    while(scanf("%d", &n)==true){

        count++;
        printf("Case %d:\n", count);
        
        for (int i = 1; i < n+1; i++)
        {
            marked[i] = UNVISITED; ring[i] = i;
        }

        /*for (int i = 1; i< n+1; i++)
        {
            for (int j = 1; j< n+1; j++)
            {
                soma = i+j;
                if(itsPrime(soma)==true){
                    pares[i][j] = 1;
                    pares[j][i] = 1; 
                }
            }
        }*/
        
        primeRing(ring, marked, n, 1);//começa no 1, sempre
        cout << endl;
    }

    return 0;
}