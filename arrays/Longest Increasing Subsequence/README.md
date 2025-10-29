# 📈 Longest Increasing Subsequence (LIS)

This folder contains a **C implementation** of the **Longest Increasing Subsequence (LIS)** problem using **Dynamic Programming (O(n²) approach)**.  
It’s written to be **beginner-friendly**, well-documented, and aligned with the repository’s contribution guidelines.

---

## 🧩 Folder Structure
arrays/<br>
└── Longest Increasing Subsequence/<br>
├── Longest_Increasing_Subsequence.c<br>
└── README.md


---

## 🧠 Problem Statement
Given an array of integers, find the **length of the longest strictly increasing subsequence (LIS)**  
and print one example of such a subsequence.

---

## 💡 Example
**Input:**<br>
10 22 9 33 21 50 41 60


**Output:**<br>
Length of Longest Increasing Subsequence is 5<br>
One LIS: 10 22 33 50 60


---

## ⚙️ How to Compile and Run
**Compile Command:**
```bash
gcc -std=c11 -O2 -Wall "arrays/Longest Increasing Subsequence/Longest_Increasing_Subsequence.c" -o lis
```
Run Command:<br>
./lis

| Type      | Complexity |
| --------- | ---------- |
| **Time**  | O(n²)      |
| **Space** | O(n)       |

