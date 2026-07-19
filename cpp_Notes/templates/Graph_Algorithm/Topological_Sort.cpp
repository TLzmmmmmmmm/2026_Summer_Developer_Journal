#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define maxn 100000

void initEdge(int n, vector<int> edges[maxn]) {
    for (int i = 0; i < n ; i++) {
        edges[i].clear();
    }
}

void addEdge(vector<int> edges[maxn], int u, int v) {
    edges[u].push_back(v);
}

bool topoSort(int n, vector<int> edges[maxn], vector<int>& ans) {
    vector<int> deg;
    queue<int> q;
    ans.clear();
    for(int i = 0; i < n; i++) {
        deg.push_back(0);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < edges[i].size() ; j++) {
            int v = edges[i][j];
            deg[v]++;
        }
    }
    for(int i = 0; i < n; i++) {
        if (!deg[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(int i = 0; i < edges[u].size() ; i++) {
            int v = edges[u][i];
            deg[v]--;
            if(deg[v] == 0) {
                q.push(v);
            }
        }
    }

    // return whether there is a cycle or not
    return ans.size() == n;
}