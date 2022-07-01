#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

typedef struct e
{
    char palavra[19];
    int ocupado;

}E;

int qtd;

char** criar(){

    char** matrix = (char**)malloc(101 * sizeof(char*));

    for (int i=0; i<101; i++)
    {
        matrix[i] = (char*)malloc(18 * sizeof(char));
        matrix[i] = "nada";
    }

    //printf("Tudo certo");

    return matrix;
}

void remover(char *matrix[18], char* string){
    
    
    for (int i = 0; i < 101; i++)
    {
        if (strcmp(matrix[i], string)==0)
        {
            strcpy(matrix[i], "nada");
            qtd--;
        }
    }
    
}

int h(char* key){
    
    int cnt=0;

    for (int i = 0; i <strlen(key); i++)
    {
        cnt += i*(int)(key[i]);
        //printf("%d\n", cnt);
    }

    return (19*cnt);
    
}

int hash(char* key){

    int k = h(key) - (101* floor(h(key)/101));

    return k;
}

int colision(int k, int j, char** matrix){

    int l = (k+(j*j)+23*j) % 101;

    if (strcmp(matrix[l], "nada")==0)
    {
        return l;
    }else if (j>=20)
    {
        return -1;
    }else return colision(k, j+1, matrix);
}

void inserir(char** matrix, char* string){

    int k = hash(string);
    printf("%d\n", k);
    int j = 1;

    *if(strcmp(matrix[k], "nada")==0){
        strcpy(matrix[k], string);
    }else
    {
        k = colision(k, j, matrix);
        if (k!=-1)
        {
           strcpy(matrix[k], string);
        }
    }*/
}

int main(){
    char string[19]; string[0] = ' ';
    int n=0, m=0;
    int count=0, count2=0;
    char** matrix = criar();
    char comando[2];
    //char comando[0];
    scanf("%d", &n);
    //printf("%d", n); 
    do
    {   
        scanf("%d", &m);
        //printf("%d",  m);
        count2 =0;
        do
        {  
            for (int i = 0; i < 3; i++)
            {
                scanf(" %c", &comando[i]);
            }
            
            if (strcmp(comando, "ADD")==0)
            {   
                scanf("%s", string);
                inserir(matrix, string);

            }else if (strcmp(comando, "DEL")==0)
            {
                
                scanf("%s", string);
                //remover(matrix, string);
            }
                
            count2++;
        } while (count2<m);
        
        count++;
    } while (count<n);

    return 0;
}
