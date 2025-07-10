## ✅ Problem: Combination Sum

### 🔹 Statement:

Given a set of **distinct integers `arr[]`** and a target sum `target`, find all unique combinations where:

* The chosen numbers sum to `target`
* You may use **an element multiple times**

Each combination should be **in non-decreasing order** (your code ensures that because it doesn't move forward in recursion when reusing the same index).

---

### 🔸 Examples:

```cpp
Input: arr = [2, 4, 6, 8], target = 8
Output:
[2, 2, 2, 2]
[2, 2, 4]
[2, 6]
[4, 4]
[8]

Input: arr = [2, 4, 6, 8], target = 9
Output: []
```

---

## 💡 Brute Force (Conceptual)

Try **all combinations** of elements and filter those that sum to `target`.

This leads to exponential time as it explores every path:

* At each index, choose: **Include** the element (and stay on the same index) or **Exclude** the element (and move forward)

Due to the inclusion possibility (multiple times), the recursion tree is large → needs optimization via backtracking.

---

## ✅ Optimized Approach (Backtracking)

### 🔹 Idea:

* Try each element starting from current index.
* If `arr[i] <= target`, include it and recurse with `target - arr[i]`.
* After that, backtrack and try without including `arr[i]`.

### 🔹 Implementation:

```cpp
void combinationSumUtil(int i, int target, vector<int> &arr, 
                        vector<int> &currCombination, vector<vector<int>> &result) {
    if (target == 0) {
        result.push_back(currCombination); // valid combination
        return;
    }
    if (i == arr.size()) return;

    // Include arr[i]
    if (arr[i] <= target) {
        currCombination.push_back(arr[i]);
        combinationSumUtil(i, target - arr[i], arr, currCombination, result);
        currCombination.pop_back();
    }

    // Exclude arr[i]
    combinationSumUtil(i + 1, target, arr, currCombination, result);
}
```

### 🔹 Wrapper:

```cpp
vector<vector<int>> combinationSum(vector<int> arr, int target) {
    vector<vector<int>> result;
    vector<int> currCombination;
    combinationSumUtil(0, target, arr, currCombination, result);
    return result;
}
```

---

## ✅ Time and Space Complexity

### ⏱ Time Complexity: `O(2 ^ max(n, target))`

* At each element, we can either include or exclude.
* Repeated inclusion of elements expands the tree.
* Worst-case is exponential, especially if target is large and small elements can be used many times.

### 📦 Space Complexity: `O(max(n, target))`

* Due to recursion stack and the current combination path (`currCombination`).

---

## ✅ Dry Run:

```cpp
Input: [2, 4, 6, 8], target = 8

→ [2,2,2,2] → sum = 8 ✔️  
→ [2,2,4]   → sum = 8 ✔️  
→ [2,6]     → sum = 8 ✔️  
→ [4,4]     → sum = 8 ✔️  
→ [8]       → sum = 8 ✔️  
```

---

## ✅ Output:

```cpp
vector<vector<int>> res = combinationSum({2, 4, 6, 8}, 8);
vector<vector<int>> res2 = combinationSum({2, 4, 6, 8}, 9);
```

**res:**

```
2 2 2 2
2 2 4
2 6
4 4
8
```

**res2:**

```
(no output — no valid combination)
```

---

## ✅ Summary Table

| Step             | Decision                         | Result               |
| ---------------- | -------------------------------- | -------------------- |
| arr\[i] ≤ target | Include arr\[i] and recurse      | Explore left branch  |
| Else or done     | Exclude arr\[i] and move to next | Explore right branch |

---

## ✅ Problem: Phone Keypad – Generate All Possible Words

### 🔹 Statement:

Given a vector of digits `0–9`, generate all possible letter combinations **as per mobile keypad mapping**.

The mapping is as follows:

| Digit | Characters |
| ----- | ---------- |
| 2     | abc        |
| 3     | def        |
| 4     | ghi        |
| 5     | jkl        |
| 6     | mno        |
| 7     | pqrs       |
| 8     | tuv        |
| 9     | wxyz       |

Digits `0` and `1` do not map to any letters and are ignored here.

---

### 🔸 Example:

```cpp
Input: digits = [2, 3]
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
```

---

## 💡 Brute Force (Conceptual)

Try to generate all combinations by:

* Taking one character from each digit’s mapping.
* Use recursion to explore each position.

Since each digit can map to up to 4 characters (like 7 or 9), we’ll explore `4^n` possibilities in the worst case.

---

## ✅ Optimized Approach: Backtracking (Your Code)

### 🔹 Idea:

Use recursive **backtracking** to build combinations:

* For each digit at position `i`, loop through its mapped letters.
* Add a letter, move to the next digit (`i + 1`), and backtrack afterward.

### 🔹 Code:

```cpp
vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void getPossibleWordsUtil(int i, vector<int> &digits, string &currWord, vector<string> &result) {
    if (i == digits.size()) {
        result.push_back(currWord);
        return;
    }

    for (char ch : keypad[digits[i]]) {
        currWord.push_back(ch);
        getPossibleWordsUtil(i + 1, digits, currWord, result);
        currWord.pop_back();  // Backtrack
    }
}

vector<string> getPossibleWords(vector<int> digits) {
    vector<string> result;
    string currWord = "";

    getPossibleWordsUtil(0, digits, currWord, result);
    return result;
}
```

---

## 🧠 Time and Space Complexity

Let:

* `n` = number of digits
* Each digit maps to at most 4 characters (e.g., '7', '9')

### ⏱ Time Complexity: `O(4^n)`

* At each digit, we can branch into up to 4 choices.
* Total combinations ≈ 4^n in the worst case.

### 📦 Space Complexity: `O(n)`

* Maximum depth of recursion = `n` (number of digits)
* Plus some space for storing results.

---

## ✅ Dry Run for `{2, 3}`

```text
digit 2 → 'a', 'b', 'c'
digit 3 → 'd', 'e', 'f'

Combinations:
- a + d
- a + e
- a + f
- b + d
- b + e
- ...
Total: 3 x 3 = 9
```

Output:

```
ad ae af bd be bf cd ce cf
```

---

## ✅ Output of Your `main()`:

```cpp
vector<string> result = getPossibleWords({2, 3});
```

**Printed Output:**

```
ad ae af bd be bf cd ce cf
```

---

## ✅ Summary Table

| Step   | Action                                      |
| ------ | ------------------------------------------- |
| i == n | Store `currWord` in result                  |
| Else   | Loop through `keypad[digit[i]]` and recurse |

---

## 🔁 Use Case Variations

Let me know if you want to:

* Skip digits like `0` or `1` completely
* Handle invalid digits (outside 0–9)
* Convert input string like `"23"` instead of vector `{2,3}`
* Return results in sorted order (default is DFS order)

---
