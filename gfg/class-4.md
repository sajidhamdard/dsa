## ✅ Problem Statement

Given an integer array `arr`, return a new array `result` such that:

```java
result[i] = product of all elements in arr except arr[i]
```

📌 Do this **without using division** and in **O(n)** time.
---

## ✅ Java Code

```java
import java.util.*;

public class ProductExceptSelf {

    // TC: O(n), SC: O(n)
    public static int[] productExceptSelf(int[] arr) {
        int n = arr.length;
        int[] suffixProd = new int[n];
        int[] result = new int[n];

        // Step 1: Compute suffix product
        suffixProd[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            suffixProd[i] = suffixProd[i + 1] * arr[i + 1];
        }

        // Step 2: Combine with prefix product
        int prefixProd = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefixProd * suffixProd[i];
            prefixProd *= arr[i]; // update prefix for next index
        }

        return result;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4};
        System.out.println(Arrays.toString(productExceptSelf(arr))); // [24, 12, 8, 6]
    }
}
```

---

## ✅ Dry Run Example

Input: `[1, 2, 3, 4]`

* Prefix: \[1, 1, 2, 6]
* Suffix: \[24, 12, 4, 1]
* Output: `[24, 12, 8, 6]`

---

## ✅ Time and Space Complexity

| Metric               | Value |
| -------------------- | ----- |
| **Time Complexity**  | O(n)  |
| **Space Complexity** | O(n)  |

> (We can reduce to O(1) extra space if allowed to reuse the `result` array instead of using `suffixProd`)

---

## ✅ Follow-up

You can reduce space to O(1) (excluding output array) by storing suffix directly in result array, then applying prefix in second pass. Let me know if you'd like that version too.

---

### ❌ Naive Idea: Multiply All Elements and Divide

```java
totalProduct = arr[0] * arr[1] * ... * arr[n-1];
result[i] = totalProduct / arr[i];
```

---

### ❗ But this approach has 3 **critical issues**:

---

### 1. ❌ **Division is not allowed**

In most interview problems (including Leetcode 238: **Product of Array Except Self**), you are **not allowed to use division**.

---

### 2. ❌ **Zeros in the array**

If the array contains:

* **1 zero**: result\[i] is zero for all except the zero index
* **2 or more zeros**: result is all zero
  ✅ This can be handled, but needs extra logic and multiple passes

---

### 3. ❌ **Integer overflow**

Multiplying all elements can **easily exceed the integer range**.

Example:

```java
int[] arr = {100000, 100000, 100000}; // overflow occurs
```

---

### ✅ Correct Approach: Prefix + Suffix

That’s why we:

* Avoid division
* Use prefix and suffix product approach
* Can handle zeros and avoid overflow risk (to some extent)

---

### ✅ If Interviewer Allows Division?

You can still **optimize it** using the following approach if **division is allowed and no zero exists**:

```java
public static int[] productWithDivision(int[] nums) {
    int totalProduct = 1;
    for (int num : nums) totalProduct *= num;

    int[] result = new int[nums.length];
    for (int i = 0; i < nums.length; i++) {
        result[i] = totalProduct / nums[i];
    }
    return result;
}
```

But again — **this will break with `0`s**.

---

### ✅ Conclusion

Multiplying all elements and dividing **seems simpler**, but:

| Problem              | Effect             |
| -------------------- | ------------------ |
| Division not allowed | ❌ Invalid approach |
| Zeros in array       | ❌ Wrong output     |
| Integer overflow     | ❌ Risk of crash    |
| Multiple edge cases  | ❌ More bug-prone   |

That’s why **prefix–suffix** is the safest and most accepted solution.

---
