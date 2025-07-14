#### 🔗 What are Linked Lists?

A **Linked List** is a linear data structure where elements (nodes) are stored in **non-contiguous memory**, and each node points to the **next** node.

```text
Node = [data | next] → [data | next] → ...
```

---

#### ✅ Advantages over Arrays:

* **Dynamic size**: Grows/shrinks easily at runtime.
* **Efficient insertion/deletion**: O(1) at head/tail (no shifting).

---

#### ❌ Disadvantages over Arrays:

* **Slower access**: O(n) for random access (no index-based lookup).
* **More memory**: Extra space for `next` pointer.
* **Cache-unfriendly**: Non-contiguous memory leads to poor cache performance.

---

### ✅ Java Implementation of Linked List

```java
class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class LinkedList {
    Node head;

    // Add node at end
    public void append(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }

        Node curr = head;
        while (curr.next != null) {
            curr = curr.next;
        }
        curr.next = newNode;
    }

    // Print the list
    public void printList() {
        Node curr = head;
        while (curr != null) {
            System.out.print(curr.data + " -> ");
            curr = curr.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        list.append(10);
        list.append(20);
        list.append(30);

        list.printList(); // Output: 10 -> 20 -> 30 -> null
    }
}
```

---

### 🧠 Explanation:

* `Node` class: Represents each element in the linked list.
* `append()`: Adds a node to the end.
* `printList()`: Prints the linked list from head to tail.

---

## ✅ Time Complexities of Linked List Operations

| Operation                   | Singly Linked List (SLL)                                  | Doubly Linked List (DLL)      | Array (for comparison)  |
| --------------------------- | --------------------------------------------------------- | ----------------------------- | ----------------------- |
| Access by index             | ❌ `O(n)`                                                  | ❌ `O(n)`                      | ✅ `O(1)`                |
| Search                      | ❌ `O(n)`                                                  | ❌ `O(n)`                      | ✅ `O(n)`                |
| Insert at head              | ✅ `O(1)`                                                  | ✅ `O(1)`                      | ❌ `O(n)` (shift needed) |
| Insert at tail              | ❌ `O(n)` (without tail)  <br>✅ `O(1)` (with tail pointer) | ✅ `O(1)` (if tail is tracked) | ❌ `O(n)`                |
| Insert at middle (by index) | ❌ `O(n)`                                                  | ❌ `O(n)`                      | ❌ `O(n)` (shift needed) |
| Delete at head              | ✅ `O(1)`                                                  | ✅ `O(1)`                      | ❌ `O(n)` (shift needed) |
| Delete at tail              | ❌ `O(n)` (SLL)                                            | ✅ `O(1)` (DLL with tail)      | ❌ `O(n)` (shift needed) |
| Delete by value             | ❌ `O(n)`                                                  | ❌ `O(n)`                      | ❌ `O(n)`                |

---

## 📌 Notes

* Singly Linked List has only `next` pointer, so **no backward traversal**.
* Doubly Linked List has `prev` and `next` pointers, so **more flexible** but uses **more memory**.
* Arrays give fast access but are **costly for insertion/deletion** in the middle or start.

---

**LRU (Least Recently Used)** is a **caching strategy** that removes the **least recently used item** when the cache is full.

---

### 📚 Concept:

* Tracks usage order of items.
* When an item is accessed, it becomes **most recently used**.
* If the cache exceeds capacity, **least recently used item is removed**.

---

### 🧱 Using Linked List:

* A **Doubly Linked List** is used to maintain the usage order:

  * **Head** = most recently used
  * **Tail** = least recently used
* On access:

  * Remove the node from its position and move it to the front.
* On insert:

  * Add new node at head.
  * If over capacity, remove node from tail.

---

### 🔧 Supporting Structure:

* Use **HashMap + Doubly Linked List** for efficient operations:

  * `HashMap`: O(1) access to nodes
  * `LinkedList`: O(1) insert/delete from head/tail

---

### ⏱️ Time Complexities:

| Operation | Time |
| --------- | ---- |
| Get/Put   | O(1) |

---

### 📌 What is Locality of Reference?

In computer systems, **locality of reference** means:

* **Temporal locality**: Recently accessed data is likely to be accessed again soon.
* **Spatial locality**: Nearby memory locations are likely to be accessed soon.

This is **well utilized by arrays**, which are stored in **contiguous memory blocks**.

---

### ❌ Why Linked Lists Don’t Benefit from Locality:

| Feature                   | Linked List Limitation                                                                                |
| ------------------------- | ----------------------------------------------------------------------------------------------------- |
| **Non-contiguous memory** | Nodes are scattered in memory, not sequential.                                                        |
| **Cache inefficiency**    | CPUs cache data in blocks. Since list nodes aren't next to each other, CPU cache misses happen often. |
| **Pointer chasing**       | Each access requires following a pointer, which adds overhead and breaks locality.                    |

---

### ✅ In Contrast: Arrays

* Stored in **contiguous blocks**
* Accessing `arr[i]` likely loads nearby values (`arr[i+1]`, etc.) into the **CPU cache**
* Much **faster in real-world performance** when traversing

---

### 💡 Conclusion

🔹 **Linked Lists** are flexible for insertion/deletion,
but
🔹 **Arrays** are much faster for traversal/access due to **locality of reference** and **better cache performance**.


---

### ✅ 1. Iterative Approach (Most common & efficient)

#### **Java Code:**

```java
public Node reverseList(Node head) {
    Node prev = null;
    Node curr = head;

    while (curr != null) {
        Node nextTemp = curr.next; // store next
        curr.next = prev;          // reverse current node
        prev = curr;               // move prev and curr one step forward
        curr = nextTemp;
    }

    return prev; // new head
}
```

#### 📌 Time Complexity: `O(n)`

#### 📌 Space Complexity: `O(1)`

---

### ✅ 2. Recursive Approach

#### **Java Code:**

```java
public Node reverseList(Node head) {
    if (head == null || head.next == null) {
        return head;
    }

    Node newHead = reverseList(head.next);
    head.next.next = head;
    head.next = null;

    return newHead;
}
```

#### 📌 Time Complexity: `O(n)`

#### 📌 Space Complexity: `O(n)` (due to call stack)

---

### ✅ Example:

For a list `1 → 2 → 3 → 4 → null`, after reversal → `4 → 3 → 2 → 1 → null`

---


The **Runner's Technique** (also called the **Two Pointers Technique** or **Floyd's Tortoise and Hare**) is a strategy commonly used in **linked list** and **array** problems to **traverse at different speeds** using two pointers.

---

### 🏃‍♂️ What is it?

You use **two pointers**:

* `slow` (the **tortoise**) moves **one step at a time**
* `fast` (the **hare**) moves **two steps at a time**

---

### ✅ Common Use Cases:

| Problem Type                            | How Runner's Technique Helps                              |
| --------------------------------------- | --------------------------------------------------------- |
| **Find middle of linked list**          | When `fast` reaches end, `slow` is in the middle          |
| **Detect cycle in linked list**         | If there's a loop, `fast` will meet `slow`                |
| **Check for palindrome in linked list** | Find middle, then reverse second half                     |
| **Reordering linked list**              | Find middle, reverse second half, merge both              |
| **Nth node from end**                   | Move `fast` N steps, then move both until `fast` hits end |

---

### 🧠 Example: Find middle node

```java
public ListNode middleNode(ListNode head) {
    ListNode slow = head;
    ListNode fast = head;

    while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
    }

    return slow;
}
```

---

### 🧠 Example: Detect cycle

```java
public boolean hasCycle(ListNode head) {
    ListNode slow = head, fast = head;

    while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;

        if (slow == fast) return true;
    }

    return false;
}
```

---

### 🔁 Summary:

* ✅ **Efficient**: Usually `O(n)` time and `O(1)` space.
* ✅ Used in **cycle detection**, **middle finding**, **reverse merge**, etc.
* ✅ Helps avoid extra passes over the data.

---

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
