## ✅ Problem: **Largest Rectangle in Histogram**

You're given an array of integers where each value represents the height of a bar in a histogram. Each bar has **width = 1**.

You need to find the **area of the largest rectangle** that can be formed by one or more contiguous bars.

---

## 🧠 Brute Force Approach

### 🔹 Idea:

For every bar:

* Extend to the **left and right** until you find a bar **shorter than the current**.
* Calculate the area using that width and height of the current bar.

### 🔸 Time Complexity:

* For every bar, you may traverse the entire array left and right → `O(n²)`

### 🔸 Code Sketch:

```cpp
for (int i = 0; i < n; i++) {
    int left = i, right = i;
    while (left >= 0 && arr[left] >= arr[i]) left--;
    while (right < n && arr[right] >= arr[i]) right++;
    int width = right - left - 1;
    maxArea = max(maxArea, arr[i] * width);
}
```

---

## ✅ Optimized Monotonic Stack Approach

### 🔹 Idea:

We precompute:

* `nextSmaller[i]`: Index of the **first bar to the right** shorter than `arr[i]`
* `prevSmaller[i]`: Index of the **first bar to the left** shorter than `arr[i]`

Then:

* Width = `nextSmaller[i] - prevSmaller[i] - 1`
* Area = `height[i] * width`

### 🔸 Time Complexity:

* `O(n)`
  Each element is **pushed and popped at most once** from the stack.

### 🔸 Space Complexity:

* `O(n)` for both stacks and result arrays

---

```java
import java.util.*;

class Solution {

    public static int largestRectangleArea(int[] heights) {
        int[] nextSmaller = findNextSmaller(heights);
        int[] prevSmaller = findPrevSmaller(heights);

        int maxArea = 0;
        for (int i = 0; i < heights.length; i++) {
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            int area = heights[i] * width;
            maxArea = Math.max(maxArea, area);
        }

        return maxArea;
    }

    public static int[] findNextSmaller(int[] heights) {
        int n = heights.length;
        int[] next = new int[n];
        Deque<Integer> stack = new ArrayDeque<>();

        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && heights[stack.peek()] >= heights[i]) {
                stack.pop();
            }
            next[i] = stack.isEmpty() ? n : stack.peek();
            stack.push(i);
        }

        return next;
    }

    public static int[] findPrevSmaller(int[] heights) {
        int n = heights.length;
        int[] prev = new int[n];
        Deque<Integer> stack = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && heights[stack.peek()] >= heights[i]) {
                stack.pop();
            }
            prev[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(i);
        }

        return prev;
    }

    public static void main(String[] args) {
        int[] bars = {6, 2, 5, 4, 5, 1, 6};
        System.out.println(largestRectangleArea(bars)); // Output: 12
    }
}
```

---

## 🧠 Why Monotonic Stack Works Here

Monotonic stacks help efficiently find:

* Next smaller to the **right** (decreasing stack)
* Previous smaller to the **left** (decreasing stack)

They reduce the need to check all elements on either side, thus **bringing down complexity to O(n)**.

---

## 📌 Final Recap

| Approach        | Time  | Space | Key Idea                                         |
| --------------- | ----- | ----- | ------------------------------------------------ |
| Brute Force     | O(n²) | O(1)  | Scan left and right for each bar                 |
| Monotonic Stack | O(n)  | O(n)  | Use stacks to find next/prev smaller efficiently |

---

## 📘 What is a Queue?

A **Queue** is a **linear data structure** that follows the **FIFO** principle:

> **First In, First Out**
> → The first element added is the first one to be removed.

---

## ⚙️ Basic Operations

| Operation    | Description                                | Time Complexity |
| ------------ | ------------------------------------------ | --------------- |
| `enqueue(x)` | Add element `x` to the rear                | O(1)            |
| `dequeue()`  | Remove element from the front              | O(1)            |
| `peek()`     | View the front element without removing it | O(1)            |
| `isEmpty()`  | Check if queue is empty                    | O(1)            |
| `size()`     | Returns number of elements in queue        | O(1)            |

---

## 📦 Queue Types

1. **Simple Queue**

   * Basic FIFO behavior

2. **Circular Queue**

   * Connects the end to the front to reuse space

3. **Deque (Double-Ended Queue)**

   * Insertion/removal at both ends (`addFirst`, `addLast`)

4. **Priority Queue**

   * Elements are dequeued based on **priority** (not insertion order)

---

## ✅ Use Cases

* Task scheduling
* Printer queue
* BFS traversal (Graphs, Trees)
* Handling requests (CPU, web server)

---

## 🧪 Java Code Example

```java
Queue<Integer> q = new LinkedList<>();
q.offer(10);       // enqueue
q.offer(20);
q.poll();          // dequeue → removes 10
q.peek();          // returns 20
```

---

## 📚 Notes

* In Java, use `Queue` interface (e.g., `LinkedList`, `ArrayDeque`)
* `Queue` is **not thread-safe** by default → use `ConcurrentLinkedQueue` if needed
* Use **Deque** for sliding window or monotonic queue problems

---

## 🔶 PriorityQueue

### ✅ Definition:

A **PriorityQueue** is a **heap-based** data structure where elements are dequeued in **priority order** (not insertion order).

---

### ⚙️ Key Features:

* By default: **Min-Heap** (smallest element removed first)
* Can create a **Max-Heap** using custom comparator

---

### ⏱️ Time Complexities:

| Operation  | Time     |
| ---------- | -------- |
| `offer(x)` | O(log n) |
| `poll()`   | O(log n) |
| `peek()`   | O(1)     |

---

### 📌 Java Example:

```java
PriorityQueue<Integer> minHeap = new PriorityQueue<>();
minHeap.offer(5);
minHeap.offer(1);
minHeap.offer(3);
System.out.println(minHeap.poll()); // 1 (smallest)

PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
```

---

### ✅ Use Cases:

* Dijkstra’s algorithm
* A\* search
* Top K elements
* Scheduling problems

---

## 🔷 Deque (Double-Ended Queue)

### ✅ Definition:

A **Deque** allows insertion and deletion from **both ends** (front and rear).

---

### ⚙️ Operations:

| Operation       | Description        |
| --------------- | ------------------ |
| `addFirst(x)`   | Insert at front    |
| `addLast(x)`    | Insert at rear     |
| `removeFirst()` | Remove from front  |
| `removeLast()`  | Remove from rear   |
| `peekFirst()`   | View front element |
| `peekLast()`    | View rear element  |

⏱️ All operations are **O(1)**

---

### 📌 Java Example:

```java
Deque<Integer> dq = new ArrayDeque<>();
dq.addFirst(1);
dq.addLast(2);
dq.removeFirst();  // removes 1
dq.removeLast();   // removes 2
```

---

### ✅ Use Cases:

* Sliding window maximum/minimum
* Monotonic queues
* Palindrome checking
* Undo/Redo functionality

---

To implement a **queue using two stacks**, you simulate the **FIFO** (First-In-First-Out) behavior of a queue using the **LIFO** (Last-In-First-Out) behavior of stacks.

### ✅ Concept:

Use two stacks:

* `stack1` → used for **enqueue (push)** operations.
* `stack2` → used for **dequeue (pop/peek)** operations.

#### Operations:

1. **Enqueue (push)**:

   * Simply push the element into `stack1`.

2. **Dequeue (pop)**:

   * If `stack2` is empty, move all elements from `stack1` to `stack2` (this reverses the order).
   * Then pop from `stack2`.

3. **Peek**:

   * Same as pop, but return the top without removing it.

4. **Empty**:

   * Return true if both stacks are empty.

---

### ✅ Java Implementation:

```java
import java.util.Stack;

public class MyQueue {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;

    public MyQueue() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }

    // Push element to the back of queue
    public void push(int x) {
        stack1.push(x);
    }

    // Removes the element from in front of queue and returns that element
    public int pop() {
        moveStack1ToStack2IfNeeded();
        return stack2.pop();
    }

    // Get the front element
    public int peek() {
        moveStack1ToStack2IfNeeded();
        return stack2.peek();
    }

    // Return whether the queue is empty
    public boolean empty() {
        return stack1.isEmpty() && stack2.isEmpty();
    }

    // Helper method to shift elements from stack1 to stack2 if needed
    private void moveStack1ToStack2IfNeeded() {
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }
    }

    // For demonstration
    public static void main(String[] args) {
        MyQueue queue = new MyQueue();
        queue.push(1);
        queue.push(2);
        System.out.println(queue.peek()); // 1
        System.out.println(queue.pop());  // 1
        System.out.println(queue.empty()); // false
    }
}
```

---

### 🧠 Time Complexity:

* **Push**: `O(1)`
* **Pop/Peek**: Amortized `O(1)`
  (Each element is moved from `stack1` to `stack2` at most once)

---

Here's a **comparison table** showing the **time complexities** of **queue operations** (`enqueue`, `dequeue`, and `peek`) based on **different underlying data structures** used to implement a queue:

---

### ✅ Queue Implementations and Their Time Complexities

| Implementation Type        | Enqueue (Add/Push) | Dequeue (Remove) | Peek (Front)   | Notes                                                           |
| -------------------------- | ------------------ | ---------------- | -------------- | --------------------------------------------------------------- |
| **Array (Static)**         | O(1)               | O(n)             | O(1)           | Dequeue requires shifting all elements after front              |
| **Dynamic Array**          | Amortized O(1)     | O(n)             | O(1)           | Similar shifting issue as static arrays, resizing adds overhead |
| **Singly Linked List**     | O(1) (at tail)     | O(1) (from head) | O(1)           | Efficient if tail and head pointers are maintained              |
| **Doubly Linked List**     | O(1)               | O(1)             | O(1)           | Extra memory due to backward pointers                           |
| **Two Stacks**             | O(1)               | Amortized O(1)   | Amortized O(1) | Uses two stacks; `dequeue` may trigger stack transfer           |
| **Java's LinkedList**      | O(1)               | O(1)             | O(1)           | Implements `Deque`; efficient for queue ops                     |
| **Circular Queue (Array)** | O(1)               | O(1)             | O(1)           | No shifting; uses front & rear indices                          |

---

### 📌 Summary:

* **Array (Static or Dynamic)**: Easy but inefficient for dequeue due to shifting.
* **Linked List**: Efficient and dynamic; no shifting or resizing.
* **Two Stacks**: Good trick to implement queue using stack behavior.
* **Circular Queue**: Optimal for fixed-size queues.
* **Java `LinkedList` / `ArrayDeque`**: Best for production-ready queue operations.

---
