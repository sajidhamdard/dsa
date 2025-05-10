## Combination sum ii

Below code works fine but it only 20% other Java solutions

```java

class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> set = new ArrayList<>();
        subsetSum(0, candidates, target, new ArrayList<>(), set);
        return set;
    }

    public void subsetSum(int i, int[] candidates, int target, List<Integer> list, List<List<Integer>> all) {
         if (target == 0) {
            all.add(new ArrayList<>(list));
            return;
        }
        for(int j = i; j < candidates.length; j++) {
            if(j > i && candidates[j] == candidates[j-1]) continue;
            if (candidates[j] > target) break;
            list.add(candidates[j]);
            subsetSum(j+1, candidates, target-candidates[j], list, all);
            list.remove(list.size()-1);
        }
    }
} 
```
So I asked ChatGPT for better solution in terms of time complexity and ChatGPT gave me below solution which beats 100% other solutions

```java

class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> result = new ArrayList<>();
        subsetSum(0, candidates, target, new ArrayList<>(), result);
        return result;
    }

    public void subsetSum(int i, int[] candidates, int target, List<Integer> list, List<List<Integer>> all) {
        if (target == 0) {
            all.add(new ArrayList<>(list));
            return;
        }
        
        for (int j = i; j < candidates.length; j++) {
            if (j > i && candidates[j] == candidates[j - 1]) continue; // Skip duplicates
            if (candidates[j] > target) break; // Stop if number is larger than target

            list.add(candidates[j]); // ✅ Correctly adding candidates[j]
            subsetSum(j + 1, candidates, target - candidates[j], list, all);
            list.remove(list.size() - 1); // Backtrack
        }
    }
}
```

Some of the doubts answered below for the above optimized solution.

## **1️⃣ Why Did We Use Sorting for This Problem?**  
Sorting helps in two ways:  
1. **Helps in Skipping Duplicates Efficiently**  
   - Since duplicate numbers will be adjacent after sorting, we can **easily skip them** while iterating.  
   - If we don’t sort, duplicates will be scattered throughout the array, making it **harder to detect and remove them**.  

2. **Improves Efficiency (Pruning the Search Space)**  
   - Once the array is sorted, **larger numbers appear later**.  
   - If the current number is greater than `target`, **we can stop the loop early** (because adding larger numbers will only exceed the target).  

### **Example**  
```java
int[] candidates = {10, 1, 2, 7, 6, 1, 5};
Arrays.sort(candidates);  // After sorting: [1, 1, 2, 5, 6, 7, 10]
```
- Now, all **duplicate 1’s are together** → makes skipping easy.
- If we reach `7` and the target is `6`, we can stop immediately.

---

## **2️⃣ Why Did We Use a For Loop Instead of Pick/Not Pick (Two Calls)?**  
The **pick/not pick** method works for problems where **duplicates are allowed**, like **Combination Sum I**.  
But in **Combination Sum II**, where each number can be used **only once per combination**, this approach causes **TLE** because it **recomputes duplicate combinations**.  

### **Why the For Loop is Better?**  
1. **Avoids duplicate recursive calls**  
   - Instead of making **two calls per element**, the for loop **iterates only once per level** and picks elements directly.
  
2. **Ensures each element is used at most once**  
   - `subsetSum(j + 1, candidates, target - candidates[j], list, all);`  
   - By passing `j + 1`, we **move to the next index** and ensure **no element is picked twice**.

### **Comparison**
| Approach | Explanation |
|----------|------------|
| Pick/Not Pick (TLE) | Calls `subsetSum(i+1, target-candidates[i])` and `subsetSum(i+1, target)`, causing duplicate work. |
| For Loop (Efficient) | Picks each element only once per level, skipping duplicate work. |

---

## **3️⃣ Why Did We Add `if (j > i && candidates[j] == candidates[j - 1]) continue;` (Skipping Duplicates)?**  
This **prevents duplicate combinations** from being generated.  

### **Example (Without Skipping Duplicates)**
```java
int[] candidates = {1, 1, 2};
target = 3;
```
- Without this condition, both `1` values would generate the same combination: `[1, 2]` twice.  
- The check `if (j > i && candidates[j] == candidates[j - 1]) continue;` ensures that:
  - We **only pick the first occurrence** of `1` in a given recursion level.
  - The second `1` is **skipped** to avoid duplicate work.

### **When Does it Work?**
- `j > i`: This ensures that we **only skip duplicates if they occur in the same recursion level**.
- `candidates[j] == candidates[j - 1]`: Ensures we are dealing with a duplicate.

---

## **4️⃣ How is Only One Call Inside the Loop Working Fine? (Instead of Two Calls for Pick/Not Pick)**  
In **Combination Sum I**, we had to explicitly **make two calls**:  
1. **Pick the element** → decrease target → move to next index.  
2. **Not pick the element** → move to next index without decreasing target.

But in **Combination Sum II**, this is handled automatically by the **for loop**:
1. It **iterates through each candidate only once**.
2. If we "pick" an element, we move to the **next index** (`j + 1`).
3. If we "don’t pick", the loop naturally moves to the next index without needing another recursive call.

### **Comparison**
| Approach | Explanation |
|----------|------------|
| Pick/Not Pick (TLE) | Calls recursion twice per element, causing exponential calls. |
| For Loop (Efficient) | Calls recursion only once per picked element, handling not-picking automatically. |

---

## **5️⃣ Why Are We Breaking the Loop for `if (candidates[j] > target) break;`?**  
This **prunes the recursion tree**, improving efficiency.

### **Why?**
1. **The array is sorted** → Larger numbers come later.
2. If `candidates[j] > target`, then **all further numbers will also be greater**.
3. There’s **no point in checking them**, so we **break early** to save time.

### **Example**
```java
int[] candidates = {1, 2, 5, 6, 7};
target = 3;
```
- `candidates[0] = 1` → ✅ Possible.
- `candidates[1] = 2` → ✅ Possible.
- `candidates[2] = 5` → ❌ **STOP!**
  - Since `5 > 3`, all **later elements (6,7) are also too large**.
  - Instead of wasting time checking them, **we break early**.

---

## **🚀 Final Summary**
| Question | Answer |
|----------|--------|
| **Why sorting?** | Makes duplicate skipping easier + allows early stopping (`break`). |
| **Why for loop instead of pick/not pick?** | It prevents duplicate recursive calls and ensures each number is picked only once per level. |
| **Why skip duplicates?** | To prevent generating the same combination multiple times. |
| **Why only one recursive call?** | The for loop naturally handles both "pick" and "not pick" cases. |
| **Why break on `candidates[j] > target`?** | Since the array is sorted, larger numbers are guaranteed to be invalid, so we stop early. |

---
