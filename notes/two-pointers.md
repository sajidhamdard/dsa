### **What is the Two-Pointer Approach?**
The **two-pointer approach** is an efficient algorithmic technique where two pointers (or indices) are used to traverse a data structure, usually an array or a string.

---

### **When to Use the Two-Pointer Approach?**
Use this technique when:
1. **Searching for pairs** → Finding two numbers that satisfy a condition (e.g., two-sum problem in a sorted array).
2. **Merging operations** → Like merging two sorted arrays.
3. **Partitioning problems** → Removing elements, rearranging arrays.
4. **Optimizing space & time complexity** → Avoiding extra space for duplicate removal or in-place operations.
5. **Sliding window problems** → Finding subarrays or substrings efficiently.

---

### **Types of Two-Pointer Approaches**
1. **Opposite Direction (Start & End Pointers)**  
   - Example: Finding a pair that sums to a target in a **sorted** array.
2. **Same Direction (Fast & Slow Pointers)**  
   - Example: Removing duplicates from an array.

---

### **Example: Two-Sum Problem Using Two Pointers**
#### **Problem Statement:**
Given a **sorted** array, find **two numbers** that add up to a target sum.

#### **Algorithm:**
1. Use two pointers:
   - `left` → Start of the array.
   - `right` → End of the array.
2. If `nums[left] + nums[right] == target`, return indices.
3. If `sum < target`, move `left` forward.
4. If `sum > target`, move `right` backward.
5. Repeat until the pointers meet.

---

### **Java Code**
```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int left = 0, right = nums.length - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == target) {
                return new int[]{left, right}; // Found pair
            } else if (sum < target) {
                left++; // Move left pointer right
            } else {
                right--; // Move right pointer left
            }
        }

        return new int[]{-1, -1}; // No solution found
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {1, 2, 3, 4, 6, 8, 10};
        int target = 10;

        int[] result = sol.twoSum(nums, target);
        System.out.println("Indices: " + result[0] + ", " + result[1]);
    }
}
```

---

### **Example Walkthrough**
#### **Input:**
```plaintext
nums = [1, 2, 3, 4, 6, 8, 10], target = 10
```

#### **Steps:**
1. **Start** `left = 0`, `right = 6`
   - `1 + 10 = 11 > 10` → Move `right`
2. **Next** `left = 0`, `right = 5`
   - `1 + 8 = 9 < 10` → Move `left`
3. **Next** `left = 1`, `right = 5`
   - `2 + 8 = 10 ✅` → Found!

#### **Output:**
```plaintext
Indices: 1, 5
```

---

### **Time & Space Complexity**
- **Time Complexity:** \(O(n)\) → Linear scan.
- **Space Complexity:** \(O(1)\) → No extra space used.

---

### **Key Takeaways**
✅ Efficient for **sorted** arrays.  
✅ Can be used in **search, partition, and optimization problems**.  
✅ Reduces **nested loops** to **linear time complexity** \(O(n)\).  
