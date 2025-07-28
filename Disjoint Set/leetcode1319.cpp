#include <bits/stdc++.h>
using namespace std;
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
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;  // Not enough cables

        DisjointSet ds(n);
        int extraEdges = 0;

        for (const auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];
            ds.unionByRank(u, v);
            
        }
         int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findUPar(i) == i){
                components++;
            }
                
        }

        return components -1;

    }
};

int main(){
    vector<pair<int,int>>v;
    int n = 5;
    vector<vector<int>>connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};
    Solution obj;
    cout<<obj.makeConnected(n, connections);
    return 0;
}   
