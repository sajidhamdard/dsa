## 🔹 1. **What is "in-cache" access in arrays?**

Modern CPUs use a **cache**—a small, super-fast memory close to the CPU—to speed up data access.

* When your program accesses an element in memory (like in an array), **the CPU tries to load not just that element, but nearby data into the cache**. This is called a **cache line** (typically 64 bytes).
* So, if your next access is nearby, it's **already in cache**, and you get a big performance boost.

**In-cache** access means the data is already in the cache, so it's fast to read.

---

## 🔹 2. **What is Locality of Reference?**

This is a concept from computer architecture that explains **why certain memory access patterns are faster**.

There are two types:

### ✅ a. **Temporal Locality**

* If you access the **same data again and again**, it stays in the cache.
* Example:

  ```java
  int x = arr[5];
  int y = arr[5];  // Fast! Already in cache.
  ```

### ✅ b. **Spatial Locality**

* If you access data that is **close to recently accessed data**, it's likely in the same cache line.
* Example:

  ```java
  for (int i = 0; i < n; i++) {
      sum += arr[i];  // Fast access, as arr[i] is next to arr[i-1]
  }
  ```

---

## 🔹 3. **Why is this important in arrays?**

Arrays are stored in **contiguous memory**. This layout **benefits from spatial locality**.

**Good example (cache-friendly):**

```java
for (int i = 0; i < arr.length; i++) {
    process(arr[i]);
}
```

**Bad example (poor cache use):**

```java
for (int i = 0; i < arr.length; i += 16) {
    process(arr[i]);
}
```

Here, you're skipping many elements, so the CPU may need to load a new cache line every time — slow.

---

## 🔹 Summary

| Term              | Meaning                                                                |
| ----------------- | ---------------------------------------------------------------------- |
| In-cache          | Data already loaded in CPU cache; fast to access.                      |
| Temporal locality | Access same data again soon.                                           |
| Spatial locality  | Access data near recently accessed data (like next elements in array). |
| Array benefit     | Arrays are contiguous → spatial locality → faster iteration.           |

---

Here’s a quick breakdown of **time complexities** for common operations on a **basic array** (fixed-size, like `int[] arr = new int[10]` in Java or C):

| Operation                            | Time Complexity      | Notes                                                        |
| ------------------------------------ | -------------------- | ------------------------------------------------------------ |
| **Access**                           | `O(1)`               | Direct access via index, e.g., `arr[3]`                      |
| **Update**                           | `O(1)`               | Assigning a value at an index, e.g., `arr[5] = 10`           |
| **Insertion at end**                 | `O(1)` *(amortized)* | Only if space is available (dynamic arrays like `ArrayList`) |
| **Insertion at beginning or middle** | `O(n)`               | Needs shifting elements to the right                         |
| **Deletion at end**                  | `O(1)`               | Simply reduce size (in dynamic arrays)                       |
| **Deletion at beginning or middle**  | `O(n)`               | Needs shifting elements to the left                          |
| **Search (unsorted)**                | `O(n)`               | Linear scan to find the element                              |
| **Search (sorted)**                  | `O(log n)`           | Binary search, only if the array is sorted                   |

> ✅ If you're using a **dynamic array** (like `ArrayList` in Java or `vector` in C++), the internal array resizes when full, costing `O(n)` occasionally—but average insertion at the end remains **`O(1)` amortized**.

---

### ✅ What is the **Bucketing Technique**?

The **bucketing technique** involves placing elements into **"buckets"** based on some **key, index, or range**, so that operations (like lookup, search, or match) become easier or faster.

In DSA, it's often used in:

* **Hashing** (like hashmap internal structure)
* **Counting sort**
* **Problems where elements are mapped to specific indices**

---

### 💡 **Problem: Smallest Missing Positive Integer**

Given an array `nums`, find the **smallest positive integer missing** from the array.
Example:

```txt
Input: [3, 4, -1, 1]
Output: 2
```

---

### ✅ Bucketing-Based Solution (In-Place Index Mapping)

We **bucket** each number `x` into its "correct" position at index `x - 1`.
If all numbers from `1 to n` are in their correct places, then the missing number is `n+1`.

#### 🔧 Steps:

1. Iterate and **place each number `x` (1 ≤ x ≤ n)** at index `x - 1`.
2. Ignore values ≤ 0 or > `n` (they are useless).
3. Then iterate again, and for the **first index `i` where `nums[i] != i+1`**, return `i+1`.

---

### ✅ Java Code (Using Bucketing Technique)

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;

        // Step 1: Place each number in its correct bucket (index x-1)
        for (int i = 0; i < n; i++) {
            while (
                nums[i] > 0 &&
                nums[i] <= n &&
                nums[nums[i] - 1] != nums[i]
            ) {
                // swap nums[i] with nums[nums[i] - 1]
                int temp = nums[i];
                nums[i] = nums[temp - 1];
                nums[temp - 1] = temp;
            }
        }

        // Step 2: Find first index i where nums[i] != i+1
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) return i + 1;
        }

        // If all are correct, return n+1
        return n + 1;
    }
}
```

---

### ✅ Time and Space Complexity

* **Time:** `O(n)`
  Each element is moved at most once (via swapping).
* **Space:** `O(1)`
  Done **in-place**, no extra array or hashset.

---

### 🔍 Example Dry Run: `[3, 4, -1, 1]`

1. Bucket step:

   * `3` → index `2`
   * `4` → index `3`
   * `-1` → ignore
   * `1` → index `0`

After placing:

```txt
[1, -1, 3, 4]
```

2. Scan for mismatch:

   * index 1 → `-1 ≠ 2` ⇒ return `2`

---
