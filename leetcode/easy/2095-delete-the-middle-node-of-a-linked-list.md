## [Delete the middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/)

### ✅ Solution (Beats 99%)

```java
class Solution {
    public ListNode deleteMiddle(ListNode head) {
        if(head == null || head.next == null) {
            return null;
        }
        ListNode prev = null;
        ListNode slow = head;
        ListNode fast = head;
        
        while(fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        prev.next = slow.next;
        return head;
    }
}
````

### 📊 Time Complexity:

`O(n)` : Even though fast is moving twice as fast, we’re still visiting each node once in the worst case (since we're traversing about half of them with slow, and every second one with fast).

### 🧠 Space Complexity:

`O(1)` — No extra space used

### ❌ Mistakes / Challenges Faced:

* We need to carefully handle the pointers. It's important to note which pointer is used in the while loop condition. If we forget to check fast != null before fast.next != null, we may encounter a NullPointerException
* By initializing prev to null, we make it clearer that prev always trails behind slow. It's also a bit more defensive for future code changes.
  
### 🧩 Pattern/Topic:

`LinkedList`, `Two Pointers`
