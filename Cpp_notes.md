# C++ Notes

## Sorting Algorithms

### 1. Selection Sort

- Description:
  - Divide the array into a sorted part and an unsorted part.
  - Repeatedly select the minimum element from the unsorted part.
  - Swap it with the first element of the unsorted part.
  - After the `i`th iteration, the first `i` elements are in their final positions.
- Time Complexity:
  - Best: `O(n^2)`
  - Average: `O(n^2)`
  - Worst: `O(n^2)`
- Space Complexity: `O(1)`
- In-place.
- Usually unstable.
- Performs only `O(n)` swaps, so it can be useful when writing or swapping elements is expensive.

### 2. Insertion Sort

- Description:
  - Maintain a sorted prefix of the array.
  - Take the next element and insert it into the correct position in the sorted prefix.
  - Shift larger elements one position to the right.
- Time Complexity:
  - Best: `O(n)` when the array is already sorted.
  - Average: `O(n^2)`
  - Worst: `O(n^2)`
- Space Complexity: `O(1)`
- In-place.
- Stable if equal elements are not moved past each other.
- Efficient for small or nearly sorted arrays.
- Commonly used as a subroutine in hybrid sorting algorithms.

### 3. Bubble Sort

- Description:
  - Repeatedly compare adjacent elements.
  - Swap them if they are in the wrong order.
  - After each iteration, the largest remaining element moves to the end.
- Time Complexity:
  - Best: `O(n)` with an early-stop flag.
  - Average: `O(n^2)`
  - Worst: `O(n^2)`
- Space Complexity: `O(1)`
- In-place.
- Stable if elements are swapped only when the left element is strictly greater.
- Mainly useful for learning and very small inputs.
- Stop early if no swap occurs during an iteration.

### 4. Merge Sort

- Description:
  - Divide the array into two halves.
  - Recursively sort both halves.
  - Merge the two sorted halves into one sorted array.
- Divide-and-conquer algorithm.
- Time Complexity:
  - Best: `O(n log n)`
  - Average: `O(n log n)`
  - Worst: `O(n log n)`
- Space Complexity:
  - `O(n)` for the standard array implementation.
- Stable if equal elements from the left half are selected first during merging.
- Usually not in-place for arrays.
- Suitable for linked lists and external sorting.
- Guarantees `O(n log n)` time complexity.

### 5. Quick Sort

- Description:
  - Select a pivot.
  - Partition the array so that smaller elements are placed before the pivot.
  - Place larger elements after the pivot.
  - Recursively sort the two partitions.
- Divide-and-conquer algorithm.
- Time Complexity:
  - Best: `O(n log n)`
  - Average: `O(n log n)`
  - Worst: `O(n^2)` when the partitions are extremely unbalanced.
- Space Complexity:
  - Average: `O(log n)` recursion stack.
  - Worst: `O(n)` recursion stack.
- Usually implemented in-place.
- Usually unstable.
- Generally fast for arrays because of good cache locality and small constant factors.
- Randomized pivot selection reduces the probability of the worst case.
- Three-way partitioning is useful when the array contains many duplicate values.

## Graph Algorithms

### Shortest Path Algorithms

#### 1. Dijkstra's Algorithm with a Min-Heap

- Purpose:
  - Find the shortest distances from a source vertex to all reachable vertices.
- Requirements:
  - All edge weights must be non-negative.
- Initialization:
  - `dist[i] = INF`
  - `visited[i] = false`
  - `dist[source] = 0`
  - Push the source vertex into the heap with distance `0`.
- Relaxation:
  - `dist[v] = min(dist[v], dist[u] + weight(u, v))`
- Time Complexity:
  - `O((V + E) log V)` with an adjacency list and a binary heap.
- [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/Dijkstra_Heap.cpp)

#### 2. SPFA — Shortest Path Faster Algorithm

- A queue-based implementation of the Bellman–Ford relaxation process.
- Supports negative edge weights.
- Cannot produce finite shortest paths for vertices affected by a reachable negative-weight cycle.
- Description:
  - Use a queue to store vertices whose outgoing edges may need to be relaxed.
  - Remove the front vertex `u` from the queue.
  - Relax every outgoing edge `(u, v)`.
  - If `dist[v]` is updated and `v` is not already in the queue, push `v` into the queue.
  - Continue until the queue becomes empty.
- Worst-case Time Complexity: `O(VE)`
- A reachable negative-weight cycle can be detected by tracking relaxation or enqueue counts.
- [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/SPFA.cpp)

### Graph Traversal

#### DFS — Depth-First Search

#### BFS — Breadth-First Search

### Topological Sorting

- Find one valid ordering of the vertices that satisfies all directed dependencies.
- Only applies to a DAG — Directed Acyclic Graph.
- The topological order may not be unique.
- If not all vertices can be processed, the graph contains a directed cycle.
- Common implementations:
  - Kahn's algorithm using indegrees and a queue.
  - DFS-based topological sorting.
- [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/Topological_Sort.cpp)

## Dynamic Programming

### 1. Linear DP

- States are usually arranged in a linear order.
- Each state depends on one or more previous states.
- Key concepts:
  - State definition.
  - Base case.
  - State transition.
  - Recurrence relation.
  - Iteration order.

### 2. Memoized Search

- Also called top-down dynamic programming.
- Use recursion to solve subproblems.
- Store previously computed results in an array, vector, map, or hash table.
- Return the cached result when the same state is visited again.
- Avoid repeated computation of overlapping subproblems.

### 3. Knapsack DP

- Common notation:
  - `V`: knapsack capacity.
  - `w[i]`: weight of item `i`.
  - `v[i]`: value of item `i`.
  - `UNREACHABLE`: a state that cannot be formed.

#### 3.1 0/1 Knapsack

- Each item can be selected at most once.

- Basic DP:
  - Find the maximum total value without exceeding the knapsack capacity.
  - Each item has two choices:
    - Do not select it.
    - Select it once.
  - State definition:
    - `dp[i][j]` is the maximum value using the first `i` items with an exact total weight of `j`.
  - State transition:
    - Do not select item `i`:
      - `dp[i - 1][j]`
    - Select item `i`:
      - `dp[i - 1][j - w[i]] + v[i]`
    - Therefore:
      - `dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i])`
    - The second transition is allowed only when:
      - `j >= w[i]`
      - `dp[i - 1][j - w[i]]` is reachable.
  - Initialization:
    - `dp[0][0] = 0`
    - `dp[0][j] = UNREACHABLE` for every `j > 0`.
  - Final answer for capacity at most `V`:
    - `max(dp[n][j])` for `0 <= j <= V`.
  - [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/01_Knapsack.cpp)

- Space Optimization:
  - Replace the two-dimensional DP array with a one-dimensional array.
  - State:
    - `dp[j]` is the maximum value with an exact total weight of `j`.
  - Iterate the capacity in descending order:
    - From `V` down to `w[i]`.
  - State transition:
    - `dp[j] = max(dp[j], dp[j - w[i]] + v[i])`
  - Descending iteration prevents the current item from being selected more than once.
  - [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/01_Knapsack_optimized.cpp)

#### 3.2 Complete Knapsack

- Each item can be selected an unlimited number of times.

- Basic DP:
  - Find the maximum total value without exceeding the knapsack capacity.
  - State definition:
    - `dp[i][j]` is the maximum value using the first `i` item types with an exact total weight of `j`.
  - Suppose item `i` is selected `k` times:
    - `0 <= k <= j / w[i]`
  - State transition:
    - `dp[i][j] = max(dp[i - 1][j - k * w[i]] + k * v[i])`
    - Take the maximum over all valid values of `k`.
  - Initialization:
    - `dp[0][0] = 0`
    - `dp[0][j] = UNREACHABLE` for every `j > 0`.
  - [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/Complete_Knapsack_basic.cpp)

- Time Optimization:
  - Optimized state transition:
    - `dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i])`
  - The second term uses row `i`, so item `i` may be selected again.
  - The explicit `k` loop is no longer required.
  - Time Complexity:
    - Reduced from approximately `O(nV^2)` to `O(nV)`.
  - [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/Complete_Knapsack_time_optimized.cpp)

- Space Optimization:
  - Each state depends only on the current row and the previous row.
  - Replace the two-dimensional array with a one-dimensional array.
  - Iterate the capacity in ascending order:
    - From `w[i]` to `V`.
  - State transition:
    - `dp[j] = max(dp[j], dp[j - w[i]] + v[i])`
  - Ascending iteration allows the current item to be selected repeatedly.
  - [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/Complete_Knapsack_space_optimized.cpp)