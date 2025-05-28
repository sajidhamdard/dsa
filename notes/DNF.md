The **DNF Algorithm**, also known as the **Dutch National Flag algorithm**, is a classic algorithm designed by **Edsger Dijkstra**. It's used to sort an array with three distinct values (e.g., 0s, 1s, and 2s) in a **single pass** and **in-place**.

---

### 🔶 Problem it solves:

Sort an array containing only three types of elements — e.g., `0`, `1`, and `2` — such that all `0`s come first, then `1`s, and then `2`s.

---

### 🔶 Why the name "Dutch National Flag"?

The Dutch national flag has three colors: **Red, White, and Blue** (like 0s, 1s, 2s). The goal is to partition the array into three sections — each for one color.

---

### 🔶 Key idea:

Maintain **three pointers**:

* `low` – the boundary for 0s
* `mid` – the current element being considered
* `high` – the boundary for 2s

---

### 🔶 Java Implementation:

```java
public class DutchNationalFlag {

    public static void sortColors(int[] arr) {
        int low = 0, mid = 0, high = arr.length - 1;

        while (mid <= high) {
            switch (arr[mid]) {
                case 0:
                    swap(arr, low, mid);
                    low++;
                    mid++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(arr, mid, high);
                    high--;
                    break;
            }
        }
    }

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Test
    public static void main(String[] args) {
        int[] arr = {2, 0, 2, 1, 1, 0};
        sortColors(arr);

        System.out.println("Sorted array:");
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}
```

---

### 🔶 Output:

```
Sorted array:
0 0 1 1 2 2
```

---

### 🔶 Time & Space Complexity:

* **Time:** O(n)
* **Space:** O(1) — in-place sorting

---

### 🔶 When to use:

Use DNF when you're given an array with **exactly 3 distinct values** (like colors or categories) and you need a fast, in-place sort.

---

In the **Dutch National Flag (DNF)** algorithm, we start with the **mid** pointer because it's the most efficient way to **partition the array into three sections** in a single pass.

### First, a quick refresher on what DNF does:

It sorts an array of only 3 types of elements — usually 0s, 1s, and 2s — in **one traversal**. The goal is to rearrange them so that:

```
All 0s come first, then 1s, then 2s.
```

We maintain 3 pointers:

* `low`: marks the boundary of 0s.
* `mid`: current index being evaluated.
* `high`: marks the boundary of 2s.

---

### Why start at `mid = 0`?

Because:

1. **We don't know the first element yet**:
   At the start, we haven’t inspected any elements. So, we begin evaluating from index `0`, hence `mid = 0`.

2. **mid is the pointer that scans the array**:
   The `mid` pointer is used to traverse through the array. It checks each value and decides what to do:

   * If it's `0`, swap with `low`, move both `low` and `mid` forward.
   * If it's `1`, it's already in the right place, just move `mid` forward.
   * If it's `2`, swap with `high`, move `high` backward **but don't increment `mid`** (since the swapped value needs to be re-evaluated).

3. **We want to maintain 3 regions**:
   At any time during the traversal:

   * `0 to low-1`: All 0s
   * `low to mid-1`: All 1s
   * `mid to high`: Unknown (to be processed)
   * `high+1 to end`: All 2s

   So, `mid` always points to the current element being processed in the unknown region.

---

### Example

Array: `[2, 0, 2, 1, 1, 0]`

Initial pointers:

* `low = 0`, `mid = 0`, `high = 5`

You start from `mid = 0` because that's the first element to inspect. From there, you keep processing elements by comparing `arr[mid]`.

---

### Summary

We **start at `mid = 0`** (or wherever the start of the array is) because:

* It is the first element to inspect.
* `mid` always scans the current unclassified section.
* It allows single-pass sorting by expanding the three regions (0s, 1s, and 2s) dynamically.


---

We **can** solve the Dutch National Flag problem using general-purpose sorting algorithms like:

* **Quick Sort**
* **Merge Sort**
* **Arrays.sort()** in Java (which uses Dual-Pivot QuickSort for primitives)

But here's **why DNF is better for this specific case**:

---

### ✅ Comparison: DNF vs General Sorting

| Feature                    | DNF Algorithm                      | Quick Sort / Merge Sort     |
| -------------------------- | ---------------------------------- | --------------------------- |
| **Time Complexity**        | O(n)                               | O(n log n) (average case)   |
| **Space Complexity**       | O(1) (in-place)                    | O(log n) or O(n)            |
| **Number of Passes**       | Single pass                        | Multiple recursive passes   |
| **Tailored for 3 values?** | Yes (0s, 1s, 2s)                   | No, generic for any values  |
| **Stability**              | No (can be adapted)                | Merge sort is stable        |
| **Best Use Case**          | Arrays with only 3 distinct values | Any general sorting problem |

---

### 🔑 Why DNF is better here:

* You're not really "sorting" — you're **partitioning into three categories** (like grouping socks by color).
* DNF does this in **linear time**, no recursion, and no extra space.
* It’s not just faster — it’s **semantically clearer**: it expresses the intent of the problem (grouping) better than quick sort.

---

### 📌 TL;DR:

> **Yes**, you can use Quick Sort or Merge Sort, but the **Dutch National Flag algorithm is optimized for this exact problem** and is **faster, simpler, and more readable**.
