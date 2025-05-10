### **What is Inorder Traversal?**
**Inorder traversal** is a **depth-first** traversal method for binary trees, where nodes are visited in the following order:

1. **Left Subtree**
2. **Root Node**
3. **Right Subtree**

---

### **Inorder Traversal Algorithm**
1. Recursively **traverse the left subtree**.
2. **Visit the root** node.
3. Recursively **traverse the right subtree**.

If done on a **Binary Search Tree (BST)**, **inorder traversal** visits nodes in **sorted order**.

---

### **Example Binary Tree**
```
        1
       / \
      2   3
     / \
    4   5
```
#### **Inorder Traversal Output**:
```
4 2 5 1 3
```

---

### **Java Implementation (Recursive)**
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

    // Inorder Traversal (Left -> Root -> Right)
    void inorder(Node node) {
        if (node == null)
            return;
        
        inorder(node.left);  // Visit left subtree
        System.out.print(node.data + " ");  // Visit root
        inorder(node.right); // Visit right subtree
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);

        System.out.println("Inorder Traversal:");
        tree.inorder(tree.root);
    }
}
```
#### **Output:**
```
4 2 5 1 3
```

---

### **Java Implementation (Iterative using Stack)**
If recursion is not allowed, we can use a **stack** for an **iterative** approach.

```java
import java.util.Stack;

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

    // Iterative Inorder Traversal using Stack
    void inorderIterative(Node node) {
        Stack<Node> stack = new Stack<>();
        Node current = node;

        while (current != null || !stack.isEmpty()) {
            // Reach the leftmost node
            while (current != null) {
                stack.push(current);
                current = current.left;
            }

            // Process the node
            current = stack.pop();
            System.out.print(current.data + " ");

            // Move to the right subtree
            current = current.right;
        }
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);

        System.out.println("Inorder Traversal (Iterative):");
        tree.inorderIterative(tree.root);
    }
}
```
#### **Output:**
```
4 2 5 1 3
```

---

### **Time & Space Complexity**
| Approach   | Time Complexity | Space Complexity |
|------------|---------------|----------------|
| Recursive  | **O(n)**       | **O(h)** (Recursive Stack) |
| Iterative  | **O(n)**       | **O(h)** (Stack) |

- **n** = number of nodes  
- **h** = height of the tree (O(log n) for balanced trees, O(n) for skewed trees)

---

### **Where is Inorder Traversal Used?**
✅ **Binary Search Trees (BSTs)** → Retrieves elements in sorted order.  
✅ **Expression Trees** → Converts an expression tree into infix notation.  
✅ **Tree-Based Sorting** → Used in tree-sort algorithms.  


### **Flow of Inorder Traversal (`Left → Root → Right`)**
The function `inorder(Node node)` is a **recursive function** that follows **Depth-First Search (DFS)** in **inorder order** (Left → Root → Right).

---

## **Example Binary Tree**
Let's take the following **binary tree** as an example:

```
        1
       / \
      2   3
     / \
    4   5
```

**Expected Output (Inorder Traversal):**
```
4 2 5 1 3
```

---

## **Step-by-Step Flow**
Let's analyze how the function executes **recursively**.

### **Step 1: Call `inorder(root)`**
- `root = 1`
- First, it **calls** `inorder(node.left)`, which is `inorder(2)`

---

### **Step 2: Call `inorder(2)`**
- `node = 2`
- Calls `inorder(node.left)`, which is `inorder(4)`

---

### **Step 3: Call `inorder(4)`**
- `node = 4`
- Calls `inorder(node.left)`, which is `inorder(null)`
  - `node == null`, so **returns**
- Prints **4**
- Calls `inorder(node.right)`, which is `inorder(null)`
  - `node == null`, so **returns**
- **Returns to `inorder(2)`**

---

### **Step 4: Back to `inorder(2)`**
- **Prints 2**
- Calls `inorder(node.right)`, which is `inorder(5)`

---

### **Step 5: Call `inorder(5)`**
- `node = 5`
- Calls `inorder(node.left)`, which is `inorder(null)`
  - `node == null`, so **returns**
- Prints **5**
- Calls `inorder(node.right)`, which is `inorder(null)`
  - `node == null`, so **returns**
- **Returns to `inorder(1)`**

---

### **Step 6: Back to `inorder(1)`**
- **Prints 1**
- Calls `inorder(node.right)`, which is `inorder(3)`

---

### **Step 7: Call `inorder(3)`**
- `node = 3`
- Calls `inorder(node.left)`, which is `inorder(null)`
  - `node == null`, so **returns**
- Prints **3**
- Calls `inorder(node.right)`, which is `inorder(null)`
  - `node == null`, so **returns**
- **Returns to `main` (Traversal complete!)**

---

## **Final Output**
```
4 2 5 1 3
```

---

## **Call Stack Representation**
```
inorder(1)
  inorder(2)
    inorder(4)
      inorder(null) -> return
      print(4)
      inorder(null) -> return
    return
    print(2)
    inorder(5)
      inorder(null) -> return
      print(5)
      inorder(null) -> return
    return
  return
  print(1)
  inorder(3)
    inorder(null) -> return
    print(3)
    inorder(null) -> return
  return
return
```

---

## **Summary of Execution**
| Step | Function Call | Action |
|------|-------------|---------|
| 1 | `inorder(1)` | Calls `inorder(2)` |
| 2 | `inorder(2)` | Calls `inorder(4)` |
| 3 | `inorder(4)` | Calls `inorder(null)`, prints `4`, calls `inorder(null)`, returns |
| 4 | Back to `inorder(2)` | Prints `2`, calls `inorder(5)` |
| 5 | `inorder(5)` | Calls `inorder(null)`, prints `5`, calls `inorder(null)`, returns |
| 6 | Back to `inorder(1)` | Prints `1`, calls `inorder(3)` |
| 7 | `inorder(3)` | Calls `inorder(null)`, prints `3`, calls `inorder(null)`, returns |
| 8 | Back to `inorder(1)` | All calls finished, traversal complete |

---

## **Key Takeaways**
✅ **Recursive function follows DFS traversal**.  
✅ **Left → Root → Right order ensures sorted output in BST**.  
✅ **Uses call stack for recursive depth-first execution**.  
✅ **Time Complexity:** \(O(n)\) (visits each node once).  
✅ **Space Complexity:** \(O(h)\) (where \(h\) is the tree height, \(O(\log n)\) for balanced trees, \(O(n)\) for skewed trees).  
