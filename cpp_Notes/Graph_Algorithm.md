# Graph Algorithms

## Shortest Path Algorithms

### 1. Dijkstra's Algorithm with a Min-Heap

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

### 2. Bellman–Ford Algorithm

- Purpose:
  - Find the shortest distances from one source vertex.
  - Support negative edge weights.
  - Detect a reachable negative-weight cycle.
- Core Idea:
  - Repeatedly relax every edge.
  - A shortest simple path contains at most `V - 1` edges.
- Initialization:
  - `dist[i] = INF`
  - `dist[source] = 0`
- Relaxation:
  - For every edge `(u, v, weight)`:
    - If `dist[u]` is reachable:
      - `dist[v] = min(dist[v], dist[u] + weight)`
- Basic Steps:
  - Repeat edge relaxation `V - 1` times.
  - Stop early if no distance changes during an iteration.
  - Perform one additional iteration:
    - If a distance can still be reduced, a reachable negative-weight cycle exists.
- Time Complexity:
  - `O(VE)`
- Space Complexity:
  - `O(V)`
- Efficient when:
  - Negative edge weights may exist.
  - Negative-cycle detection is required.
- Disadvantage:
  - Usually slower than Dijkstra when all edge weights are non-negative.

### 3. SPFA — Shortest Path Faster Algorithm

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

### 4. Floyd–Warshall Algorithm

- Purpose:
  - Find the shortest distances between every pair of vertices.
- Support both positive and negative edge weights.
- Requirement:
  - The graph must not contain a negative-weight cycle if finite shortest paths are required.
- State Definition:
  - `dist[i][j]` is the shortest known distance from vertex `i` to vertex `j`.
- Initialization:
  - `dist[i][i] = 0`
  - `dist[u][v] = weight(u, v)` for every edge.
  - All other distances are initialized to `INF`.
- State Transition:
  - Consider whether vertex `k` is used as an intermediate vertex:
    - `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])`
- Iteration Order:
  - `k` must be the outermost loop.
- Time Complexity:
  - `O(V^3)`
- Space Complexity:
  - `O(V^2)`
- Negative-Cycle Detection:
  - After the algorithm, if `dist[i][i] < 0` for any vertex `i`, a negative-weight cycle exists.
- Efficient when:
  - The number of vertices is relatively small.
  - Many shortest-path queries between different pairs are required.
- Important:
  - Avoid adding `INF` to another value during the state transition.

## Minimum Spanning Tree Algorithms

- Purpose:
  - Connect all vertices of a connected, undirected, weighted graph.
  - Minimize the total weight of the selected edges.
  - A spanning tree contains exactly `V - 1` edges.
- Requirement:
  - The graph must be undirected.
  - If the graph is disconnected, the result is a minimum spanning forest.

### 1. Prim's Algorithm

- Core Idea:
  - Start from one vertex.
  - Repeatedly add the minimum-weight edge that connects the current tree to a new vertex.
- Common Implementation:
  - Use an adjacency list and a min-heap.
- Basic Steps:
  - Mark a starting vertex as reachable with cost `0`.
  - Push it into the min-heap.
  - Repeatedly extract the vertex with the minimum connection cost.
  - Ignore it if it is already in the tree.
  - Add its cost to the answer.
  - Update the minimum connection costs of its unvisited neighbors.
- Time Complexity:
  - `O((V + E) log V)` with an adjacency list and a binary heap.
  - `O(V^2)` with an adjacency matrix.
- Space Complexity:
  - `O(V + E)`
- Efficient when:
  - The graph is dense when using the matrix implementation.
  - The graph is represented by adjacency lists and edge-by-edge sorting is unnecessary.
- Similarity to Dijkstra:
  - Both may use a min-heap.
  - Dijkstra minimizes distance from a source.
  - Prim minimizes the cost of connecting a new vertex to the current tree.

## Graph Traversal

### DFS — Depth-First Search

### BFS — Breadth-First Search

## Topological Sorting

- Find one valid ordering of the vertices that satisfies all directed dependencies.
- Only applies to a DAG — Directed Acyclic Graph.
- The topological order may not be unique.
- If not all vertices can be processed, the graph contains a directed cycle.
- Common implementations:
  - Kahn's algorithm using indegrees and a queue.
  - DFS-based topological sorting.
- [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/Topological_Sort.cpp)