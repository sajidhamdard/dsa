## [Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/description/)

### ✅ Solution (Beats 100%)

```java
class Solution {
    public int[] runningSum(int[] nums) {
        int[] runningSum = new int[nums.length];
        runningSum[0] = nums[0];
        for(int i = 1; i < nums.length; i++) {
            runningSum[i] = runningSum[i-1] + nums[i];
        }
        return runningSum;
    }
}
````

### 📊 Time Complexity:

O(n), where n is the length of the input array.

### 🧠 Space Complexity:

O(n) — for creating a new result array.
Can be O(1) if done in-place by modifying the input array.

### ❌ Mistakes / Challenges Faced:

* None

### 🧩 Pattern:

 Prefix Sum
