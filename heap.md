### **📌 Heap Overview**
A **Heap** is a **binary tree-based data structure** that satisfies the **heap property**:
- **Min-Heap**: The **smallest** element is always at the root.
- **Max-Heap**: The **largest** element is always at the root.
- **Complete Binary Tree**: Every level is fully filled except possibly the last.

### **📌 Min-Heap**
- **Property**: `Parent ≤ Child`
- **Root (Top) Element**: **Smallest** value
- **Operations**:
  - Insert: \(O(\log n)\)
  - Delete Min: \(O(\log n)\)
  - Get Min: \(O(1)\)
- **Example Min-Heap Tree**:
  ```
      1
     / \
    3   5
   / \
  7   8
  ```

#### **📌 Min-Heap in Java**
```java
PriorityQueue<Integer> minHeap = new PriorityQueue<>();
```

---

### **📌 Max-Heap**
- **Property**: `Parent ≥ Child`
- **Root (Top) Element**: **Largest** value
- **Operations**:
  - Insert: \(O(\log n)\)
  - Delete Max: \(O(\log n)\)
  - Get Max: \(O(1)\)
- **Example Max-Heap Tree**:
  ```
      9
     / \
    7   5
   / \
  3   4
  ```

#### **📌 Max-Heap in Java**
```java
PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
```

---

### **📌 Heap Time Complexity**
| Operation      | Min-Heap / Max-Heap |
|---------------|---------------------|
| Insert        | \(O(\log n)\)       |
| Delete Root   | \(O(\log n)\)       |
| Get Min/Max   | \(O(1)\)            |
| Build Heap    | \(O(n)\) (Heapify)  |

---

### **📌 When to Use Heaps?**
✅ **Priority Queues** (Processing elements in order)  
✅ **Top K problems** (Find `K` smallest/largest elements)  
✅ **Heap Sort** (Sorting using a heap)  
✅ **Dijkstra's Algorithm** (Shortest path problems)  

---

### **📝 Min-Heap (Smallest element first)**
```java
PriorityQueue<Integer> minHeap = new PriorityQueue<>();
minHeap.offer(5);
minHeap.offer(2);
minHeap.offer(8);
minHeap.offer(1);

System.out.println(minHeap.poll()); // Output: 1 (smallest)
```

---

### **📝 Max-Heap (Largest element first)**
```java
PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
maxHeap.offer(5);
maxHeap.offer(2);
maxHeap.offer(8);
maxHeap.offer(1);

System.out.println(maxHeap.poll()); // Output: 8 (largest)
```

---

### **📝 Min-Heap for Custom Objects (Sorting by frequency)**
```java
PriorityQueue<Map.Entry<Integer, Integer>> minHeap = 
    new PriorityQueue<>(Comparator.comparingInt(Map.Entry::getValue));
```

---

### **📝 Max-Heap for Custom Objects**
```java
PriorityQueue<Map.Entry<Integer, Integer>> maxHeap = 
    new PriorityQueue<>((a, b) -> b.getValue() - a.getValue());
```
