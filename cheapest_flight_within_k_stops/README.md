# ✈️ Cheapest Flights Within K Stops (C++ Solution)

## 📘 Problem Statement
You are given a list of flights where each flight is represented as `[u, v, price]`, indicating there is a flight from city `u` to city `v` with a cost of `price`.  
Your task is to find the **cheapest price** from the source city `src` to the destination city `dst` with at most **k stops** in between.

If no such route exists, return `-1`.

---

## 💡 Approach / Algorithm
This solution uses a **Breadth-First Search (BFS)**-based approach similar to the **Bellman-Ford algorithm**, optimized with a queue to track levels (stops).

### Steps:
1. **Graph Representation:**  
   Build an adjacency list where each node stores pairs of `(next_city, flight_cost)`.

2. **Initialization:**  
   - Create a `price[]` array initialized to a large number (`1e9`), representing the minimum cost to reach each node.
   - Set `price[src] = 0`.

3. **BFS Traversal with Stops:**  
   - Use a queue storing `(stops, {current_cost, current_city})`.  
   - For each node, explore its neighbors only if the number of stops ≤ `k`.
   - If a cheaper route to a neighboring node is found, update the cost and push it into the queue.

4. **Result:**  
   After BFS, return `price[dst]` if updated; otherwise, return `-1`.

---

## 🧠 Time & Space Complexity
- **Time Complexity:** `O(N + E)` approximately, where `E` is the number of flights (edges).
- **Space Complexity:** `O(N + E)` due to adjacency list and queue.

---