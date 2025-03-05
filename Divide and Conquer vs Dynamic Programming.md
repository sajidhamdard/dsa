## **📌 Divide and Conquer vs Dynamic Programming**

Both **Divide and Conquer (D&C)** and **Dynamic Programming (DP)** break a problem into subproblems, but they differ in how they handle overlapping subproblems and optimization.

---

## **🔹 Key Differences**

| Feature                      | **Divide & Conquer**                                                                     | **Dynamic Programming**                                                                      |
| ---------------------------- | ---------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------- |
| **Approach**                 | Breaks a problem into independent subproblems, solves recursively, and combines results. | Breaks a problem into **overlapping** subproblems and stores results to avoid recomputation. |
| **Subproblem Type**          | Independent (no repeating subproblems).                                                  | Overlapping subproblems (same subproblems are solved multiple times).                        |
| **Optimal Substructure?**    | Yes ✅ (Optimal solutions can be combined).                                              | Yes ✅ (Optimal solutions can be used to build larger solutions).                            |
| **Overlapping Subproblems?** | ❌ No (Solves each subproblem separately).                                               | ✅ Yes (Avoids recomputing solved subproblems).                                              |
| **Efficiency**               | Can be inefficient due to redundant calculations.                                        | More efficient due to memoization or tabulation.                                             |
| **Example Algorithms**       | Merge Sort, Quick Sort, Binary Search.                                                   | Fibonacci Sequence, Knapsack Problem, Shortest Path (Dijkstra, Floyd-Warshall).              |

---

## **🔹 Example 1: Fibonacci Sequence**

The Fibonacci sequence is a classic example where **Dynamic Programming** is better than **Divide and Conquer** because of overlapping subproblems.

### **❌ Divide & Conquer (Naïve Recursive Fibonacci)**

```java
public class FibonacciDC {
    public static int fib(int n) {
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2); // Redundant calculations
    }

    public static void main(String[] args) {
        System.out.println(fib(6)); // Output: 8
    }
}
```

⛔ **Time Complexity:** **O(2ⁿ) → Exponential (Very slow)**

---

### **✅ Dynamic Programming (Memoization)**

```java
import java.util.*;

public class FibonacciDP {
    static Map<Integer, Integer> memo = new HashMap<>();

    public static int fib(int n) {
        if (n <= 1) return n;
        if (memo.containsKey(n)) return memo.get(n);

        int result = fib(n - 1) + fib(n - 2);
        memo.put(n, result); // Store computed result
        return result;
    }

    public static void main(String[] args) {
        System.out.println(fib(6)); // Output: 8
    }
}
```

✅ **Time Complexity:** **O(n) → Much faster than Divide & Conquer**

---

## **🔹 Example 2: Merge Sort vs. Fibonacci**

- **Merge Sort** (Divide and Conquer) works well because subarrays are independent.
- **Fibonacci Calculation** (Dynamic Programming) works better with memoization because of overlapping subproblems.

---

## **🔹 When to Use What?**

✅ **Use Divide & Conquer when:**  
✔ The problem can be divided into completely independent subproblems.  
✔ There is **no need to store** previously computed results.  
✔ Examples: **Sorting (Merge Sort, Quick Sort), Searching (Binary Search).**

✅ **Use Dynamic Programming when:**  
✔ The problem has **overlapping subproblems** (same calculations repeated).  
✔ Results of previous computations can be **stored and reused**.  
✔ Examples: **Fibonacci, Knapsack Problem, Shortest Path Problems.**
