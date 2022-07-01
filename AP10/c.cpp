#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include "math.h"
#include <iostream>
#include <list>
#include <stack>
#define UNVISITED -2
#define VISITED -1

using namespace std;

typedef struct edge{
    int element;
    struct link *next;
}Edge;

typedef struct graph
{
   list<Edge>**list;
   int numEdge;
   int* Mark;
   int numVertex;
}Graph;


Graph* create_graph(int n){//

    Graph* g = (Graph*) malloc(sizeof(Graph));
    if(g==NULL) printf("Problema na alocação");

    g->Mark = new int[n];
    for (int i = 0; i < n; i++)
    {
        g->Mark[i] = UNVISITED;
    }
    
    g->list = (list<Edge>**) new list<Edge>*[n];
    for (int i = 0; i < n; i++)
    {
        g->list[i] = new list<Edge>();
    }
    
    g->numEdge = 0;
    g->numVertex = n;
    return g;
}

int n(Graph* g){
    return(g->numVertex);
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

void moveToStart(List* l){
    l->curr = l->head;
}

int first(Graph* g, int v){
    if (size(g->list[v])== 0)
    {
        return n(g);
    }
    g->list[v];
    Edge it = g->list[v]->getValue();
    return it.vertex();
    
}

int next(int v, int w){
    
}

void setEdge(Graph* g, int v, int w){

}

void toposort(){

}

void graphTransverse(Graph* g){
    stack<int>s;

    for (int v = 0; v < n(g); v++)
    {
        setMark(g,v, UNVISITED);
    }
    for (int v = 0; v < n(g); v++)
    {
        //printf("V:%dM:%d", v, getMark(g, v));
        if (getMark(g,v) == UNVISITED)
        {   
            toposort(g, v, s);printf("\n");
        }//printMark(g);     
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