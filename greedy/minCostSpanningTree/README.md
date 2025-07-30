# Minimum Cost Spanning Tree Algorithms

This directory contains implementations of two classic algorithms for finding the minimum spanning tree (MST) of a graph:

## What is a Minimum Spanning Tree?

A minimum spanning tree (MST) is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together without any cycles and with the minimum possible total edge weight.

## Kruskal's Algorithm

[Kruskal's Algorithm](kruskal.cpp) is a greedy algorithm that finds a minimum spanning tree for a connected weighted graph by adding edges in order of increasing weight, skipping edges that would create a cycle.

### Algorithm Steps:

1. Sort all edges in non-decreasing order of their weight
2. Initialize an empty MST and a disjoint set data structure
3. For each edge in the sorted order:
   - If including this edge doesn't form a cycle (using the disjoint set to check), add it to the MST
   - Otherwise, discard the edge
4. Continue until the MST has (V-1) edges, where V is the number of vertices

### Implementation Highlights:

```cpp
int kruskalMST(int V, vector<Edge> &edges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b) {
        return a.weight < b.weight;
    });

    DisjointSet ds(V);
    int minCost = 0;
    vector<Edge> mst;
    
    for(auto e : edges) {
        if(ds.findUPar(e.u) != ds.findUPar(e.v)) {
            ds.unionByRank(e.u, e.v);
            minCost += e.weight;
            mst.push_back(e);
        }
    }
    
    return minCost;
}
```

### Time Complexity:

- O(E log E) or O(E log V) where E is the number of edges and V is the number of vertices
- The sorting of edges takes O(E log E) time
- The disjoint set operations take O(E log V) time in the worst case

### Space Complexity:

- O(E + V) for storing the edges, MST, and disjoint set data structure

## Prim's Algorithm

[Prim's Algorithm](prims.cpp) is another greedy algorithm that finds a minimum spanning tree by starting from an arbitrary vertex and always adding the minimum weight edge that connects a vertex in the tree to a vertex outside the tree.

### Algorithm Steps:

1. Initialize a priority queue and a visited array
2. Start with any vertex (usually vertex 1) with a weight of 0
3. While the priority queue is not empty:
   - Extract the minimum weight edge
   - If the destination vertex is already visited, skip it
   - Otherwise, mark it as visited, add its weight to the MST cost
   - Add all adjacent edges to the priority queue

### Implementation Highlights:

```cpp
int primMST(int V, unordered_map<int, vector<pair<int, int>>> &adj) {
    vector<bool> visited(V + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1}); // Start with vertex 1 with weight 0
    int minCost = 0;

    while(!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();

        if (visited[node]) continue;
        minCost += weight;
        visited[node] = true;

        for(auto [nei, wt] : adj[node]) {
            if(!visited[nei]) {
                pq.push({wt, nei});
            }
        }
    }

    return minCost;
}
```

### Time Complexity:

- O((V+E) log V) where V is the number of vertices and E is the number of edges
- Each vertex is processed once (O(V))
- Each edge is considered once (O(E))
- Priority queue operations take O(log V) time

### Space Complexity:

- O(V + E) for the adjacency list, priority queue, and visited array

## Comparison

| Aspect | Kruskal's Algorithm | Prim's Algorithm |
|--------|---------------------|-------------------|
| Approach | Edge-based | Vertex-based |
| Data Structure | Disjoint Set | Priority Queue |
| Best for | Sparse graphs | Dense graphs |
| Time Complexity | O(E log E) | O((V+E) log V) |

## Example Usage

Both algorithms are demonstrated with the same example graph:

```cpp
vector<tuple<int, int, int>> edges = {
    {1, 2, 5}, {2, 3, 3}, {3, 4, 6}, {4, 1, 4}, {2, 4, 2}
};
```

### Compile and Run

```bash
# For Kruskal's Algorithm
g++ -std=c++11 kruskal.cpp -o kruskal
./kruskal

# For Prim's Algorithm
g++ -std=c++11 prims.cpp -o prims
./prims
```