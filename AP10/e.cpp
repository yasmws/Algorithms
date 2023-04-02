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
   int* topoSortVec;
}Graph;


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

static const int MAX = 10000;
static const int WHITE = 0;
static const int BLACK = 1;

int n, e;
int indeg[MAX], color[MAX];
vector<int> L[MAX];
vector<int> vec;

void bfs(int u) {
	queue<int> Q;
	Q.push(u);
	color[u] = BLACK;
	while (!Q.empty()) {
		int uu = Q.front();
		Q.pop();
		vec.push_back(uu);
		for (int i = 0; i < L[uu].size(); i++) {
			int v = L[uu][i];
			indeg[v]--;
			if (indeg[v] == 0) {
				color[v] = BLACK;
				Q.push(v);
			}
		}
	}
}

void TopoligicalSort() {
	for (int i = 0; i < n; i++)	{
		if (color[i] == WHITE && indeg[i] == 0) {
			bfs(i);
		}
	}
}


Graph* create_graph(int n){//
    Graph* g = (Graph*) malloc(sizeof(Graph));
    if(g==NULL) printf("Problema na alocação");
    
    g->Mark = new int[n];
    for (int i = 0; i < n; i++)
    {
        g->Mark[i] = UNVISITED;
    }

    g->topoSortVec = new int[n];
    for (int i = 0; i < n; i++)
    {
        g->topoSortVec[i] = 0;
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

void setEdge(Graph* g, int i, int j){
    
    if (g->matrix[i][j] == 0 )
    {
        g->numEdge++;
    }
    g->matrix[i][j] = 1;
    g->Mark[i] = UNVISITED;
    
}


int main(){
    int n, q, linhas=0, colunas=0;
    scanf("%d %d", &n, &q);
    Graph* g = create_graph(n);

    for (int i = 0; i < q; i++)
    {
       
        scanf("%d %d", &linhas, &colunas);
        setEdge(g, linhas, colunas);
            //printMatrix(g);

        //graphTransverse2(g, start);
            //BFS(g, start); 

        graphTransverse(g, 0);
            //DFS(g, start); 
        printVec(g);

            printf("\n");
    }
}


int main() {
	cin >> n >> e;
	int s, t;

	for (int i = 0; i < n; i++) {
		color[i] = WHITE;
		indeg[i] = 0;
	}

	for (int i = 0; i < e; i++)	{
		cin >> s >> t;
		indeg[t]++;
		L[s].push_back(t);
	}

	TopoligicalSort();

	for (int i = 0; i < n; i++)	{
		cout << vec[i] << endl;
	}

	return 0;

}