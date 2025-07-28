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


## ✅ Stack using One Queue

### 💡 Goal:

Simulate **LIFO (stack)** behavior using **FIFO (queue)** operations only.

---

### 🔁 Core Idea (Rotation Trick):

When you `push(x)` into the queue:

1. Add `x` to the queue.
2. Rotate the queue by removing all elements before `x` and adding them back at the end.
3. This makes `x` the **front** of the queue — simulating stack top.

---

### 🧠 Example Flow:

```java
push(1) → queue: [1]
push(2) → add 2 → [1, 2] → rotate → [2, 1]
push(3) → add 3 → [2, 1, 3] → rotate → [3, 2, 1]
```

Now:

* `pop()` → 3
* `top()` → 3
* `pop()` → 2
* etc.

---

### ✅ Java Code:

```java
import java.util.LinkedList;
import java.util.Queue;

class MyStack {
    private Queue<Integer> queue;

    public MyStack() {
        queue = new LinkedList<>();
    }

    public void push(int x) {
        queue.add(x);
        int size = queue.size();
        // Rotate previous elements behind the new one
        while (size-- > 1) {
            queue.add(queue.poll());
        }
    }

    public int pop() {
        return queue.poll(); // Always returns the most recently pushed element
    }

    public int top() {
        return queue.peek();
    }

    public boolean empty() {
        return queue.isEmpty();
    }
}
```

---

### ⏱️ Time Complexity:

| Operation | Time                   |
| --------- | ---------------------- |
| `push()`  | O(n) — due to rotation |
| `pop()`   | O(1)                   |
| `top()`   | O(1)                   |
| `empty()` | O(1)                   |

---

## ✅ Reverse a queue

```java
import java.util.LinkedList;
import java.util.Queue;

public class ReverseQueue {

    // TC: O(n), SC: O(n) due to recursion stack
    public static void reverse(Queue<Integer> queue) {
        if (queue.isEmpty()) {
            return;
        }

        int front = queue.poll();  // Remove front element
        reverse(queue);            // Recursively reverse the remaining queue
        queue.add(front);          // Add current element to the rear
    }

    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        q.add(2);
        q.add(3);
        q.add(4);

        reverse(q);  // Reverses the queue

        while (!q.isEmpty()) {
            System.out.print(q.poll() + " ");
        }
    }
}
```

---

## ✅ Logic (Short Explanation):

1. **Base Case**: If the queue is empty, stop recursion.
2. **Recursive Step**:

   * Remove the front element and store it.
   * Recursively reverse the rest of the queue.
   * After recursion returns, insert the removed element at the **rear**.
3. This reverses the queue because:

   * The first element removed will be added **last**, and so on — reversing the order.

---

### 🧠 Example:

Input queue: `1 2 3 4`
Recursion unfolds → Adds `1` at the end → Result: `4 3 2 1`

---


Code that generates the **first `n` binary numbers in sequence**, along with a **comparison** between the **brute-force** and **optimized queue-based approach**.

---

## ✅ Optimized Approach using Queue

```java
import java.util.*;

public class BinaryNumberGenerator {

    // TC: O(n)
    // SC: O(n * log n) because each binary string is of log(n) length
    public static List<String> generateFirstNBinaryNumbers(int n) {
        Queue<String> queue = new LinkedList<>();
        List<String> result = new ArrayList<>();

        queue.add("1");
        int inserts = 1;

        while (inserts < n) {
            String curr = queue.poll();
            result.add(curr);

            queue.add(curr + "0");
            queue.add(curr + "1");
            inserts += 2;
        }

        while (result.size() < n) {
            result.add(queue.poll());
        }

        return result;
    }

    public static void main(String[] args) {
        List<String> res = generateFirstNBinaryNumbers(11);
        for (String s : res) {
            System.out.println(s);
        }
    }
}
```

---

## ✅ Output for `n = 11`

```
1
10
11
100
101
110
111
1000
1001
1010
1011
```

---

## 📊 Comparison: Brute-force vs Queue Approach

| Criteria             | Brute Force (Integer to Binary)                               | Queue-based BFS (Optimized)                                                         |
| -------------------- | ------------------------------------------------------------- | ----------------------------------------------------------------------------------- |
| **Idea**             | Convert numbers from 1 to n using `Integer.toBinaryString(i)` | Use BFS-style queue, starting from "1", and generate next using "0" and "1" appends |
| **Time Complexity**  | O(n log n) — due to binary conversion for each number         | O(n) — each element generated using string append                                   |
| **Space Complexity** | O(n \* log n) — storing n strings                             | O(n \* log n) — storing n strings                                                   |
| **Advantage**        | Simple and easy to code                                       | BFS-like structure simulates binary tree level order traversal                      |
| **Drawback**         | Slower for large `n`, repeated conversions                    | Slightly more complex but more efficient generation                                 |

---

### ✅ Brute Force (for reference)

```java
public static List<String> bruteForceBinary(int n) {
    List<String> res = new ArrayList<>();
    for (int i = 1; i <= n; i++) {
        res.add(Integer.toBinaryString(i)); //or use divide by 2 approach
    }
    return res;
}
```

---

## 🧠 Summary:

* ✅ **Brute Force** is simple but inefficient due to conversions.
* ✅ **Queue (BFS approach)** generates binary numbers like level-order traversal of a binary tree:

  * Start with `"1"`, then `"10"`, `"11"`, then `"100"`, `"101"`, etc.
* 🔁 Can be optimized further by using a `List<String>` as both result and queue (to reduce memory).

Now you want to **optimize the binary number generator to use only O(1) extra space** — i.e., not use any extra queue or data structures beyond the result list itself.

---

## ✅ Idea: Use Brute Force + In-place Conversion (no queue)

The **most space-efficient** approach is to:

* Iterate from `1` to `n`
* Convert each number to binary using `Integer.toBinaryString(i)`
* Directly store the result in a list

### ✅ O(1) extra space

```java
import java.util.*;

public class BinaryNumberGenerator {

    // TC: O(n * log n), SC: O(n * log n) for result, O(1) extra space
    public static List<String> generateFirstNBinaryNumbers(int n) {
        List<String> result = new ArrayList<>(n);
        for (int i = 1; i <= n; i++) {
            result.add(Integer.toBinaryString(i));
        }
        return result;
    }

    public static void main(String[] args) {
        List<String> res = generateFirstNBinaryNumbers(11);
        for (String s : res) {
            System.out.println(s);
        }
    }
}
```

---

## ✅ Time & Space Complexity

| Metric               | Value                                            |
| -------------------- | ------------------------------------------------ |
| **Time Complexity**  | O(n \* log n) — log n for each binary conversion |
| **Space Complexity** | O(n \* log n) — for storing result strings       |
| **Extra Space**      | O(1) — no auxiliary data structure like queue    |

---

## ⚠️ Note:

* This version avoids the **queue**, which means no BFS-style generation.
* It **does not** follow the "generate binary like binary tree" method but is **simpler and more space-efficient**.

---

## 🧠 Summary:

| Version                 | Time       | Extra Space | Notes                                        |
| ----------------------- | ---------- | ----------- | -------------------------------------------- |
| Queue (BFS)             | O(n)       | O(n)        | Good for understanding binary tree traversal |
| Brute Force (optimized) | O(n log n) | O(1)        | Most efficient in memory                     |

---

In LeetCode problems, when they mention a **"stream of characters"**, it typically means:

---

### ✅ **A sequence of characters that comes one by one over time**, rather than being given all at once.

Think of it like this:

> You're reading characters **as they arrive**, not as a full string.

---

### 🧠 Examples of problems with character streams:

1. **[Design Stream Checker](https://leetcode.com/problems/stream-of-characters/)**

   * You're given one character at a time via `query(char letter)`, and you must decide whether the current stream forms a word from a dictionary.

2. **[Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)**

   * While not explicitly a stream, it **can be thought of as reading a stream** and maintaining a window of unique characters.

---

### 🔄 Analogy:

If a string is:

```text
"abcde"
```

* In normal problems, you're given `"abcde"` as a full input.
* In **stream problems**, you receive:

  * `'a'`
  * then `'b'`
  * then `'c'` … and so on

You may be asked to process or make decisions **after each character arrives**, as if it’s **streaming live data** (like from a keyboard, network, or file).

---

### 🔧 You Might Need To:

* Maintain a buffer or queue of the last **k characters**
* Use Trie or HashSet for prefix/suffix matching
* Update your result **incrementally**

---

### 📦 Common use-cases:

* Autocomplete systems
* Spell checkers
* Live pattern matching
* Realtime log scanning

---

## 🔷 Problem: First Non-Repeating Character in a Stream of Characters

Given an input stream `s` consisting only of lowercase alphabets. While reading characters from the stream, you have to tell which character has appeared **only once** in the stream up to that point.

If there are multiple characters that have appeared only once, you must return **the one that appeared first** among them.

If there is **no non-repeating character**, append `'#'` to the result.

---

### 📝 Note:

1. You need to find the answer for every `i` (0 ≤ i < n).
2. To find the answer for index `i`, consider the stream from index `0` to index `i` inclusive.

---

### 🔸 Function Signature:

```java
public String firstNonRepeating(String s);
```

---

### 💡 Examples:

#### Example 1:

```
Input:  s = "aabc"
Output: "a#bb"

Explanation:
Step 0: "a"    → first non-repeating = 'a'  
Step 1: "aa"   → no non-repeating    → '#'  
Step 2: "aab"  → first non-repeating = 'b'  
Step 3: "aabc" → first non-repeating = 'b'  
```

#### Example 2:

```
Input:  s = "zz"
Output: "z#"

Explanation:
Step 0: "z"  → first non-repeating = 'z'  
Step 1: "zz" → all characters repeated → '#'  
```

---

### 🔸 Input:

* A string `stream` (1 ≤ stream.length() ≤ 10⁵) — a sequence of lowercase letters

### 🔸 Output:

* A string where each character represents the first non-repeating character at that point in the stream (or `#` if none exists)

---

### 🔍 Example 1:

```
Input:  "aabc"
Output: "a#bb"
```

### 🔍 Example 2:

```
Input:  "bcbdcd"
Output: "bbbb##"
```

---

## 🧠 Brute Force Approach

### ✅ Idea:

For every character in the stream:

* Check all previous characters to find the first one with frequency = 1.

### ❌ Time Complexity:

* O(n²), since checking previous characters can take O(n) per index.

---

## ✅ Optimized Approach (Using Queue)

### 🔹 Idea:

* Maintain a `Queue<Character>` to store potential non-repeating characters.
* Keep a frequency map (`int[26]`) to track how many times each character has occurred.
* After processing each character:

  * Add it to the queue (if it's the first time).
  * Remove characters from the front of the queue while they are repeated.
  * Append the front of the queue to the result (or `#` if queue is empty).

### ✅ Time Complexity: O(n)

### ✅ Space Complexity: O(1) → 26 letters + queue

---

## ✅ Java Implementation:

```java
import java.util.*;

public class StreamFirstNonRepeating {

    public static String firstNonRepeating(String stream) {
        int[] freq = new int[26];
        Queue<Character> q = new LinkedList<>();
        StringBuilder res = new StringBuilder();

        for (char ch : stream.toCharArray()) {
            freq[ch - 'a']++;

            if (freq[ch - 'a'] == 1) {
                q.offer(ch);
            }

            while (!q.isEmpty() && freq[q.peek() - 'a'] > 1) {
                q.poll();
            }

            if (q.isEmpty()) {
                res.append('#');
            } else {
                res.append(q.peek());
            }
        }

        return res.toString();
    }

    public static void main(String[] args) {
        System.out.println(firstNonRepeating("aabc"));     // a#bb
        System.out.println(firstNonRepeating("bcbdcd"));   // bbb##
        System.out.println(firstNonRepeating("aaaa"));     // a###
        System.out.println(firstNonRepeating("abcd"));     // aaaaa
        System.out.println(firstNonRepeating("a"));        // a
    }
}
```

---
