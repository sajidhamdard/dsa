## **Maximum Depth of Binary Tree** (LeetCode #104) using **3 approaches** in Java:

**Problem Statement:**
Given the root of a binary tree, return its maximum depth.
*A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.*

---

### Binary Tree Node Definition (Common for all)

```java
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int val) { this.val = val; }
}
```

---

## 1️⃣ DFS (Recursive)

This is the **standard recursive solution** — we go down to leaves and return `max(leftDepth, rightDepth) + 1`.

### Code:

```java
public int maxDepth(TreeNode root) {
    if (root == null) return 0;
    int leftDepth = maxDepth(root.left);
    int rightDepth = maxDepth(root.right);
    return Math.max(leftDepth, rightDepth) + 1;
}
```

### Time Complexity:

**O(n)** → We visit each node exactly once.

### Space Complexity:

**O(h)** → Height of recursion stack (worst case O(n) if skewed, O(log n) if balanced).

---

## 2️⃣ BFS (Level Order Traversal)

We use a **queue** to traverse level by level and count how many levels we have.

### Code:

```java
import java.util.*;

public int maxDepth(TreeNode root) {
    if (root == null) return 0;
    Queue<TreeNode> queue = new LinkedList<>();
    queue.offer(root);
    int depth = 0;
    
    while (!queue.isEmpty()) {
        int size = queue.size(); // Number of nodes at current level
        for (int i = 0; i < size; i++) {
            TreeNode node = queue.poll();
            if (node.left != null) queue.offer(node.left);
            if (node.right != null) queue.offer(node.right);
        }
        depth++; // After finishing one level, increase depth
    }
    
    return depth;
}
```

### Time Complexity:

**O(n)** → We visit each node once.

### Space Complexity:

**O(n)** → Queue holds up to O(n) nodes at the widest level (worst case).

---

## 3️⃣ Iterative DFS (Using Stack)

We simulate DFS manually with a **stack**. To also track depth, we push `(node, current depth)` pairs.

### Code:

```java
import java.util.*;

public int maxDepth(TreeNode root) {
    if (root == null) return 0;
    
    Stack<Pair<TreeNode, Integer>> stack = new Stack<>();
    stack.push(new Pair<>(root, 1));
    int maxDepth = 0;
    
    while (!stack.isEmpty()) {
        Pair<TreeNode, Integer> current = stack.pop();
        TreeNode node = current.getKey();
        int depth = current.getValue();
        if (node != null) {
            maxDepth = Math.max(maxDepth, depth);
            stack.push(new Pair<>(node.left, depth + 1));
            stack.push(new Pair<>(node.right, depth + 1));
        }
    }
    
    return maxDepth;
}
```

> ⚠️ **Note:** If you're not familiar with `Pair`, you can create your own class or use arrays like `stack.push(new Object[]{node, depth})`.
> But `Pair` from `javafx.util.Pair` or `Map.Entry` (or custom class) is clean.

### Time Complexity:

**O(n)** → Visit each node once.

### Space Complexity:

**O(n)** → Stack holds O(n) nodes in the worst case.

---

## Summary Table

| Method                | Time Complexity | Space Complexity |
| --------------------- | --------------- | ---------------- |
| DFS (Recursive)       | O(n)            | O(h)             |
| BFS (Queue)           | O(n)            | O(n)             |
| Iterative DFS (Stack) | O(n)            | O(n)             |

---

> **BFS (queue)** and **Iterative DFS (stack)** look **structurally similar** — both explicitly manage a data structure to track nodes.
> Both process nodes level-by-level or depth-by-depth **explicitly**, unlike recursion where the call stack is implicit.

|                    | BFS            | Iterative DFS |
| ------------------ | -------------- | ------------- |
| Data structure     | Queue (FIFO)   | Stack (LIFO)  |
| Traversal style    | Level by level | Deep first    |
| Ordering           | Wide first     | Deep first    |
| Max Depth problem? | Yes            | Yes           |

For **maximum depth problem**, both work fine — no need to "force" Iterative DFS if you already have DFS recursion or BFS working.

---

## 💡 **So why learn Iterative DFS at all?**

> It’s not just for *this* problem — it’s a **general-purpose tool** that becomes critical when recursion is problematic.

### 1️⃣ **When recursion can cause stack overflow (too deep recursion)**

* Java has **limited call stack size** (\~1000-5000 frames usually).
* In **very deep trees** (or graphs), **recursion fails**, but Iterative DFS (with explicit stack) works.

```java
// Example: Tree with height = 100000 (skewed)
TreeNode root = new TreeNode(1);
TreeNode curr = root;
for (int i = 2; i <= 100000; i++) {
    curr.right = new TreeNode(i);
    curr = curr.right;
}

// Recursive DFS → StackOverflowError ❌
// Iterative DFS → Works fine ✅
```

---

### 2️⃣ **When problem constraints force you to control traversal order explicitly**

* Some problems require **postorder**, **preorder**, or **custom traversal order**.
* Iterative DFS lets you **customize traversal** more flexibly than recursion sometimes (e.g., reverse postorder).

Examples:

* Serialize/deserialize tree
* Topological sort (graph)
* Detect cycles in graph

---

### 3️⃣ **When interviewers explicitly ask for “do it without recursion”**

* Many interviewers ask this **to test your understanding of call stack**.
  If you say "I’ll use recursion" → they ask: "Now show me the iterative version."
  So being ready avoids getting stuck.

---

### 4️⃣ **When environment does not support recursion well (embedded, limited stack)**

E.g., in **competitive programming**, **embedded systems**, or **low-memory environments**, recursion is risky.

---

## ⚖️ **Summary:**

|                             | Recursive DFS | BFS (queue) | Iterative DFS (stack)            |
| --------------------------- | ------------- | ----------- | -------------------------------- |
| Easy to write?              | ✅             | ✅           | ❌ (slightly more code)           |
| Risk of stack overflow?     | ❌ (yes)       | ✅           | ✅                                |
| Explicit traversal control? | ❌ (harder)    | ✅           | ✅                                |
| Handles deep trees safely?  | ❌             | ✅           | ✅                                |
| Interview readiness?        | ✅             | ✅           | ✅✅✅ (shows deeper understanding) |

---

## 🚀 **Final Advice (practical)**

* For **simple problems** (max depth, path sum, etc.):
  ✅ Use recursive DFS or BFS

* For **interview prep & advanced problems**:
  ✅ Learn Iterative DFS
  (it’s like having an extra tool in your toolbox)

* You don’t need to **always use** Iterative DFS
  But you should be **comfortable** switching to it when recursion fails or interviewer asks.
