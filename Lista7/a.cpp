#include<iostream>
using namespace std;
#define MAX 9
#define TONS 300
int flag;
int allM[TONS][MAX][MAX];

bool valid(int M[MAX][MAX], int n, int lin, int col) {
   
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
}

void printM(int n){

    for (int k=flag; k>0; k--){
	
		for (int i = 0; i <n; i++)
		{
			for (int j = 0; j <n; j++)
			{
				if (allM[k][i][j]==1)
				{
					cout << "Q ";
				}else cout << "- ";
			}cout << endl; 
		}cout <<endl;
	}

}

void armazenarM(int M[MAX][MAX], int n){

	for (int i = 0; i <n; i++)
    {
        for (int j = 0; j <n; j++)
        {
			allM[flag][i][j] = M[i][j];
        }
    }
}




bool qns(int M[MAX][MAX], int n, int col) {
   
   if (col >= n){
		flag += 1;
        armazenarM(M, n);        
        return true;
   }else{
        for (int i = 0; i<n; i++){     
            if (valid(M, n, i, col)==true){

                M[i][col] = 1;      
                qns(M, n, col + 1);
                M[i][col] = 0;        
            }
        }
    }  

}

int main(){

    int M[MAX][MAX];
    int n=0, col=0;
    char s[10]; 

    while (scanf("%s", &s)==true)
    {
        cin >> n; //n esta entre 1 e 8
        cout << s <<endl<<endl;
        flag = 0;
        qns(M, n, col);
		if(flag>0){ 
			printM(n);
		}else cout << "Not Possible" <<endl <<endl;
		
    }

    return 0;
}