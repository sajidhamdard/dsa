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

### 🔹 1. **Access (Read / Get element)**

* **Time Complexity:** `O(1)`
* **Reason:** Accessing `arr[i]` by index is direct (constant time).

---

### 🔹 2. **Update (Set element)**

* **Time Complexity:** `O(1)`
* **Reason:** Similar to access, updating `arr[i] = x` takes constant time.

---

### 🔹 3. **Insert**

* **At the end (append):**

  * **Time Complexity:** `O(1)` *(if no resizing needed in dynamic arrays like ArrayList or Python list)*
  * **Amortized:** `O(1)`
  * **Worst Case (when resize happens):** `O(n)`
  * **Fixed-size array:** Inserting at end is not possible unless space is available.

* **At beginning or middle (index i):**

  * **Time Complexity:** `O(n)`
  * **Reason:** Elements after index `i` must be shifted right to make space.

---

### 🔹 4. **Delete**

* **At the end:**

  * **Time Complexity:** `O(1)`
  * **Reason:** Just reduce the size pointer or ignore the last element.

* **At beginning or middle (index i):**

  * **Time Complexity:** `O(n)`
  * **Reason:** All elements after `i` must be shifted left to fill the gap.

---

### 🔹 5. **Search**

* **Unsorted array:**

  * **Time Complexity:** `O(n)`
  * **Reason:** Linear scan is needed.

* **Sorted array (Binary Search):**

  * **Time Complexity:** `O(log n)`

---

### ✅ Summary Table

| Operation         | Time Complexity                       |
| ----------------- | ------------------------------------- |
| Access            | `O(1)`                                |
| Update            | `O(1)`                                |
| Insert (end)      | `O(1)` (amortized), `O(n)` worst case |
| Insert (anywhere) | `O(n)`                                |
| Delete (end)      | `O(1)`                                |
| Delete (anywhere) | `O(n)`                                |
| Search (unsorted) | `O(n)`                                |
| Search (sorted)   | `O(log n)`                            |

---

## ✅ Problem Statement

Given a `m x n` matrix, if any element is `0`, set its entire row and column to `0`.
Do this **in-place**, without using extra space for another matrix.

---

## ✅ Explanation

* We use the **first row and first column** to **mark** which rows/columns should be set to `0`.
* We handle the first row/column separately using two boolean flags.

---

## ✅ Java Code

```java
import java.util.*;

public class MatrixZeroSetter {

    public static void makeMatrixZeros(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

        boolean firstRowZero = false;
        boolean firstColZero = false;

        // Check if first column has any zero
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Check if first row has any zero
        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Use first row and column as markers
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set cells to 0 based on markers
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero the first column if needed
        if (firstColZero) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }

        // Zero the first row if needed
        if (firstRowZero) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }
    }

    public static void main(String[] args) {
        int[][] matrix = {
            {1, 1, 1, 1, 1},
            {1, 1, 0, 0, 1},
            {1, 0, 1, 1, 1},
            {0, 1, 1, 1, 1}
        };

        makeMatrixZeros(matrix);

        for (int[] row : matrix) {
            for (int val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}
```

---

## ✅ Alternate Approaches & Challenges

### ❌ Brute Force:

* Traverse matrix, store zero positions in a list.
* In 2nd pass, update entire row and column.
* **Issue:** Needs extra space `O(n + m)` or `O(n*m)`.

### ✅ Optimized (Current Code):

* Uses first row and column as flags → **no extra space**.
* Needs careful handling of the first row/column separately.

---

## ✅ Time & Space Complexity

| Metric    | Value      |
| --------- | ---------- |
| **Time**  | `O(n * m)` |
| **Space** | `O(1)`     |

* Only two boolean variables used.
* Matrix is modified in-place.

---


## ✅ Problem Statement

Given an integer array, find the **maximum sum of any contiguous subarray** (i.e., elements must be consecutive).

📌 This is the classic **Kadane’s Algorithm** problem.

---

## ✅ Explanation

* At each index `i`, decide:

  * Either start a new subarray from `arr[i]`
  * Or extend the previous subarray by adding `arr[i]`
* Keep track of the **maximum sum so far**.

---

## ✅ Java Code

```java
public class MaxSubarraySum {

    // Kadane’s Algorithm (without extra space)
    // TC: O(n), SC: O(1)
    public static int maxSumSubarray(int[] arr) {
        int n = arr.length;

        int result = arr[0];
        int maxTillPrev = arr[0];

        for (int i = 1; i < n; i++) {
            maxTillPrev = Math.max(arr[i], maxTillPrev + arr[i]);
            result = Math.max(result, maxTillPrev);
        }

        return result;
    }

    public static void main(String[] args) {
        System.out.println(maxSumSubarray(new int[]{1, 2, 3, -2, 5}));   // 9
        System.out.println(maxSumSubarray(new int[]{-1, -2, -3}));       // -1
        System.out.println(maxSumSubarray(new int[]{1, 2, 3, 2, 5}));    // 13
        System.out.println(maxSumSubarray(new int[]{-1, 2, 3, -2, -5})); // 5
    }
}
```

---

## ✅ Alternate Approach (with extra space)

```java
public static int maxSumSubarrayWithExtraSpace(int[] arr) {
    int n = arr.length;
    int[] maxSum = new int[n];

    maxSum[0] = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        maxSum[i] = Math.max(arr[i], maxSum[i - 1] + arr[i]);
        result = Math.max(result, maxSum[i]);
    }

    return result;
}
```

---

## ✅ Time & Space Complexity

| Metric                  | Value                              |
| ----------------------- | ---------------------------------- |
| **Time Complexity**     | `O(n)`                             |
| **Space (extra space)** | `O(n)` — in version using DP array |
| **Space (optimal)**     | `O(1)` — in optimized version      |

---

## ✅ Why not use brute force?

* Brute force would check all subarrays → **O(n²)** time.
* Kadane’s is optimal with **O(n)** time and **O(1)** space.

---


## ✅ Problem Statement

Given a **circular integer array `nums`**, return the **maximum possible sum of a non-empty subarray** of `nums`.

A **circular subarray** means the subarray can wrap around from the end of the array to the beginning.

---

## ✅ Example

```java
Input: nums = [1, -2, 3, -2]
Output: 3
Explanation: Subarray [3] has the maximum sum = 3

Input: nums = [5, -3, 5]
Output: 10
Explanation: Wraparound subarray [5, ..., 5] gives 10

Input: nums = [-3, -2, -3]
Output: -2
```

---

## ✅ Explanation of Approach

We consider **two cases**:

### Case 1: Subarray is **non-circular**

* Use **Kadane's algorithm** to get `maxSum` (normal max subarray).

### Case 2: Subarray is **circular**

* Total sum of array: `totalSum`
* Find the **minimum subarray sum** (as removing it gives the max circular sum).

  * Trick: Multiply all elements by `-1`, then run Kadane’s to get `minSum = -maxSum(inverted array)`
* `circularMaxSum = totalSum - minSubarraySum`

---

## ✅ Key Step:

```java
result = max(maxSum, totalSum - minSum)
```

But if **all numbers are negative**, circular sum becomes zero (invalid). So in that case, return `maxSum` only.

---

## ✅ Java Code

```java
class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int totalSum = Arrays.stream(nums).sum();
        int maxSum = kadane(nums);

        // Invert the array to find min subarray sum
        for (int i = 0; i < nums.length; i++) {
            nums[i] *= -1;
        }

        int minSum = kadane(nums); // actually this is -1 * minSubarraySum
        int circularSum = totalSum + minSum;

        // If all numbers are negative, circularSum becomes 0, which is invalid
        if (maxSum < 0) return maxSum;

        return Math.max(maxSum, circularSum);
    }

    private int kadane(int[] nums) {
        int currentSum = 0;
        int maxSum = Integer.MIN_VALUE;
        for (int n : nums) {
            currentSum += n;
            maxSum = Math.max(maxSum, currentSum);
            if (currentSum < 0) currentSum = 0;
        }
        return maxSum;
    }
}
```

---

## ✅ Time & Space Complexity

| Metric               | Value  |
| -------------------- | ------ |
| **Time Complexity**  | `O(n)` |
| **Space Complexity** | `O(1)` |

---

## ✅ Edge Cases

| Case                     | Explanation                                   |
| ------------------------ | --------------------------------------------- |
| All elements negative    | Return the maximum (least negative) element   |
| Only one element         | Return that element                           |
| Wrap-around max subarray | Properly handled using totalSum - minSubarray |

---
