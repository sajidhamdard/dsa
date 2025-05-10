### **📌 Problem: Path Sum**  
🔗 **LeetCode Link:** [Path Sum - LeetCode](https://leetcode.com/problems/path-sum/)  

#### **🔹 My Initial Approach: (18% Beats)**
- Used **DFS with backtracking**.  
- Stored the path in a **list** and recalculated sum at every leaf node.  
- **Issue:** Extra space for list + repeated summation (`O(N)` sum calculation per path).  
- **Time Complexity:** `O(N²)` (worst case).  
- **Space Complexity:** `O(N)` (due to list storage).  

##### **🚀 Code I Initially Wrote:**
```java
class Solution {
    public boolean hasPathSum(TreeNode root, int targetSum) {
        return dfs(root, targetSum, new ArrayList<>());
    }

    public boolean dfs(TreeNode root, int targetSum, List<Integer> list) {
        if (root == null) return false;
        list.add(root.val);
        if (root.left == null && root.right == null && sum(list) == targetSum) {
            return true;
        } else {
            if (dfs(root.left, targetSum, list) || dfs(root.right, targetSum, list)) return true;
            list.remove(list.size() - 1);
        }
        return false;
    }

    public int sum(List<Integer> list) {
        int sum = 0;
        for (Integer n : list) sum += n;
        return sum;
    }
}
```
---

#### **🔹 Optimized Approach: (Better Performance 🚀)**
- Used **DFS with direct sum tracking** instead of storing paths.  
- **Key Insight:** Instead of storing the path, just track the **remaining targetSum** at each step.  
- **Time Complexity:** `O(N)`, since each node is visited once.  
- **Space Complexity:** `O(H)`, where `H` is the height of the tree (better than `O(N)`).  

##### **✅ Optimized Code (Beats 100% Submissions 🚀)**
```java
class Solution {
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null) return false;
        targetSum -= root.val;
        if (root.left == null && root.right == null) return targetSum == 0;
        return hasPathSum(root.left, targetSum) || hasPathSum(root.right, targetSum);
    }
}
```
---

### **📌 Key Takeaways & Learning**
✅ **Use direct sum tracking** instead of maintaining an extra list.  
✅ **Backtracking removal isn’t needed** if we just track `targetSum`.  
✅ **Avoid unnecessary calculations** (like summing lists).  
✅ **Always analyze space complexity** when using recursion.  

---

Here’s how you can structure your **Excel notes** for this problem.  

---

### **📌 Excel Format for Notes**  

| **Problem**     | **Path Sum** (LeetCode #112) |
|----------------|-----------------------------|
| **Approach 1 (Initial Solution - 18%)** | Used DFS with backtracking, stored path in a list, recalculated sum at each leaf. |
| **Issues with Approach 1** | Extra space for list, repeated sum computation (`O(N²)` complexity). |
| **Approach 2 (Optimized Solution 🚀)** | Used direct `targetSum` tracking instead of storing paths. Eliminated extra space usage. |
| **Time Complexity (Before & After)** | `O(N²)` → `O(N)` |
| **Space Complexity (Before & After)** | `O(N)` → `O(H)` (only recursion stack) |
| **Key Learning** | Use `targetSum` instead of storing paths. Stop early when condition met. Avoid unnecessary summation. |
| **Optimized Code** | ✅ Included (See below) |
| **Dry Run (for `[5,4,8,11,null,13,4,7,2,null,null,null,1]` with `targetSum = 22`)** | ✅ Included (See below) |

---

### **📌 Dry Run Notes (To Include in Excel)**  

#### **Tree Representation**
```
        5
       / \
      4   8
     /   / \
    11  13  4
   /  \      \
  7    2      1
```

| **Step** | **Node** | **Remaining targetSum** | **Action** |
|----------|---------|-----------------|-----------|
| Start | `5` | `22 - 5 = 17` | Recur on left (`4`) |
| Step 2 | `4` | `17 - 4 = 13` | Recur on left (`11`) |
| Step 3 | `11` | `13 - 11 = 2` | Recur on left (`7`), then right (`2`) |
| Step 4 | `7` | `2 - 7 = -5` | Not a valid path (Backtrack) |
| Step 5 | `2` | `2 - 2 = 0` ✅ | Path Found: `[5, 4, 11, 2]` |

Final **Output:** `true`

---
