#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef struct dictionary
{
    int m; //size of the hash table
    int cnt;
    int* H; //hash table as an array of entry
    int* Perm; //permutation array
    int (*h)(char* key); //hash function
}Dictionary;

Dictionary* create_dict(int size, int (*h)(int key)){

    Dictionary* d = (Dictionary*) malloc(sizeof(Dictionary)*1);
    if(d==NULL){printf("Problema na alocação");}

    d->m = size;
    d->cnt = 0;
    d->H = malloc
    d->Perm = create_permutation(size-1);
    d->h = &hash;

    return d;
}

/*
void insert(Dictionary* d, int(*h)(int key), int e){

    int pos=0; 

    if (size(d)<d->m && find(d, k)==NULL)
    {
        pos = d->h(key);
        if(d->H[pos]!=NULL && d->H[pos]!=deleted){
            i = 0;
            do
            {
                i = i+1;
                offset = d.Perm[i-1];
                newPos = (pos+offset)%d.m;
            } while (d.H[newPos]==NULL || d.H[newPos]==deleted);
            pos = newPos;
        }
        entry = create_entry(k, e);
        d.H[pos] = entry;
        d.cnt = d.cnt +1;
    }
    
}
*/

int hash(char* key){

    int s = strlen(key)/4;
    int sum = 0;
    for (int i = 0; i < s-1; i++)
    {
        sub = subString(K, i*4, (i*4) +4);
        mult = 1;
        for (int j = 0; j <3; j++)
        {
            sum = sum + sub[j] * mult;
            mult = mult * 256
        }
    }

    sub = subString(K, s*4);
    mult = 1;
    s = strlen(sub);

    return abs(sum)%m;
}

void encontrarString(){

    find(string);
    //colocar string na hash table
}

void inserirString(){

    char string[16];
    scanf("%s", string);
    //colocar string na hash table
}

void removerString(){

    char string[16];
    scanf("%s", string);
    encontrarString(string);
    //colocar string na hash table
}

int main(){

    char word[18];
    
    //int (*h_ptr)(char*) = &hash;
    int tam; scanf("%d", &tam); //tamanho do dicionario
    //int k; scanf("%d", &k);
    Dictionary* d = create_dict(tam, &Hash());

/*
    char comando[5];
    do
    {   
        scanf("%s", comando);
        if (strcmp(comando, "add")==0)
        {   
            inserirString();
        }else if (strcmp(comando, "rmv")==0)
        {
            removerString();
        }else if (strcmp(comando, "sch")==0)
        {
            char string[16];
            scanf("%s", string);
            encontrarString();
            printf("%s", )
        }
        
    } while (strcmp(comando, "fim")!=0);
*/

    return 0;
}