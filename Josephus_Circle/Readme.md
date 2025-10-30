# Josephus Circle – Interactive Visual Edition

**File:** `josephus_circle_interactive.c`  
**Category:** Simulation / Algorithms / Interactive Learning  
**Difficulty:** Intermediate (Beginner-Friendly with Guidance)  
**Hacktoberfest 2025**

---

## Problem Statement

> **n** people stand in a circle.  
> Starting from person **1**, every **k-th** alive person is eliminated.  
> **Who is the last survivor?**

This is the **Josephus Problem** — a classic in computer science.

---

## Features

| Feature              | Description                                    |
| -------------------- | ---------------------------------------------- |
| **Visual Circle**    | `O` = alive, `X` = eliminated                  |
| **Step-by-Step**     | Press **Enter** after each elimination         |
| **Color Output**     | Green (alive), Red (eliminated), Yellow (info) |
| **Input Validation** | No crashes on bad input                        |
| **Replay Menu**      | Play again without restarting                  |
| **Math Formula**     | For `k=2`: `f(n) = 2*l + 1`                    |

---

## How to Run

```bash
# Compile
gcc -o josephus simulation/josephus_circle_interactive.c

# Run
./josephus
```
