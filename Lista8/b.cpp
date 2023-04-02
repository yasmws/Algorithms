#include<iostream>
using namespace std;
#define M 5

int coinChange(int n, int D[M]){
    
    int F[M+1][n+1];

    for (int i = 0; i < M+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            if(i==0){ 
                F[i][j] = 0;
            }
            else if(j==0){
                F[i][j] = 1;
            }else if (D[i-1] > j)
            {
                F[i][j]= F[i-1][j];
            }else F[i][j] = F[i-1][j] + F[i][j - D[i-1]];

            //printf("%d ", F[i][j]);
        } //cout << endl;
    }//cout << endl;

    return F[M][n];
    
}

int main(){

    int n, ways=0;
    int D[M] = {1, 5, 10, 25, 50};

    while (scanf("%d", &n)==true)
    {
        ways = coinChange(n, D);
        cout << ways << endl;
    }

    return 0;

}