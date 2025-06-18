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

## ✅ Problem Statement

Given a **sorted array** `arr` and a `target` integer, determine whether **any two elements** in the array sum to `target`.

Return `true` if such a pair exists, else return `false`.

---

## ✅ Explanation

We use the **Two Pointer Technique**:

* Start with two pointers:

  * `left` at the beginning
  * `right` at the end
* At each step:

  * Calculate `sum = arr[left] + arr[right]`
  * If `sum == target`: return `true`
  * If `sum < target`: move `left++`
  * If `sum > target`: move `right--`
* Continue until `left < right` is false

This works efficiently **only if the array is sorted**.

---

## ✅ Java Code

```java
public class PairSumInSortedArray {

    // TC: O(n), SC: O(1)
    public static boolean checkIfSumExists(int[] arr, int target) {
        int left = 0, right = arr.length - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == target) return true;
            if (sum < target) left++;
            else right--;
        }

        return false;
    }

    public static void main(String[] args) {
        System.out.println(checkIfSumExists(new int[]{1, 2, 5, 6, 10}, 8));  // true
        System.out.println(checkIfSumExists(new int[]{1, 2, 5, 6, 10}, 9));  // false
        System.out.println(checkIfSumExists(new int[]{1, 2, 5, 6, 10}, 10)); // true
        System.out.println(checkIfSumExists(new int[]{1, 2, 5, 5, 6, 10}, 10)); // true
        System.out.println(checkIfSumExists(new int[]{1}, 2));              // false
        System.out.println(checkIfSumExists(new int[]{1}, 1));              // false
    }
}
```

---

## ✅ Time and Space Complexity

| Metric               | Value |
| -------------------- | ----- |
| **Time Complexity**  | O(n)  |
| **Space Complexity** | O(1)  |

---

## ✅ Edge Case Notes

* Array of size < 2 → always return `false`
* Array **must be sorted**. If not, either sort it first or use a HashSet approach in O(n) time.

---

### ✅ Approach: Using HashSet (Unsorted Array)

**Idea**:

* Iterate through the array.
* For each element `num`, check if `target - num` exists in a `HashSet`.
* If yes → pair exists → return `true`
* Otherwise, add `num` to the `HashSet` and continue.

---

### 🧠 Why it works:

If `a + b = target`, then checking `target - a == b` ensures we find the pair in O(1) using the set.

---

### ⏱️ Time Complexity: `O(n)`

### 🗃️ Space Complexity: `O(n)`


---

## ✅ Problem:

> **Check if a Triplet or Quadruplet Exists with Given Sum**

Given an array of integers and a target value, return whether:

* Any **3 elements** (`arr[i] + arr[j] + arr[k]`) add up to the target → Triplet Sum
* Any **4 elements** (`arr[i] + arr[j] + arr[k] + arr[l]`) add up to the target → Quadruplet Sum

---

## 💡 Brute Force (Triplet Sum):

* Use 3 nested loops to try all combinations.
* **Time Complexity:** O(n³)
* **Space Complexity:** O(1)

---

## 💡 Optimized Approach (Two Pointer for Triplets):

1. **Sort** the array.
2. Loop through each element `i`:

   * For every `i`, fix it and find a pair (`j`, `k`) such that `arr[j] + arr[k] = target - arr[i]` using 2-pointer.
3. For quadruplets, do the same by fixing two elements and using 2-pointer for the rest.

---

## ✅ Java Code (Triplet + Quadruplet)

```java
import java.util.Arrays;

public class SumChecker {

    // Two-pointer approach
    public static boolean checkIfSumPairExists(int[] arr, int target, int left, int right) {
        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == target) return true;
            if (sum < target) left++;
            else right--;
        }
        return false;
    }

    // Triplet Sum Exists
    public static boolean checkIfTripletSumExists(int[] arr, int target) {
        Arrays.sort(arr);
        int n = arr.length;

        for (int i = 0; i < n; i++) {
            int newTarget = target - arr[i];

            if (checkIfSumPairExists(arr, newTarget, i + 1, n - 1)) {
                return true;
            }
        }
        return false;
    }

    // Quadruplet Sum Exists
    public static boolean checkIfQuadrupleSumExists(int[] arr, int target) {
        Arrays.sort(arr);
        int n = arr.length;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int newTarget = target - arr[i] - arr[j];

                // Must start from j+1, not i+1 (to avoid using same elements again)
                if (checkIfSumPairExists(arr, newTarget, j + 1, n - 1)) {
                    return true;
                }
            }
        }
        return false;
    }

    // Test
    public static void main(String[] args) {
        System.out.println(checkIfTripletSumExists(new int[]{1, 4, 45, 6, 10, 8}, 13)); // true
        System.out.println(checkIfTripletSumExists(new int[]{1, 4, 45, 6, 10, 8}, 30)); // false
        System.out.println(checkIfTripletSumExists(new int[]{1, 4, 45, 6, 10, 8}, 26)); // true
        System.out.println(checkIfTripletSumExists(new int[]{1}, 3)); // false

        System.out.println(checkIfQuadrupleSumExists(new int[]{1, 4, 45, 6, 10, 8}, 63)); // true (45+10+6+2)
        System.out.println(checkIfQuadrupleSumExists(new int[]{1, 2, 3, 4, 5}, 100)); // false
    }
}
```

---

## ⏱ Time & Space Complexity:

### ✅ For Triplet:

* **Time:** O(n²)

  * Outer loop `O(n)` and inner two-pointer scan `O(n)`
* **Space:** O(1) (ignoring sort)

### ✅ For Quadruplet:

* **Time:** O(n³)

  * Two outer loops `O(n²)` and two-pointer `O(n)`
* **Space:** O(1)

---
