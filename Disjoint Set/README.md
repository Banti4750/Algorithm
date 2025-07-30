# Disjoint Set (Union-Find)

This directory contains implementations of the Disjoint Set data structure (also known as Union-Find) and its applications.

## Disjoint Set Implementation

The [disjointset.cpp](disjointset.cpp) file contains a class-based implementation of the Disjoint Set data structure with union by rank optimization and path compression.

### Key Components

#### Data Structure

```cpp
class DisjointSet {
    vector<int> rank, parent;
    // ...
};
```

- `parent`: Stores the parent of each node
- `rank`: Stores the rank (approximate height) of each set for union by rank optimization

#### Operations

1. **Find Operation with Path Compression**
   ```cpp
   int findUPar(int node) {
       if(node == parent[node]) {
           return node;
       } else {
           return parent[node] = findUPar(parent[node]);
       }
   }
   ```
   - Time Complexity: O(α(n)) amortized, where α is the inverse Ackermann function (practically constant)

2. **Union by Rank**
   ```cpp
   void unionByRank(int u, int v) {
       int pu = findUPar(u);
       int pv = findUPar(v);
       if(pu == pv) {
           return;
       }
       if(rank[pu] > rank[pv]) {
           parent[pv] = pu;
       } else if(rank[pu] < rank[pv]) {
           parent[pu] = pv;
       } else {
           parent[pv] = pu;
           rank[pu]++;
       }
   }
   ```
   - Time Complexity: O(α(n)) amortized

### Applications

The Disjoint Set data structure is used in various algorithms and problems:

1. **Detecting Cycles in Undirected Graphs**
   - If we try to union two vertices that already belong to the same set, a cycle is detected

2. **Kruskal's Algorithm for Minimum Spanning Tree**
   - Used to efficiently check if adding an edge creates a cycle

3. **Connected Components in a Graph**
   - Efficiently find and merge connected components

4. **LeetCode Problems**:
   - [LeetCode 1319](leetcode1319.cpp): Number of Operations to Make Network Connected
   - [LeetCode 1559](leetcode1559.cpp): Detect Cycles in 2D Grid

### Example Usage

```cpp
int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    
    // Check if two elements are in the same set
    if (ds.findUPar(3) == ds.findUPar(7))
        cout << "Same\n";
    else
        cout << "Not same\n";
        
    // Union two sets
    ds.unionByRank(3, 7);
    
    // Check again
    if (ds.findUPar(3) == ds.findUPar(7))
        cout << "Same\n";
    else
        cout << "Not same\n";
        
    return 0;
}
```

### Compile and Run

```bash
g++ -std=c++11 disjointset.cpp -o disjointset
./disjointset
```