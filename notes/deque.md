## What is a **Deque**?

* **Deque** stands for **"Double Ended Queue"**.
* It is a **linear data structure** that allows **insertion** and **removal** of elements from **both ends** (front and rear).
* It can act like both a **Queue** (FIFO) and a **Stack** (LIFO).

In Java, **Deque** is an **interface** in the `java.util` package, and commonly used implementations are:

* `ArrayDeque`
* `LinkedList`

---

## Why is it useful?

You can:

* Add or remove elements from **both front and rear**.
* Use it as a **stack**, **queue**, or **both** easily.

---

## 📌 **All Deque Methods (Useful for both ends + normal ones)**

| Category           | Method          | Works on         | Description                                 |
| ------------------ | --------------- | ---------------- | ------------------------------------------- |
| **Insert**         | `add(e)`        | **Tail (rear)**  | Adds to tail, throws exception if fails     |
|                    | `offer(e)`      | **Tail (rear)**  | Adds to tail, returns `false` if fails      |
|                    | `addFirst(e)`   | **Head (front)** | Adds to front, throws exception             |
|                    | `offerFirst(e)` | **Head (front)** | Adds to front, returns `false` if fails     |
|                    | `addLast(e)`    | **Tail (rear)**  | Same as `add(e)` — adds to tail             |
|                    | `offerLast(e)`  | **Tail (rear)**  | Same as `offer(e)` — adds to tail           |
|                    | `push(e)`       | **Head (front)** | Stack push (same as `addFirst`)             |
| **Remove**         | `remove()`      | **Head (front)** | Removes from front, throws exception        |
|                    | `poll()`        | **Head (front)** | Removes from front, returns `null` if empty |
|                    | `removeFirst()` | **Head (front)** | Same as `remove()`                          |
|                    | `pollFirst()`   | **Head (front)** | Same as `poll()`                            |
|                    | `removeLast()`  | **Tail (rear)**  | Removes from tail, throws exception         |
|                    | `pollLast()`    | **Tail (rear)**  | Removes from tail, returns `null` if empty  |
|                    | `pop()`         | **Head (front)** | Stack pop (same as `removeFirst`)           |
| **Peek (Examine)** | `element()`     | **Head (front)** | Returns front, throws exception if empty    |
|                    | `peek()`        | **Head (front)** | Returns front, returns `null` if empty      |
|                    | `getFirst()`    | **Head (front)** | Same as `element()`                         |
|                    | `peekFirst()`   | **Head (front)** | Same as `peek()`                            |
|                    | `getLast()`     | **Tail (rear)**  | Returns last, throws exception              |
|                    | `peekLast()`    | **Tail (rear)**  | Returns last, returns `null` if empty       |

---

## 🟢 **Quick Tricks to Remember**

| **If you think Stack behavior (LIFO)** | **If you think Queue behavior (FIFO)** |
| -------------------------------------- | -------------------------------------- |
| `push(e)` → insert at **front**        | `offer(e)` → insert at **rear**        |
| `pop()` → remove from **front**        | `poll()` → remove from **front**       |
| `peek()` → check front element         | `peek()` → check front element         |

> **Deque** is **versatile** — supports both **Queue** (offer/poll/peek) **and Stack** (push/pop/peek) with same methods.

---

## 📌 **Final cheat sheet**

| **Front**                       | **Rear**                            |
| ------------------------------- | ----------------------------------- |
| `addFirst / offerFirst / push`  | `addLast / offerLast / add / offer` |
| `removeFirst / pollFirst / pop` | `removeLast / pollLast`             |
| `getFirst / peekFirst / peek`   | `getLast / peekLast`                |

---

## Example — Using **all types of methods** together

```java
import java.util.Deque;
import java.util.ArrayDeque;

public class DequeAllMethods {
    public static void main(String[] args) {
        Deque<Integer> deque = new ArrayDeque<>();

        // Stack-like behavior
        deque.push(10);  // same as addFirst(10)
        deque.push(20);
        System.out.println("After push: " + deque); // [20, 10]

        System.out.println("Pop: " + deque.pop()); // removes 20
        System.out.println("After pop: " + deque); // [10]

        // Queue-like behavior
        deque.offer(30); // adds to rear
        deque.offer(40);
        System.out.println("After offer: " + deque); // [10, 30, 40]

        System.out.println("Poll: " + deque.poll()); // removes 10
        System.out.println("After poll: " + deque); // [30, 40]

        // Explicit front / rear manipulation
        deque.offerFirst(5);
        deque.offerLast(50);
        System.out.println("Deque after offerFirst/offerLast: " + deque); // [5, 30, 40, 50]

        System.out.println("pollFirst(): " + deque.pollFirst()); // removes 5
        System.out.println("pollLast(): " + deque.pollLast());   // removes 50

        System.out.println("Final Deque: " + deque); // [30, 40]
    }
}
```

---

## ✨ **Summary**

* **Stack-like** → `push`, `pop`, `peek` → operates on front
* **Queue-like** → `offer`, `poll`, `peek` → operates on rear
* **Explicit control** → `addFirst/Last`, `removeFirst/Last`, `peekFirst/Last`
