#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define valueType long long

const valueType inf = numeric_limits<valueType>::max() / 4;

void floydInit(
    int n,
    vector<vector<valueType>>& d
) {
    d.assign(
        n,
        vector<valueType>(n, inf)
    );

    for (int i = 0; i < n; ++i) {
        d[i][i] = 0;
    }
}

void addEdge(
    vector<vector<valueType>>& d,
    int u,
    int v,
    valueType w
) {
    // Keep the smaller edge if parallel edges exist.
    d[u][v] = min(d[u][v], w);
}

void floydUpdate(
    int n,
    int k,
    vector<vector<valueType>>& d
) {
    for (int i = 0; i < n; ++i) {
        if (d[i][k] == inf) {
            continue;
        }

        for (int j = 0; j < n; ++j) {
            if (d[k][j] == inf) {
                continue;
            }

            d[i][j] = min(
                d[i][j],
                d[i][k] + d[k][j]
            );
        }
    }
}

bool FloydWarshall(
    int n,
    vector<vector<valueType>>& d
) {
    // k must be the outermost loop.
    for (int k = 0; k < n; ++k) {
        floydUpdate(n, k, d);
    }

    // A negative diagonal value means a negative cycle exists.
    for (int i = 0; i < n; ++i) {
        if (d[i][i] < 0) {
            return false;
        }
    }

    return true;
}