### 🔍 **What is Hashing?**

Hashing is a technique to **map data (key)** to a **fixed-size value (index)** using a **hash function**, typically used in **hash tables**, like `HashMap`, `HashSet`.

---

### 🐢 **Why things are slow without hashing?**

Without hashing:

* Insertion, search, and deletion in **arrays/lists** = O(n)
* You must **linearly scan** to find a key
* In **sorted arrays**, you can use binary search = O(log n), but still slower than hashing

---

### ⚡ **How hashing helps?**

* Maps keys directly to an index → **average O(1)** time
* No need to search — just jump to the location

---

### 🎯 **Hash Collision**

Occurs when **two different keys hash to the same index**.

#### 👉 How it's handled:

1. **Chaining** – Store a list at each index (e.g., LinkedList or Tree)
2. **Open Addressing** – Probe for next available slot (e.g., linear probing)

---

### ✅ **What makes a good hash function?**

* Distributes keys **evenly**
* Minimizes **collisions**
* Fast to compute
* Deterministic (same input → same output)

Example: `hash = key % tableSize` (simple, but may be weak)

---

### 📊 **Time Complexities (Hash-based DS like HashMap/HashSet):**

| Operation     | Average Case | Worst Case (due to collisions) |
| ------------- | ------------ | ------------------------------ |
| Insertion     | O(1)         | O(n)                           |
| Deletion      | O(1)         | O(n)                           |
| Search/Access | O(1)         | O(n)                           |

> Worst case happens if **all keys collide** and go into one bucket (e.g., all linked in one list).

---

### 🧠 Summary:

* Hashing = fast mapping of keys to index
* Avoids O(n) searches
* Collisions must be handled
* Good hash function = fewer collisions
* Avg case for insert/search/delete: **O(1)**

---


### 🔍 **Problem Summary:**
[LeetCode Link](https://leetcode.com/problems/search-a-2d-matrix-ii/)

Given a `m x n` matrix where:

* Each **row** is sorted in ascending order (left → right)
* Each **column** is sorted in ascending order (top → bottom)

Check if a given `target` exists in the matrix.

---

### ❌ **Brute Force Approach:**

Loop through every element:

```java
for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        if (matrix[i][j] == target) return true;
    }
}
```

* **Time Complexity:** O(m × n)
* **Space Complexity:** O(1)

---

### ✅ **Optimized Solution:**

Start from **top-right** corner of the matrix:

```java
int row = 0;
int col = matrix[0].length - 1;
```

Then:

* If `matrix[row][col] == target`: return `true`
* If `matrix[row][col] > target`: move **left** (`col--`)
* Else: move **down** (`row++`)

Repeat until out of bounds.

---

### 🔍 Why this works:

Because:

* Rows are sorted → left move gives smaller
* Columns are sorted → down move gives larger

This lets you **eliminate one row or column in each step**, making the search efficient.

---

### 📌 Code:

```java
public boolean searchMatrix(int[][] matrix, int target) {
    int row = 0;
    int col = matrix[0].length - 1;

    while (row < matrix.length && col >= 0) {
        if (matrix[row][col] == target) return true;
        if (matrix[row][col] > target) col--;
        else row++;
    }
    return false;
}
```

---

### 📒 Notes (TC vs SC):

| Approach          | Time Complexity | Space Complexity | Notes                             |
| ----------------- | --------------- | ---------------- | --------------------------------- |
| Brute Force       | O(m × n)        | O(1)             | Check every cell                  |
| Optimized (Yours) | O(m + n)        | O(1)             | Eliminate row/column step-by-step |

---
