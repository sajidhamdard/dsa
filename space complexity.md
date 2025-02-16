### **What is Space Complexity?**

Space Complexity refers to the amount of **memory (RAM)** an algorithm needs to run, based on the size of the input.

📌 **It includes:**

1. **Input size (`n`)** – The memory taken by input data.
2. **Auxiliary space** – Extra memory used (e.g., arrays, recursion stack, etc.).
3. **Fixed memory** – Memory for constants and variables (independent of `n`).

---

## **1️⃣ Why is Space Complexity Important?**

- A fast algorithm (low time complexity) might **use too much memory**.
- Some systems have **limited memory**, so we must optimize space usage.
- Helps in designing efficient programs that scale well.

---

## **2️⃣ Common Space Complexities**

| Space Complexity | Meaning                                     |
| ---------------- | ------------------------------------------- |
| **O(1)**         | Constant space (no extra memory used)       |
| **O(n)**         | Linear space (memory grows with `n`)        |
| **O(n²)**        | Quadratic space (nested data structures)    |
| **O(log n)**     | Logarithmic space (used in recursive calls) |

---

## **3️⃣ Examples of Space Complexity**

### **✅ O(1) - Constant Space**

💡 **No extra memory used, only a few variables**

```java
class Example {
    public int sum(int[] arr) {
        int total = 0;  // Only 1 variable
        for (int num : arr) {
            total += num;
        }
        return total;
    }
}
```

✅ **Space Complexity = O(1)**  
⏳ **Why?** No extra memory is used other than `total`.

---

### **✅ O(n) - Linear Space**

💡 **Extra space used to store output**

```java
class Example {
    public int[] runningSum(int[] nums) {
        int[] sum = new int[nums.length]; // Extra array
        sum[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
        return sum;
    }
}
```

✅ **Space Complexity = O(n)**  
⏳ **Why?** The new `sum` array takes extra memory proportional to `n`.

---

### **✅ O(log n) - Logarithmic Space (Recursion)**

💡 **Recursive calls use stack memory**

```java
class Example {
    public int binarySearch(int[] arr, int left, int right, int target) {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target)
            return binarySearch(arr, mid + 1, right, target); // Recursive call
        else
            return binarySearch(arr, left, mid - 1, target);
    }
}
```

✅ **Space Complexity = O(log n)**  
⏳ **Why?** The recursive calls **use log n space** in the call stack.

---

### **✅ O(n²) - Quadratic Space (Matrix)**

💡 **Using a 2D array takes O(n²) space**

```java
class Example {
    public int[][] createMatrix(int n) {
        int[][] matrix = new int[n][n];  // Extra 2D array
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = i + j;
            }
        }
        return matrix;
    }
}
```

✅ **Space Complexity = O(n²)**  
⏳ **Why?** The matrix needs `n * n` space.

---

## **4️⃣ Time Complexity vs Space Complexity**

| Complexity                        | Meaning               | Example           |
| --------------------------------- | --------------------- | ----------------- |
| **O(1) Time, O(1) Space**         | Fast, no extra memory | `sum(arr)`        |
| **O(n) Time, O(1) Space**         | Slow, no extra memory | `findMax(arr)`    |
| **O(n) Time, O(n) Space**         | Extra memory used     | `runningSum(arr)` |
| **O(log n) Time, O(log n) Space** | Recursive calls       | `binarySearch()`  |

---

## **5️⃣ Key Takeaways**

- **O(1) is best** (no extra memory).
- **Recursive functions use O(log n) space**.
- **Using extra arrays or matrices increases space complexity**.
- **Balance between Time Complexity and Space Complexity** for best performance.

Would you like any more examples? 😊🚀
