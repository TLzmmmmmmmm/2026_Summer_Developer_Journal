#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
}

void DFS(
    int u,
    const vector<vector<int>>& graph,
    vector<bool>& visited
) {
    visited[u] = true;

    cout << u << ' ';

    for (int v : graph[u]) {
        if (!visited[v]) {
            DFS(v, graph, visited);
        }
    }
}

void DFSTraversal(
    const vector<vector<int>>& graph
) {
    int n = static_cast<int>(graph.size());

    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            DFS(i, graph, visited);
        }
    }
}