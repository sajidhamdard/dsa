### **🔹 What is Memoization?**

**Memoization** is an **optimization technique** used to speed up recursive algorithms by **storing previously computed results** and reusing them instead of recomputing.

It is a **top-down dynamic programming (DP) approach** that avoids redundant calculations.

---

### **🔹 How Memoization Works**

1. **Use a data structure** (e.g., an array, HashMap) to store already computed results.
2. **Before computing a value**, check if it’s already in the data structure.
3. If **found**, return the stored result (**avoid redundant calls**).
4. If **not found**, compute it **recursively** and store the result for future use.

---

### **🔹 Fibonacci Example: Without vs. With Memoization**

#### **🚫 Without Memoization (Slow, Exponential O(2ⁿ))**

```java
class Solution {
    public int fib(int n) {
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2);  // Redundant calculations!
    }
}
```

⏳ **Problem:** `fib(4)` calls `fib(3)` and `fib(2)`, but `fib(3)` also calls `fib(2)`, causing **duplicate work**.

---

### **✅ With Memoization (Fast, O(n))**

```java
import java.util.HashMap;

class Solution {
    private HashMap<Integer, Integer> memo = new HashMap<>();

    public int fib(int n) {
        if (n <= 1) return n;
        if (memo.containsKey(n)) return memo.get(n); // Check if already computed

        int result = fib(n - 1) + fib(n - 2);
        memo.put(n, result);  // Store result for future use
        return result;
    }
}
```

### **🔹 Execution for `fib(4)`**

| Call     | Memo Check   | Computation       | Stored in Memo     |
| -------- | ------------ | ----------------- | ------------------ |
| `fib(4)` | ❌ Not found | `fib(3) + fib(2)` | Store `fib(4) = 3` |
| `fib(3)` | ❌ Not found | `fib(2) + fib(1)` | Store `fib(3) = 2` |
| `fib(2)` | ❌ Not found | `fib(1) + fib(0)` | Store `fib(2) = 1` |
| `fib(1)` | ✅ Found `1` | No compute        | -                  |
| `fib(0)` | ✅ Found `0` | No compute        | -                  |

✅ **Final Result:** `fib(4) = 3`

---

### **🔹 Time Complexity**

| Approach                | Complexity                     |
| ----------------------- | ------------------------------ |
| **Without Memoization** | O(2ⁿ) (Exponential, very slow) |
| **With Memoization**    | O(n) (Much faster)             |

🚀 **Memoization significantly improves performance by avoiding duplicate recursive calls!**
