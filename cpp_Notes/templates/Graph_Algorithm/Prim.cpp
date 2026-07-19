#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define valueType long long

const valueType inf = numeric_limits<valueType>::max() / 4;

struct Dist {
    int v;
    valueType w;

    Dist() {}

    Dist(int _v, valueType _w)
        : v(_v), w(_w) {}

    bool operator < (const Dist& d) const {
        return w > d.w;
    }
};

typedef priority_queue<Dist> Heap;

void addEdge(
    vector<Dist>* edges,
    int u,
    int v,
    valueType w
) {
    // Prim requires an undirected graph.
    edges[u].push_back(Dist(v, w));
    edges[v].push_back(Dist(u, w));
}

void primInit(
    int n,
    int st,
    Heap& heap,
    vector<bool>& visited,
    vector<valueType>& minCost,
    vector<int>& parent
) {
    visited.assign(n, false);
    minCost.assign(n, inf);
    parent.assign(n, -1);

    minCost[st] = 0;
    heap.push(Dist(st, 0));
}

Dist primFindMin(Heap& heap) {
    Dist current = heap.top();
    heap.pop();

    return current;
}

bool primUpdate(
    const Dist& current,
    vector<Dist>* edges,
    Heap& heap,
    vector<bool>& visited,
    vector<valueType>& minCost,
    vector<int>& parent,
    valueType& totalWeight,
    int& vertexCount
) {
    int u = current.v;

    // Ignore duplicate or outdated heap entries.
    if (
        visited[u] ||
        current.w != minCost[u]
    ) {
        return false;
    }

    visited[u] = true;
    totalWeight += current.w;
    ++vertexCount;

    for (const Dist& edge : edges[u]) {
        int v = edge.v;

        if (
            !visited[v] &&
            edge.w < minCost[v]
        ) {
            minCost[v] = edge.w;
            parent[v] = u;

            heap.push(
                Dist(v, minCost[v])
            );
        }
    }

    return true;
}

bool Prim(
    int n,
    int st,
    vector<Dist>* edges,
    valueType& totalWeight,
    vector<int>& parent
) {
    Heap heap;

    vector<bool> visited;
    vector<valueType> minCost;

    int vertexCount = 0;
    totalWeight = 0;

    primInit(
        n,
        st,
        heap,
        visited,
        minCost,
        parent
    );

    while (!heap.empty()) {
        Dist current = primFindMin(heap);

        primUpdate(
            current,
            edges,
            heap,
            visited,
            minCost,
            parent,
            totalWeight,
            vertexCount
        );
    }

    return vertexCount == n;
}