# Algorithms Collection

This repository contains implementations of various algorithms and data structures.

## Contents

### Dynamic Programming
- [Traveling Salesman Problem](dp/travelsales.cpp) - Implementation of the TSP using dynamic programming with bitmasks
- [Basic DP Examples](dp/basic.cpp) - Basic dynamic programming examples

### Graph Algorithms
- [Dijkstra's Algorithm](Graph/dijkastra.cpp) - Single-source shortest path algorithm

### Disjoint Set (Union-Find)
- [Disjoint Set Implementation](Disjoint%20Set/disjointset.cpp) - Basic implementation of disjoint set data structure
- [LeetCode 1319 Solution](Disjoint%20Set/leetcode1319.cpp) - Number of Operations to Make Network Connected
- [LeetCode 1559 Solution](Disjoint%20Set/leetcode1559.cpp) - Detect Cycles in 2D Grid

### Greedy Algorithms
- [Huffman Coding](greedy/Huffman.Coding.cpp) - Data compression algorithm
- [Minimum Cost Spanning Tree](greedy/minCostSpanningTree/) - Algorithms to find minimum spanning trees
  - [Kruskal's Algorithm](greedy/minCostSpanningTree/kruskal.cpp)
  - [Prim's Algorithm](greedy/minCostSpanningTree/prims.cpp)

## Traveling Salesman Problem

The [Traveling Salesman Problem (TSP)](dp/travelsales.cpp) is implemented using dynamic programming with bitmasks. This approach has a time complexity of O(n²·2ⁿ) and space complexity of O(n·2ⁿ).

### Implementation Details

- Uses recursive DP with memoization
- Represents visited cities using bitmasks
- Finds the minimum cost path that visits all cities exactly once and returns to the starting city
- The state is defined by (mask, pos) where:
  - mask: bitmask representing the set of visited cities
  - pos: current city

### Usage

Compile and run the program:

```bash
g++ -std=c++11 dp/travelsales.cpp -o tsp
./tsp
```

The program uses a sample distance matrix and outputs the minimum cost of the TSP tour.