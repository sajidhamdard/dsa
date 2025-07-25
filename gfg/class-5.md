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


### ✅ What is Divide and Conquer?

**Divide and Conquer** is a powerful algorithmic technique used to solve complex problems by:

1. **Dividing** the problem into smaller subproblems
2. **Conquering** (solving) each subproblem recursively
3. **Combining** the results of subproblems to get the final solution

---

### 🧠 Simple Example:

**Merge Sort**

* **Divide** the array into halves
* **Sort** each half recursively
* **Merge** the sorted halves

---

### 🧮 Common Problems Using Divide and Conquer:

* **Binary Search**
* **Merge Sort**, **Quick Sort**
* **Finding Maximum/Minimum**
* **Matrix multiplication**
* **Closest Pair of Points**

---

### ⏱ Time Complexity:

Often helps bring down time from **O(n²)** to **O(n log n)**

---

### ✅ Binary Search **uses** Divide and Conquer — but they are not the same.

---

### 🧠 Think of it like this:

* **Divide and Conquer** is a **general technique** (a strategy)
* **Binary Search** is a **specific algorithm** that applies this technique

---

### 📌 Example:

| Concept              | What it Does                                        |
| -------------------- | --------------------------------------------------- |
| **Divide & Conquer** | Divides a big problem into smaller ones recursively |
| **Binary Search**    | Divides the array into two halves to find a value   |

So, **Binary Search** is an example of the **Divide and Conquer** technique.

---

### ✅ In short:

> **Every Binary Search uses Divide and Conquer, but not every Divide and Conquer algorithm is Binary Search.**

---

### 🔍 Why Divide and Conquer Makes Problems Easier:

When we apply **Divide and Conquer**, we break down a complex problem into smaller subproblems. These subproblems are **easier to understand and solve**, and most of the heavy lifting is done by **recursion**.

---

### 🧠 Key Benefits:

* **Simplifies logic**: Recursion handles repeated patterns, so you focus only on the base case and divide step.
* **Reduces time complexity**: Many problems that take O(n²) time can be optimized to O(n log n), like in Merge Sort.
* **Encourages clean, modular code**: Each step (divide, solve, combine) is neatly separated.

---

Recursion often **absorbs the complexity**, making it easier to reason about and solve the overall problem.

---

## 🧠 Approach: Binary Search

We use **modified binary search**:

1. **First Occurrence**:

   * When `arr[mid] == target`, store it in result
   * Move to the **left half** to check for earlier occurrence

2. **Last Occurrence**:

   * When `arr[mid] == target`, store it in result
   * Move to the **right half** to check for later occurrence

---

## ⏱ Time and Space Complexity

* **Time:** `O(log n)` for both first and last search
* **Space:** `O(1)` (no extra memory used)

---

## ✅ Java Code

```java
import java.util.*;

public class Solution {

    public static int getFirstOccurrence(int[] arr, int target) {
        int low = 0, high = arr.length - 1;
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                result = mid;
                high = mid - 1;  // go left
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }

    public static int getLastOccurrence(int[] arr, int target) {
        int low = 0, high = arr.length - 1;
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                result = mid;
                low = mid + 1;  // go right
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }

    public static int[] findFirstAndLastOccurrence(int[] arr, int target) {
        int first = getFirstOccurrence(arr, target);
        if (first == -1) return new int[]{-1, -1};

        int last = getLastOccurrence(arr, target);
        return new int[]{first, last};
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(findFirstAndLastOccurrence(new int[]{1, 3, 5, 5, 5, 5, 67, 123, 125}, 5)));     // [2, 5]
        System.out.println(Arrays.toString(findFirstAndLastOccurrence(new int[]{1, 3, 5, 5, 5, 5, 67, 123, 125}, 123)));   // [7, 7]
        System.out.println(Arrays.toString(findFirstAndLastOccurrence(new int[]{5, 5, 5, 5}, 5)));                         // [0, 3]
        System.out.println(Arrays.toString(findFirstAndLastOccurrence(new int[]{1, 3, 5, 5, 5, 5, 67, 123, 125}, 68)));    // [-1, -1]
    }
}
```

---


## ✅ Problem: Integer Square Root of a Number

**Given:** A non-negative integer `n`
**Goal:** Return the **floor value** of the square root of `n`.
That is, return the greatest integer `x` such that `x * x ≤ n`.

### 🔍 Examples:

* `sqrtOfN(25)` → 5
* `sqrtOfN(30)` → 5
* `sqrtOfN(1)` → 1

---

## 🧠 Approach: Binary Search

We search for the square root between `1` and `n/2`.
At each step, we:

* Check if `mid * mid == n` → return `mid`
* If `mid * mid < n`, move `low = mid + 1`, and store `mid` as a candidate
* Else, reduce search space with `high = mid - 1`

---

## ⏱ Time and Space Complexity

* **Time:** O(log n)
* **Space:** O(1)

---

## ☑️ Java Code

```java
public class Solution {

    // TC: O(log n), SC: O(1)
    public static int sqrtOfN(int n) {
        if (n <= 1) return n;

        int low = 1, high = n / 2;
        int result = 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Use long to avoid overflow
            long square = (long) mid * mid;

            if (square == n) {
                return mid;
            } else if (square < n) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }

    public static void main(String[] args) {
        System.out.println(sqrtOfN(1));   // 1
        System.out.println(sqrtOfN(25));  // 5
        System.out.println(sqrtOfN(30));  // 5
        System.out.println(sqrtOfN(0));   // 0
        System.out.println(sqrtOfN(100)); // 10
    }
}
```

---

## 📌 Note:

* Use `long` for `mid * mid` to avoid integer overflow for large inputs.

---

## ✅ Problem: Search in a Sorted Rotated Array

You are given a **sorted** array that has been **rotated** at some unknown pivot. Your task is to search for a given `target` value in the array.

If the element exists, return its index. If not, return `-1`.

---

### 🔍 Example

Input:
`arr = [5, 6, 7, 8, 9, 10, 1, 2, 3], target = 2`
Output: `7`

---

## 🧠 Approach: Modified Binary Search

Even though the array is rotated, **one half will always be sorted**.

* If the left half `arr[low] to arr[mid]` is sorted, check if the target lies within that range.
* If not, search in the right half.
* Otherwise, the right half `arr[mid] to arr[high]` is sorted — check there.
* Repeat until found.

---

## ⏱ Time and Space Complexity

* **Time Complexity:** O(log n)
* **Space Complexity:** O(1)

---

## ☑️ Java Code

```java
public class Solution {

    // TC: O(log n), SC: O(1)
    public static int searchInSortedRotatedArray(int[] arr, int target) {
        int low = 0, high = arr.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) return mid;

            // Left half is sorted
            if (arr[low] <= arr[mid]) {
                if (target >= arr[low] && target <= arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (target >= arr[mid] && target <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        System.out.println(searchInSortedRotatedArray(new int[]{5, 6, 7, 8, 9, 10, 1, 2, 3}, 2));   // 7
        System.out.println(searchInSortedRotatedArray(new int[]{5, 6, 7, 8, 9, 10, 1, 2, 3}, 1));   // 6
        System.out.println(searchInSortedRotatedArray(new int[]{5, 6, 7, 8, 9, 10, 1, 2, 3}, 10));  // 5
        System.out.println(searchInSortedRotatedArray(new int[]{5, 6, 7, 8, 9, 10, 1, 2, 3}, 5));   // 0
        System.out.println(searchInSortedRotatedArray(new int[]{5, 6, 7, 8, 9, 10, 1, 2, 3}, 20));  // -1
        System.out.println(searchInSortedRotatedArray(new int[]{5, 6, 7, 8, 9, 10}, 6));           // 1
    }
}
```

---

## 💡 Notes

* Be sure to handle duplicates separately (different logic needed if duplicates are allowed).
* Always compute `mid` using `low + (high - low) / 2` to avoid integer overflow.

---

### ✅ Problem Statement

You are given a rotated sorted array with **no duplicates**. Find the minimum element in **O(log n)** time.

Example:
Input: `[4, 5, 6, 7, 0, 1, 2]`
Output: `0`

---

### 🧠 Approach

You used **Binary Search**, which is the most optimal approach here:

1. You compare `nums[mid]` with `nums[high]`.
2. If `nums[mid] <= nums[high]`, the minimum lies on the **left side (including mid)**, so move `high = mid`.
3. Else, the minimum lies on the **right side (excluding mid)**, so do `low = mid + 1`.
4. Loop continues until `low == high`.

---

### ⏱ Time and Space Complexity

* **Time Complexity:** O(log n)
* **Space Complexity:** O(1)

---

### ✅ Final Verdict

This is a **perfect and accepted** solution for **rotated sorted array without duplicates**.

---
