#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include <bits/stdc++.h>
using namespace std;
#define INF 888888888
#define N 80000

struct par
{
    int first;
    int second;
    par() {}

    par(int c, int weight) : first(c), second(weight) {}
    bool operator<(const par &p)const
    {
        return second > p.second;
    }
}p;

int Dijkstra(int n, int S, int T, int D[N], vector<par>*g, par p){

    priority_queue<par> pq;
    int a=0, b=0, weight=0;

    for (int i = 0; i < n; i++)//ok
    {
        D[i] = INF;
        //printf("%d", D[i]);
    }
    D[S] = 0;
    pq.push(par(S, 0));
    while (!pq.empty())
    {
        //printf("entrei");
        p = pq.top();//coloca o topo da pq no par
        pq.pop();//tira-se o topo da pq
        a = p.first;
        int tam = g[a].size();
        //printf("tam: %d", tam);
        //printf("aqui");
        for (int i = 0; i < tam; i++)
        {
            b = g[a][i].first;
            weight = g[a][i].second;
            if (D[b] > D[a] + weight)
            {
                D[b] = D[a] + weight;
                pq.push(par(b, D[b]));
            }
        }
    }
    return D[T];
}

int main()
{
    int numCasos=0, count=0, n=0, m=0, a=0, b=0, weight=0;
    int S=0, T=0, result=0;
    scanf("%d", &numCasos);
    int D[N];
    vector<par> g[N];
    par p;
   
    while (count<numCasos)
    {   
        result = INF;
        scanf("%d %d %d %d", &n, &m, &S, &T);

        if(m!=0){

            for (int i = 0; i < n; i++)//ok
            {
                D[i] = INF;
                g[i].clear();
                //printf("%d", D[i]);
            }

            for (int i = 0; i < m; i++)//ok
            {
                scanf("%d %d %d", &a, &b, &weight);
                g[a].push_back(par(b, weight));
                g[b].push_back(par(a, weight));
            }

            //dijskstra a partir daqui
            //printf("%d %d", S, T); 
            result = Dijkstra(n, S, T, D, g, p);
            //printf("%d", result);
        }
        
        if (result != INF)
        {   
            printf("Case #%d: %d\n", count+1, result);

        }else printf("Case #%d: unreachable\n", count+1);

        count++;

    }
    
    return 0;
}