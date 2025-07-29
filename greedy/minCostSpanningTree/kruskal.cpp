// select min edges weight but if it is forming cycle then ignore it an move to next smaller edge

// linear
// tc  ->>> (n*n)

// using minHeap
//tc ->>> (v)*logv

#include <bits/stdc++.h>
using namespace std;

int main(){
     vector<tuple<int, int, int>> edges = {
        {1, 2, 5}, {2, 3, 3}, {3, 4, 6}, {4, 1, 4}, {2, 4, 2}
    };

    // Build adjacency list with weights
    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto [u, v, w] : edges) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected
    }
}