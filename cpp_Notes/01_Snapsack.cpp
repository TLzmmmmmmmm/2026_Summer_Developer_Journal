#include <iostream>

using namespace std;

#define maxn 101
#define maxv 1001
#define inf -1
#define init 0
#define vType int

vType opt(vType a, vType b) {
    if (a == inf) return b;
    if (b == inf) return a;
    return max(a, b);
}

void Knapsack01(int n, int V, int w[maxn], vType v[maxn], vType dp[maxn][maxv]) {
    // 1. initialize
    for (int i = 1; i <= V; i++) {
        dp[0][i] = inf;
    }
    dp[0][0] = 0;

    // 2. state transition
    for (int i = 1; i <= n; i++) {
        for (int j = 0 ; j <= V; j++) {
            if (j >= w[i]) {
                dp[i][j] = opt( dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}