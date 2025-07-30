# Greedy Algorithms

This directory contains implementations of various greedy algorithms.

## Huffman Coding

The [Huffman Coding](Huffman.Coding.cpp) is a lossless data compression algorithm that assigns variable-length codes to input characters based on their frequencies.

### Implementation Details

- Uses a min-heap (priority queue) to build the Huffman tree
- Represents characters with variable-length binary codes
- Characters with higher frequencies get shorter codes

#### Key Components:

1. **Node Structure**:
   ```cpp
   class Node {
   public:
       int data;  // frequency
       Node *left, *right;
       // ...
   };
   ```

2. **Min Heap**:
   ```cpp
   class Compare {
   public:
       bool operator()(Node* a, Node* b) {
           return a->data > b->data;
       }
   };
   
   priority_queue<Node*, vector<Node*>, Compare> pq;
   ```

3. **Tree Construction**:
   ```cpp
   while (pq.size() >= 2) {
       Node* l = pq.top();
       pq.pop();
       Node* r = pq.top();
       pq.pop();
       Node* newNode = new Node(l->data + r->data);
       newNode->left = l;
       newNode->right = r;
       pq.push(newNode);
   }
   ```

4. **Code Generation**:
   ```cpp
   void preorder(Node* root, vector<string> &ans, string curr) {
       // ...
   }
   ```

### Time Complexity

- O(n log n) where n is the number of unique characters

### Space Complexity

- O(n) for the priority queue and tree structure

## Minimum Cost Spanning Tree

This subdirectory contains two classic algorithms for finding the minimum spanning tree of a graph:

### 1. [Kruskal's Algorithm](minCostSpanningTree/kruskal.cpp)

Kruskal's algorithm finds a minimum spanning tree by adding edges in order of increasing weight, skipping edges that would create a cycle.

#### Key Features:

- Uses a Disjoint Set data structure to detect cycles
- Sorts edges by weight
- Greedily selects the minimum weight edge that doesn't form a cycle

#### Time Complexity:

- O(E log E) where E is the number of edges (due to sorting)

### 2. [Prim's Algorithm](minCostSpanningTree/prims.cpp)

Prim's algorithm builds a minimum spanning tree by starting from a vertex and always adding the minimum weight edge that connects a vertex in the tree to a vertex outside the tree.

#### Key Features:

- Uses a priority queue to select the next minimum weight edge
- Maintains a set of visited vertices
- Similar to Dijkstra's algorithm in implementation

#### Time Complexity:

- O((V+E) log V) where V is the number of vertices and E is the number of edges

### Example Usage

Both algorithms are demonstrated with the same example graph:

```cpp
vector<tuple<int, int, int>> edges = {
    {1, 2, 5}, {2, 3, 3}, {3, 4, 6}, {4, 1, 4}, {2, 4, 2}
};
```

### Compile and Run

```bash
# For Huffman Coding
g++ -std=c++11 Huffman.Coding.cpp -o huffman
./huffman

# For Kruskal's Algorithm
g++ -std=c++11 minCostSpanningTree/kruskal.cpp -o kruskal
./kruskal

# For Prim's Algorithm
g++ -std=c++11 minCostSpanningTree/prims.cpp -o prims
./prims
```