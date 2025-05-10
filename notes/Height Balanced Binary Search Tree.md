A **height-balanced Binary Search Tree (BST)** is a **binary tree** where the height difference (balance factor) between the left and right subtrees of any node is at most **1**.

### **Key Properties:**

1. **BST Property:**
   - Left subtree nodes < Root < Right subtree nodes.
2. **Balanced Property:**
   - For every node, the height difference between the left and right subtrees is **at most 1**:
     \[
     | \text{height(left)} - \text{height(right)} | \leq 1
     \]

### **Example of a Height-Balanced BST**

```
        4
       / \
      2   6
     / \  / \
    1   3 5  7
```

- Each subtree has a height difference of at most `1`, so it is **balanced**.

### **Unbalanced BST Example**

```
      10
     /
    5
   /
  3
 /
1
```

- The left subtree is much deeper than the right, so it is **not height-balanced**.

### **Common Height-Balanced Trees**

1. **AVL Tree** → Strictly height-balanced.
2. **Red-Black Tree** → Loosely balanced.

Would you like an implementation of a height-balanced BST? 🚀
