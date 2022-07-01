#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include "math.h"
#include <iostream>
#include <queue>
#define UNVISITED -2
#define VISITED -1
//esse código funciona
using namespace std;

typedef struct graph
{
   int** matrix;
   int numEdge;
   int* Mark;
   int tam;
}Graph;


Graph* create_graph(int n){//
    Graph* g = (Graph*) malloc(sizeof(Graph));
    if(g==NULL) printf("Problema na alocação");
    g->Mark = new int[n];
    for (int i = 0; i < n; i++)
    {
        g->Mark[i] = UNVISITED;
    }
    
    g->matrix = new int*[n];
    for (int i = 0; i < n; i++)
    {
        g->matrix[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g->matrix[i][j] = 0;
        }
        
    }
    
    g->numEdge = 0;
    g->tam = n;
    return g;
}

int n(Graph* g){
    return(g->tam);
}

void setMark(Graph* g, int v, int estado){
    g->Mark[v] = estado;
}

int getMark(Graph* g, int v){
    return (g->Mark[v]);
}

void printMark(Graph* g){
    
    for (int j = 0; j < n(g); j++)
    {
        printf("%d ", g->Mark[j]);
    }printf("\n");
    
}

int first(Graph* g, int v){//

    for (int i = 0; i < n(g); i++)
    {
        if (g->matrix[v][i] != 0)
        {
            return i;
        }
    }
    return n(g);
}

int first2(Graph* g, int v){//

    for (int i = 0; i < n(g); i++)
    {
        if (g->matrix[i][v] != 0)
        {
            return i;
        }
    }
    return n(g);
}

int next(Graph* g, int v, int w){//
    
    for (int i = w+1; i < n(g); i++)
    {
        if (g->matrix[v][i] == UNVISITED)
        {
            return i;
        }
    }

    return n(g);
}

void setEdge(Graph* g, int i, int j){//
    
    if (g->matrix[i][j] == 0 )
    {
        g->numEdge++;
    }
    g->matrix[i][j] = 1;
    
}

void delEdge(Graph* g, int i , int j){//
    if (g->matrix[i][j]!=0)
    {
        g->numEdge--;
    }
    g->matrix[i][j] = 0;
}


void DFS(Graph* g, int v){//problema

    printf("%d ", v);
    setMark(g, v, VISITED);
    int w = first2(g, v);
    while (w < n(g))
    {
        if(getMark(g, w) == UNVISITED){
            //printf("%d", w);
            DFS(g,w);
        }
        w = next(g, v, w);
    }
}

void BFS(Graph* g, int start){//ok

    queue<int>q;

    q.push(start);
    setMark(g, start, VISITED);
    while (q.size()>0)
    {
        int v = q.front();
        printf("%d ", v);
        q.pop();
        int w = first(g,v);
        printf("%d", w);
        while (w < n(g))
        {
            if (getMark(g,w) == UNVISITED)
            {
                setMark(g, w, VISITED);
                q.push(w);
            }
            w = next(g, v, w);
            
        }
        
    }
    
}

void graphTransverse2(Graph* g, int w){
    for (int v = 0; v < n(g); v++)
    {
        setMark(g,v, UNVISITED);
    }
    //printMark(g);
    BFS(g, w);
    //printMark(g);
    for (int v = 0; v < n(g); v++)
    {
        if (getMark(g,v) == UNVISITED)
        {
            BFS(g, v);
        }     
    }
}

void graphTransverse(Graph* g, int w){
    for (int v = 0; v < n(g); v++)
    {
        setMark(g,v, UNVISITED);
    }
    //printMark(g);
    DFS(g, w);
    //printMark(g);
    for (int v = 0; v < n(g); v++)
    {
        if (getMark(g,v) == UNVISITED)
        {
            DFS(g, v);
        }     
    }
}

int main(){
    int n, q, linhas=0, colunas=0;
    char comando[4];
    scanf("%d %d", &n, &q);
    Graph* g = create_graph(n);

    for (int i = 0; i < q; i++)
    {
        scanf(" %s", comando);
        if (strcmp(comando,"add")==0)
        {   
            scanf("%d %d", &linhas, &colunas);
            setEdge(g, linhas, colunas);
            setEdge(g, linhas, colunas);
            //printMatrix(g);

        }else if (strcmp(comando, "BFS")==0)//ok
        {
            int start;
            scanf("%d", &start);
            graphTransverse2(g, start);
            //BFS(g, start); 
            printf("\n");
            
        }else if (strcmp(comando, "DFS")==0)
        {
            //graphTransverse(g);
            int start;
            scanf("%d", &start);
            graphTransverse(g, start);
            //DFS(g, start); 
            printf("\n");
        }
        
    }
    
}