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
