#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

typedef struct e //estrutura do elemento
{
    char palavra[15];
    int ocupado;

}E;

typedef struct t//tabela
{   
    E e[101];
    int tam;
}T;

T* criar(){ //criando

    T* t = (T*)malloc(1* sizeof(T));
    if (t==NULL)
    {
       printf("Problema na alocação");
    }
    for (int i = 0; i < 101; i++)
    {
        t->e[i].ocupado =0;
    }
    t->tam==0;

    return t;
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

void remover(T* t, char* string){ //removendo
    int k = hash(string);
    int l=0, flag =0;
    //printf("aqui");
    
    for (int i = 0; i <20; i++)
    {
        for (int i = 0; i <20 && flag ==0; i++)//20 chaves possíveis
        {
            l = (k+(i*i)+23*i) %101; //printf("%d\n", l);
            if (t->e[l].ocupado==1 && strcmp(t->e[l].palavra, string)==0)//se ocupado, pergunta se as strings são iguais 
            {   
                //printf("?");//n entra
                t->e[l].ocupado=-1;//deletado
                t->tam--;
                flag =1;
            }
        }
    }
}

int encontrar(T*t, char* string){//ok
    //se encontro, volta 1. caso contrário, volta 0.
    int k = hash(string);
    int flag=0, l=0;
    
    for (int i = 0; i <20 || flag ==1; i++)//20 chaves possíveis
    {
        l = (k+(i*i)+23*i) %101;
        if (t->e[l].ocupado==0)//se livre
        {
            return 0;
        }else if (strcmp(t->e[l].palavra, string)==0)//se ocupado, pergunta se as strings são iguais 
        {
            return 1;
        }
        
    }
    
}

void inserir(T* t, char* string){//ok
    
    int k = hash(string);
    //printf("%d\n", k);
    int flag=0;

    if(encontrar(t, string)==0){
        //printf("encontrar:%d", encontrar(t, string));
        int l;
        for (int i = 0; i <20 && flag ==0; i++)//20 chaves possíveis
        {
            l = (k+(i*i)+23*i) %101;
            if (t->e[l].ocupado==0 || t->e[l].ocupado==-1)//se livre
            {
                //vamos inserir
                strcpy(t->e[l].palavra, string);
                t->e[l].ocupado=1;
                t->tam++;
                flag=1;
                
            }
        }
    }

}

int main(){//ok
        
    char string[15];
    int n=0;
    int y=0;
    int count=0, count2=0;
    char comando[3];
    
    scanf("%d", &n);
    do
    {   
        T* t = criar();
        scanf("%d", &y); 
        int x = y;
        //printf("y0 - %d\n", y);
        count2 = 0;
        do
        { 
            for (int i = 0; i < 4; i++)
            {
                scanf(" %c", &comando[i]);
    
            }//printf("%s\n", comando);

            if (strcmp(comando, "ADD:")==0)//inserir
            {   
                scanf("%s", string);
                inserir(t, string);
                
            }else if (strcmp(comando, "DEL:")==0)//remover
            {   
                scanf("%s", string);
                remover(t, string);//problema aqui
            }

            count2++;
        } while (count2<x);
        
        printf("%d\n", t->tam);

        for (int i = 0; i <101; i++)
        {   
            if (t->e[i].ocupado==1)//se não estiver vazio
            {
                printf("%d:%s\n", i, t->e[i].palavra);  
            }               
        }printf("\n");

        count++; free(t);
    } while (count<n);


    return 0;
}


