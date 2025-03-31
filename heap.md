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


### **🤔 Why Use Heap When We Have List, Map, etc.?**  

✅ **Heap is optimized for fast retrieval of the smallest/largest element!**  
Unlike **List** and **Map**, a **Heap guarantees** that getting the min/max element is always **O(1)**.  

---

### **📌 Difference Between Heap, List, and Map**
| Data Structure | Best For | Time Complexity (Min/Max retrieval) |
|--------------|-------------------------------|---------------------------|
| **Heap (PriorityQueue)** | **Top K frequent, scheduling, priority-based tasks** | **O(1)** (peek), **O(log n)** (insert/remove) |
| **List (ArrayList, LinkedList)** | **Storing elements in order** | **O(n)** (must search for min/max manually) |
| **Map (HashMap, TreeMap)** | **Key-value lookups** | **O(n) (HashMap needs full scan for min/max), O(log n) (TreeMap)** |

---

### **📌 When to Use Heap Over List/Map?**
| Scenario | Best Choice | Why? |
|----------|------------|------|
| **Find K smallest/largest elements** | Heap | **O(n log k)** vs. O(n log n) for sorting |
| **Priority scheduling (task execution, Dijkstra’s algo, Huffman coding)** | Heap | Always retrieves highest-priority first |
| **Frequent min/max lookups (dynamic data)** | Heap | Faster than sorting every time |

### **📌 Example**
🔴 **List Approach (Slow min/max retrieval)**
```java
List<Integer> list = Arrays.asList(3, 1, 4, 2);
System.out.println(Collections.min(list)); // O(n) time
```

✅ **Heap Approach (Fast min retrieval)**
```java
PriorityQueue<Integer> minHeap = new PriorityQueue<>(Arrays.asList(3, 1, 4, 2));
System.out.println(minHeap.peek()); // O(1) time
```

---

### **📌 Conclusion**
- **Use `List`** if you just need to store elements in order.
- **Use `Map`** for key-value lookups.
- **Use `Heap`** when you need **fast min/max retrieval** or need to process elements **by priority**.

---

🚀 **TL;DR**:  
🔹 **Heap is best when you need to frequently get/remove the smallest/largest element in `O(1)`.**  
🔹 **List/Map cannot guarantee this efficiency.**


When you insert an element into a `PriorityQueue` (which is implemented using a **binary heap**), it **automatically adjusts its position** based on its priority.  

### **📌 How Does `PriorityQueue` Work Internally?**
1. **Insertion**: When a new element is added, it is placed at the last available position in the heap (to maintain a **complete binary tree** structure).  
2. **Heapify-Up (Bubble-Up)**: The element is compared with its parent and swapped **if necessary** to maintain the **heap property** (Min-Heap or Max-Heap).  
3. **Deletion (`poll()`)**: The root element (highest priority) is removed, and the last element is moved to the root. Then, **Heapify-Down (Sink-Down)** is performed to restore the heap property.  

---

### **📌 Example: Min-Heap Insertion (Natural Order)**
📌 **Adding elements one by one (`1, 2, 3, 0`) into a Min-Heap (`PriorityQueue`)**
```
pq.add(1)  →  [1]
pq.add(2)  →  [1, 2]
pq.add(3)  →  [1, 2, 3]
pq.add(0)  →  [0, 1, 3, 2] (Heapify-Up occurs, 0 moves to root)
```
**Heap Structure after inserting `0`:**
```
    0
   / \
  1   3
 /
2
```
Now, `poll()` will remove `0`, and the heap will adjust itself.

---

### **📌 Example Code**
```java
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>(); // Min-Heap
        minHeap.add(1);
        minHeap.add(2);
        minHeap.add(3);
        minHeap.add(0); // This will move to the root automatically
        
        System.out.println(minHeap.poll()); // Output: 0 (smallest element)
        System.out.println(minHeap.poll()); // Output: 1
        System.out.println(minHeap.poll()); // Output: 2
        System.out.println(minHeap.poll()); // Output: 3
    }
}
```
---

### **📌 Max-Heap Example (Custom Comparator)**
📌 If we use a **Max-Heap**, elements are **arranged in descending order**:
```java
import java.util.PriorityQueue;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder()); // Max-Heap
        maxHeap.add(1);
        maxHeap.add(2);
        maxHeap.add(3);
        maxHeap.add(0); // Largest will move to the root

        System.out.println(maxHeap.poll()); // Output: 3 (largest element)
        System.out.println(maxHeap.poll()); // Output: 2
        System.out.println(maxHeap.poll()); // Output: 1
        System.out.println(maxHeap.poll()); // Output: 0
    }
}
```

---

### **📌 Summary**
✔ `PriorityQueue` **adjusts elements** inside a **binary heap** structure.  
✔ **Min-Heap (default)** → Smallest element is always at the root.  
✔ **Max-Heap (custom comparator)** → Largest element is always at the root.  
✔ **Heapify-Up & Heapify-Down** keep the heap property intact. 
