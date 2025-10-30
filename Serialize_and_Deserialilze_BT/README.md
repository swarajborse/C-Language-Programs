# 🌳 Serialize and Deserialize Binary Tree (C++ Solution)

## 📘 Problem Statement
Design an algorithm to **serialize** (convert a binary tree into a string) and **deserialize** (rebuild the tree from that string).  
Your algorithm should ensure that both processes are **lossless** — meaning that the deserialized tree must be identical to the original one.

Serialization converts the tree structure into a string using **level-order traversal (BFS)**.  
Deserialization reconstructs the binary tree from this string representation.

---

## 💡 Approach / Algorithm
This solution uses **Breadth-First Search (BFS)** traversal to serialize and deserialize the binary tree.

### 🔹 Serialization:
1. Use a queue to perform level-order traversal.
2. Append each node’s value to a string separated by commas.
3. For `NULL` nodes, append `#` to mark missing children.
4. The final string represents the structure and values of the binary tree.

### 🔹 Deserialization:
1. Split the serialized string using a `stringstream` with commas as delimiters.
2. The first value creates the root node.
3. Use a queue to reconstruct left and right child nodes for each parent level by level.
4. Replace `#` tokens with `NULL` pointers to maintain the correct structure.

---

## 🧠 Time & Space Complexity
- **Time Complexity:** `O(N)` — Each node is processed exactly once during both serialization and deserialization.  
- **Space Complexity:** `O(N)` — For the queue and the output string.

---