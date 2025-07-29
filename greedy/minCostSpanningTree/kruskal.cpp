// select min edges weight but if it is forming cycle then ignore it an move to next smaller edge

// linear
// tc  ->>> (n*n)

// using minHeap
//tc ->>> (v)*logv

#include <bits/stdc++.h>
using namespace std;


struct Edge {
    int u, v, weight;
};


class DisjointSet{
    vector<int>rank , parent;
    public:
    DisjointSet( int n){
        rank.resize(n+1 , 0);
        parent.resize(n+1);
        for(int i =0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }else{
             return parent[node] = findUPar(parent[node]);
        }
    }

    void unionByRank(int u , int v){
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu == pv){
            return ;
        }
        if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }else if((rank[pu] < rank[pv])){
             parent[pu] = pv;
        }else{
              parent[pv] = pu;
               rank[pu]++;
        }
    }
};

int kruskalMST(int V, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b) {
        return a.weight < b.weight;
    });

    DisjointSet ds(V);
    int minCost =0;
    vector<Edge> mst;
    for(auto e:edges){
        if(ds.findUPar(e.u) != ds.findUPar(e.v)) {
            ds.unionByRank(e.u , e.v);
            minCost += e.weight;
            mst.push_back(e);
       }

    }

     cout << "Edges in MST:\n";
    for (auto &e : mst) {
        cout << e.u << " - " << e.v << " : " << e.weight << "\n";
    }

    return minCost;
}

int main(){
     int V = 4; // Number of vertices (1-indexed)

    // Define graph edges
    vector<Edge> edges = {
        {1, 2, 5},
        {2, 3, 3},
        {3, 4, 6},
        {4, 1, 4},
        {2, 4, 2}
    };

    int cost = kruskalMST(V, edges);
    cout << "Minimum Cost of MST: " << cost << endl;

    return 0;
}