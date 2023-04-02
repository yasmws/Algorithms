#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

typedef struct e //estrutura do elemento
{
    char palavra[16];
    int ocupado;

}E;

E* criar(){ //criando

    E* e = (E*)malloc(101 * sizeof(E));
    if (e==NULL)
    {
       printf("Problema na alocação");
    }
    for (int i = 0; i < 101; i++)
    {
        e[i].ocupado =0;
        strcpy(e[i].palavra, "");
    }

    return e;
}

int remover(E* e, char* string){ //removendo
    
    
    for (int i = 0; i < 101; i++)
    {
        if (strcmp(e[i].palavra, string)==0)
        {
            strcpy(e[i].palavra, "-");
            e[i].ocupado=0;
            return -1;
        }
    }
    return 0;
}

int h(char* key){   //ok
    
    int cnt=0;
    for (int i = 0; i <strlen(key); i++)
    {
        cnt += (i+1)*(key[i]);
        
    }//printf("%d\n", cnt);

    return (19*cnt);
}

int hash(char* key){    //ok

    //int k = h(key) - (101* floor(h(key)/101));
    int k = h(key) %101;

    return k;
}

int colision(int k, int j, E* e){

    //int l = (k+(j*j)+23*j) - (101* floor((k+(j*j)+23*j)/101));
    int l = (k+(j*j)+23*j) %101;

    //printf("col:%d, tentativa:%d", l, j);

    if (e[l].ocupado==0)//se livre
    {
        return l;
    }else if (j>20)
    {   
        //printf("não dá\n");
        return -1;
    }else colision(k, j+1, e);
}


int inserir(E* e, char* string){

    int k = hash(string);
    //printf("%d\n", k);
    int j = 1;
 
    //printf("%d-%d\n", k, e[k].ocupado);

    for (int i = 0; i <101; i++)
    {
        if (strcmp(e[i].palavra,string)==0){ // se são palavras iguais, não faço nada
        //printf("%s", e[i].palavra);
        return 0;
        }
    
    }
    
    if(e[k].ocupado==0){//livre
        strcpy(e[k].palavra, string);
        e[k].ocupado=1;
        return 1;
    }else if (e[k].ocupado==1)
    {  
        //printf("colisao no %d", k); //problema na colisao
        k = colision(k, j, e);
        //printf("hash:%d\n", k);
        if (k!=-1)
        {
           strcpy(e[k].palavra, string);
           e[k].ocupado=1;
           return 1;
        }else return 0;
        
    }
}

int main(){
        
    char string[16];
    int n=0;
    int y=0;
    int count=0, count2=0, count3=0;
    char comando[3];

    scanf("%d", &n);
    do
    {   
        E* e = criar();
        scanf("%d", &y); 
        int x = y;
        //printf("y0 - %d\n", y);
        count2 = 0; count3 = 0;
        do
        { 
            for (int i = 0; i < 4; i++)
            {
                scanf(" %c", &comando[i]);
                //printf("%s", comando);
            }
            if (strcmp(comando, "ADD:")==0)
            {   
                scanf("%s", string);
               
                count3 += inserir(e, string);
                   //printf("%s", string); 
                
            }else if (strcmp(comando, "DEL:")==0)
            {
                scanf("%s", string);
                
                count3 += remover(e, string);
                
            }

            count2++;
        } while (count2<x);
        
        printf("%d\n", count3);


        for (int i = 0; i <101; i++)
        {   
            if (e[i].ocupado==1)
            {
                printf("%d:%s\n", i, e[i].palavra);
                
            }
                            
        }printf("\n");

        count++;
    } while (count<n);

    return 0;
}