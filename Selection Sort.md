### **Selection Sort Algorithm** 🔄

**Selection Sort** is a simple **comparison-based sorting algorithm** that repeatedly selects the **smallest element** and places it in the correct position.

---

## **🔹 How Selection Sort Works?**

1️⃣ **Find the smallest element** in the unsorted part of the array.  
2️⃣ **Swap** it with the first element of the unsorted part.  
3️⃣ Move the boundary between sorted and unsorted parts one step right.  
4️⃣ Repeat until the array is fully sorted.

---

## **🔹 Example of Selection Sort**

### **🔹 Sorting [5, 3, 8, 4, 2]**

```
Step 1: Find min (2) → Swap with 5 → [2, 3, 8, 4, 5]
Step 2: Find min (3) → Already in place → [2, 3, 8, 4, 5]
Step 3: Find min (4) → Swap with 8 → [2, 3, 4, 8, 5]
Step 4: Find min (5) → Swap with 8 → [2, 3, 4, 5, 8] ✅ Sorted
```

---

## **🔹 Selection Sort Implementation in Java**

### **✅ Iterative Approach**

```java
import java.util.Arrays;

public class SelectionSort {
    public static void selectionSort(int[] arr) {
        int n = arr.length;

        for (int i = 0; i < n - 1; i++) {
            int minIndex = i; // Assume the first element is the smallest

            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) { // Find the minimum
                    minIndex = j;
                }
            }

            // Swap the found minimum element with the first element of the unsorted part
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    public static void main(String[] args) {
        int[] arr = {5, 3, 8, 4, 2};
        selectionSort(arr);
        System.out.println(Arrays.toString(arr)); // Output: [2, 3, 4, 5, 8]
    }
}
```

✅ **Simple & easy to understand**  
✅ **No extra space needed (In-place sorting)**

---

## **🔹 Time Complexity Analysis**

| Case                            | Complexity |
| ------------------------------- | ---------- |
| **Best Case (Already Sorted)**  | **O(n²)**  |
| **Worst Case (Reversed Order)** | **O(n²)**  |
| **Average Case**                | **O(n²)**  |

🚀 **Selection Sort always runs in O(n²), even if the array is already sorted.**  
🚀 **Not efficient for large datasets but useful when swaps are costly.**

---

## **🔹 When to Use Selection Sort?**

✅ **When memory space is limited** (in-place sorting)  
✅ **When swapping is more expensive than comparisons**  
✅ **When the array size is small**

🚫 **Not ideal for large datasets** because **O(n²) complexity** makes it slow.

---

## **🔹 Selection Sort vs. Other Sorting Algorithms**

| Sorting Algorithm  | Time Complexity (Avg) | Space Complexity    | Stability                       |
| ------------------ | --------------------- | ------------------- | ------------------------------- |
| **Selection Sort** | **O(n²)**             | **O(1)** (In-place) | ❌ No (Swaps may disrupt order) |
| **Bubble Sort**    | **O(n²)**             | **O(1)**            | ✅ Yes                          |
| **Insertion Sort** | **O(n²)**             | **O(1)**            | ✅ Yes                          |
| **Merge Sort**     | **O(n log n)**        | **O(n)**            | ✅ Yes                          |
| **Quick Sort**     | **O(n log n)**        | **O(log n)** (Best) | ❌ No                           |
