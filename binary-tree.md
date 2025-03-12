### **What is a Binary Tree?**
A **binary tree** is a hierarchical data structure in which each node has at most **two children**:
1. **Left Child**
2. **Right Child**

Each node contains:
- **Data (Value)**
- **Reference to the left child**
- **Reference to the right child**

---

### **Types of Binary Trees**
1. **Full Binary Tree** → Every node has **0 or 2 children**.
2. **Perfect Binary Tree** → A full tree where **all leaf nodes** are at the same level.
3. **Complete Binary Tree** → All levels are **completely filled**, except possibly the last level (filled from left to right).
4. **Balanced Binary Tree** → The difference between heights of left and right subtrees is at most **1**.
5. **Degenerate (Skewed) Tree** → Each parent has **only one child** (like a linked list).

---

### **Basic Structure of a Binary Tree in Java**
```java
class Node {
    int data;
    Node left, right;

    public Node(int value) {
        data = value;
        left = right = null;
    }
}

public class BinaryTree {
    Node root;

    public BinaryTree() {
        root = null;
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);

        System.out.println("Binary tree created.");
    }
}
```

---

### **Example Binary Tree**
```
        1
       / \
      2   3
     / \
    4   5
```

---

### **Common Operations**
1. **Traversal**
   - **Inorder (Left → Root → Right)** → `4 2 5 1 3`
   - **Preorder (Root → Left → Right)** → `1 2 4 5 3`
   - **Postorder (Left → Right → Root)** → `4 5 2 3 1`
   - **Level-order (BFS using Queue)** → `1 2 3 4 5`
   
2. **Insertion**
3. **Deletion**
4. **Height Calculation**
5. **Searching (DFS, BFS)**

---

### **When to Use a Binary Tree?**
✅ **Efficient Searching & Sorting** (Binary Search Tree - BST)  
✅ **Hierarchical Data Representation** (File systems, Organization charts)  
✅ **Fast Lookup in BST** (Balanced BST gives \(O(\log n)\) complexity)  
✅ **Expression Evaluation** (Arithmetic expressions, Expression trees)
