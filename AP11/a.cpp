#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include "math.h"
#include<stdio.h>
#include<bits/stdc++.h>
#define UNVISITED 0
#define VISITED 1
#define INFINITY -8
using namespace std;

class Heap
{
    int a;
    int b;
    int weight;
public:
    Heap(int x, int y, int w)
    {
        a = x;
        b = y;
        weight = w;
    }
    int getA() const {return a;}
    int getB() const {return b;}
    int getWeight() const {return weight;}
}

class Comparator
{
  public:
    int operator()(Heap& H1, Heap& H2)
    {
        return H1.getWeight() > H2.getWeight();
    }
};


void dijkstra(vector<p>&g, int s, int* D, priority_queue<Heap>&pq, pair<int, int>&p){

    int P[n(g)], v, w;
    for (int i = 0; i < n(g); i++)
    {
        D[i] = INFINITY;
        P[i] -= 1;
        setMark(g, i, UNVISITED);
    }
    
    //heap tripla H
    pq.push(Heap(s, s, 0));
    D[s] = 0;
    for (int i = 0; i < n(g); i++)
    {
        do
        {
          p.first() = pq.top();  
          
        } while (getMark(g, v)==UNVISITED);
        setMark(g, v, VISITED);
        P[v] = p;
        w = first(g, v);
        while (w<n(g))
        {
            if((getMark(g, w) != VISITED) && D[w]>D[v]+weight(g, v, w))
            {
                D[w] = D[v] + weight(g, v, w);
                insert(H(v, w, D[w]));
            }
            w = next(g, v, w);
        }
    }
}

int main(){
    int n, m, a, b, c, s;
    priority_queue< Heap, vector<Heap>, Comparator<Heap, Heap> > pq;
    vector<int> D(n, INFINITY); 
    pair<int, int>p;//pair
    vector<p> g[n]; //graph

    cin >> n >> m;
    
    for(int i=0; i<m; i++){ 
        cin >> a >> b >> c;
        g[a].push_back({b, c}); 
        g[b].push_back({a, c});
    }

    dijkstra(g, s, D, pq, p)

}