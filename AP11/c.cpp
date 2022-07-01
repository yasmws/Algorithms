#include<stdio.h>
#include<bits/stdc++.h>
#define UNVISITED 0
#define VISITED 1
#define INFINITY -8
using namespace std;


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
   vector < vector < int > >list;
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

int next(Graph* g, int v, int w){
    
    for (int i = 0; i < g->list[v].size(); i++)
    {
        if (g->list[v][i]==w)
        {
            if (i != g->list[v].size() - 1)
            {
                return g->list[v][i+1];   
            }
        }
        
    }return n(g);
    
}

int first(Graph* g, int v){

    if (g->list[v].empty()==0)
    {
        return g->list[v][0];
    }else return n(g);
    
}

void printList(Graph* g){
    for (int i = 0; i < g->list.size(); i++)
    {
        for (int j = 0; j < g->list[i].size(); j++)
        {
           printf("%d", g->list[i][j]); 
        }
        printf("\n");
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

void dijkstra(Graph G, int s, int* D){
    pair<int, int>p;
    int tam = n(G);
    int P[tam];
    int v, w;

    for (int i = 0; i < n(G); i++)
    {
        D[i] = INFINITY;
        P[i] += -1;
        setMark(G, i, UNVISITED);
    }

    pq.push(Heap(s, s, 0)); //H[1] = (s, s, 0);
    D[s] = 0;

    for (int i = 0; i < n(G); i++)
    {
        do
        {
            p.first() = pq.top();
        } while (getMark(G, v)==UNVISITED);

        setMark(G, v, VISITED);
        P[v] = p;
        w = first(G, v);

        while (w<tam)
        {
            if((getMark(G, w) != VISITED) && D[w]>D[v] + weight(G, v, w))
            {
                D[w] = D[v] + weight(G, v, w);
                insert(H(v, w, D[w]));
            }
            w = next(G, v, w);
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


}