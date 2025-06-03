## [Number of Steps to Reduce a Number to Zero](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/description/)

### ✅ Solution (Beats 100%)

```java
class Solution {
    public int numberOfSteps(int num) {
        int count = 0;
        if(num == 0) return count;

        int n = num;
        while(n > 0) {
            n = n % 2 == 0 ? n/2 : n-1;
            ++count;
        }
        return count;
    }
}
````

### 📊 Time Complexity:

O(log n), Because we're either halving or decrementing the number, and the halving dominates in reducing size, the total number of iterations will be bounded by O(log n).

### 🧠 Space Complexity:

O(1) — No extra space used

### ❌ Mistakes / Challenges Faced:

* None

### 🧩 Pattern/Topic:

Math, Bit Manipulation
