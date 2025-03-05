### **Binary Search Algorithm** 🔍  
Binary Search is an **efficient searching algorithm** used to find an element in a **sorted array** in **O(log n)** time.  

---

## **🔹 How Binary Search Works?**
1️⃣ **Find the middle element** of the array.  
2️⃣ **Compare the middle element with the target value**:  
   - If it's equal → ✅ Return the index.  
   - If it's smaller → 🔽 Search in the **right half**.  
   - If it's larger → 🔼 Search in the **left half**.  
3️⃣ Repeat the process **until the element is found or the search space is empty**.  

---

## **🔹 Binary Search Example**
### **🔹 Example 1: Searching for `7` in a sorted array**
```text
Array: [1, 3, 5, 7, 9, 11, 13]
Target: 7

Step 1: Middle = 5  (index 2), 7 > 5 → Search Right
Step 2: Middle = 9  (index 4), 7 < 9 → Search Left
Step 3: Middle = 7  (index 3), Found at index 3 🎯
```

---

## **🔹 Binary Search Implementation in Java**
### **✅ Iterative Approach (Using Loops)**
```java
public class BinarySearch {
    public static int binarySearch(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2; // Avoids integer overflow

            if (arr[mid] == target) return mid; // 🎯 Found
            else if (arr[mid] < target) left = mid + 1; // 🔽 Search right half
            else right = mid - 1; // 🔼 Search left half
        }
        return -1; // Not found
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 5, 7, 9, 11, 13};
        int target = 7;
        int index = binarySearch(arr, target);
        System.out.println("Index of " + target + " is: " + index); // Output: 3
    }
}
```
✅ **Efficient**  
✅ **No extra memory usage**  
✅ **O(log n) time complexity**  

---

### **✅ Recursive Approach**
```java
public class BinarySearchRecursive {
    public static int binarySearch(int[] arr, int left, int right, int target) {
        if (left > right) return -1; // Base case: Not found

        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid; // 🎯 Found
        else if (arr[mid] < target) return binarySearch(arr, mid + 1, right, target); // 🔽 Right half
        else return binarySearch(arr, left, mid - 1, target); // 🔼 Left half
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 5, 7, 9, 11, 13};
        int target = 7;
        int index = binarySearch(arr, 0, arr.length - 1, target);
        System.out.println("Index of " + target + " is: " + index); // Output: 3
    }
}
```
🔹 **More readable**  
🔹 **Uses extra stack memory (O(log n)) due to recursion**  

---

## **🔹 When to Use Binary Search?**
✅ **Array must be sorted**  
✅ **Faster than linear search (O(n)) for large datasets**  
✅ **Great for searching in large datasets (e.g., dictionaries, databases, logs)**  

---

## **🔹 Time Complexity**
| Case | Complexity |
|------|------------|
| **Best Case** (Element found at middle) | **O(1)** |
| **Worst Case** (Repeated division until 1 element) | **O(log n)** |
| **Average Case** | **O(log n)** |

---

### **🚀 Summary**
🔹 **Binary Search is an efficient search algorithm** with **O(log n)** complexity.  
🔹 **Best used for sorted arrays** and large datasets.  
🔹 **Can be implemented iteratively (better) or recursively (simpler).**  
