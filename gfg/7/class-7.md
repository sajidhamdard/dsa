## ✅ Problem: Group Anagrams

### 🔹 Statement:

Given a list of strings, **group all anagrams together**.
Two strings are anagrams if they contain the same characters in any order (e.g., `"act"`, `"tac"`, `"cat"`).

### 🔹 Example:

```cpp
Input:  {"act", "dog", "cat", "god", "tac"}
Output: [["act", "cat", "tac"], ["dog", "god"]]
```

---

## 💡 Brute Force Approach

### 🔹 Idea:

* For each string, sort the characters.
* Group strings that have the same sorted version.

### 🔹 Code:

```cpp
vector<vector<string>> groupAnagramsBrute(vector<string>& arr) {
    unordered_map<string, vector<string>> mp;

    for (string s : arr) {
        string sortedStr = s;
        sort(sortedStr.begin(), sortedStr.end());
        mp[sortedStr].push_back(s);
    }

    vector<vector<string>> result;
    for (auto& entry : mp) {
        result.push_back(entry.second);
    }

    return result;
}
```

### ⏱ Time Complexity: `O(n * k log k)`

* `n`: number of strings
* `k`: max length of a string (due to sorting each string)

### 📦 Space Complexity: `O(n * k)`

* For storing groups of strings

---

## ✅ Optimized Approach Using Frequency Hash (Your Code)

### 🔹 Idea:

* Instead of sorting, generate a **frequency-based hash key** for each string.
* This avoids sorting overhead and works in `O(k)` time per string.

### 🔹 Hash Key:

For `"act"` → frequency: `{1, 1, 1, 0, 0, ..., 0}`
Hash key: `"1#1#1#0#0#...#0#"`

### 🔹 Code:

```cpp
string createHashKey(string s) {
    vector<int> freq(26, 0);
    for (char ch : s) {
        freq[ch - 'a']++;
    }

    string result = "";
    for (int i = 0; i < 26; i++) {
        result += to_string(freq[i]) + "#";
    }

    return result;
}

vector<vector<string>> groupAnagrams(vector<string> arr) {
    unordered_map<string, vector<string>> anagrams;

    for (string word : arr) {
        string key = createHashKey(word);
        anagrams[key].push_back(word);
    }

    vector<vector<string>> result;
    for (auto& entry : anagrams) {
        result.push_back(entry.second);
    }

    return result;
}
```

---

## ✅ Optimization Note:

In your `TODO`, you mentioned optimizing **Auxiliary Space** from `O(n * k)` to `O(n)`.

This **cannot be fully reduced** to `O(n)` because:

* You still need to store each word once ⇒ `O(n * k)` space is required for final output.
* However, you already avoid sorting cost.

✅ **What your code optimizes** is the **string sorting step**, which reduces time from `O(k log k)` to `O(k)`.

---

## ✅ Time and Space Analysis

| Approach              | Time Complexity  | Space Complexity | Notes                                  |
| --------------------- | ---------------- | ---------------- | -------------------------------------- |
| Brute (Sort)          | `O(n * k log k)` | `O(n * k)`       | Easy to write, slower for large inputs |
| Optimized (Hash freq) | `O(n * k)`       | `O(n * k)`       | Faster for long strings, avoids sort   |

---

## ✅ Output of This Example:

```cpp
Input: {"act", "dog", "cat", "god", "tac"}
Output: 
act cat tac 
dog god 
```

---

## ✅ Main Function:

```cpp
int main() {
    vector<vector<string>> res = groupAnagrams({"act", "dog", "cat", "god", "tac"});
    for (vector<string>& group : res) {
        for (string& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }
}
```

---

Let me know if you'd like:

* To return sorted groups
* To implement it for case-insensitive strings
* To handle Unicode characters as well

---

## ✅ Problem: Group Anagrams

### 🔹 Statement:

Given a list of strings, **group all anagrams together**.
Two strings are anagrams if they contain the same characters in any order (e.g., `"act"`, `"tac"`, `"cat"`).

### 🔹 Example:

```cpp
Input:  {"act", "dog", "cat", "god", "tac"}
Output: [["act", "cat", "tac"], ["dog", "god"]]
```

---

## 💡 Brute Force Approach

### 🔹 Idea:

* For each string, sort the characters.
* Group strings that have the same sorted version.

### 🔹 Code:

```cpp
vector<vector<string>> groupAnagramsBrute(vector<string>& arr) {
    unordered_map<string, vector<string>> mp;

    for (string s : arr) {
        string sortedStr = s;
        sort(sortedStr.begin(), sortedStr.end());
        mp[sortedStr].push_back(s);
    }

    vector<vector<string>> result;
    for (auto& entry : mp) {
        result.push_back(entry.second);
    }

    return result;
}
```

### ⏱ Time Complexity: `O(n * k log k)`

* `n`: number of strings
* `k`: max length of a string (due to sorting each string)

### 📦 Space Complexity: `O(n * k)`

* For storing groups of strings

---

## ✅ Optimized Approach Using Frequency Hash (Your Code)

### 🔹 Idea:

* Instead of sorting, generate a **frequency-based hash key** for each string.
* This avoids sorting overhead and works in `O(k)` time per string.

### 🔹 Hash Key:

For `"act"` → frequency: `{1, 1, 1, 0, 0, ..., 0}`
Hash key: `"1#1#1#0#0#...#0#"`

### 🔹 Code:

```cpp
string createHashKey(string s) {
    vector<int> freq(26, 0);
    for (char ch : s) {
        freq[ch - 'a']++;
    }

    string result = "";
    for (int i = 0; i < 26; i++) {
        result += to_string(freq[i]) + "#";
    }

    return result;
}

vector<vector<string>> groupAnagrams(vector<string> arr) {
    unordered_map<string, vector<string>> anagrams;

    for (string word : arr) {
        string key = createHashKey(word);
        anagrams[key].push_back(word);
    }

    vector<vector<string>> result;
    for (auto& entry : anagrams) {
        result.push_back(entry.second);
    }

    return result;
}
```

---

## ✅ Optimization Note:

In your `TODO`, you mentioned optimizing **Auxiliary Space** from `O(n * k)` to `O(n)`.

This **cannot be fully reduced** to `O(n)` because:

* You still need to store each word once ⇒ `O(n * k)` space is required for final output.
* However, you already avoid sorting cost.

✅ **What your code optimizes** is the **string sorting step**, which reduces time from `O(k log k)` to `O(k)`.

---

## ✅ Time and Space Analysis

| Approach              | Time Complexity  | Space Complexity | Notes                                  |
| --------------------- | ---------------- | ---------------- | -------------------------------------- |
| Brute (Sort)          | `O(n * k log k)` | `O(n * k)`       | Easy to write, slower for large inputs |
| Optimized (Hash freq) | `O(n * k)`       | `O(n * k)`       | Faster for long strings, avoids sort   |

---

## ✅ Output of This Example:

```cpp
Input: {"act", "dog", "cat", "god", "tac"}
Output: 
act cat tac 
dog god 
```

---

## ✅ Main Function:

```cpp
int main() {
    vector<vector<string>> res = groupAnagrams({"act", "dog", "cat", "god", "tac"});
    for (vector<string>& group : res) {
        for (string& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }
}
```

---

A **recursion tree** is a **visual representation** of how recursive calls are made during the execution of a recursive function. It helps you understand:

* How the function breaks down the problem
* How many calls are made
* How deep the recursion goes
* What the **time complexity** might be

---

## 🔍 Why Use a Recursion Tree?

* To **analyze time complexity**
* To **visualize subproblems**
* To **track overlapping subproblems** (important for DP)
* To understand how recursive calls **branch out**

---

## 📊 Example: Fibonacci Recursion Tree

Let’s take `fib(4)` using the standard recursive approach:

```java
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}
```

### ✨ Recursion Tree for `fib(4)`

```
               fib(4)
              /     \
         fib(3)     fib(2)
         /    \      /   \
    fib(2)  fib(1) fib(1) fib(0)
    /   \
fib(1) fib(0)
```

Now calculate values bottom-up:

* `fib(0)` = 0
* `fib(1)` = 1
* `fib(2)` = `fib(1) + fib(0)` = 1 + 0 = 1
* `fib(3)` = `fib(2) + fib(1)` = 1 + 1 = 2
* `fib(4)` = `fib(3) + fib(2)` = 2 + 1 = 3

---

## 🕒 Time Complexity Using Recursion Tree

* Every call splits into **two more calls**, except base cases.
* So total calls grow roughly like a **binary tree**.
* Hence, the time complexity is:

  $$
  T(n) = T(n - 1) + T(n - 2) \Rightarrow O(2^n)
  $$

---

## 🔄 Recursion Tree in Other Examples

### Example: Factorial `fact(4)`

```
fact(4)
  |
fact(3)
  |
fact(2)
  |
fact(1)
  |
fact(0)
```

Here, the recursion tree is a straight line — **no branching**, just one call per level.

---

## ✅ Summary

| Feature            | Explanation                                 |
| ------------------ | ------------------------------------------- |
| **Recursion Tree** | Tree showing all recursive calls            |
| **Helps With**     | Understanding execution & time complexity   |
| **Used In**        | Fibonacci, Merge Sort, Backtracking, etc.   |
| **Time Analysis**  | Count number of nodes or levels in the tree |

---

### 🔙 What is Backtracking?

**Backtracking** is a **systematic trial-and-error** algorithmic technique used to solve problems by exploring all possible options and **undoing (backtracking)** when a solution path doesn't lead to a valid result.

> It's like exploring all possible decisions and undoing a choice if it leads to a dead end.

---

## ✅ Key Concepts of Backtracking:

1. **Recursive approach**: Try one choice, then move to the next level.
2. **Undo step (backtrack)**: If a path doesn’t lead to a solution, undo the last move and try a different path.
3. **Use cases**: It’s used in problems involving **searching**, **combinations**, **permutations**, and **constraints**.

---

## 🧠 When to Use Backtracking?

Use backtracking when:

* You want **all solutions**, or the **first valid solution**
* You need to try multiple combinations/permutations
* You face constraints (like “no duplicate values,” “must be in range,” etc.)

---

## 📚 Classic Examples

| Problem                             | Description                                 |
| ----------------------------------- | ------------------------------------------- |
| Subsets / Power set                 | Generate all subsets                        |
| Permutations                        | All arrangements of elements                |
| N-Queens                            | Place N queens on a board without attacking |
| Sudoku Solver                       | Fill numbers with row/col/box constraints   |
| Rat in a Maze / Maze solver         | Find a path from start to end               |
| Word Search in Grid (like LeetCode) | Find words by moving up/down/left/right     |

---

## 🧾 Example: Subsets using Backtracking (Java)

```java
void backtrack(int[] nums, int start, List<Integer> current, List<List<Integer>> result) {
    result.add(new ArrayList<>(current));  // include current subset

    for (int i = start; i < nums.length; i++) {
        current.add(nums[i]);             // choose
        backtrack(nums, i + 1, current, result); // explore
        current.remove(current.size() - 1);      // un-choose (backtrack)
    }
}

List<List<Integer>> subsets(int[] nums) {
    List<List<Integer>> result = new ArrayList<>();
    backtrack(nums, 0, new ArrayList<>(), result);
    return result;
}
```

### ✨ Dry Run for `nums = [1, 2]`

```
Start with []
Choose 1 → [1]
  Choose 2 → [1,2] ✅
  Backtrack → [1]
Backtrack → []

Choose 2 → [2] ✅
Backtrack → []

All subsets: [], [1], [1,2], [2]
```

---

## 🧩 Summary Table

| Concept          | Backtracking                                    |
| ---------------- | ----------------------------------------------- |
| Approach         | Try → Explore → Undo                            |
| Suitable for     | Combinations, Permutations, Constraint problems |
| Key Steps        | Choose → Recurse → Un-choose                    |
| Time Complexity  | Often exponential (depends on problem)          |
| Example problems | N-Queens, Sudoku, Subsets, Word Search          |

---

## ✅ Problem: Tower of Hanoi

### 🔹 Statement:

You are given **3 rods** (A, B, C) and **n disks**. Initially, all `n` disks are stacked on rod `A` in **decreasing order** of size (largest at bottom).

Your task is to:

1. Move all `n` disks from rod `A` to rod `C`.
2. You can use rod `B` as an auxiliary.
3. **Constraints:**

   * You can move only one disk at a time.
   * A larger disk cannot be placed on top of a smaller disk.

### 🔸 Objective:

* Print the steps to move disks (optional).
* Return the **total number of moves**.

---

## 🧠 Brute Force / Recursive Approach (Standard Method)

### 🔹 Idea:

To move `n` disks from `A` to `C` using `B`:

1. Move `n-1` disks from `A` to `B` using `C`.
2. Move the `n`-th (largest) disk from `A` to `C`.
3. Move the `n-1` disks from `B` to `C` using `A`.

This follows the same logic recursively.

---

### 🔹 Recursive Function with Steps (Your Code):

```cpp
int towerOfHanoiUtil(int n, string A, string C, string B) {
    if (n == 0) return 0;

    int result = towerOfHanoiUtil(n - 1, A, B, C);
    cout << "Move " << n << "-th Disk from " << A << " to " << C << endl;
    result++;
    result += towerOfHanoiUtil(n - 1, B, C, A);

    return result;
}
```

### 🔹 Wrapper Function:

```cpp
int towerOfHanoi(int n) {
    return towerOfHanoiUtil(n, "A", "C", "B");
}
```

---

## 🔄 Recursive Formula (Moves Only)

The number of moves required for `n` disks is:

```
T(n) = 2*T(n-1) + 1
T(0) = 0
```

Which leads to:

```
T(n) = 2^n - 1
```

### 🔹 Code Without Printing:

```cpp
int towerOfHanoiWithoutVisuals(int n) {
    if (n == 0) return 0;
    return 2 * towerOfHanoiWithoutVisuals(n - 1) + 1;
}
```

---

## 🧪 Example Outputs:

```cpp
towerOfHanoiWithoutVisuals(2) → 3
towerOfHanoiWithoutVisuals(3) → 7
```

### 🔹 Steps for n=2:

```
Move 1-th Disk from A to B
Move 2-th Disk from A to C
Move 1-th Disk from B to C
```

---

## ✅ Time and Space Complexity

| Function                       | Time Complexity | Space Complexity | Notes                             |
| ------------------------------ | --------------- | ---------------- | --------------------------------- |
| `towerOfHanoiUtil()`           | `O(2^n)`        | `O(n)`           | Due to recursive calls and output |
| `towerOfHanoiWithoutVisuals()` | `O(n)`          | `O(n)`           | Just calculates total moves       |

---

## 🔁 Summary

| n | Minimum Moves |
| - | ------------- |
| 1 | 1             |
| 2 | 3             |
| 3 | 7             |
| 4 | 15            |
| n | 2ⁿ − 1        |

---

## ✅ Main Function:

```cpp
int main() {
    cout << towerOfHanoiWithoutVisuals(2) << endl;  // 3
    cout << towerOfHanoiWithoutVisuals(3) << endl;  // 7
}
```

---
