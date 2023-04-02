#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include "math.h"
#include <iostream>
#include <stack>
#include <queue>
#define UNVISITED -2
#define VISITED -1

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

void printMatrix(Graph* g){
    //printf("%d", n(g)-1);

    for (int i = 0; i < n(g); i++)
    {
        for (int j = 0; j < n(g); j++) 
        {
            printf("%d ", g->matrix[i][j]);
        }
        printf("\n");
    }
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

int next(Graph* g, int v, int w){//
    
    for (int i = w+1; i < n(g); i++)
    {
        if (g->matrix[v][i] != 0)
        {
            return i;
        }
    }

    return n(g);
}

void setEdge(Graph* g, int i, int j){
    
    if (g->matrix[i][j] == 0 )
    {
        g->numEdge++;
    }
    g->matrix[i][j] = 1;
    
}


void toposort(Graph* g, int v, stack<int>&s){

    setMark(g, v, VISITED); int flag = 0;
    int w = first(g, v); printf("%d", w);
    while (w < n(g))
    {
        if(getMark(g, w) == UNVISITED){
            toposort(g, w, s);
        }
        
        w = next(g, v, w);
    }
    printf("%d", v);
    s.push(v); flag=1;

}

void graphTransverse(Graph* g){
    stack<int>s;

    for (int v = 0; v < n(g); v++)
    {
        setMark(g,v, UNVISITED);
    }
    for (int v = 0; v < n(g); v++)
    {
        if (getMark(g,v) == UNVISITED)
        {   
            toposort(g, v, s); 
            printMark(g);
            printf("\n");
        }    
    }
    for (int i = 0; i <n(g); i++)
    {
        printf("%d\n", s.top());
        s.pop();
    }
}

int main(){
    int n, m, linhas, colunas;
    scanf("%d %d", &n, &m);
    Graph* g = create_graph(n);

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &linhas, &colunas);
        setEdge(g, linhas, colunas);
    }

    printMatrix(g);//matrix ok

    graphTransverse(g);

    
}