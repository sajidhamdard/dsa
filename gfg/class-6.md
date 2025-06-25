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
