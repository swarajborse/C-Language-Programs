# 🛣️ Dijkstra’s Algorithm using Set (C++ Solution)

## 📘 Problem Statement
Given a weighted, undirected graph represented by a list of edges, find the **shortest distance** from a given **source vertex** to all other vertices in the graph using **Dijkstra’s Algorithm**.

The graph is represented as a vector of edges, where each edge has three integers:  
`[u, v, wt]` — representing an edge between vertices `u` and `v` with weight `wt`.

---

## 💡 Approach / Algorithm
This solution implements **Dijkstra’s Algorithm** using a **Set (C++ STL)** to efficiently get and update the node with the smallest distance at each step.

### 🔹 Steps:
1. **Graph Construction:**  
   Build an adjacency list of the form `{node → [(adjNode, weight), ...]}` from the given edges.

2. **Initialization:**  
   - Set all distances to `∞` (1e9) except the source node which is set to `0`.  
   - Use a **set of pairs** `{distance, node}` to pick the node with the smallest current distance.

3. **Relaxation Process:**  
   - Extract the node with the smallest distance from the set.  
   - For each of its adjacent nodes:
     - If a shorter path is found, update the distance and insert the new pair into the set.  
     - Remove outdated entries for that node to keep the set optimized.

4. **Result:**  
   Return the distance array containing the shortest path from the source node to all other vertices.

---

## 🧠 Time & Space Complexity
- **Time Complexity:** `O(E * log V)` — Each edge relaxation involves a logarithmic insertion/deletion in the set.  
- **Space Complexity:** `O(V + E)` — For adjacency list and distance tracking.

---