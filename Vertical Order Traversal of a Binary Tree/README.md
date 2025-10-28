# 🌳 Vertical Order Traversal of a Binary Tree (C++ Solution)

## 📘 Problem Statement
Given the **root of a binary tree**, the task is to return the **vertical order traversal** of its nodes' values.

Nodes that are in the same **vertical line** are grouped together and listed from **top to bottom**.  
If multiple nodes share the same position, their values should be sorted in ascending order.

---

## 💡 Approach / Algorithm
This solution uses **Breadth-First Search (BFS)** traversal while tracking each node's **vertical** and **level** position to correctly organize nodes into vertical columns.

### 🔹 Steps:
1. **Position Tracking:**  
   - Assign coordinates to each node:  
     - Vertical (`x`) decreases by 1 for left child and increases by 1 for right child.  
     - Level (`y`) increases by 1 as we go down the tree.

2. **Data Structure Used:**  
   - A nested map: `map<int, map<int, multiset<int>>>`  
     - Outer map → vertical order (`x`)  
     - Inner map → level order (`y`)  
     - Multiset → sorted values at the same position

3. **Traversal:**  
   - Use a **queue** for BFS to process nodes level by level.  
   - For each node, insert its value in the corresponding position in the map.

4. **Result Construction:**  
   - After traversal, iterate through the map in order of vertical positions.  
   - Combine all levels for each vertical into a single list.

---

## 🧠 Time & Space Complexity
- **Time Complexity:** `O(N log N)` — due to ordered maps and multiset insertions.  
- **Space Complexity:** `O(N)` — for storing the nodes and traversal data.

---