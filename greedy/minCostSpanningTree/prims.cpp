//Select connnected edge and smaller edge
//time ->> (v+e)logv
//space ->> (v+e)
// bfs + minHeap

#include <bits/stdc++.h>
using namespace std;

int primMST(int V, unordered_map<int, vector<pair<int, int>>> &adj){
    vector<bool>visited(V +1 , false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0 , 1});
    int minCost =0;

    while(!pq.empty()){
        auto [weight, node] = pq.top();
        pq.pop();

          if (visited[node]) continue;
        minCost+=weight;
        visited[node] = true;

        for(auto [nei , wt] : adj[node]){
            if(!visited[nei]){
                pq.push({wt , nei});
            }
        }
    }

    return minCost;
}

int main() {
     vector<tuple<int, int, int>> edges = {
        {1, 2, 5}, {2, 3, 3}, {3, 4, 6}, {4, 1, 4}, {2, 4, 2}
    };

    // Build adjacency list with weights
    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto [u, v, w] : edges) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected
    }
    int V = 4; // Number of nodes
    int cost = primMST(V, adj);
    cout << "Minimum Cost of Spanning Tree: " << cost << endl;

    return 0;
}