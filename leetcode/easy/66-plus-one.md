## [Plus One](https://leetcode.com/problems/plus-one/description/)

### ✅ Solution (Beats 100%)

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int i = digits.length - 1;
        while(i >= 0) {
            if(digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
            i--;
        }
        // If we reach here, all digits were 9
        int[] arr = new int[digits.length+1];
        arr[0] = 1;
        return arr;
    }
}
````

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int[] arr = null;
        int carryover = 1;
        for(int i = digits.length - 1; i >= 0; i--) {
            carryover = carryover + digits[i];
            carryover  = carryover > 0 ? carryover / 10 : 0;
        }
        arr = carryover == 1 ? new int[digits.length+1] : new int[digits.length];
        carryover = 1;
        for(int i = digits.length - 1; i >= 0; i--) {
            carryover = carryover + digits[i];
            arr[i] = carryover % 10;
            carryover  = carryover > 0 ? carryover / 10 : 0;
        }
        if(carryover == 1) {
            arr[0] = carryover;
        }
        return arr;
    }
}
```

### 📊 Time Complexity:

`O(n)`

### 🧠 Space Complexity:

`O(n)` — extra space used to store n+1 elements

### ❌ Mistakes / Challenges Faced:

* The first solution modifies the input array, which some interviewers might not prefer. However, the approach is efficient and elegant. In the second solution, we first calculate the carryover to determine the required size of the result array dynamically. Both solutions are valid, but the first one is more concise and clear in its logic.

### 🧩 Pattern/Topic:

`Array`, `Math`
