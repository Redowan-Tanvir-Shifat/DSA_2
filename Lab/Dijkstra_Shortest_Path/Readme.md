# Dijkstra's Algorithm Documentation

## Overview
Dijkstra's Algorithm is a shortest-path algorithm used in graph theory to find the shortest path from a single source node to all other nodes in a weighted graph. It ensures non-negative weights and is widely used in networking, mapping, and routing applications.

---

## Key Concepts
- **Graph Representation**: The graph is represented as a set of vertices (nodes) and edges (connections) with weights.
- **Source Node**: The starting point of the algorithm.
- **Priority Queue**: Often implemented using a min-heap to efficiently retrieve the next node with the smallest distance.
- **Relaxation**: The process of updating the shortest path estimate for a node.

---

## Algorithm Steps
1. **Initialization**:
   - Set the distance to the source node to 0 and all other nodes to infinity.
   - Mark all nodes as unvisited.
   - Use a priority queue (min-heap) to manage nodes based on their current shortest distance.

2. **Processing**:
   - While the priority queue is not empty:
     1. Extract the node with the smallest distance.
     2. For each unvisited neighbor, calculate the distance from the current node.
     3. If the calculated distance is smaller than the current stored distance, update it.
     4. Push the updated neighbor into the priority queue.

3. **Completion**:
   - The algorithm ends when all nodes have been visited or the priority queue is empty.

---

## Input and Output
### Input:
- **Graph**: A weighted graph represented as an adjacency list.
- **Source Node**: The starting node for the algorithm.

### Output:
- A list of the shortest distances from the source node to all other nodes.

---

## Complexity
- **Time Complexity**: O((V + E) log V)
  - V: Number of vertices.
  - E: Number of edges.
  - Explanation: Priority queue operations dominate the complexity.

- **Space Complexity**: O(V + E)
  - To store the graph and distance data.

---

## Example
### Graph:
Adjacency List Representation:
```
Graph = {
    0: [(1, 4), (2, 1)],
    1: [(3, 1)],
    2: [(1, 2), (3, 5)],
    3: []
}
```

### Source Node:
```
Source = 0
```

### Output:
```
Shortest distances from Source 0: [0, 3, 1, 4]
```

---

## Applications
1. **Navigation Systems**: Finding the shortest route between two points.
2. **Network Routing**: Optimizing data packet paths in computer networks.
3. **Robotics**: Path planning for robots in dynamic environments.
4. **Game Development**: Shortest pathfinding for characters.

---

## Limitations
1. Does not work with negative weight edges.
2. May be computationally expensive for very large graphs.

---