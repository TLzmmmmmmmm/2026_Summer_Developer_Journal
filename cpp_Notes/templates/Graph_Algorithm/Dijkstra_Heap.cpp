#include <iostream>
#include <vector>
#include <queue>


using namespace std;

#define inf 1000000001
#define maxn 100001
#define valueType int

struct Dist {
    int v;
    valueType w;
    Dist() {}
    Dist(int _v, valueType _w) : v(_v), w(_w) {}
    bool operator < (const Dist& d) const {
        return w > d.w;
    }
};

typedef priority_queue<Dist> Heap;

void addEdge(vector<Dist>* edges, int u, int v, valueType w) {
    edges[u].push_back(Dist(v, w));
}

void dijkstraInit(int n, int st, Heap& heap, bool* visited, valueType* d) {
    for (int i = 0 ; i < n; ++i) {
        d[i] = inf;
        visited[i] = false;
    }
    d[st] = 0;
    heap.push(Dist(st, d[st]));
}

int dijkstraFindMin(Heap& heap) {
    Dist s = heap.top();
    heap.pop();
    return s.v;
}

void dijkstraUpdate(int u, vector<Dist>* edges, Heap& heap, bool* visited, valueType* d) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;
    for(int i = 0 ; i < edges[u].size(); ++i) {
        int v = edges[u][i].v;
        valueType w = edges[u][i].w;
        if (d[u] + w < d[v]) {
            d[v] = d[u] + w;
            heap.push(Dist(v, d[v]));
        }
    }
}

void DijkStraHeap(int n, int st, vector<Dist>* edges, valueType* d) {
    Heap heap;
    bool visited[maxn] = {false};
    dijkstraInit(n, st, heap, visited, d);
    while(!heap.empty()) {
        int u = dijkstraFindMin(heap);
        dijkstraUpdate(u, edges, heap, visited, d);
    }
}