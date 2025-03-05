The **Digital Root Formula** is a mathematical shortcut to find the repeated sum of digits of a number until a single digit is obtained.

### **Understanding the Digital Root**

The digital root of a number is the single-digit value obtained by repeatedly summing its digits.

For example:

- **38** → 3 + 8 = **11** → 1 + 1 = **2** (Digital Root = 2)
- **987** → 9 + 8 + 7 = **24** → 2 + 4 = **6** (Digital Root = 6)

### **Mathematical Formula**

Instead of using recursion or loops, the **digital root** can be computed directly using:

\[
\text{Digital Root} = 1 + (num - 1) \mod 9
\]

### **Why Does This Work?**

This formula comes from **modulo 9 properties**:

- A number **modulo 9** gives the same remainder as the sum of its digits modulo 9.
- The sequence of summing digits repeatedly **until a single-digit** is the same as taking `num % 9`, except when `num` is a multiple of 9 (in which case the result is 9 instead of 0).

So, we adjust for this by using the formula:

\[
1 + (num - 1) \mod 9
\]

### **Special Cases**

1. If `num = 0`, return `0` directly.
2. If `num % 9 == 0` and `num > 0`, the digital root is **9**.

### **Example Computations**

Using the formula:

- `38`: \( 1 + (38 - 1) \mod 9 = 1 + 37 \mod 9 = 1 + 1 = 2 \) ✅
- `987`: \( 1 + (987 - 1) \mod 9 = 1 + 986 \mod 9 = 1 + 6 = 7 \) ✅

### **Time Complexity**

- This formula runs in **O(1)** time, much faster than recursion or loops.

Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

You can solve this problem in **two ways**:

### **1. Recursive Approach (O(log num))**

This method keeps summing the digits until only one digit remains.

```java
class Solution {
    public int addDigits(int num) {
        if (num < 10) return num; // Base case: If single digit, return it
        int sum = 0;

        while (num > 0) {
            sum += num % 10; // Extract the last digit and add it to sum
            num /= 10; // Remove the last digit
        }

        return addDigits(sum); // Recursively call with the new sum
    }
}
```

**Example Execution:**

```
num = 38 → 3 + 8 = 11 → 1 + 1 = 2
Output: 2
```

**Time Complexity:** \( O(\log n) \)  
**Space Complexity:** \( O(\log n) \) (due to recursion stack)

---

### **2. O(1) Time Complexity – Digital Root Formula**

You can solve this in constant time using the **digital root formula**:

```java
class Solution {
    public int addDigits(int num) {
        if (num == 0) return 0;
        return 1 + (num - 1) % 9; // Digital Root formula
    }
}
```

**Explanation of the Formula:**

- If `num % 9 == 0` and `num > 0`, the answer is `9`.
- Otherwise, the result is `num % 9`.

**Example Computation:**

```
num = 38 → (38 - 1) % 9 + 1 → 37 % 9 + 1 → 1 + 1 = 2
```

**Time Complexity:** \( O(1) \)  
**Space Complexity:** \( O(1) \)
