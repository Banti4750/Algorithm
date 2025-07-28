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

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);   
     if (ds.findUPar(3) == ds.findUPar(7))   
        cout << "Same\n";   
    else            
        cout << "Not same\n";
    ds.unionByRank(3, 7);
    if (ds.findUPar(3) == ds.findUPar(7))
        cout << "Same\n";
    else
        cout << "Not same\n";   
    return 0;
}