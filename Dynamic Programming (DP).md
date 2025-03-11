### **🔹 What is Dynamic Programming (DP)?**

Dynamic Programming (DP) is an **optimization technique** used to solve problems by **breaking them down into overlapping subproblems** and solving each subproblem only **once**, storing the results to avoid redundant calculations.

It is used for **problems with optimal substructure** (where the solution to a larger problem depends on smaller subproblems) and **overlapping subproblems** (where the same subproblems occur multiple times).

---

### **🔹 Key Concepts of DP**

1. **Optimal Substructure:**
   - A problem exhibits optimal substructure if its solution can be constructed from solutions to its subproblems.
2. **Overlapping Subproblems:**
   - If the same subproblems are solved multiple times, DP can **store** results to avoid recomputation.

---

### **🔹 Two Approaches to DP**

#### **1️⃣ Memoization (Top-Down Approach)**

- **Uses recursion** and **stores results** in a data structure (array, HashMap, etc.).
- Starts solving from the **main problem**, breaking it into subproblems.
- **Example:** Fibonacci with recursion + HashMap.

#### **2️⃣ Tabulation (Bottom-Up Approach)**

- **Uses iteration (loops) and builds the solution** from smaller subproblems.
- Starts from the **smallest base cases** and works upwards.
- **Example:** Fibonacci using an array.

---

### **🔹 Example: Fibonacci Sequence**

#### **🚫 Without DP (Recursive, O(2ⁿ))**

```java
class Solution {
    public int fib(int n) {
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
}
```

❌ **Problem:** Too many redundant calculations.

---

### **✅ 1️⃣ Memoization (Top-Down, O(n))**

```java
import java.util.HashMap;

class Solution {
    private HashMap<Integer, Integer> memo = new HashMap<>();

    public int fib(int n) {
        if (n <= 1) return n;
        if (memo.containsKey(n)) return memo.get(n);

        int result = fib(n - 1) + fib(n - 2);
        memo.put(n, result); // Store result
        return result;
    }
}
```

✅ **Benefit:** Stores results in `memo`, avoiding redundant work.

---

### **✅ 2️⃣ Tabulation (Bottom-Up, O(n))**

```java
class Solution {
    public int fib(int n) {
        if (n <= 1) return n;

        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2]; // Build solution iteratively
        }

        return dp[n]; // Final answer
    }
}
```

✅ **Benefit:** Iterative, avoids recursion stack overhead.

---

### **🔹 When to Use DP?**

- **Problems involving choices** (e.g., Knapsack problem).
- **Problems with overlapping subproblems** (e.g., Fibonacci, DP on Trees).
- **Optimization problems** (e.g., Longest Common Subsequence).

---

### **🔹 Summary**

| Approach                   | Time Complexity | Space Complexity     | Used When?                           |
| -------------------------- | --------------- | -------------------- | ------------------------------------ |
| **Recursive (No DP)**      | O(2ⁿ)           | O(n) (Call Stack)    | Simple, but slow for large `n`       |
| **Memoization (Top-Down)** | O(n)            | O(n) (HashMap/Array) | Recursive, avoids redundant calls    |
| **Tabulation (Bottom-Up)** | O(n)            | O(n) (Array)         | Iterative, avoids recursion overhead |

🚀 **DP makes recursive problems efficient by storing and reusing results!**
