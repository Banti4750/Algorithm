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
    vector<vector<int>>dir = {{0 , -1} , {-1 , 0}}; 
    bool containsCycle(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        DisjointSet ds(row * col);
        for(int i =0;i<row;i++){
            for(int j =0;j<col;j++){
                 int index = i * col + j;
                for(auto d:dir){
                    int ni= i+d[0];
                    int nj = j+d[1];

                    if(ni >= 0 && ni < row && nj >= 0 && nj < col && grid[i][j] == grid[ni][nj] ){
                         int newindex = ni * col + nj;
                         if(ds.findUPar(index) == ds.findUPar(newindex)){
                            return true;
                         }else{
                            ds.unionByRank(index, newindex);
                         }
                    }
                }
            }
        }
        return false;
    }
};

int main(){
    vector<vector<char>>grid = {{'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'}};
    Solution sol;
    cout<<sol.containsCycle(grid)<<endl;
    return 0;   
}