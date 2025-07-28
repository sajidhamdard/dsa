### ✅ **Steps for Recursive Tree Method (to solve recurrences)**

This method is helpful when you're given a recursive function, and you want to find out how much total work is done — i.e., the **time complexity**.

---

#### **Step 1: Draw a Recursive Tree**

* Visualize the recursive calls as a tree.
* Each node represents one function call.
* Children of a node represent the recursive calls made by that function call.

---

#### **Step 2: Calculate Work Done by Each Node**

* Ignore the cost of recursive calls themselves — just focus on the work **inside** the function (non-recursive part).
* Assume this is constant (say, **C = O(1)**) per node for simplicity.

---

#### **Step 3: Calculate the Maximum Depth of the Tree**

* Determine how many levels deep the tree goes.
* This is typically determined by how the problem size shrinks in each call.
* For example, if the function reduces `n` to `n/2`, the height is `log₂n`.

---

#### **Step 4: Sum Up the Work at All Levels**

* Multiply the number of nodes at each level by the work done per node.
* Add up the work from all levels.
* If it forms a **Geometric Progression (GP)**, use the GP formula:

---

### 🧮 **GP Sum Formula**

$$
\text{Sum} = a \cdot \frac{r^n - 1}{r - 1}
$$

Where:

* `a` = first term (work at level 0)
* `r` = growth factor (e.g., if each node makes 2 calls → r = 2)
* `n` = number of levels

---

### 📘 **Example**

```cpp
void fun(int n, bool b) {
    ...
    return fun(n/2, true) + fun(n/2, false);
}
```

Let’s analyze this:

#### Step 1: Draw Recursive Tree

* Each call makes **2 recursive calls** with `n/2`.
* So it's a binary tree structure.

#### Step 2: Work per Node

* Let's assume the work is O(1) (not shown, but common for such questions).

#### Step 3: Height of Tree

* At each level, `n` becomes `n/2`, so height H = `log₂n`.

#### Step 4: Total Work

* Level 0: 1 call → O(1)
* Level 1: 2 calls → 2×O(1)
* Level 2: 4 calls → 4×O(1)
* ...
* Level log₂n: 2^(log₂n) = n calls

Total work = O(1 + 2 + 4 + ... + n) = O(n)

(This is a GP: a = 1, r = 2, number of terms = log₂n + 1)

---

### ✅ Final Time Complexity: **O(n)**

---

## 🔤 Character Operations

---

### ✅ **1. Check if Character is Uppercase**

```cpp
if (ch >= 'A' && ch <= 'Z') {
    // ch is an uppercase letter
}
```

---

### ✅ **2. Check if Character is Lowercase**

```cpp
if (ch >= 'a' && ch <= 'z') {
    // ch is a lowercase letter
}
```

---

### ✅ **3. Check if Character is a Digit**

```cpp
if (ch >= '0' && ch <= '9') {
    // ch is a digit
}
```

---

### 🔁 **4. Convert Lowercase to Uppercase**

```cpp
ch = ch - 'a' + 'A';
```

#### Example:

```cpp
char ch = 'a';
ch = ch - 'a' + 'A';  // becomes 'A'

char ch = 'c';
ch = ch - 'a' + 'A';  // becomes 'C'
```

---

### 🔁 **5. Convert Uppercase to Lowercase**

```cpp
ch = ch - 'A' + 'a';
```

#### Example:

```cpp
char ch = 'B';
ch = ch - 'A' + 'a';  // becomes 'b'
```

---

Here’s a structured explanation for solving `a^b` (a raised to the power b) using different approaches:

---

## 🔢 Solving `a^b` (Power Function)

### ✅ **1. Brute Force (Iterative)**

Multiply `a` by itself `b` times.

```java
public static long powerBrute(int a, int b) {
    long result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}
```

* **Time Complexity**: O(b)
* **Space Complexity**: O(1)

---

### ✅ **2. Recursive Power**

```java
public static long powerRecursive(int a, int b) {
    if (b == 0) return 1;
    return a * powerRecursive(a, b - 1);
}
```

* **Time Complexity**: O(b)
* **Space Complexity**: O(b) (due to recursive stack)

---

### ✅ **3. Optimized: Exponentiation by Squaring (Recursive)**

If `b` is even:
  `a^b = (a^(b/2)) * (a^(b/2))`
If `b` is odd:
  `a^b = a * (a^(b/2)) * (a^(b/2))`

```java
public static long powerFastRecursive(int a, int b) {
    if (b == 0) return 1;

    long half = powerFastRecursive(a, b / 2);

    if (b % 2 == 0)
        return half * half;
    else
        return a * half * half;
}
```

* **Time Complexity**: O(log b)
* **Space Complexity**: O(log b)

---

### ✅ **4. Optimized: Exponentiation by Squaring (Iterative)**

Best for large powers and avoids recursion stack overflow.

```java
public static long powerFastIterative(int a, int b) {
    long result = 1;
    long base = a;

    while (b > 0) {
        if (b % 2 == 1) {
            result *= base;
        }
        base *= base;
        b /= 2;
    }
    return result;
}

```

* **Time Complexity**: O(log b)
* **Space Complexity**: O(1)

---

### 💡 Optional: Modulo Power (e.g., `a^b % m`)

Used in competitive programming to avoid overflow:

```cpp
long long power(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;

    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}
```

---

## 🤔 **If iterative is possible, why use recursion?**

### ✅ Use Recursion When:

| Reason                       | Explanation                                                                                                                                              |
| ---------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **1. Simpler Logic**         | Recursion often mirrors the problem's structure. For example, problems like tree traversal, DFS, permutations, and backtracking are naturally recursive. |
| **2. Code Readability**      | Recursive solutions are usually shorter and easier to read (fewer loops, less boilerplate).                                                              |
| **3. Divide & Conquer**      | Some problems like Merge Sort, Quick Sort, and Binary Search are easier to implement using recursion.                                                    |
| **4. Stack Behavior Needed** | When you need to remember "state" at each level — e.g., in backtracking or parsing — recursion makes it easy by using the call stack.                    |

---

### ❌ Recursion Has Drawbacks:

| Issue               | Why It Matters                                                                                        |
| ------------------- | ----------------------------------------------------------------------------------------------------- |
| **Stack Overflow**  | Deep recursion (like factorial of 100000) can crash due to exceeding the call stack limit.            |
| **Overhead**        | Recursive calls are slower than loops because of function call overhead (push/pop on the call stack). |
| **Harder to Debug** | Tracing recursion is more difficult than following a loop in an IDE.                                  |

---

### ✅ Iterative Is Better When:

| Use Case                                | Reason                                                                                            |
| --------------------------------------- | ------------------------------------------------------------------------------------------------- |
| **Performance-critical apps**           | Iterative avoids stack overhead and is more memory efficient.                                     |
| **Tail recursion not optimized**        | Java, unlike languages like Scala or Haskell, doesn't optimize tail recursion.                    |
| **When problem is naturally iterative** | Like calculating factorial, Fibonacci (with memoization or bottom-up), or power (as in our case). |

---

### 📌 Real-World Guideline:

* **Start with recursion if the logic is naturally recursive**, like:

  * Tree problems
  * Graph traversals (DFS)
  * Backtracking
  * Divide & Conquer

* **Convert to iterative** if:

  * You need better performance
  * You hit recursion limits
  * It's easy to implement with loops (e.g., power, factorial)

---

### ⚖️ Final Thought:

> Recursion is a *tool* for clarity and structure. Iteration is a *tool* for performance and control. Use what's best **for the problem** and **the constraints**.

---

## ✅ Example:

If `n = 13`, you're writing:

```
1, 2, 3, ..., 9 → 9 numbers → 1 digit each → 9 digits  
10, 11, 12, 13 → 4 numbers → 2 digits each → 8 digits  
Total = 9 + 8 = 17 digits
```

The given function `countDigitsFrom1ToN(n)` computes this total **efficiently in O(log n)** time.

---

## 🔍 Code Explanation

```cpp
int countDigitsFrom1ToN(int n) {
    int result = 0;
    for (int i = 1; i - 1 < n; i *= 10) {
        result += n - (i - 1);
    }
    return result;
}
```

### 🧠 Key Idea:

It works in **digit-length blocks**:

* 1-digit numbers: from `1` to `9`
* 2-digit numbers: from `10` to `99`
* 3-digit numbers: from `100` to `999`, and so on...

### 🔁 Loop Walkthrough:

#### ✅ `i` represents powers of 10:

* `i = 1` → 1-digit numbers start from 1
* `i = 10` → 2-digit numbers start from 10
* `i = 100` → 3-digit numbers start from 100
* etc.

---

### ✏️ Formula in Loop:

```cpp
result += n - (i - 1);
```

This counts how many numbers exist from `i` to `n`, inclusive:

* For `i = 1`, contribution = `n - 0 = n` → all numbers
* For `i = 10`, contribution = `n - 9` → only 2-digit numbers and above
* For `i = 100`, contribution = `n - 99` → only 3-digit numbers and above
* ...

And so on.

It repeats until `i - 1 >= n` (i.e., we've crossed `n`).

---

## ✅ Dry Run for `n = 25`

```
i = 1      → result += 25 - (1 - 1) = 25
i = 10     → result += 25 - (10 - 1) = 25 - 9 = 16
i = 100    → 100 - 1 = 99 > 25, so loop ends
Total = 25 + 16 = 41
```

### ✅ Manual Count:

* 1–9 → 9 × 1 = 9 digits
* 10–25 → 16 × 2 = 32 digits
  → Total = 9 + 32 = **41** ✅

---

## 🧠 Time & Space Complexity

| Complexity | Value                           |
| ---------- | ------------------------------- |
| **Time**   | O(log₁₀(n)) — because `i *= 10` |
| **Space**  | O(1)                            |

---

## ✅ Summary

This loop smartly calculates digits used from 1 to `n`:

* Without converting numbers to strings
* Without manually counting digits of each number
* Uses digit-block logic based on powers of 10
