### ✅ What is Binary Search?

Binary Search is a fast algorithm to find an element in a **sorted array** by repeatedly dividing the search space in half.

---

### ✅ When to Use:

* The array/list is **sorted**
* You need to **search efficiently** (find index, condition, min/max, etc.)

---

### ⚙️ How It Works:

1. Set `low = 0`, `high = n - 1`
2. While `low <= high`:

   * Use:
     👉 `mid = low + (high - low) / 2` ← ✅ Safe for large numbers
     ❌ Avoid `mid = (low + high) / 2` → might overflow for big values
   * If `target == arr[mid]` → Found
   * If `target < arr[mid]` → Search left side
   * If `target > arr[mid]` → Search right side

---

### ⏱ Time Complexity:

* **O(log n)** — much faster than linear search (**O(n)**)

---
