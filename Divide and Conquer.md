## **📌 Divide and Conquer Algorithm**

🔹 **Divide and Conquer** is a powerful algorithmic technique that **breaks a problem into smaller subproblems**, solves them recursively, and then combines the results to get the final solution.

---

## **🔹 Steps in Divide and Conquer**

1️⃣ **Divide** → Break the problem into smaller subproblems.  
2️⃣ **Conquer** → Solve each subproblem recursively.  
3️⃣ **Combine** → Merge the results of subproblems to get the final answer.

---

## **🔹 Real-Life Example**

🔹 **Sorting a deck of cards**  
1️⃣ **Divide**: Split the deck into two halves.  
2️⃣ **Conquer**: Sort each half separately.  
3️⃣ **Combine**: Merge both sorted halves to get a fully sorted deck.

---

## **🔹 Examples of Divide and Conquer Algorithms**

### **1️⃣ Merge Sort (Sorting Algorithm)**

**Breaks the array into smaller parts, sorts them, and merges them back.**

#### **✅ Java Example: Merge Sort**

```java
public class MergeSort {
    public static void mergeSort(int[] arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    private static void merge(int[] arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int[] leftArr = new int[n1];
        int[] rightArr = new int[n2];

        System.arraycopy(arr, left, leftArr, 0, n1);
        System.arraycopy(arr, mid + 1, rightArr, 0, n2);

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            arr[k++] = (leftArr[i] <= rightArr[j]) ? leftArr[i++] : rightArr[j++];
        }
        while (i < n1) arr[k++] = leftArr[i++];
        while (j < n2) arr[k++] = rightArr[j++];
    }

    public static void main(String[] args) {
        int[] arr = {5, 2, 9, 1, 6, 4};
        mergeSort(arr, 0, arr.length - 1);
        System.out.println(java.util.Arrays.toString(arr));
    }
}
```

✅ **Time Complexity**: **O(n log n)**

---

### **2️⃣ Quick Sort (Sorting Algorithm)**

**Picks a pivot, partitions the array, and sorts recursively.**

---

### **3️⃣ Binary Search (Searching Algorithm)**

**Divides the sorted array into two halves and searches recursively.**

#### **✅ Java Example: Binary Search**

```java
public class BinarySearch {
    public static int binarySearch(int[] arr, int left, int right, int target) {
        if (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) return mid;
            if (arr[mid] > target) return binarySearch(arr, left, mid - 1, target);
            return binarySearch(arr, mid + 1, right, target);
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {2, 3, 4, 10, 40};
        int target = 10;
        System.out.println("Element found at index: " + binarySearch(arr, 0, arr.length - 1, target));
    }
}
```

✅ **Time Complexity**: **O(log n)**

---

## **🔹 When to Use Divide and Conquer?**

✅ **When a problem can be divided into independent subproblems**  
✅ **When recursion makes the solution easier**  
✅ **When the problem requires efficient sorting or searching**
