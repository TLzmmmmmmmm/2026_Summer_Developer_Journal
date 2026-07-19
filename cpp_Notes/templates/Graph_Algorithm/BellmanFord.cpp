#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define valueType long long

const valueType inf = numeric_limits<valueType>::max() / 4;

struct Edge {
    int u;
    int v;
    valueType w;

    Edge() {}

    Edge(int _u, int _v, valueType _w)
        : u(_u), v(_v), w(_w) {}
};

void addEdge(vector<Edge>& edges, int u, int v, valueType w) {
    edges.push_back(Edge(u, v, w));
}

void bellmanFordInit(int n, int st, valueType* d) {
    for (int i = 0; i < n; ++i) {
        d[i] = inf;
    }

    d[st] = 0;
}

bool bellmanFordUpdate(
    const vector<Edge>& edges,
    valueType* d
) {
    bool updated = false;

    for (const Edge& edge : edges) {
        if (d[edge.u] == inf) {
            continue;
        }

        if (d[edge.u] + edge.w < d[edge.v]) {
            d[edge.v] = d[edge.u] + edge.w;
            updated = true;
        }
    }

    return updated;
}

bool BellmanFord(
    int n,
    int st,
    const vector<Edge>& edges,
    valueType* d
) {
    bellmanFordInit(n, st, d);

    // A shortest simple path contains at most n - 1 edges.
    for (int i = 1; i < n; ++i) {
        if (!bellmanFordUpdate(edges, d)) {
            break;
        }
    }

    // Check for a reachable negative-weight cycle.
    for (const Edge& edge : edges) {
        if (
            d[edge.u] != inf &&
            d[edge.u] + edge.w < d[edge.v]
        ) {
            return false;
        }
    }

    return true;
}