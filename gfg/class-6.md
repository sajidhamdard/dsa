### 🔍 **What is Hashing?**

Hashing is a technique to **map data (key)** to a **fixed-size value (index)** using a **hash function**, typically used in **hash tables**, like `HashMap`, `HashSet`.

---

### 🐢 **Why things are slow without hashing?**

Without hashing:

* Insertion, search, and deletion in **arrays/lists** = O(n)
* You must **linearly scan** to find a key
* In **sorted arrays**, you can use binary search = O(log n), but still slower than hashing

---

### ⚡ **How hashing helps?**

* Maps keys directly to an index → **average O(1)** time
* No need to search — just jump to the location

---

### 🎯 **Hash Collision**

Occurs when **two different keys hash to the same index**.

#### 👉 How it's handled:

1. **Chaining** – Store a list at each index (e.g., LinkedList or Tree)
2. **Open Addressing** – Probe for next available slot (e.g., linear probing)

---

### ✅ **What makes a good hash function?**

* Distributes keys **evenly**
* Minimizes **collisions**
* Fast to compute
* Deterministic (same input → same output)

Example: `hash = key % tableSize` (simple, but may be weak)

---

### 📊 **Time Complexities (Hash-based DS like HashMap/HashSet):**

| Operation     | Average Case | Worst Case (due to collisions) |
| ------------- | ------------ | ------------------------------ |
| Insertion     | O(1)         | O(n)                           |
| Deletion      | O(1)         | O(n)                           |
| Search/Access | O(1)         | O(n)                           |

> Worst case happens if **all keys collide** and go into one bucket (e.g., all linked in one list).

---

### 🧠 Summary:

* Hashing = fast mapping of keys to index
* Avoids O(n) searches
* Collisions must be handled
* Good hash function = fewer collisions
* Avg case for insert/search/delete: **O(1)**

---

### 🔍 **Java HashMap: LinkedList vs Red-Black Tree**

#### 🔸 **Before Java 8**

* Each bucket in `HashMap` used a **LinkedList** to store entries with the same hash (i.e., collisions).
* In worst-case (many collisions), operations degrade to **O(n)** time.

#### 🔸 **Java 8 and after**

* If the number of entries in a bucket **exceeds 8**, and the bucket size is large enough (table ≥ 64):
  → The **LinkedList is converted to a Red-Black Tree**.

#### 📈 **Why Red-Black Tree?**

* To avoid **performance degradation** due to hash collisions.
* Reduces worst-case time complexity from **O(n)** → **O(log n)** for search, insert, delete in a bucket.

---

### ⚙️ **Thresholds (Java 8 HashMap):**

| Condition                  | Action                     |
| -------------------------- | -------------------------- |
| > 8 entries in a bucket    | Convert to Tree            |
| < 6 entries after deletion | Convert back to LinkedList |

---

### 🧠 Summary:

* **LinkedList** is simple but slow with collisions → O(n)
* **Red-Black Tree** improves performance → O(log n)
* Java 8+ uses both: **LinkedList for few entries**, **Tree for many**

---

### 🔍 **Problem Summary:**
[LeetCode Link](https://leetcode.com/problems/search-a-2d-matrix-ii/)

Given a `m x n` matrix where:

* Each **row** is sorted in ascending order (left → right)
* Each **column** is sorted in ascending order (top → bottom)

Check if a given `target` exists in the matrix.

---

### ❌ **Brute Force Approach:**

Loop through every element:

```java
for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        if (matrix[i][j] == target) return true;
    }
}
```

* **Time Complexity:** O(m × n)
* **Space Complexity:** O(1)

---

### ✅ **Optimized Solution:**

Start from **top-right** corner of the matrix:

```java
int row = 0;
int col = matrix[0].length - 1;
```

Then:

* If `matrix[row][col] == target`: return `true`
* If `matrix[row][col] > target`: move **left** (`col--`)
* Else: move **down** (`row++`)

Repeat until out of bounds.

---

### 🔍 Why this works:

Because:

* Rows are sorted → left move gives smaller
* Columns are sorted → down move gives larger

This lets you **eliminate one row or column in each step**, making the search efficient.

---

### 📌 Code:

```java
public boolean searchMatrix(int[][] matrix, int target) {
    int row = 0;
    int col = matrix[0].length - 1;

    while (row < matrix.length && col >= 0) {
        if (matrix[row][col] == target) return true;
        if (matrix[row][col] > target) col--;
        else row++;
    }
    return false;
}
```

---

### 📒 Notes (TC vs SC):

| Approach          | Time Complexity | Space Complexity | Notes                             |
| ----------------- | --------------- | ---------------- | --------------------------------- |
| Brute Force       | O(m × n)        | O(1)             | Check every cell                  |
| Optimized (Yours) | O(m + n)        | O(1)             | Eliminate row/column step-by-step |

---

## ✅ Problem Statement

Given an array of integers, check whether there exists a **subarray (of at least one element)** whose elements **sum up to 0**.

### 🔸 Example

```cpp
Input:  [4, 2, -3, 1, 6]
Output: true  // because the subarray [2, -3, 1] sums to 0

Input:  [4, 2, 3, 6, 6]
Output: false // no subarray sums to 0
```

---

## 💡 Brute Force Approach

### 🔹 Idea:

Try every possible subarray and check if the sum is 0.

### 🔹 Algorithm:

* Loop over all subarrays using two nested loops.
* Calculate sum of each subarray.
* If any subarray sum is 0, return `true`.

### 🔹 Code:

```cpp
bool checkZeroSumSubarrayBruteForce(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0)
                return true;
        }
    }
    return false;
}
```

### ⏱ Time Complexity: `O(n^2)`

### 📦 Space Complexity: `O(1)`

---

## ✅ Optimized Approach using Prefix Sum and Hash Set

### 🔹 Idea:

Maintain a **running sum (prefix sum)** while iterating through the array.
If at any point:

* the running sum is **0**, or
* the same running sum has appeared **before**,

then a **zero sum subarray exists**.

Why?
Because if two prefix sums are equal, the sum of elements in between is 0.

### 🔹 Algorithm:

1. Initialize a set `sums` and insert `0` in it.
2. Initialize `sum = 0`.
3. Iterate through array:

   * Add current element to `sum`.
   * If `sum` is already in the set, return `true`.
   * Else, insert `sum` into the set.
4. If loop ends, return `false`.

---

### 🔹 Code:

```cpp
#include<bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
bool checkZeroSumSubarray(vector<int> arr) {
    int sum = 0;
    unordered_set<int> sums;
    sums.insert(0);

    for (int num : arr) {
        sum += num;
        if (sums.find(sum) != sums.end()) {
            return true;
        }
        sums.insert(sum);
    }

    return false;
}
```

---

### ⏱ Time Complexity: `O(n)`

* We go through the array once.
* Set operations are `O(1)` on average.

### 📦 Space Complexity: `O(n)`

* In the worst case, we store `n` different prefix sums.

---

## 🧪 Test Cases:

```cpp
cout << checkZeroSumSubarray({4, 2, -3, 1, 6}) << endl; // true
cout << checkZeroSumSubarray({4, 2, 0, 1, 6}) << endl;  // true (0 itself)
cout << checkZeroSumSubarray({4, 2, -3, 1, -4}) << endl; // true
cout << checkZeroSumSubarray({4, -4, 3, 4, 6}) << endl; // true (4, -4)
cout << checkZeroSumSubarray({4, 2, 3, -6, 6}) << endl; // true (2, 3, -6, 6)
cout << checkZeroSumSubarray({4, 2, 3, 6, 6}) << endl;  // false
```

---

## ✅ Summary:

| Approach         | Time Complexity | Space Complexity | Notes                  |
| ---------------- | --------------- | ---------------- | ---------------------- |
| Brute Force      | O(n²)           | O(1)             | Simple, but slow       |
| Prefix Sum + Set | O(n)            | O(n)             | Fast, uses extra space |

---


## ✅ 1. Check if Subarray with Sum = Target is Present

### 🔹 Problem:

Return `true` if **any subarray** has a sum equal to `target`.

### 🔹 Approach:

Use prefix sum and a hash set:

* If `prefixSum - target` has been seen before, subarray exists.

### 🔹 Code:

```cpp
bool hasSubarrayWithSum(vector<int>& arr, int target) {
    unordered_set<int> prefixSums;
    int sum = 0;
    prefixSums.insert(0); // to handle exact match from start

    for (int num : arr) {
        sum += num;
        if (prefixSums.find(sum - target) != prefixSums.end())
            return true;
        prefixSums.insert(sum);
    }
    return false;
}
```

### ⏱ TC: `O(n)`, 📦 SC: `O(n)`

---

## ✅ 2. Find Any Subarray with Sum = 0 (return \[start, end] index)

### 🔹 Problem:

Return the start and end index of **any subarray** with sum = 0.

### 🔹 Approach:

Use prefix sum and unordered map: `sum -> index`
If `prefixSum` repeats, subarray between previous index+1 and current index has sum = 0.

### 🔹 Code:

```cpp
vector<int> findZeroSumSubarray(vector<int>& arr) {
    unordered_map<int, int> prefixSumIndex;
    int sum = 0;
    prefixSumIndex[0] = -1; // base case

    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
        if (prefixSumIndex.find(sum) != prefixSumIndex.end()) {
            return {prefixSumIndex[sum] + 1, i};
        }
        prefixSumIndex[sum] = i;
    }

    return {}; // No subarray found
}
```

### ⏱ TC: `O(n)`, 📦 SC: `O(n)`

---

## ✅ 3. Find Any Subarray with Sum = Target (return \[start, end] index)

### 🔹 Problem:

Return indices `[start, end]` of **any subarray** whose sum is equal to `target`.

### 🔹 Approach:

Same as above, just change `0` to `target`.

### 🔹 Code:

```cpp
vector<int> findSubarrayWithTargetSum(vector<int>& arr, int target) {
    unordered_map<int, int> prefixSumIndex;
    int sum = 0;
    prefixSumIndex[0] = -1;

    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
        if (prefixSumIndex.find(sum - target) != prefixSumIndex.end()) {
            return {prefixSumIndex[sum - target] + 1, i};
        }
        prefixSumIndex[sum] = i;
    }

    return {};
}
```

### ⏱ TC: `O(n)`, 📦 SC: `O(n)`

---

## ✅ 4. Count Number of Subarrays with Sum = Target

### 🔹 Problem:

Return total number of subarrays whose sum equals the `target`.

### 🔹 Approach:

Use a frequency map of prefix sums.

### 🔹 Code:

```cpp
int countSubarraysWithSum(vector<int>& arr, int target) {
    unordered_map<int, int> prefixCount;
    int sum = 0, count = 0;
    prefixCount[0] = 1;

    for (int num : arr) {
        sum += num;
        if (prefixCount.find(sum - target) != prefixCount.end()) {
            count += prefixCount[sum - target];
        }
        prefixCount[sum]++;
    }

    return count;
}
```

### ⏱ TC: `O(n)`, 📦 SC: `O(n)`

---

## 🧪 Example Usage:

```cpp
vector<int> arr = {1, 2, 3, -2, 5};

// 1.
cout << hasSubarrayWithSum(arr, 3) << endl;

// 2.
auto res1 = findZeroSumSubarray(arr);  // could be [1, 3]
if (!res1.empty()) cout << res1[0] << " " << res1[1] << endl;

// 3.
auto res2 = findSubarrayWithTargetSum(arr, 5);  // e.g., [2, 4]
if (!res2.empty()) cout << res2[0] << " " << res2[1] << endl;

// 4.
cout << countSubarraysWithSum(arr, 5) << endl;
```

---

## ✅ Problem: Count Subarrays with Equal Number of 0s and 1s

### 🔹 Statement:

Given a binary array (containing only 0s and 1s), count the number of **subarrays** in which the number of 0s and 1s are **equal**.

### 🔹 Examples:

```cpp
Input:  [1, 0, 0, 1, 0, 1, 1]
Output: 8

Input:  [1, 1, 1, 1]
Output: 0

Input:  [0, 0, 0]
Output: 0

Input:  [0, 1, 1, 1, 1]
Output: 1  // Only subarray [0, 1] has equal 0s and 1s
```

---

## 💡 Brute Force Approach

### 🔹 Idea:

* Use two nested loops to check all subarrays.
* Count number of 0s and 1s in each subarray.
* If counts are equal, increment result.

### 🔹 Code:

```cpp
int countEqual01Brute(vector<int> arr) {
    int count = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        int zero = 0, one = 0;
        for (int j = i; j < n; j++) {
            if (arr[j] == 0) zero++;
            else one++;

            if (zero == one) count++;
        }
    }

    return count;
}
```

### ⏱ Time Complexity: `O(n^2)`

### 📦 Space Complexity: `O(1)`

Slow for large arrays.

---

## ✅ Optimized Approach Using Prefix Sum with Map

### 🔹 Trick:

Transform the problem into **"count subarrays with sum = 0"**, by replacing:

* every `0` with `-1`
* every `1` with `+1`

Then count the number of subarrays whose prefix sum is zero.

### 🔹 Why it works:

* Equal number of 0s and 1s ⇨ their net contribution in transformed array is 0.

### 🔹 Code:

```cpp
long long int countSubarraysWithEqual0sAnd1s(vector<int> arr) {
    long long int res = 0;
    unordered_map<int, long long int> sumFreq;

    int sum = 0;
    sumFreq[0] = 1; // To handle subarrays starting from index 0

    for (int i = 0; i < arr.size(); i++) {
        sum += (arr[i] == 1 ? +1 : -1); // Transform 0 → -1, 1 → +1

        res += sumFreq[sum]; // Add count of previous same prefix sum
        sumFreq[sum]++;      // Update frequency
    }

    return res;
}
```

---

## ✅ Dry Run Example:

```cpp
Input: [1, 0, 0, 1, 0, 1, 1]
Transformed: [1, -1, -1, 1, -1, 1, 1]
Prefix sums: [1, 0, -1, 0, -1, 0, 1]
```

We count how many times each prefix sum has occurred.
Every time a prefix sum repeats, it means the subarray between the previous and current index has sum 0 ⇒ equal 0s and 1s.

---

## 🧠 Time and Space Complexity

| Approach    | Time Complexity | Space Complexity | Notes                 |
| ----------- | --------------- | ---------------- | --------------------- |
| Brute Force | `O(n²)`         | `O(1)`           | Slow for large inputs |
| Optimized   | `O(n)`          | `O(n)`           | Uses prefix sum & map |

---

## ✅ Test Cases:

```cpp
cout << countSubarraysWithEqual0sAnd1s({1, 0, 0, 1, 0, 1, 1}) << endl; // 8
cout << countSubarraysWithEqual0sAnd1s({1, 1, 1, 1}) << endl;          // 0
cout << countSubarraysWithEqual0sAnd1s({0, 0, 0}) << endl;             // 0
cout << countSubarraysWithEqual0sAnd1s({0, 1, 1, 1, 1}) << endl;       // 1
```

---

## ✅ Problem: Longest Substring with All Distinct Characters

### 🔹 Statement:

Given a string `s`, return the **length of the longest substring** that contains **all distinct characters** (i.e., no character repeats).

---

### 🔸 Example:

```cpp
Input:  "geeksforgeeks"
Output: 7    // "eksforg"

Input:  "aaaa"
Output: 1    // Only 'a'

Input:  "geforegkse"
Output: 7    // "eforegk"
```

---

## 💡 Brute Force Approach

### 🔹 Idea:

* Try all substrings.
* For each, check if all characters are unique.
* Keep track of the maximum length found.

### 🔹 Code:

```cpp
int longestDistinctBrute(string s) {
    int n = s.length();
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        unordered_set<char> seen;
        for (int j = i; j < n; j++) {
            if (seen.find(s[j]) != seen.end()) break;
            seen.insert(s[j]);
            maxLen = max(maxLen, j - i + 1);
        }
    }

    return maxLen;
}
```

### ⏱ Time Complexity: `O(n^2)`

### 📦 Space Complexity: `O(n)` (for the set)

---

## ✅ Optimized Approach (Sliding Window + Hash)

### 🔹 Idea:

Use a **sliding window** with two pointers (`left`, `right`) to maintain a window with **all distinct characters**.

* Move `right` and include characters.
* If a duplicate is found, move `left` to exclude the previous occurrence.

### 🔹 Implementation Details:

* Use a `vector<bool>` of size 26 (for lowercase English letters).
* Track current characters in the window.

---

### 🔹 Code:

```cpp
int longestSubstrWithDistinctChars(string s) {
    vector<bool> isPresent(26, false);
    int n = s.length();
    int result = 0;

    int left = 0, right = 0;
    while (right < n) {
        if (!isPresent[s[right] - 'a']) {
            isPresent[s[right] - 'a'] = true;
            result = max(result, right - left + 1);
        } else {
            // Remove characters from left until we remove s[right]
            while (s[left] != s[right]) {
                isPresent[s[left] - 'a'] = false;
                left++;
            }
            left++; // remove s[right] as well
        }
        right++;
    }

    return result;
}
```

---

## ✅ Dry Run Example: `"geeksforgeeks"`

1. Window expands: `g`, `ge`, `gee` → duplicate `e`
2. Move `left` till first `e` is gone.
3. Window becomes: `eks`, `eksf`, `eksfo`, `eksfor`, `eksforg` (max length = 7)

---

## 🧠 Time and Space Complexity

| Approach    | Time Complexity | Space Complexity  | Notes                             |
| ----------- | --------------- | ----------------- | --------------------------------- |
| Brute Force | `O(n^2)`        | `O(n)`            | Simple, but inefficient           |
| Optimized   | `O(n)`          | `O(1)` (26 fixed) | Sliding window for fast execution |

> Use a `vector<bool>(26)` for lowercase letters only. For general characters (like upper/lower/symbols), use `unordered_set<char>`.

---

## 🧪 Test Cases:

```cpp
cout << longestSubstrWithDistinctChars("geeksforgeeks") << endl; // 7
cout << longestSubstrWithDistinctChars("aaaa") << endl;          // 1
cout << longestSubstrWithDistinctChars("geforegkse") << endl;    // 7
```

---
