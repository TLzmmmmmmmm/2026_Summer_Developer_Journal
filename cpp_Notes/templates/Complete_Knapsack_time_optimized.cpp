#include <iostream>
using namespace std;

#define maxn 1001
#define maxv 1001
#define inf -1
#define init 0
#define vType int

vType opt(vType a, vType b) {
    if (a == inf) return b;
    if (b == inf) return a;
    return max(a, b);
}
// n -> number of items 
// V -> total available space
// w -> space of each item
// v -> value of each item
// dp -> value of optimized combination
void KnapsackComplete(int n, int V, int w[maxn], vType v[maxn], vType dp[maxn][maxv]) {
    // 1. initialize
    for (int i = 1; i <= V; i++) {
        dp[0][i] = inf;
    }
    dp[0][0] = init;

    // 2. state transition
    for (int i = 1; i <= n; i++) {
        for (int j = 0 ; j < w[i]; ++j) {
            dp[i][j] = dp[i-1][j];
        }
        for (int j = w[i]; j <= V; j++) {
            dp[i][j] = opt(dp[i-1][j], dp[i][j-w[i]] + v[i]);
        }
    }
}