### ✅ **Approach Summary** (O(n) time, O(1) space):

1. **Find middle node** (using slow & fast pointers).
2. **Reverse second half** of the list from the middle.
3. **Cut off first half** at the middle (`slow.next = null`).
4. **Compare** both halves node by node.
5. (Optional) Restore the original list if needed.

---

### ✅ Handles:

* **Odd-length lists** (middle node is ignored in comparison).
* **Even-length lists** (perfect split).

---

### ✅ Java Code:

```java
class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) return true;

        // Step 1: Find middle node
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // Step 2: Reverse second half
        ListNode secondHalf = reverse(slow);
        ListNode firstHalf = head;

        // Step 3: Compare both halves
        while (secondHalf != null) {
            if (firstHalf.val != secondHalf.val) {
                return false;
            }
            firstHalf = firstHalf.next;
            secondHalf = secondHalf.next;
        }

        return true;
    }

    private ListNode reverse(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;

        while (curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev; // new head of reversed list
    }
}
```

---

### ✅ Example Walkthrough:

**List:** `1 → 2 → 3 → 2 → 1`

* Middle = `3`
* Reversed second half = `1 → 2`
* Compare: `1 == 1`, `2 == 2` ✅ → Palindrome

---

### ❗️Optional Enhancements:

* Restore the reversed half to its original form if needed (for interview-friendly clean-up).
* Split the list by doing `slow.next = null` if you want to visually break the list in two.


---

## ✅ Problem: Detect Cycle in Linked List

### 🔹 Statement:

Given the `head` of a singly linked list, return `true` if there is a **cycle**, otherwise return `false`.

---

## ✅ Approach 1: HashSet (Store Visited Nodes)

### 🔸 Idea:

* Traverse the list node by node.
* Store each node’s reference in a `HashSet`.
* If you encounter a node already in the set → **cycle detected**.
* If you reach `null`, there is **no cycle**.

### 🔸 Time & Space:

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)` (extra space for storing nodes)

### 🔸 Java Code:

```java
import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode(int val) { this.val = val; }
}

public class CycleDetectionWithHashSet {
    public boolean hasCycle(ListNode head) {
        Set<ListNode> visited = new HashSet<>();

        while (head != null) {
            if (visited.contains(head)) {
                return true; // Cycle detected
            }
            visited.add(head);
            head = head.next;
        }

        return false;
    }
}
```

---

## ✅ Approach 2: Floyd’s Cycle Detection Algorithm (Slow and Fast Pointer)

### 🔸 Idea:

* Use two pointers:

  * `slow` moves one step at a time.
  * `fast` moves two steps at a time.
* If there is a cycle, `slow` and `fast` will eventually **meet**.
* If `fast` or `fast.next` becomes `null`, there’s **no cycle**.

### 🔸 Time & Space:

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)` → No extra memory used

### 🔸 Java Code:

```java
class CycleDetectionFloyd {
    public boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;           // Move by 1
            fast = fast.next.next;      // Move by 2

            if (slow == fast) {
                return true; // Cycle detected
            }
        }

        return false; // No cycle
    }
}
```

---

## ✅ Comparison Table

| Feature           | HashSet Approach      | Slow-Fast Pointer (Floyd’s) |
| ----------------- | --------------------- | --------------------------- |
| Time Complexity   | `O(n)`                | `O(n)`                      |
| Space Complexity  | `O(n)` (extra memory) | `O(1)` (no extra memory)    |
| Simplicity        | Easier to implement   | Slightly more efficient     |
| Modification Safe | Yes                   | Yes                         |

---

## ✅ Sample Test

```java
public static void main(String[] args) {
    ListNode a = new ListNode(1);
    ListNode b = new ListNode(2);
    ListNode c = new ListNode(3);
    ListNode d = new ListNode(4);

    a.next = b;
    b.next = c;
    c.next = d;
    d.next = b; // cycle here

    CycleDetectionFloyd cd = new CycleDetectionFloyd();
    System.out.println(cd.hasCycle(a)); // true
}
```

---

# ✅ **Linked List Cycle – Final Notes**

---

## 📌 1. Detect a Cycle in a Linked List

### ✅ **Approach: Floyd’s Cycle Detection (Slow & Fast Pointer)**

* Use two pointers:

  * `slow` moves 1 step at a time.
  * `fast` moves 2 steps at a time.
* If they meet → cycle exists.
* If `fast` or `fast.next` becomes null → no cycle.

### 🔸 Time: `O(n)`

### 🔸 Space: `O(1)`

---

## 📌 2. Find the Starting Node of the Cycle

### ✅ **Steps:**

1. First, detect the cycle (`slow == fast`).
2. Reset one pointer to `head`.
3. Move both pointers 1 step at a time.
4. The node where they meet is the **start of the loop**.

### 🔸 Time: `O(n)`

### 🔸 Space: `O(1)`

---

## 📌 3. Remove the Cycle

### ✅ **Logic:**

* Detect cycle using Floyd’s algorithm.
* Once detected, find the **node before the loop starts**.
* Set its `next` to `null` to break the cycle.

### ✅ **Special Case:** If the loop starts at `head` (fully circular list), find the last node whose `next` is `head`, and break it.

### 🔸 Time: `O(n)`

### 🔸 Space: `O(1)`

---

# ✅ **Final Java Code (Optimal, Covers All 3)**

```java
class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class LinkedListCycleOperations {

    // ✅ Detect if a cycle exists
    public static boolean hasCycle(Node head) {
        Node slow = head;
        Node fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) return true;
        }

        return false;
    }

    // ✅ Find the starting node of the cycle
    public static Node detectCycleStart(Node head) {
        Node slow = head;
        Node fast = head;

        // Step 1: Detect cycle
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) {
                // Step 2: Move one pointer to head
                slow = head;
                while (slow != fast) {
                    slow = slow.next;
                    fast = fast.next;
                }
                return slow; // Start of loop
            }
        }

        return null; // No cycle
    }

    // ✅ Detect and Remove the cycle
    public static void detectAndRemoveLoop(Node head) {
        if (head == null) return;

        Node slow = head;
        Node fast = head;

        // Step 1: Detect cycle
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) break;
        }

        if (slow != fast) return; // No cycle

        // Step 2: Special case - fully circular list
        if (slow == head) {
            while (slow.next != head) {
                slow = slow.next;
            }
            slow.next = null;
            return;
        }

        // Step 3: Find node before the start of the loop
        fast = head;
        while (slow.next != fast.next) {
            slow = slow.next;
            fast = fast.next;
        }

        // Step 4: Break the loop
        slow.next = null;
    }

    // ✅ Utility: Print linked list
    public static void printLinkedList(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    // ✅ Test
    public static void main(String[] args) {
        Node head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(3);
        head.next.next.next = new Node(4);
        head.next.next.next.next = new Node(5);
        head.next.next.next.next.next = new Node(6);
        head.next.next.next.next.next.next = new Node(7);
        head.next.next.next.next.next.next.next = new Node(8);
        head.next.next.next.next.next.next.next.next = head.next.next; // cycle at node 3

        System.out.println("Cycle Exists? " + hasCycle(head)); // true

        Node loopStart = detectCycleStart(head);
        System.out.println("Cycle starts at: " + (loopStart != null ? loopStart.data : "null")); // 3

        detectAndRemoveLoop(head); // removes the cycle

        System.out.println("After removing cycle:");
        printLinkedList(head); // prints full list till end
    }
}
```

---

## ✅ Summary Table

| Operation        | Time | Space | Notes                                    |
| ---------------- | ---- | ----- | ---------------------------------------- |
| Detect cycle     | O(n) | O(1)  | Floyd’s algo                             |
| Find cycle start | O(n) | O(1)  | After detection, move both pointers      |
| Remove cycle     | O(n) | O(1)  | Special handling if cycle starts at head |

---

### 🔁 Stack – Summary:

1. **LIFO (Last In First Out):**
   The last element added is the first one to be removed.

2. **Real-life Example:**

   * Stack of plates: Add on top, remove from top.

3. **Major Operations:**

   * **Push:** Add element to the top.
   * **Pop:** Remove the top element.
   * **Peek / Top:** Look at the top element without removing it.
   * **size():** Returns number of elements in the stack.
   * **isEmpty:** Checks if the stack is empty.

4. **Implementation Options:**

   * **Arrays:** Faster, uses fixed size; good when size is known.
   * **Linked List:** Dynamic size; good when size is unknown.
   * **Inbuilt Stack Classes:** Safe and recommended for use (like `Stack` in Java or Python's list with stack methods).

---

### ✅ **What is a Dynamic Array?**

A **dynamic array** is a data structure that:

* Stores elements in a **contiguous block of memory** (like a regular array),
* But can **grow** or **shrink** in size **dynamically** during runtime.

---

### ✅ **How it differs from a normal (static) array:**

| Feature           | Static Array           | Dynamic Array                       |
| ----------------- | ---------------------- | ----------------------------------- |
| Size              | Fixed at creation      | Grows/shrinks automatically         |
| Memory Allocation | Once, at the beginning | Resize + copy if full               |
| Insertion Cost    | O(1) (if space)        | Amortized O(1)                      |
| Example Languages | C (with `int arr[10]`) | Java (`ArrayList`), Python (`list`) |

---

### 🔧 **How it works (behind the scenes):**

1. **Start with a small fixed-size array** (e.g., size = 2).
2. When it gets full and you try to `add`:

   * Allocate **new larger array** (typically double the size).
   * **Copy all elements** to the new array.
   * Add the new element.

   ➤ This makes most insertions **O(1)**, but occasionally **O(n)** when resizing happens.

---

### ✅ **Benefits:**

* Easy to use — no need to know size ahead of time.
* Fast random access (like normal arrays).
* Automatically handles growth.

---

### ❌ **Drawbacks:**

* Occasional cost of resizing and copying.
* Memory overhead (extra capacity reserved).

---

### 🧠 **Common Implementations:**

* **Java:** `ArrayList`
* **Python:** `list` (internally dynamic)
* **C++:** `vector`
* **JavaScript:** Arrays are dynamic by default

---

### 📌 Summary:

> A **dynamic array** behaves like a regular array but **automatically resizes** itself when needed, making it a flexible and efficient structure for storing a growing list of items.

---

### 🔍 Problem (Non-Circular):

Given an array, for each element, find the **next greater element to its right**. If none, return `-1`.

---

### 🚫 Brute Force Approach

**Logic**: For each element, scan to the right and find the first greater element.

```java
// TC: O(n^2), SC: O(1)
for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        if (arr[j] > arr[i]) {
            result[i] = arr[j];
            break;
        }
    }
    // if no break happens, assign -1
}
```

### ❌ Drawbacks:

* **Inefficient** for large arrays (O(n²))
* Repeated comparisons
* Poor performance in interviews / coding tests

---

### ✅ Optimized Approach (Monotonic Stack)

**Idea**:

* Traverse **from right to left**
* Use a **stack** to maintain a decreasing sequence
* For each element:

  * Pop all smaller elements (they can't be "next greater")
  * The top of the stack (if any) is the **next greater**
  * Push current element to stack

---

### ✅ Java Conversion

```java
import java.util.*;

public class NextGreaterElement {
    
    // TC: O(n), SC: O(n)
    public static int[] nextGreaterElements(int[] arr) {
        int n = arr.length;
        int[] result = new int[n];
        Stack<Integer> stack = new Stack<>();

        for (int i = n - 1; i >= 0; i--) {
            // Pop smaller or equal elements
            while (!stack.isEmpty() && stack.peek() <= arr[i]) {
                stack.pop();
            }

            result[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(arr[i]);
        }

        return result;
    }

    public static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        printArray(nextGreaterElements(new int[]{5, 3, 6, 4, 2, 3, 9, 10}));
        printArray(nextGreaterElements(new int[]{1, 2, 3, 4}));
        printArray(nextGreaterElements(new int[]{4, 3, 2, 1}));
        printArray(nextGreaterElements(new int[]{5, 4, 3, 2, 1, 10}));
    }
}
```

---

### 💡 Output Explanation

#### Input: `[5, 3, 6, 4, 2, 3, 9, 10]`

* Output: `[6, 6, 9, 9, 3, 9, 10, -1]`

#### Input: `[1, 2, 3, 4]`

* Output: `[2, 3, 4, -1]`

#### Input: `[4, 3, 2, 1]`

* Output: `[-1, -1, -1, -1]`

#### Input: `[5, 4, 3, 2, 1, 10]`

* Output: `[10, 10, 10, 10, 10, -1]`

---

### Summary

| Approach        | Time Complexity | Space Complexity | Notes                      |
| --------------- | --------------- | ---------------- | -------------------------- |
| Brute Force     | O(n²)           | O(1)             | Simple but inefficient     |
| Monotonic Stack | O(n)            | O(n)             | Best choice for interviews |

---

## 🔁 Why We Traverse **Right to Left**

In the **Next Greater Element (non-circular)** problem, for each element, we want to find the **first greater element to its right**.

So if you process from **left to right**, for each element, you’d have to **look ahead**, which leads to brute-force logic (nested loop = `O(n²)`).

### 👉 Instead, going from **right to left**:

* You’ve **already processed** elements to the right.
* You maintain a **stack** of possible “next greater” candidates.
* So in **one pass**, you can solve it using a **monotonic stack** efficiently.

---

## 📚 What is a Monotonic Stack?

A **monotonic stack** is a stack that is **always in sorted order (increasing or decreasing)** from top to bottom.

There are two types:

### 1. **Monotonic Decreasing Stack**

* Each new element you push is **less than or equal to** the element below it.
* Used to find the **next greater element**.

### 2. **Monotonic Increasing Stack**

* Each new element you push is **greater than or equal to** the element below it.
* Used to find the **next smaller element**.

---

## 🧠 In This Problem (Next Greater Element)

We use a **monotonic decreasing stack**:

* We want the next **greater** element.
* So we **remove** all smaller elements (they’re useless).
* The element at the top of the stack will be the **next greater** one.

---

### 🔄 Step-by-Step Example

Input: `[2, 1, 3]`
Process from right to left.

```
Stack: []
i = 2 → result[2] = -1 → push 3 → Stack = [3]
i = 1 → 3 > 1 → result[1] = 3 → push 1 → Stack = [3,1]
i = 0 → 1 < 2 → pop 1 → 3 > 2 → result[0] = 3 → push 2 → Stack = [3,2]
```

Output: `[3, 3, -1]`

---

## ✅ Benefits of Monotonic Stack

* **O(n) time**, since each element is pushed and popped at most once.
* Elegant and **widely used** in:

  * Next greater/smaller element
  * Histogram problems
  * Sliding window maxima

---

## 🧭 Summary

| Concept              | Why it's used here                                             |
| -------------------- | -------------------------------------------------------------- |
| **Right to left**    | So we have "future" elements already in the stack              |
| **Monotonic stack**  | Efficient way to find next greater by popping useless elements |
| **Decreasing stack** | Helps find the next **greater** element to the right           |
