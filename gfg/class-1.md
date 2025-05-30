**Asymptotic analysis** is a way to describe the **efficiency of an algorithm** (usually time or space) in terms of **input size** as the input grows **very large (approaches infinity)**. It helps us understand how an algorithm behaves in the **worst, best, or average case**, without worrying about machine-specific constants or small input sizes.

---

### 🔍 **Key Concepts:**

1. **Focus on Input Size (n):**
   Asymptotic analysis looks at how the algorithm scales as `n → ∞`.

2. **Ignores Constants and Lower-Order Terms:**
   For large `n`, constants and smaller terms are negligible.
   For example, `f(n) = 3n² + 5n + 10` becomes `Θ(n²)`.

3. **Compares Algorithm Efficiency:**
   It allows you to compare two algorithms independent of hardware.

---

### ✅ **Why Is It Useful?**

* You don’t need to run the program to evaluate performance.
* It gives a standard way to express and compare complexity.
* Helps in choosing the most efficient algorithm for large datasets.

---

### 🧠 **Types of Asymptotic Notation:**

| Notation    | Meaning                            | Example                                           |
| ----------- | ---------------------------------- | ------------------------------------------------- |
| **O(f(n))** | Upper Bound (Worst Case)           | `O(n²)` means it grows no faster than `n²`        |
| **Ω(f(n))** | Lower Bound (Best Case)            | `Ω(n)` means it takes at least `n` steps          |
| **Θ(f(n))** | Tight Bound (Average/Typical Case) | `Θ(n log n)` means it always grows like `n log n` |

---

### 📌 Example:

Suppose you have this loop:

```java
for (int i = 0; i < n; i++) {
    System.out.println(i);
}
```

* This runs `n` times → Time Complexity: **O(n)** (Linear time)

---

### 🧪 Summary:

* Asymptotic analysis = performance for large input sizes.
* Ignores constants and small variations.
* Uses Big-O, Big-Ω, and Big-Θ to describe time/space complexity.

---

### 🔁 **Code Structure (Nested Loops)**

```cpp
for (i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        cout << i + j << endl;
    }
}
```

---

### ⏱️ **Time Complexity (TC)**

* Outer loop runs **`n` times**
* Inner loop runs **`m` times** for each iteration of the outer loop
* Inside the inner loop: constant time operation (`cout`)

**Total operations = n × m**

🔸 **Time Complexity: `O(n * m)`**

---

### 🧠 **Space Complexity (SC)**

* `i` and `j` are loop variables → take constant space
* `cout` operation doesn't store anything
* No arrays, dynamic allocations, or recursive calls

🔸 **Space Complexity: `O(1)`**

---

### 💡 **Auxiliary Space (Extra runtime space)**

* No extra space used apart from a few variables
* No recursion or additional data structures

🔸 **Auxiliary Space: `O(1)`**

---

### ✅ Final Answer:

* **Time Complexity:** `O(n * m)`
* **Space Complexity:** `O(1)`
* **Auxiliary Space:** `O(1)`

---

Now we are printing a **matrix of strings** instead of integers:

```cpp
arr => matrix of strings

for (i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        cout << arr[i][j] << endl;
    }
}
```

---

### ✅ **Loop Execution Count** (Still the same):

* Outer loop: `n` times
* Inner loop: `m` times per outer iteration
* Total iterations: `n * m`

So structurally, the **loop still runs `O(n * m)` times**.

---

### 🚨 Difference: **What happens inside the loop**

* You’re now printing a **string**, not an integer.
* The time to print a string depends on its **length**.
* If all strings are of average length **`k`**, then:

  * `cout << arr[i][j]` takes **`O(k)`** time per operation.

---

### 🧠 **Updated Time Complexity:**

Each of the `n * m` iterations takes `O(k)` time (where `k` = average string length):

🔸 **Time Complexity = `O(n * m * k)`**

> This is **slower** than printing integers because printing strings takes time proportional to their length.

---

### 📦 Space Complexity:

* The matrix stores `n * m` strings, each of length ≈ `k`
* So total memory used: `O(n * m * k)`
* No extra memory is used during traversal

🔸 **Space Complexity: `O(n * m * k)`**
🔸 **Auxiliary Space: `O(1)`** (if we're only printing, not allocating anything extra at runtime)

---

### ✅ Final Answer:

* **Time Complexity:** `O(n * m * k)` (k = average string length)
* **Space Complexity:** `O(n * m * k)`
* **Auxiliary Space:** `O(1)`

---

This image explains the **time complexity analysis** of processing a list of strings in two steps. Here’s the breakdown:

---

### 🧾 **Problem Setup:**

* Input: `n` strings of length `m` each.
  Example input:
  `["abd", "dfg", "bca", "ddb"]`
* Goal: Perform **two steps** on them.
* Let `n = number of strings` and `m = length of each string`.

---

### ✅ **Step-by-step Analysis:**

---

### 🔹 **Step 1: Sort characters of each string**

* `"abd"` → `"abd"`
* `"dfg"` → `"dfg"`
* `"bca"` → `"abc"`
* `"ddb"` → `"bdd"`

This is sorting individual strings → each takes `O(m log m)` time.
There are `n` strings.

➡️ **Step 1 Time Complexity:**

```
O(n * m log m)
```

---

### 🔹 **Step 2: Sort the entire list of strings**

Input to this step (after step 1):
`["abd", "dfg", "abc", "bdd"]` → Sort these lexicographically →
`["abc", "abd", "bdd", "dfg"]`

Now you're sorting `n` strings, where each comparison takes `O(m)` time (since comparing strings of length `m`).

➡️ **Step 2 Time Complexity:**

```
O(n log n * m) = O(n m log n)
```

Some alternatives:

* If you treat each string as a key of `length m`, this is equivalent to:

```
O(n * m log n)
```

Or more generally:

```
O(n m log n)
```

✅ The image correctly *rejects* a naive and wrong `O((n log n)^2)` estimate.

---

### 🔚 **Final Time Complexity:**

Step 1: `O(n m log m)`
Step 2: `O(n m log n)`

🟰 **Total:**

```
O(n m log m + n m log n) = O(n m log(nm))
```

Using the identity:
`log(nm) = log n + log m`

This is the correct **tight bound**.

---

### ✅ Summary:

| Step        | Operation            | Time Complexity    |
| ----------- | -------------------- | ------------------ |
| Step 1      | Sort each string     | O(n m log m)       |
| Step 2      | Sort list of strings | O(n m log n)       |
| **Overall** | Combined             | **O(n m log(nm))** |

---

### ✅ When we say **“using the identity”**, it refers to a known **mathematical property** (or formula) used to simplify an expression.

---

### 🔍 The Identity in Question:

$$
\log(n \cdot m) = \log n + \log m
$$

This is a **logarithmic identity**. It’s always true for positive values of `n` and `m`.

---

### 🧠 Why Use This Identity?

In time complexity analysis, we often get expressions like:

* $O(n \cdot m \cdot \log n + n \cdot m \cdot \log m)$

We can factor out common terms:

$$
O(nm (\log n + \log m))
$$

And then apply the identity:

$$
\log n + \log m = \log(nm)
$$

So:

$$
O(nm (\log n + \log m)) = O(nm \log(nm))
$$

---

### 💡 Meaning of “Using the Identity” in this context:

It means you're **simplifying the expression** using a well-known mathematical rule (the logarithmic addition rule in this case).

---

### 📌 Summary:

> “Using the identity $\log(nm) = \log n + \log m$” means you are simplifying or transforming your expression using this **logarithmic rule**.

---

Understanding **when to multiply** and **when to add time complexities** is critical for accurate analysis. Here's a clear breakdown:

### ✅ **You ADD time complexities when:**

The two code blocks **run one after another (sequentially)** — not nested.

#### 🔹 Example:

```cpp
// Block A
for (int i = 0; i < n; i++) {
    // O(n)
}

// Block B
for (int j = 0; j < m; j++) {
    // O(m)
}
```

**Time Complexity:**

$$
O(n) + O(m) = O(n + m)
$$

👉 Use addition when **operations are independent and not nested**.

---

### ✅ **You MULTIPLY time complexities when:**

The two code blocks are **nested** — one inside the other.

#### 🔹 Example:

```cpp
for (int i = 0; i < n; i++) {          // O(n)
    for (int j = 0; j < m; j++) {      // O(m)
        // inner work
    }
}
```

**Time Complexity:**

$$
O(n) \times O(m) = O(nm)
$$

👉 Use multiplication when **one operation happens inside another**, increasing the number of total operations.

---

### 🔄 TL;DR Quick Rule:

| Scenario                   | Combine Time Complexities As |
| -------------------------- | ---------------------------- |
| Code blocks **sequential** | Add: `O(A) + O(B)`           |
| Code blocks **nested**     | Multiply: `O(A × B)`         |

---

### 💡 Real-World Analogy:

* **Addition**: You wash clothes (`O(n)`) and then cook food (`O(m)`).

  * Total time: `O(n + m)`
* **Multiplication**: For each shirt (`O(n)`), you sew `m` buttons (`O(m)`).

  * Total time: `O(n × m)`

---

### ✅ Code:

```cpp
// TC: O(n^2)
void func(int n) {
    for (int i = 0; i < n; i++) {              // Outer loop
        for (int j = i + 1; j < n; j++) {      // Inner loop
            cout << i + j << endl;             // Constant time work
        }
    }
}
```

---

### 🔍 Step-by-step Analysis:

Let’s focus on how many times the **`cout << i + j`** line executes.

#### ✅ Outer loop:

Runs from `i = 0` to `i = n-1` → **n iterations**

#### ✅ Inner loop:

For each value of `i`, `j` runs from `i+1` to `n-1`. So number of iterations for each `i` is:

```
(n - i - 1)
```

Let’s compute the total number of `cout` executions (total iterations of inner loop over all `i`):

---

### 🧠 Total Operations:

$$
\sum_{i=0}^{n-1}(n - i - 1)
= \sum_{i=0}^{n-1}(n - 1 - i)
= \sum_{k=1}^{n}(k) = \frac{n(n-1)}{2}
$$

---

### 📈 Final Time Complexity:

* The total number of `cout` executions is:

  $$
  \frac{n(n-1)}{2}
  $$

* Drop constants and lower-order terms:

  $$
  \boxed{O(n^2)}
  $$

---

### 🧪 Example:

Let’s say `n = 4`:

* i = 0 → j = 1,2,3 → 3 iterations
* i = 1 → j = 2,3 → 2 iterations
* i = 2 → j = 3 → 1 iteration
* i = 3 → j = none → 0 iterations

Total = `3 + 2 + 1 = 6 = (4 × 3)/2`

Again, matches the formula:

$$
\frac{n(n-1)}{2}
$$

---

### ✅ Summary:

* Nested loops, but inner loop depends on `i`
* Total operations = **triangular sum**
* Time complexity is **O(n²)**
* **Efficient compared to full `O(n²)` when both loops run full `n` times**

---

* **Sum of first n natural numbers**:

**Sum of first n natural numbers**:  
`∑ i from 1 to n` = `n(n + 1) / 2`

**Sum of Arithmetic Progression (AP)**:  
Sₙ = n/2 × [2a + (n − 1)d]  
(where `a` is the first term, `d` is the common difference)

**Sum of Geometric Progression (GP)** (for r ≠ 1):  
Sₙ = a × (1 − rⁿ) / (1 − r)  
(where `a` is the first term, `r` is the common ratio)

---

### ❓ Q1: If Big-O is an upper bound, then why not always say O(n²) or O(n!) just to be safe?

Because while **Big-O is an upper bound**, we want the **tightest** or **smallest meaningful upper bound**.

#### ✅ Example:

Imagine a function takes `3n` steps. Technically:

* It's O(n)
* It's also O(n²), O(n³), O(n!), O(2ⁿ), etc. — **all upper bounds**

But **O(n)** is the *smallest correct upper bound*.

> If we said O(n²), it’s *technically true*, but **misleading**, because we’re implying the algorithm is slower than it actually is.

#### 🎯 Key idea:

Big-O is used to **communicate performance**. If we always gave loose upper bounds, we’d lose all sense of efficiency comparison.

So we aim for:

> ✅ **Tightest Big-O bound that is still correct**.

---

### ❓ Q2: If Θ(n) gives the exact bound, why not just use Θ all the time?

Because:

> Θ(n) means the function is **both** O(n) and Ω(n) (lower bound), i.e., it **always** takes around n time.

But we often **don’t know the exact behavior**, or we care only about the **worst-case scenario**.

#### 🔍 Example:

Take quicksort:

* Worst case: O(n²)
* Best case: Ω(n log n)
* Average case: Θ(n log n)

In most cases, we only care about the **worst-case**, so we say:

> "Quicksort is O(n²)", even though it's not Θ(n²).

Also, sometimes behavior varies with input — so Θ may **not apply**, but O still does.

---

### 🔁 Summary:

| Concept     | Meaning         | When we use it                   |
| ----------- | --------------- | -------------------------------- |
| **O(f(n))** | Upper bound (≤) | To express worst-case runtime    |
| **Ω(f(n))** | Lower bound (≥) | To show minimum time it takes    |
| **Θ(f(n))** | Tight bound (≡) | To express exact growth if known |

---

### ✅ In short:

* **We use Big-O** because it gives a safe bound on performance, especially **worst-case**.
* **We avoid loose upper bounds** (like O(n²) for a linear algorithm) because they **misrepresent performance**.
* **We use Θ** only when we’re sure the runtime is tightly bounded on both sides.

---

## 🔍 Problem:

Given an array of size `n`, find the target value using linear search.

> ✅ For **linear search**, the **worst-case** time is **O(n)**
> ✅ The **best-case** is **Ω(1)** (target is at index 0)
> ✅ The **average-case** is **Θ(n)**

---

### ✅ Assumptions for Average Case:

To calculate average case, we need to define what “average” means:

* The **target is present** in the array.
* The **target is equally likely to be at any index** (uniform distribution).
* If the target is **not found**, we scan the entire array.

---

### 📊 Let's compute expected number of comparisons:

#### Case 1: Target is **present**

* Suppose array size is `n`
* Probability target is at index `i` = `1/n` (uniformly likely)
* If target is at index `i`, we make `i+1` comparisons (because arrays are 0-indexed)

So, the **expected comparisons (E)** is:

$$
E = \frac{1}{n} \sum_{i=0}^{n-1} (i + 1) = \frac{1}{n} \sum_{i=1}^{n} i = \frac{1}{n} \cdot \frac{n(n+1)}{2} = \frac{n+1}{2}
$$

So on average, the algorithm performs **(n+1)/2 comparisons**, which is **Θ(n)**.

---

#### Case 2: Target is **not present**

* The algorithm checks all `n` elements ⇒ `n` comparisons.
* So the time is **O(n)**, and it's the **worst-case** too.

---

### 📈 Final Summary:

| Case         | Comparisons | Time Complexity |
| ------------ | ----------- | --------------- |
| Best Case    | 1           | Ω(1)            |
| Average Case | (n+1)/2     | Θ(n)            |
| Worst Case   | n           | O(n)            |

---

### 💡 Conclusion:

* You **prove average-case** by computing the **expected number of steps** across all inputs.
* For linear search, average case = Θ(n), because we expect to look at half the elements on average.

---

### Expression:

$$
O(n + m^2 + k)
$$

We want to simplify this Big-O expression.

---

### 📌 Rule: In Big-O, we **keep the dominant term(s)** and **drop the lower-order ones**.

But there's a catch:
We **cannot drop** terms unless we know how they relate to each other (which is **not known** in this case).

---

### Let's analyze:

You have three terms:

* `n` (linear term)
* `m²` (quadratic term)
* `k` (another linear term, but on a different variable)

Because:

* These are all **different variables**
* We do **not know** if, for example, `n ≫ m²`, or `m² ≫ n`, or how `k` behaves

👉 **We cannot drop any of them without further info**.

---

### ✅ Final Answer:

So the correct Big-O remains:

$$
\boxed{O(n + m^2 + k)}
$$

This is already simplified as much as possible **unless**:

* You are told something like `n = O(m²)` or `k ≪ n`, etc.

---

### 🧠 Remember:

Big-O simplification only allows us to drop terms when:

* They're the **same variable** (e.g., `O(n + n²) = O(n²)`)
* Or you **know relationships** between variables

---

## ✅ 1. **Integers (e.g., `int`, `long`)**

Each integer takes a **fixed amount of memory**, depending on the language and type:

| Type      | Memory (Typical)                               |
| --------- | ---------------------------------------------- |
| `int`     | 4 bytes (32 bits)                              |
| `long`    | 8 bytes (64 bits)                              |
| `boolean` | 1 byte (sometimes more, depending on language) |

So an array of `n` integers takes **O(n)** space, with **constant-sized elements**.

---

## ✅ 2. **Strings**

Strings are more complex:

* A string is an **object** (not a primitive type).
* A string contains:

  * A reference (pointer) in the array
  * Plus the actual character array stored elsewhere in memory
* Each character typically takes **1 byte (ASCII)** or **2 bytes (Unicode)**

### Example:

Array of `n` strings, where:

* Each string has length `L`
* Then total space = `O(n * L)` in worst case

So even though the array itself is size `n`, the actual memory depends on the **total characters** in all strings.

---

## 🔁 Comparison:

| Data Type     | Space per element                 | Total space (for array of size `n`) |
| ------------- | --------------------------------- | ----------------------------------- |
| Integer array | Constant (e.g., 4 bytes)          | O(n)                                |
| String array  | Varies (depends on string length) | O(total characters) = O(n \* L)     |

---

### 💡 Conclusion:

* **Integers** → fixed space → O(n)
* **Strings** → variable space → O(n \* average string length)

So in terms of **auxiliary space**, strings **usually consume more**, and you **cannot treat them as equivalent** to integers.

---

### 🔁 Problem: Fibonacci using Recursion

```java
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
```

---

## 🧠 General Approach to Calculate Time Complexity of Recursive Code:

---

### ✅ Step 1: **Write the Recurrence Relation**

Look at how many times the function is being called recursively, and how the input size changes.

In the above code:

* For each `fib(n)`, two calls are made: `fib(n-1)` and `fib(n-2)`
* So the recurrence is:

  $$
  T(n) = T(n-1) + T(n-2) + O(1)
  $$

(The `+ O(1)` is for the addition operation.)

---

### ✅ Step 2: **Estimate the Growth**

You analyze how many total calls happen as the recursion tree expands.

The recursive tree for `fib(n)` looks like a **binary tree**, where each node splits into two more nodes (except the base cases). The number of calls roughly doubles with each increase in `n`.

This gives:

$$
T(n) \approx 2^n
$$

So, **Time Complexity** = **O(2^n)** — exponential.

---

### ✅ Step 3: **Optional – Draw Recursion Tree**

To visualize it better, you can draw the recursion tree:

```
fib(4)
├── fib(3)
│   ├── fib(2)
│   │   ├── fib(1)
│   │   └── fib(0)
│   └── fib(1)
└── fib(2)
    ├── fib(1)
    └── fib(0)
```

This helps to count the total calls and see overlapping subproblems.

---

### ✅ Step 4: **Check for Overlapping Subproblems**

If the same subproblem is being solved multiple times, and you **don't** use memoization, the complexity is worse.

* `fib(2)` is solved twice
* `fib(1)` is solved 3 times
* Hence, many redundant calls → exponential time

---

## 🧮 Bonus: Fibonacci with Memoization

```java
int fib(int n, int[] dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}
```

Here, each `fib(i)` is computed **once**, so:

* **Time Complexity:** O(n)
* **Space Complexity:** O(n) for the `dp[]` array + O(n) call stack

---

## ✅ Summary of General Steps:

| Step | Description                                                          |
| ---- | -------------------------------------------------------------------- |
| 1    | Identify base case and recursive calls                               |
| 2    | Write the recurrence relation                                        |
| 3    | Estimate total number of calls (recursion tree helps)                |
| 4    | Check for overlapping subproblems                                    |
| 5    | Use Master Theorem (if it's divide-and-conquer with fixed branching) |

---

## Let's analyze the **auxiliary space** of this recursive Fibonacci code:

---

### 🔁 Code:

```java
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
```

---

## 💡 What is Auxiliary Space?

**Auxiliary space** refers to the **extra space used by the algorithm, excluding the input and output.** In recursive functions, it mainly comes from the **call stack** used by function calls.

---

## 📚 Analysis of Call Stack

This function is **recursive**, and each recursive call goes deeper until it reaches the base case `n <= 1`.

Let’s look at the worst-case scenario:

* `fib(n)` calls `fib(n - 1)` and `fib(n - 2)`
* But **only one of these paths is active at a time on the call stack**
* The **longest chain of calls** is `fib(n) → fib(n - 1) → fib(n - 2) → ... → fib(1)`

So, the **maximum depth** of the recursive call stack is `O(n)`.

---

## ✅ Final Answer:

* **Auxiliary Space = O(n)** (due to recursion stack)
* **Note:** This is true **even though time complexity is O(2^n)** — because calls like `fib(n-2)` complete before we recurse into other branches, so the **call stack never holds more than n calls at once**.

---

## Let's now analyze **auxiliary space** for the **memoized version** of Fibonacci.

---

### 🧠 Memoized Fibonacci Code:

```java
int fib(int n, int[] dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}
```

---

## ✅ Step-by-Step Analysis

### 📦 Space used:

There are **two** main sources of space usage:

1. **Recursion call stack**
2. **Memoization array** (`dp[]`)

---

### 1️⃣ **Recursion Stack (Auxiliary Space)**

* The function is still recursive.
* The **worst-case depth** of the recursive calls is **`n`** (we go `fib(n) → fib(n-1) → ... → fib(1)`).
* So, **auxiliary space** due to the call stack = **O(n)**

> Even though `fib(n-2)` is reused from memo, `fib(n-1)` still leads to deep recursion.

---

### 2️⃣ **Memoization Array (`dp[]`)**

* This is additional space, but not part of auxiliary space. It's considered **explicit space**.
* Size = `O(n)` for storing all values from `fib(0)` to `fib(n)`.

---

## ✅ Final Answer:

| Type of Space        | Complexity         |
| -------------------- | ------------------ |
| **Auxiliary Space**  | O(n)               |
| **Total Space Used** | O(n) + O(n) = O(n) |

(The total is still O(n), as both are linear.)

---
