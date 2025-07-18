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
