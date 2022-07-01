#include<iostream>
using namespace std;
#define MAX 9
int flag;

/*bool valid(int M[MAX][MAX], int n, int lin, int col) {
   
   for (int i = 0; i < col; i++){   
        if (M[lin][i]==1){
            return false;
        }
   }

   for (int i=lin, j=col; i>=0 && j>=0; i--, j--){
        if (M[i][j]==1){       
            return false;
        }
    }
   
   for (int i=lin, j=col; j>=0 && i<n; i++, j--){
        if (M[i][j]==1){      
            return false;
        }
    }

    return true;
}*/

bool valid(int M[MAX][MAX], int n, int lin, int col) {
   
   for (int i = 0; i < lin; i++){   
        if (M[i][col]==1){
            return false;
        }
   }

   for (int i=lin, j=col; i>=0 && j>=0; i--, j--){
        if (M[i][j]==1){       
            return false;
        }
    }
   
   for (int i=lin, j=col; i>=0 && j<n; i--, j++){
        if (M[i][j]==1){      
            return false;
        }
    }

    return true;
}

void printM(int M[MAX][MAX], int n){

    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j <n; j++)
        {
            if (M[i][j]==1)
            {
                cout << "Q ";
            }else cout << "- ";
        }cout << endl; 
    }cout <<endl;

}


bool qns(int M[MAX][MAX], int n, int lin) {
   
   if (lin == n){
		flag = 1;
        printM(M,n);          
        return true;
   }else{
        for (int i = 0; i<n; i++){ 
           
            if (valid(M, n, lin, i)==true){

                M[lin][i] = 1;      
                qns(M, n, lin + 1);
                M[lin][i] = 0;        
            }
        }
    }  

}

int main(){

    int M[MAX][MAX];
    int n=0, lin=0;
    char s[10]; 
    flag=0;

    cin >> n; //n esta entre 1 e 8
    qns(M, n, lin);
    if(flag==0){
        cout << "Not Possible";
    }

    return 0;
}