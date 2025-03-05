## **📌 Merge Sort vs Quick Sort**

Both **Merge Sort** and **Quick Sort** are **Divide and Conquer** algorithms, but they differ in their approach, performance, and memory usage.

---

## **🔹 Key Differences**

| Feature                            | **Merge Sort**                                                       | **Quick Sort**                                                     |
| ---------------------------------- | -------------------------------------------------------------------- | ------------------------------------------------------------------ |
| **Approach**                       | Divide the array into two halves, sort them recursively, then merge. | Pick a pivot, partition the array, and recursively sort subarrays. |
| **Time Complexity (Best/Average)** | **O(n log n)**                                                       | **O(n log n)**                                                     |
| **Time Complexity (Worst Case)**   | **O(n log n)**                                                       | **O(n²) (if poorly chosen pivot)**                                 |
| **In-Place?**                      | ❌ No (requires extra space for merging).                            | ✅ Yes (modifies the array in place).                              |
| **Stability**                      | ✅ Yes (preserves order of equal elements).                          | ❌ No (equal elements may swap positions).                         |
| **Performance in Small Datasets**  | ❌ Slower                                                            | ✅ Faster                                                          |
| **Performance in Large Datasets**  | ✅ Good for large datasets.                                          | ✅ Fast if pivot is chosen well.                                   |
| **Best Use Case**                  | Sorting **linked lists, external sorting (large files)**.            | Sorting **arrays, in-memory sorting**.                             |

---

## **🔹 Merge Sort vs Quick Sort Example**

Let's take an example:

```java
int[] arr = {10, 7, 8, 9, 1, 5};
```

### **✅ Merge Sort Process**

1. **Divide:**
   - [10, 7, 8] and [9, 1, 5]
   - Further divide → [10] [7,8] and [9] [1,5]
2. **Sort each part and Merge:**
   - [7,8,10] and [1,5,9]
   - Merge → [1,5,7,8,9,10]

---

### **✅ Quick Sort Process**

1. **Choose Pivot:** `pivot = 5`
2. **Partition:**
   - Left: `[1]` (smaller than pivot)
   - Pivot: `[5]`
   - Right: `[10, 7, 8, 9]` (greater than pivot)
3. **Recursively sort left and right parts**
   - Left: `[1]` (already sorted)
   - Right: `[7, 8, 9, 10]`
   - Final sorted array: `[1, 5, 7, 8, 9, 10]`

---

## **🔹 When to Use What?**

✅ **Use Merge Sort when:**  
✔ Stable sorting is required.  
✔ Working with **linked lists** (efficient merging).  
✔ Sorting **very large datasets** (external sorting).

✅ **Use Quick Sort when:**  
✔ Sorting **arrays** in memory.  
✔ Faster performance is needed **(O(n log n) on average)**.  
✔ Pivot can be **chosen well** to avoid worst-case O(n²).

---

## **🔹 Final Verdict**

✔ **Quick Sort is generally preferred** for in-memory sorting due to its **faster performance and lower memory usage**.  
✔ **Merge Sort is preferred** for **linked lists** and **large datasets** where stability matters.
