### **What is DFS (Depth-First Search)?**  
**DFS (Depth-First Search)** is a traversal algorithm used for searching and processing nodes in a **graph or tree** by going **deep first** before backtracking.

---

### **How DFS Works**
1. **Start from a given node** (root in a tree, any node in a graph).  
2. **Visit a child node and keep going deeper** until no unvisited child is left.  
3. **Backtrack and explore other branches**.  
4. **Use a Stack (LIFO) or recursion to keep track of visited nodes**.

---

### **Example: DFS on a Tree**
#### **Tree Structure**
```
         1
       / | \
      2  3  4
     / \
    5   6
```
#### **DFS Traversal Output (Preorder)**
```
1 → 2 → 5 → 6 → 3 → 4
```

#### **Java Code for DFS on a Tree (Using Recursion)**
```java
import java.util.*;

class DFSExample {
    public static void dfsTraversal(Map<Integer, List<Integer>> tree, int node, Set<Integer> visited) {
        if (visited.contains(node)) return;

        System.out.print(node + " "); // Process the node
        visited.add(node);

        for (int child : tree.getOrDefault(node, new ArrayList<>())) {
            dfsTraversal(tree, child, visited); // Recur for child nodes
        }
    }

    public static void main(String[] args) {
        Map<Integer, List<Integer>> tree = new HashMap<>();
        tree.put(1, Arrays.asList(2, 3, 4));
        tree.put(2, Arrays.asList(5, 6));

        System.out.print("DFS Traversal: ");
        dfsTraversal(tree, 1, new HashSet<>()); // Start DFS from node 1
    }
}
```
**Output:**
```
DFS Traversal: 1 2 5 6 3 4
```

---

### **DFS on a Graph**
Graphs may have **cycles**, so we must track visited nodes.

#### **Graph Example**
```
    1 -- 2
    |    |
    3 -- 4
```
#### **DFS Traversal Output (Starting from 1)**
```
1 → 2 → 4 → 3
```

#### **Java Code for DFS on a Graph (Using Stack)**
```java
import java.util.*;

class DFSGraph {
    public static void dfsGraph(Map<Integer, List<Integer>> graph, int start) {
        Stack<Integer> stack = new Stack<>();
        Set<Integer> visited = new HashSet<>();

        stack.push(start);

        while (!stack.isEmpty()) {
            int node = stack.pop();

            if (!visited.contains(node)) {
                System.out.print(node + " ");
                visited.add(node);
            }

            for (int neighbor : graph.getOrDefault(node, new ArrayList<>())) {
                if (!visited.contains(neighbor)) {
                    stack.push(neighbor);
                }
            }
        }
    }

    public static void main(String[] args) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        graph.put(1, Arrays.asList(2, 3));
        graph.put(2, Arrays.asList(1, 4));
        graph.put(3, Arrays.asList(1, 4));
        graph.put(4, Arrays.asList(2, 3));

        System.out.print("DFS Traversal: ");
        dfsGraph(graph, 1); // Start DFS from node 1
    }
}
```
**Output:**
```
DFS Traversal: 1 3 4 2
```

---

### **DFS Variations**
1. **Preorder (Node → Left → Right)**  
   - Example: **1 → 2 → 5 → 6 → 3 → 4**
2. **Inorder (Left → Node → Right) [For Binary Trees]**  
   - Example: **5 → 2 → 6 → 1 → 3 → 4**
3. **Postorder (Left → Right → Node)**  
   - Example: **5 → 6 → 2 → 3 → 4 → 1**

---

### **Simple DFS Questions to Try**
1. **Find the depth (height) of a tree using DFS.**  
2. **Detect a cycle in an undirected graph using DFS.**  
3. **Find all paths between two nodes in a graph.**  
4. **Find the number of connected components in a graph.**  
5. **Solve a maze using DFS (Backtracking).**  
