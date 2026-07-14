# C++ Notes

## Algorithm
### 1. Dijkstra + Heap
   - find the shortest path of all nodes from the given start point
   - initialize
     - dist[i] = inf
     - visited[i] = false
     - dist[s] = false
     - heap.push((s, dist[s]))
   - update: dist[v] = min(dist[v], dist[u]+w(u, v))
   - Code:
    ```cpp
      struct Dist {
        int v;
        valueType w;
        Dist() {}
        Dist(int _v, valueType _w) : v(_v), w(_w) {}
        bool operator < (const Dist& d) const {
          return w > d.w;
        }
      }
      typedef priority_queue<Dist> Heap;

      void addEdge(vector<Dist>* edges, int u, int v, valueType w) {
        edges[u].push_back(Dist(v, w))；
      }

      void dijkstraInit(int n, int st, Heap& heap, valueType* d) {
        for
      }

      int dijkstraFindMin(Heap& heap) {
        Dist s = heap.top();
        heap.pop();
        return s.v
      }

      void DijkStraHeap(int n, int st, vector<Dist>* edges, valueType* d) {
        Heap heap;
        bool visited[maxn] = {false};
        dijkstraInit();
        while(!heap.empty()) {
          int u = dijkstraFindMin(heap);
          dijkstraUpdate();
        }
      }
    ```


        
