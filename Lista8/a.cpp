#include<iostream>
using namespace std;
#define TAM 2001
#define max(a, b) (a>b?a:b)

int knapsack(int n, int W, int v[TAM], int w[TAM]){
    
    int F[n+1][W+1];

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < W+1; j++)
        {
            if(i==0 || j==0){ 
                F[i][j] = 0;
            }
            else if (w[i]<=j)
            {
                F[i][j]= max(F[i-1][j], v[i]+F[i-1][j-w[i]]);
            }else F[i][j] = F[i-1][j];

            //printf("%d ", F[i][j]);
        } //cout << endl;
    }

    return F[n][W];
    
}

int main(){

    int W, n;
    int v[TAM], w[TAM];
    cin >> W >> n;

    w[0]=0; v[0]=0;

    for (int i = 1; i < n+1; i++)
    {
        cin >> w[i];
        cin >> v[i];
    }

    int resultado = knapsack(n, W, v, w);
    cout << resultado;


    return 0;

}