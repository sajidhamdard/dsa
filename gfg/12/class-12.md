## 🌳 Tree - Quick Summary

### 🔹 What is a Tree?

A **Tree** is a non-linear data structure where:

* Each node stores some data.
* Nodes are connected using **pointers** (references in Java).
* The connection forms a **hierarchy** (parent → children).

---

### 🔸 What is a Binary Tree?

A **Binary Tree** is a tree where **each node can have at most two children** — commonly called:

* `left`
* `right`

---

## 🔑 Key Terms:

| Term          | Meaning                                                                  |
| ------------- | ------------------------------------------------------------------------ |
| **Root**      | First node in the tree. Everything grows from here. (e.g. node 1)        |
| **Edge**      | Connection between two nodes (like 1 → 2 or 3 → 6)                       |
| **Siblings**  | Nodes with the same parent (like 4 and 5 are children of 2)              |
| **Leaf Node** | Node with no children (e.g. 8, 9, 10...)                                 |
| **Height**    | Max number of levels from root to deepest leaf. In the image, height = 4 |

---

## 🧱 How Tree is Represented in Code?

### ✅ Java / C++ Class Representation (Binary Tree):

Just like a LinkedList has:

```java
class Node {
    int val;
    Node next;
}
```

A Binary Tree node has:

```java
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
}
```

* Each node stores data (`val`)
* It has **pointers to its two children** (`left` and `right`)

---

### 🔁 LinkedList vs Tree

| Concept       | LinkedList                    | Binary Tree                      |
| ------------- | ----------------------------- | -------------------------------- |
| Pointer Names | `next` (and maybe `prev`)     | `left`, `right`                  |
| Shape         | Linear (like a chain)         | Hierarchical (like a tree)       |
| Traversal     | Straightforward (start → end) | Many ways (preorder, inorder...) |

---

## ✅ 1. **Tree Traversals** (Visiting nodes)

There are 3 main **depth-first** traversals:

### 🔹 A. **Inorder** (Left → Root → Right)

```text
Traverse left → visit current → traverse right
```

* For BST, **Inorder gives sorted output**.
* Example for tree:
  Inorder: `8 4 9 2 10 5 11 1 13 6 3 14 7`

---

### 🔹 B. **Preorder** (Root → Left → Right)

```text
Visit current → traverse left → traverse right
```

* Used to **copy a tree**.
* Example: `1 2 4 8 9 5 10 11 3 6 13 7 14`

---

### 🔹 C. **Postorder** (Left → Right → Root)

```text
Traverse left → traverse right → visit current
```

* Used to **delete tree** safely.
* Example: `8 9 4 10 11 5 2 13 6 14 7 3 1`

---

## ✅ 2. **Level Order Traversal** (Breadth-first)

* Use a **Queue**
* Visit nodes **level by level**
* Example: `1 2 3 4 5 6 7 8 9 10 11 13 14`

---

## ✅ 3. **Types of Binary Trees**

### 🔸 A. **Full Binary Tree**

* Every node has **0 or 2 children**.
* No node has exactly 1 child.

### 🔸 B. **Complete Binary Tree**

* All levels completely filled except the **last**, and the last level has nodes **as far left as possible**.

### 🔸 C. **Perfect Binary Tree**

* All **internal nodes have 2 children**, and all **leaf nodes are at the same level**.
* Very symmetric.

| Type     | Condition                                                 |
| -------- | --------------------------------------------------------- |
| Full     | Each node has 0 or 2 children                             |
| Complete | All levels filled; last level filled **left to right**    |
| Perfect  | All levels fully filled; leaf nodes at the **same level** |

---

## ✅ 4. **How to Build Tree from an Array (Level Order)**

Example: array = `[1, 2, 3, 4, 5]`

Using level order (breadth-first), we build the tree like:

```text
        1
      /   \
     2     3
    / \
   4   5
```

### Java Code:

```java
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}

public TreeNode buildTreeFromArray(Integer[] arr) {
    if (arr.length == 0 || arr[0] == null) return null;

    TreeNode root = new TreeNode(arr[0]);
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);
    int i = 1;

    while (!q.isEmpty() && i < arr.length) {
        TreeNode curr = q.poll();

        if (i < arr.length && arr[i] != null) {
            curr.left = new TreeNode(arr[i]);
            q.offer(curr.left);
        }
        i++;

        if (i < arr.length && arr[i] != null) {
            curr.right = new TreeNode(arr[i]);
            q.offer(curr.right);
        }
        i++;
    }

    return root;
}
```

---

## ✅ Summary Diagram

| Concept       | Example                               |
| ------------- | ------------------------------------- |
| Inorder       | Left → Root → Right                   |
| Preorder      | Root → Left → Right                   |
| Postorder     | Left → Right → Root                   |
| Level Order   | BFS using Queue                       |
| Full Tree     | 0 or 2 children only                  |
| Complete Tree | Filled level-wise (left to right)     |
| Perfect Tree  | All nodes full, all leaves same level |

---

If a tree node can have **more than 2 children**, it is no longer a **binary tree**, but instead a **generic tree** (or **N-ary tree**).

## ✅ How to Represent a Node with More Than 2 Children?

In a **binary tree**, we use:

```java
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
}
```

But for a **general tree** (each node can have `n` children), use a **list** to store children:

### 🔸 Java Representation for Generic Tree (N-ary Tree):

```java
import java.util.*;

class TreeNode {
    int val;
    List<TreeNode> children;

    TreeNode(int val) {
        this.val = val;
        this.children = new ArrayList<>();
    }
}
```

Here, each node:

* Stores an `int` value.
* Has a list of child nodes (`children`) — not limited to 2.

---

## 🔍 Example: Build This Tree

```
        1
      / | \
     2  3  4
       / \
      5   6
```

### Java Code to Build This Tree:

```java
TreeNode root = new TreeNode(1);

TreeNode node2 = new TreeNode(2);
TreeNode node3 = new TreeNode(3);
TreeNode node4 = new TreeNode(4);
TreeNode node5 = new TreeNode(5);
TreeNode node6 = new TreeNode(6);

root.children.add(node2);
root.children.add(node3);
root.children.add(node4);

node3.children.add(node5);
node3.children.add(node6);
```

---

## ✅ When to Use Which?

| Structure   | Use When...                              |
| ----------- | ---------------------------------------- |
| Binary Tree | Each node has **at most 2 children**     |
| N-ary Tree  | A node can have **more than 2 children** |
| Trie Tree   | Specialized n-ary tree for strings/words |

---

```java
public class TreeTraversal {

    static class TreeNode {
        int val;
        TreeNode left, right;

        TreeNode(int val) {
            this.val = val;
        }
    }

    // Traversals
    void preorder(TreeNode root) {
        if (root == null) return;
        System.out.print(root.val + " ");
        preorder(root.left);
        preorder(root.right);
    }

    void inorder(TreeNode root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.val + " ");
        inorder(root.right);
    }

    void postorder(TreeNode root) {
        if (root == null) return;
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.val + " ");
    }

    public static void main(String[] args) {
        TreeTraversal t = new TreeTraversal();

        // Building the tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        System.out.print("Preorder: ");
        t.preorder(root); // 1 2 4 5 3
        System.out.println();

        System.out.print("Inorder: ");
        t.inorder(root); // 4 2 5 1 3
        System.out.println();

        System.out.print("Postorder: ");
        t.postorder(root); // 4 5 2 3 1
        System.out.println();
    }
}
```


Here's a clean Java implementation of **Level Order Traversal** (Breadth-First Search) for a binary tree using a **queue**:

## ✅ Level Order Traversal in Java (BFS)

### 🔹 Example Tree:

```
        1
       / \
      2   3
     / \   \
    4   5   6
```

### 🔹 Output:

```
1 2 3 4 5 6
```

---

## ✅ Java Code

```java
import java.util.*;

public class LevelOrderTraversal {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) {
            this.val = val;
        }
    }

    public static void levelOrder(TreeNode root) {
        if (root == null) return;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            TreeNode curr = queue.poll();
            System.out.print(curr.val + " ");

            if (curr.left != null) {
                queue.offer(curr.left);
            }
            if (curr.right != null) {
                queue.offer(curr.right);
            }
        }
    }

    public static void main(String[] args) {
        // Build the tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.right = new TreeNode(6);

        // Print level order
        System.out.print("Level Order Traversal: ");
        levelOrder(root);
    }
}
```

---

## ✅ Time & Space Complexity

| Metric           | Value |
| ---------------- | ----- |
| Time Complexity  | O(n)  |
| Space Complexity | O(n)  |

> where `n` is the number of nodes in the tree

---

### ✅ Level Order Traversal — Auxiliary Space (Space Complexity)

Level Order Traversal uses a **Queue** (BFS approach), so its **auxiliary space** depends on:

---

## 🔹 Space Complexity = O(w)

Where:

* `w` = **maximum width** of the binary tree
* That is, **maximum number of nodes at any level**

---

## 🔍 Why?

During traversal:

* At each level, we enqueue all the children of the current level.
* So, at most, the queue will hold **all nodes of the widest level**.

---

## 🧠 Realistic Examples:

### 1. **Perfect Binary Tree**

* A perfect binary tree with `n` nodes has:

  * Height `h = log₂(n + 1)`
  * Max width = `n / 2` (last level)

➡️ So **auxiliary space = O(n)** in worst case.

---

### 2. **Skewed Tree (e.g., all nodes on one side)**

```
    1
     \
      2
       \
        3
```

* Max width = 1
* Queue holds 1 node at any point
  ➡️ So **aux space = O(1)**

---

### ✅ Summary

| Tree Type      | Max Queue Size       | Aux Space |
| -------------- | -------------------- | --------- |
| Perfect Binary | Half of nodes (≈n/2) | O(n)      |
| Skewed Tree    | 1                    | O(1)      |
| General Tree   | Max width (w)        | O(w)      |

---


## ✅ What is “Level-by-Level Order Traversal”?

It means printing **each level of the binary tree on a separate line**.

### 🔹 Example Tree:

```
        1
       / \
      2   3
     / \   \
    4   5   6
```

### 🔹 Output (Level-by-Level):

```
1
2 3
4 5 6
```

---

## ✅ Java Code Using Queue + Level Size

```java
import java.util.*;

public class LevelOrderByLevel {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    public static void levelOrderByLevel(TreeNode root) {
        if (root == null) return;

        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while (!q.isEmpty()) {
            int levelSize = q.size(); // Number of nodes at current level

            // Traverse the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode curr = q.poll();
                System.out.print(curr.val + " ");

                if (curr.left != null) q.offer(curr.left);
                if (curr.right != null) q.offer(curr.right);
            }
            System.out.println(); // Newline after each level
        }
    }

    public static void main(String[] args) {
        // Sample tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.right = new TreeNode(6);

        levelOrderByLevel(root);
    }
}
```

---

## 🧠 How It Works (Dry Run):

* Start with root → `queue = [1]`
* While queue is not empty:

  * `levelSize = queue.size()` → how many nodes to process now
  * Process `levelSize` nodes → print them and enqueue their children
  * After that level, `System.out.println()` starts the next level on a new line

---

## ✅ Time & Space Complexity

| Metric                                                   | Value |
| -------------------------------------------------------- | ----- |
| Time                                                     | O(n)  |
| Space (Queue)                                            | O(w)  |
| Where `n` = total nodes, and `w` = max width of the tree |       |

---
