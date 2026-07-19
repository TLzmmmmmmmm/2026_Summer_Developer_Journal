#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
}

void BFS(
    int start,
    const vector<vector<int>>& graph,
    vector<bool>& visited
) {
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << ' ';

        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void BFSTraversal(
    const vector<vector<int>>& graph
) {
    int n = static_cast<int>(graph.size());

    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            BFS(i, graph, visited);
        }
    }
}