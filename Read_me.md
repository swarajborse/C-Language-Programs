# 0/1 Knapsack Problem

This folder contains a **C implementation of the 0/1 Knapsack Problem** using **Dynamic Programming (DP)**.  
The program calculates the **maximum total value** that can be obtained in a knapsack of given capacity.

---

## 🧠 Problem Statement
Given:
- `n` items with weights `wt[]` and values `val[]`
- A knapsack of capacity `W`  

Select items such that the **total value is maximized** without exceeding the capacity.  
Each item can be taken **0 or 1 times** (cannot break items).

---

## 💡 Example

**Input:**<br>
Enter the number of items: 4<br>
Enter the weights of items:<br>
2 3 4 5<br>
Enter the values of items:<br>
3 4 5 6<br>
Enter the maximum capacity of knapsack: 5


**Output:**<br>
Maximum value = 7


---

## ⚙️ How to Compile and Run

**Compile:**
```bash
gcc -std=c11 -O2 -Wall Knapsack_0_1.c -o knapsack
```

Time Complexity<br>
| Type      | Complexity |
| --------- | ---------- |
| **Time**  | O(n * W)   |
| **Space** | O(n * W)   |
