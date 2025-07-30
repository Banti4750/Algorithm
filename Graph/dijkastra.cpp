// use for find shortest path both for directed and undirected
//DRAWBACK  ->>> it amy or may not work for negative edges

//  Relaxation step is important

// if(d[u] + cost(u , v) < d[u]){
//     d[u] = d[v] + cost(u , v);
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    // List of edges: {u, v, weight}
    vector<tuple<int, int, int>> edges = {
        {1, 2, 5}, {2, 3, 3}, {3, 4, 6}, {4, 1, 4}, {2, 4, 2}
    };

    // Build adjacency list with weights
    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto [u, v, w] : edges) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected
    }

    int V = 4; // Number of vertices
    int source = 1; // Source node

    // Distance array, initialized with INF
    vector<int> dist(V + 1, INT_MAX);
    dist[source] = 0;

    // Min-heap priority queue -> {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        // Traverse all neighbors
        for (auto [neigh, weight] : adj[node]) {
            if (dist[node] + weight < dist[neigh]) {
                dist[neigh] = dist[node] + weight;
                pq.push({dist[neigh], neigh});
            }
        }
    }

    // Print shortest distances
    for (int i = 1; i <= V; i++) {
        cout << "Distance from " << source << " to " << i << " = ";
        if (dist[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}