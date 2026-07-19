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

void Knapsack01(int n, int V, int w[maxn], vType v[maxn], vType dp[maxv]) {
    // 1. initialize
    for (int i = 1; i <= V; i++) {
        dp[i] = inf;
    }
    dp[0] = init;

    // 2. state transition
    for (int i = 1; i <= n; i++) {       
        for (int j = V ; j >= w[i]; j--) {
            if (dp[j-w[i]] != inf)
            {
                dp[j] = max(dp[j],dp[j-w[i]] + v[i]);
            }
        }
    }
}
