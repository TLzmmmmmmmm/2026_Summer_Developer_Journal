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
   - [Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/Dijkstra_Heap.cpp)


        
