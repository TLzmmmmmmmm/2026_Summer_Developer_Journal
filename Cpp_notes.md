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
     - dp[i][j] == the combination of first i elements within space of j
     - dp[i][j] = max( dp[i-1][j], dp[i-1][j-c[i]] + w[i])
     - dp[0][0] = 0 and dp[o][i] = inf
     - [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/01_Snapsack.cpp)
   - space optimization
     - use 1D array to replace 2D array
     - update ith row value from back to front using (i-1)th row's value
     - [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/01_Snapsack_optimized.cpp)
        
