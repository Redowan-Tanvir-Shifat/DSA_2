# Kruskal's Algorithm Documentation

## Overview
Kruskal's Algorithm is a popular method for finding the Minimum Spanning Tree (MST) of a weighted, undirected graph. It selects edges in increasing order of weight, ensuring no cycles are formed, until all vertices are connected.

---

## Key Concepts
- **Graph Representation**: The graph is represented as a set of vertices and edges with weights.
- **Spanning Tree**: A subset of edges that connects all vertices in the graph without forming cycles.
- **Union-Find**: A data structure used to detect cycles and manage connected components efficiently.

---

## Algorithm Steps
1. **Sort Edges**:
   - Sort all edges of the graph in non-decreasing order of their weights.

2. **Initialize Union-Find**:
   - Create a union-find (disjoint-set) structure to track connected components.

3. **Process Edges**:
   - Iterate through the sorted edges:
     1. Check if the current edge forms a cycle using union-find.
     2. If it does not form a cycle, add the edge to the MST.

4. **Completion**:
   - Repeat until the MST contains exactly (V - 1) edges, where V is the number of vertices.

---

## Input and Output
### Input:
- **Graph**: A weighted, undirected graph represented as an edge list or adjacency list.

### Output:
- A list of edges that form the Minimum Spanning Tree (MST).

---

## Complexity
- **Time Complexity**: O(E log E + E × α(V))
  - E: Number of edges.
  - V: Number of vertices.
  - α(V): Inverse Ackermann function (amortized cost of union-find operations).

- **Space Complexity**: O(V + E)
  - To store the graph and union-find data structure.

---

## Example
### Graph:
Edge List Representation:
```
Edges = [
    (0, 1, 10),
    (0, 2, 6),
    (0, 3, 5),
    (1, 3, 15),
    (2, 3, 4)
]
```

### Output:
```
MST Edges:
(2, 3, 4)
(0, 3, 5)
(0, 1, 10)
```

---

## Applications
1. **Network Design**: Constructing efficient communication or transportation networks.
2. **Clustering**: Grouping data points in hierarchical clustering.
3. **Circuit Design**: Optimizing wiring layouts.
4. **Game Development**: Generating random spanning trees in maps.

---

## Limitations
1. Requires sorting edges, which can be computationally expensive for large graphs.
2. Does not work with directed graphs or graphs containing negative weights.

---
