## **📌 Quick Sort Algorithm**

🔹 **Quick Sort** is a **Divide and Conquer** sorting algorithm that works by selecting a **pivot** element, partitioning the array around it, and recursively sorting the partitions.

🔹 **It is one of the fastest sorting algorithms** with an average-case time complexity of **O(n log n)**.

---

## **🔹 Steps in Quick Sort**

1️⃣ **Choose a pivot element** (can be first, last, middle, or random).  
2️⃣ **Partition the array**:

- Move all elements smaller than the pivot to the left.
- Move all elements greater than the pivot to the right.  
  3️⃣ **Recursively apply Quick Sort** to the left and right subarrays.  
  4️⃣ **Combine** the sorted parts.

---

## **🔹 Example of Quick Sort in Java**

```java
import java.util.Arrays;

public class QuickSort {
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high); // Find pivot
            quickSort(arr, low, pivotIndex - 1);  // Sort left half
            quickSort(arr, pivotIndex + 1, high); // Sort right half
        }
    }

    private static int partition(int[] arr, int low, int high) {
        int pivot = arr[high]; // Choose pivot (last element)
        int i = low - 1; // Pointer for smaller element

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high); // Place pivot in correct position
        return i + 1; // Return pivot index
    }

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        int[] arr = {10, 7, 8, 9, 1, 5};
        System.out.println("Before Sorting: " + Arrays.toString(arr));

        quickSort(arr, 0, arr.length - 1);

        System.out.println("After Sorting: " + Arrays.toString(arr));
    }
}
```

---

## **🔹 Output**

```
Before Sorting: [10, 7, 8, 9, 1, 5]
After Sorting: [1, 5, 7, 8, 9, 10]
```

---

## **🔹 Quick Sort Complexity**

| Case                                                     | Time Complexity |
| -------------------------------------------------------- | --------------- |
| **Best Case** (Pivot divides evenly)                     | **O(n log n)**  |
| **Average Case**                                         | **O(n log n)**  |
| **Worst Case** (Already sorted, unbalanced partitioning) | **O(n²)**       |

---

## **🔹 When to Use Quick Sort?**

✅ **Use Quick Sort when:**  
✔ Fast sorting is needed **(O(n log n) on average)**.  
✔ **In-place sorting** is required (doesn't need extra memory like Merge Sort).  
✔ You can **choose a good pivot** to minimize worst-case performance.

❌ **Avoid Quick Sort when:**  
✖ The input is already sorted or nearly sorted (may cause **O(n²)** worst-case).  
✖ **Stable sorting** is required (Quick Sort is not stable by default).

---
