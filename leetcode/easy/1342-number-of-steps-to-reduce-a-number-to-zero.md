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

### Bit manipulation solution

```java
class Solution {
    public int numberOfSteps(int num) {
        int count = 0;
        if(num == 0) return count;
        int n  = num;
        while(n > 0) {
            if((n & 1) == 0) {
                //even
                ++count;
            } else {
                //if 1 add 1 else add 2
                count += (n == 1) ? 1 : 2;
            }
            n = n >> 1;
        }
        return count;
    }
}
```

### 📊 Time Complexity:

`O(log n)` : Because we're either halving or decrementing the number, and the halving dominates in reducing size, the total number of iterations will be bounded by O(log n).

### 🧠 Space Complexity:

`O(1)` — No extra space used

### ❌ Mistakes / Challenges Faced:

* In bit manipulation solution if number is odd then we have to handle the edge case where number is 1. For 1 we will add only 1 to the total count. Rest all logic is straight forward.

### 🧩 Pattern/Topic:

`Math`, `Bit Manipulation`
