## [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)

### ✅ Solution (Beats 100%)

```java
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
}
````

### 📊 Time Complexity:

`O(n)` : Even though fast is moving twice as fast, we’re still visiting each node once in the worst case (since we're traversing about half of them with slow, and every second one with fast).

### 🧠 Space Complexity:

`O(1)` — No extra space used

### ❌ Mistakes / Challenges Faced:

* We need to carefully handle the pointers. It's important to note which pointer is used in the while loop condition. If we forget to check fast != null before fast.next != null, we may encounter a NullPointerException
### 🧩 Pattern/Topic:

`Linked List`, `Two Pointers`
