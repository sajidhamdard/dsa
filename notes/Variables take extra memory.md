Both solutions logically achieve the same result, but the first solution **may** use slightly less memory due to how variables are handled in memory. Let's break it down:

---

### **First Solution (Less Memory Usage)**

```java
class Solution {
    public int[] runningSum(int[] nums) {
        int sum[] = new int[nums.length];  // Array to store running sum
        for(int i = 0; i < nums.length; i++) {
            if (i == 0) {
                sum[i] = nums[i];
            } else {
                sum[i] = sum[i - 1] + nums[i];  // Directly updating sum array
            }
        }
        return sum;
    }
}
```

- The only extra memory used is for the **`sum`** array.
- The running sum is stored directly in the **`sum`** array, so no additional integer variable is needed.

---

### **Second Solution (More Memory Usage)**

```java
class Solution {
    public int[] runningSum(int[] nums) {
        int[] ans = new int[nums.length];  // Array to store running sum
        int previousSum = 0;               // Extra variable
        for(int i = 0; i < nums.length; i++) {
            previousSum = previousSum + nums[i];
            ans[i] = previousSum;
        }
        return ans;
    }
}
```

- Uses an **extra integer variable (`previousSum`)** to store the running sum.
- This variable takes **4 bytes of additional memory** (since an `int` in Java is 4 bytes).
- Since the array **size remains the same**, the difference in memory is minimal.

---

### **Why is the First Solution More Memory-Efficient?**

1. **No Extra Variable:** The first solution **doesn't use an additional integer variable (`previousSum`)**, while the second one does.
2. **Direct Modification of Output Array:** In the first solution, the array itself stores the cumulative sum directly, whereas the second solution first stores the sum in `previousSum`, then assigns it to `ans[i]`.

📌 **Overall, the difference in memory usage is very small (just 4 bytes per function call), but if the problem is executed many times (in large-scale applications), it could have a slight impact.** 🚀
