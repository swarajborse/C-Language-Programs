# 🧭 Shortest Path in Binary Matrix (C++ Solution)

## 📘 Problem Statement
Given an `n x n` binary matrix `grid`, where each cell is either `0` (open) or `1` (blocked), find the **shortest clear path** from the **top-left cell (0,0)** to the **bottom-right cell (n-1,n-1)**.

A clear path can move in **8 possible directions** (up, down, left, right, and all 4 diagonals).  
If no such path exists, return `-1`.

---

## 💡 Approach / Algorithm
This solution uses a **Breadth-First Search (BFS)** algorithm to find the shortest path in an unweighted grid.

### 🔹 Steps:
1. **Check Base Condition:**  
   If the starting or ending cell is blocked (`1`), return `-1`.

2. **Initialize:**  
   - A `dist` matrix to store the minimum distance to reach each cell.  
   - A queue for BFS traversal storing `(distance, (row, col))`.

3. **BFS Traversal:**  
   - Start from `(0, 0)` with distance `1`.  
   - Explore all **8 directions** (up, down, left, right, and diagonals).  
   - Update distances and push valid moves into the queue.  
   - Return the distance once `(n-1, n-1)` is reached.

4. **If Unreachable:**  
   After BFS ends, if destination isn’t reached, return `-1`.

---

## 🧠 Time & Space Complexity
- **Time Complexity:** `O(n²)` — Each cell is visited at most once.  
- **Space Complexity:** `O(n²)` — For distance matrix and queue storage.

---