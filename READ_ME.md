# Matrix Chain Multiplication (MCM)

This folder contains a **C implementation of the Matrix Chain Multiplication problem** using **Dynamic Programming (O(n³))**.  
The program calculates the **minimum number of scalar multiplications** needed to multiply a chain of matrices.

---

## 🧠 Problem Statement
Given a sequence of matrices `A1, A2, ..., An`, with dimensions `p0 x p1, p1 x p2, ..., pn-1 x pn`,  
find the minimum number of multiplications required to multiply the matrices in an optimal order.

---

## 💡 Example

**Input:**<br>
Enter the number of matrices: 4<br>
Enter the dimensions of matrices (n+1 numbers):<br>
40 20 30 10 30


**Output:**<br>
Minimum number of multiplications = 26000


---

## ⚙️ How to Compile and Run

**Compile:**
```bash
gcc -std=c11 -O2 -Wall Matrix_Chain_Multiplication.c -o mcm
```

Time Complexity <br>
| Type      | Complexity |
| --------- | ---------- |
| **Time**  | O(n³)      |
| **Space** | O(n²)      |
