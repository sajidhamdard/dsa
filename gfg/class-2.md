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

Let me know if you want a dry run of this example or help analyzing a different recursive function.
