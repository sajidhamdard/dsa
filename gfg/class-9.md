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
