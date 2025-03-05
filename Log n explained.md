### **What is "log" in Time Complexity?**

The term **"log"** (logarithm) is used in time complexity to describe algorithms that reduce the problem size **exponentially** at each step.

---

## **1️⃣ What is a Logarithm?**

A **logarithm** is the inverse of exponentiation.  
In simple terms, the logarithm **answers this question**:  
👉 **"How many times do we divide by a number to reach 1?"**

### **Mathematical Definition:**

\[
\log_b (x) = y \quad \text{means} \quad b^y = x
\]
Where:

- **`b`** = base (default is 2 in computer science)
- **`x`** = input number
- **`y`** = number of times we divide by `b` to reach `1`

---

## **2️⃣ Why Do We Use `log` in Time Complexity?**

We use **log** in time complexity when the **input size is reduced by a constant factor in each step**.

💡 **Example:** Suppose we have `n = 16` elements and an algorithm cuts the problem **in half** every step:

| Step | Remaining Elements (`n`) |
| ---- | ------------------------ |
| 1    | 16                       |
| 2    | 8                        |
| 3    | 4                        |
| 4    | 2                        |
| 5    | 1                        |

❓ **How many steps did it take to reach `1`?**  
👉 `log₂(16) = 4`

This is why **Binary Search (halving the search space) runs in O(log n) time**!

---

## **3️⃣ Example: Binary Search (O(log n))**

🔹 **Imagine searching for a word in a dictionary**:

- Instead of reading every word, **you open the middle page**.
- If your word is before the middle, **search the left half**.
- Otherwise, **search the right half**.
- Keep repeating until you find the word.

### **Binary Search in Java**

```java
class Example {
    public int binarySearch(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
}
```

🔹 **Each step halves the search space**  
👉 **Total steps = log₂(n)**  
Thus, **Binary Search runs in O(log n) time**!

---

## **4️⃣ Other Examples of `log n` Time Complexity**

### **a) Divide & Conquer Algorithms**

- **Merge Sort:** `O(n log n)` (divides input into halves and sorts)
- **Quick Sort:** `O(n log n)` (divides based on a pivot)

### **b) Data Structures**

- **Binary Search Tree (BST) Search:** `O(log n)`
- **Heap Operations:** `O(log n)`

---

## **5️⃣ Comparison: O(n) vs O(log n)**

Let’s assume `n = 1,000,000`:

| Complexity            | Steps Needed |
| --------------------- | ------------ |
| **O(n)**              | 1,000,000    |
| **O(log n) (Base 2)** | **~20**      |

📌 **Biggest takeaway?**  
✅ **O(log n) is much faster than O(n)** for large inputs!

---

## **6️⃣ Summary**

| Complexity   | Meaning                                            |
| ------------ | -------------------------------------------------- |
| **O(n)**     | Grows **linearly** (loops over all elements)       |
| **O(n²)**    | Grows **quadratically** (nested loops)             |
| **O(log n)** | Grows **logarithmically** (halves input each time) |

💡 **If an algorithm repeatedly reduces the problem size by a factor (like dividing by 2), its time complexity is O(log n).** 🚀
