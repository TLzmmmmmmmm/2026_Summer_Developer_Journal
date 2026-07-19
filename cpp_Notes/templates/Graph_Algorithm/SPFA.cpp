#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define maxn 2026
#define maxm 1000
#define etype int
#define inf 1000000000
#define longOrShortPath <

struct EDGE
{
    int v;
    etype w;

    EDGE() {}
    EDGE(int _v, etype _w) {
        v = _v;
        w = _w;
    }
};

vector<EDGE> edges[maxn];
etype dist[maxn];


void initEdges(int n, vector<EDGE>* edges) {
    for (int i = 0; i <= n; i++)
    {
        edges[i].clear();
    } 
}

void addEdge(vector<EDGE>* edges, int u, int v, etype w) {
    edges[u].push_back(EDGE(v, w));
}

void SPFAInit(int n, int s, etype dist[maxn]) {
    for(int i = 0; i <= n; i++) {
        dist[i] = (i == s) ? 0 : inf;
    }
}

void SPFAUpdate(vector<EDGE>* edges, int u, etype dist[maxn], queue<int>& q, bool inqueue[maxn]) {
    for (int i = 0; i < edges[u].size(); i++) {
        int v = edges[u][i].v;
        etype w = edges[u][i].w;
        if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            if (!inqueue[v]) {
                inqueue[v] = true;
                q.push(v);
            }
        }
    }
}

// int gcd(int a, int b) {
//     return !b ? a : gcd(b, a%b);
// }

// int lcm(int a, int b) {
//     return a / gcd(a, b) * b;
// }

void SPFA(vector<EDGE>* edges, int n, int s, etype dist[maxn]) {
    queue<int> q;
    bool inqueue[maxn];
    SPFAInit(n, s, dist);
    q.push(s);
    inqueue[s] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        inqueue[u] = false;
        SPFAUpdate(edges, u, dist, q, inqueue);
    }
}