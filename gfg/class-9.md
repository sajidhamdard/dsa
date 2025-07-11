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
