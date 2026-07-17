# C++ Notes

## Algorithm
### 1. Dijkstra + Heap
   - find the shortest path of all nodes from the given start point
   - initialize
     - dist[i] = inf
     - visited[i] = false
     - dist[s] = false
     - heap.push((s, dist[s]))
   - update: 
     - dist[v] = min(dist[v], dist[u]+w(u, v))
   - [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/Dijkstra_Heap.cpp)

### 2. SPFA (Shortest Path First Algorithm)
   - Optimized Bellman Ford Algorithm
   - if there exitsts a shortest path, find shortest path from starting node; if not, there is a negative flow cycle.
   - Discription:
     - use queue to store nodes that are going to be relaxed
     - get the front node and list all edges leaving that node, do relax (d[v] = min(d[v], d[u] + w(u, v)))
     - check if v is in the queue, if not, push v into that queue
     - keep doing these steps untill queue is empty
   - Negative Flow Cycle
   - [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/SPFA.cpp)

### 3. Linear DP
   - state transition / recurrence relation

### 4. Topological sort
   - give all possible legal order
   - DAG (Directed Acyclic Graph)
   - [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/Topological_Sort.cpp)

### 5. memorized search
   - use hash table to avoid repetitive calculation
   - recursion

### 6. 0/1 Knapsack
   - basic: 
     - find the optimum combination that has maximum value within limited space
     - each item could only be selected once, either selected or not
     - dp[i][j] == the maximum value of first i elements within space of exactly j
     - dp[i][j] = max( dp[i-1][j], dp[i-1][j-c[i]] + w[i])
     - dp[0][0] = 0 and dp[o][i] = inf
     - [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/01_Knapsack.cpp)
   - space optimization
     - use 1D array to replace 2D array
     - update ith row value from back to front using (i-1)th row's value
     - [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/01_Knapsack_optimized.cpp)

### 7. Complete Knapsack
   - basic
      - find the optimum combination that has maximum value within limited space
      - each item could be selected as many as we want, unlimited
      - dp[i][j] == the maximum value of first i elements within space of exactly j
      - dp[i][j] = max(dp[i-1][j-k*c[i]] + k*w[i]) (the ith item is selected k times, where 0 <= k <= j/c[i]) 
      - [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/Complete_Knapsack_basic.cpp)
   - time optimized
      - dp[i][j] = max(dp[i-1][j], dp[i][j-c[i]] + w[i])
      - we don't need the k loop anymore
      - [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/Complete_Knapsack_time_optimized.cpp)
   - space optimized
      - each element (dp[i][j]) in dp[n][m] depends only on row i and row i-1, so we could reduce the space to 1 row rather than n rows (2D -> 1D)
      - go from the first element to the last element
      - dp[j] = max( dp[j], dp[j-c[i]] + w[i])
      - [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/Complete_Knapsack_space_optimized.cpp)
