## [Reverse Integer](https://leetcode.com/problems/reverse-integer/description/)

### ✅ Solution (Beats 87%)

```java
class Solution {
    public int reverse(int x) {
        int num = 0;
        int n = Math.abs(x);
        while(n != 0) {
            int rem = n % 10;
            if (num > (Integer.MAX_VALUE - rem) / 10) {
                return 0;
            }
            num = num * 10 + rem;
            n = n / 10;
        }
        return x < 0 ? -num : num;
    }
}
````

```java
class Solution {
    public int reverse(int x) {
        long num = 0;
        while(x != 0) {
            int rem = x % 10;
            num = num * 10 + rem;
            x = x / 10;
        }
        return (num >= Integer.MIN_VALUE && num <= Integer.MAX_VALUE) ? (int) num : 0;
    }
}
```

### 📊 Time Complexity:

`O(log n)` : Dividing by 10

### 🧠 Space Complexity:

`O(1)` — No extra space used

### ❌ Mistakes / Challenges Faced:

---

*Reversing the digits wasn't a challenge, but the real difficulty came while handling the 32-bit integer overflow. The second solution, which uses a `long`, passes all test cases, but it's not considered valid since it relies on a 64-bit integer to store the result. The first solution handles overflow correctly by checking conditions before updating the number. The expression `num > (Integer.MAX_VALUE - rem) / 10` ensures we avoid overflow by stopping before multiplying by 10 would exceed the limit, and adding the remainder helps correctly handle edge cases.*

---

### 🧩 Pattern/Topic:

`Linked List`, `Two Pointers`
