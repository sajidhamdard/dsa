### **Tortoise and Hare Algorithm (Slow & Fast Pointer Technique) 🐢🐇**

The **Tortoise and Hare Algorithm** is a two-pointer technique used in linked lists and cycle detection problems. The idea is to use two pointers that move at different speeds to efficiently solve problems.

---

## **🛠 How It Works**

- **Slow Pointer (`tortoise`)** moves **one step** at a time.
- **Fast Pointer (`hare`)** moves **two steps** at a time.
- Because the fast pointer moves twice as fast, it will eventually either:
  1. **Reach the end of the list** (for middle node problems).
  2. **Catch up with the slow pointer** (for cycle detection problems).

---

## **🐢🐇 Finding the Middle Node of a Linked List**

### **Steps:**

1. Initialize two pointers:
   ```java
   ListNode slow = head, fast = head;
   ```
2. Move `slow` **one step** and `fast` **two steps** until `fast` reaches the end:
   ```java
   while (fast != null && fast.next != null) {
       slow = slow.next;
       fast = fast.next.next;
   }
   ```
3. When the loop ends, `slow` will be at the **middle node**.
4. If there are two middle nodes (even-length list), it will return the **second middle node** (as required in the problem).

### **Why does it work?**

- When `fast` moves **twice as fast**, by the time `fast` reaches the end, `slow` will have covered **half the distance**.
- This ensures that `slow` is at the **middle** when `fast` becomes `null`.

✅ **Time Complexity:** `O(N)` (traverse the list once).  
✅ **Space Complexity:** `O(1)` (no extra space, just two pointers).

---

## **🐢🐇 Detecting a Cycle in a Linked List**

This technique is also used in **Floyd’s Cycle Detection Algorithm** to check if a linked list has a cycle.

1. Start both `slow` and `fast` at the head.
2. Move `slow` **one step** and `fast` **two steps**.
3. If they **meet at the same node**, a cycle exists.
4. If `fast` reaches `null`, there is **no cycle**.

---

### **Where is Tortoise and Hare Algorithm Used?**

✔ Finding the **middle of a linked list**  
✔ Detecting **cycles in a linked list** (Floyd’s Algorithm)  
✔ Finding the **starting point of a cycle**  
✔ Checking **looping behavior** in mathematical sequences (e.g., happy numbers)
