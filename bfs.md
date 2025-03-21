### **What is BFS (Breadth-First Search)?**  
**BFS (Breadth-First Search)** is a traversal algorithm used for searching and processing nodes in a **graph or tree** level by level.

---

### **How BFS Works**
1. **Start from a given node** (root in a tree, any node in a graph).  
2. **Visit all its direct neighbors first** before going deeper.  
3. **Use a Queue (FIFO) to keep track of visited nodes.**  
4. **Process nodes level by level** (first all nodes at depth 1, then depth 2, etc.).

---

### **Example: BFS on a Tree**
#### **Tree Structure**
```
         1
       / | \
      2  3  4
     / \
    5   6
```
#### **BFS Traversal Output**
```
1 → 2 → 3 → 4 → 5 → 6
```

#### **Java Code for BFS on a Tree**
```java
import java.util.*;

class BFSExample {
    public static void bfsTraversal(Map<Integer, List<Integer>> tree, int start) {
        Queue<Integer> queue = new LinkedList<>();
        Set<Integer> visited = new HashSet<>();

        queue.add(start); // Start from root node
        visited.add(start);

        while (!queue.isEmpty()) {
            int node = queue.poll(); // Remove and process the front node
            System.out.print(node + " "); // Print the node

            // Add all unvisited children to the queue
            for (int child : tree.getOrDefault(node, new ArrayList<>())) {
                if (!visited.contains(child)) {
                    queue.add(child);
                    visited.add(child);
                }
            }
        }
    }

    public static void main(String[] args) {
        // Creating the tree
        Map<Integer, List<Integer>> tree = new HashMap<>();
        tree.put(1, Arrays.asList(2, 3, 4));
        tree.put(2, Arrays.asList(5, 6));

        System.out.print("BFS Traversal: ");
        bfsTraversal(tree, 1); // Start BFS from node 1
    }
}
```
**Output:**
```
BFS Traversal: 1 2 3 4 5 6
```

---

### **BFS on a Graph**
Graphs may have **cycles**, so we must track visited nodes.

#### **Graph Example**
```
    1 -- 2
    |    |
    3 -- 4
```
#### **BFS Traversal Output (Starting from 1)**
```
1 → 2 → 3 → 4
```

#### **Java Code for BFS on a Graph**
```java
import java.util.*;

class BFSGraph {
    public static void bfsGraph(Map<Integer, List<Integer>> graph, int start) {
        Queue<Integer> queue = new LinkedList<>();
        Set<Integer> visited = new HashSet<>();

        queue.add(start);
        visited.add(start);

        while (!queue.isEmpty()) {
            int node = queue.poll();
            System.out.print(node + " ");

            for (int neighbor : graph.getOrDefault(node, new ArrayList<>())) {
                if (!visited.contains(neighbor)) {
                    queue.add(neighbor);
                    visited.add(neighbor);
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

        System.out.print("BFS Traversal: ");
        bfsGraph(graph, 1); // Start BFS from node 1
    }
}
```
**Output:**
```
BFS Traversal: 1 2 3 4
```

---

### **Simple BFS Questions to Try**
1. **Print all nodes in a tree level by level.**
2. **Find the shortest path in an unweighted graph using BFS.**
3. **Count the number of levels (depth) in a tree using BFS.**
4. **Detect a cycle in an undirected graph using BFS.**
5. **Find the connected components in a graph.**
