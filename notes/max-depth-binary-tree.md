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
