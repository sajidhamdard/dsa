The **Maximum Subarray Problem** involves finding a contiguous subarray within a given array that has the largest sum. Below are the key approaches to solving this problem, along with their algorithmic steps:

---

### **1. Brute Force Approach (O(N³))**
#### **Algorithm:**
1. Iterate over all possible subarrays using two nested loops.
2. For each subarray, calculate the sum using a third loop.
3. Keep track of the maximum sum encountered.

---

### **2. Optimized Brute Force (O(N²))**
#### **Algorithm:**
1. Iterate over all possible subarrays using two nested loops.
2. Instead of using a third loop to calculate the sum, maintain a running sum while extending the subarray.
3. Keep track of the maximum sum encountered.

---

### **3. Kadane’s Algorithm (O(N))**
#### **Algorithm:**
1. Initialize `maxSum` as the smallest possible integer and `currentSum` as `0`.
2. Traverse the array:
   - Add the current element to `currentSum`.
   - If `currentSum` exceeds `maxSum`, update `maxSum`.
   - If `currentSum` becomes negative, reset it to `0` (since a negative sum will not contribute to a larger sum).
3. Return `maxSum`.

---

### **4. Divide and Conquer Approach (O(N log N))**
#### **Algorithm:**
1. Recursively divide the array into two halves.
2. Find the maximum subarray sum in:
   - The left half.
   - The right half.
   - The crossing subarray (which spans both halves).
3. Return the maximum of the three values.

---

Kadane’s Algorithm is the most efficient approach for this problem, solving it in **O(N)** time complexity.
