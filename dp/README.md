# Dynamic Programming Algorithms

This directory contains implementations of various dynamic programming algorithms.

## Traveling Salesman Problem (TSP)

The [Traveling Salesman Problem](travelsales.cpp) is a classic algorithmic problem in the field of computer science and operations research. The problem asks for the shortest possible route that visits each city exactly once and returns to the origin city.

### Implementation

Our implementation uses dynamic programming with bitmasks to solve the TSP efficiently:

```cpp
int tsp(int mask, int pos, vector<vector<int>> &dist, vector<vector<int>> &dp, int n)
```

#### Parameters:
- `mask`: A bitmask representing the set of cities that have been visited
- `pos`: The current city position
- `dist`: Distance/cost matrix between cities
- `dp`: Memoization table to store already computed results
- `n`: Total number of cities

#### Time Complexity: O(n²·2ⁿ)
- We have 2ⁿ possible subsets of cities (represented by bitmasks)
- For each subset, we consider n possible current positions
- For each state, we iterate through n cities to find the next city to visit

#### Space Complexity: O(n·2ⁿ)
- We need to store results for n·2ⁿ states in the dp table

### Example Usage

The implementation includes a sample distance matrix for 4 cities:

```cpp
vector<vector<int>> cost = {
    {0, 10, 15, 20}, 
    {10, 0, 35, 25}, 
    {15, 35, 0, 30}, 
    {20, 25, 30, 0}
};
```

To use with your own data, replace this matrix with your own distance matrix where `cost[i][j]` represents the cost of traveling from city `i` to city `j`.

### Compile and Run

```bash
g++ -std=c++11 travelsales.cpp -o tsp
./tsp
```

## Basic Dynamic Programming Examples

The [basic.cpp](basic.cpp) file demonstrates fundamental dynamic programming concepts using the Fibonacci sequence as an example. It includes:

### Top-Down Approach (Memoization)

```cpp
int fib(int n, vector<int>& dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}
```

### Bottom-Up Approach (Tabulation)

```cpp
// In main function
int n = 10;
vector<int> fib(n + 1, 0);
fib[0] = 0;
fib[1] = 1;
for(int i = 2; i <= n; i++) {
    fib[i] = fib[i-2] + fib[i-1];
}
```

The file illustrates the key difference between greedy algorithms and dynamic programming: in greedy algorithms, we follow a predefined process, while in dynamic programming, we explore all possible solutions and store results for future use.