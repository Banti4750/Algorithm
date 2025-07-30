# Graph Algorithms

This directory contains implementations of various graph algorithms.

## Dijkstra's Algorithm

The [Dijkstra's Algorithm](dijkastra.cpp) is a popular algorithm for finding the shortest paths between nodes in a graph with non-negative edge weights.

### Implementation Details

Our implementation uses a priority queue (min-heap) to efficiently select the next vertex with the minimum distance:

```cpp
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
```

#### Key Components:

1. **Adjacency List**: Represents the graph with weights
   ```cpp
   unordered_map<int, vector<pair<int, int>>> adj;
   ```

2. **Distance Array**: Tracks the shortest distance from the source to each vertex
   ```cpp
   vector<int> dist(V + 1, INT_MAX);
   ```

3. **Relaxation Step**: The core operation that updates distances when a shorter path is found
   ```cpp
   if (dist[node] + weight < dist[neigh]) {
       dist[neigh] = dist[node] + weight;
       pq.push({dist[neigh], neigh});
   }
   ```

### Time Complexity

- O((V + E) log V) where V is the number of vertices and E is the number of edges

### Space Complexity

- O(V + E) for the adjacency list and priority queue

### Limitations

- May not work correctly with negative edge weights
- Cannot detect negative cycles

### Example Usage

The implementation includes a sample graph with 4 vertices and 5 edges. To use with your own graph:

1. Define your edges as tuples `{u, v, weight}`
2. Set the number of vertices `V`
3. Choose a source vertex

### Compile and Run

```bash
g++ -std=c++11 dijkastra.cpp -o dijkstra
./dijkstra
```

The program will output the shortest distance from the source vertex to all other vertices in the graph.