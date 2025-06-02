## [Richest Customer Wealth]([https://leetcode.com/problems/running-sum-of-1d-array/description/](https://leetcode.com/problems/richest-customer-wealth/))

### ✅ Solution (Beats 100%)

```java
class Solution {
    public int maximumWealth(int[][] accounts) {
        int maxWealth = 0;
        for(int[] row: accounts) {
            int currentWealth = 0;
            for(int num : row) {
                currentWealth += num;
            }
            maxWealth = Math.max(currentWealth, maxWealth);
        }
        return maxWealth;
    }
}
````

### 📊 Time Complexity:

O(m * n), where m is the total rows and n is total columns the input 2D array.

### 🧠 Space Complexity:

O(1) — No extra space used

### ❌ Mistakes / Challenges Faced:

* None

### 🧩 Pattern/Topic:

Array, Matrix
