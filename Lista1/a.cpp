#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include "math.h"
#include<stdio.h>
#include<stack>
#include<vector>
#define UNVISITED 0
#define VISITED 1
using namespace std;

typedef struct graph
{
   vector <vector<int>>list;
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

    g->list.resize(n);
    
    g->numEdge = 0;
    g->numVertex = n;
    return g;
}

void setMark(Graph* g, int v, int estado){
    g->Mark[v] = estado;
}

int getMark(Graph* g, int v){
    return g->Mark[v];
}

int n(Graph* g){
    return g->numVertex;
}

void setEdge(Graph* g, int l, int c){

    g->list[l].push_back(c);

}

/*void topoSort(Graph* g, int v, stack<int>&s) {
    setMark(g, v, ENTERED);

    for (int i=0; i < g->list[v].size(); i++){
        int w = g->list[v][i];
        if (getMark(g, w)!=VISITED){
            topoSort(g, w, s);
        }
    }
    g->Mark[v] = VISITED;
    s.push(v);
}*/

int next(Graph* g, int v, int w){
    
    for (int i = w+1; i < n(g); i++)
    {
        if (g->list[v][i] != 0)
        {
            return g->list[v][i];
        }
        
    }return g->list[v].size();
    
}

int first(Graph* g, int v){

    if (g->list[v].empty()==0)
    {
        return g->list[v][0];
    }else return g->list[v].size();
    

    /*for (int i = 0; i < n(g); i++)
    {
        if (g->list[v][i]!=0)
        {
            return g->list[v][i];
        }
    }return n(g);*/
    
}

void topoSort(Graph* g, int v, stack<int>&s) {
    setMark(g, v, VISITED);
    int w = first(g, v); 

    while (w< g->list[v].size())
    {
        if (getMark(g, w)==UNVISITED)
        {
            topoSort(g, w, s);
        }
        w = next(g, v, w);
        
    }
    
    s.push(v);
}

void graphTransverse(Graph* g) {
    stack<int>s;

    for (int v=0; v< n(g); v++){
        setMark(g, v, UNVISITED);
    }

    for (int v = 0; v < n(g); v++)
    {
        if (getMark(g,v)==UNVISITED)
        {
            topoSort(g, v, s);
        }
        
    }
    
    while(s.empty()==0) {
        printf("%d", s.top());
        s.pop();
    }

}

void printList(Graph* g){
    for (int i = 0; i < g->list.size(); i++)
    {
        for (int j = 0; j <g->list[i].size(); j++)
        {
           printf("%d", g->list[i][j]); 
        }
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

    //printList(g);

    graphTransverse(g);

}