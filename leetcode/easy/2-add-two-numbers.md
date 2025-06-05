## [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/description/)

### ✅ Solution (Beats 100%)

```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode();
        ListNode tempNode = head;
        int carryOver = 0;
        while(l1 != null || l2 != null || carryOver > 0) {
            int total = (l1 != null ? l1.val : 0) + (l2 != null ? l2.val : 0) + carryOver;
            carryOver = total / 10;
            ListNode node = new ListNode(total % 10);
            head.next = node;
            head = head.next;
            l1 = l1 != null ? l1.next : null;
            l2 = l2 != null ? l2.next : null;
        }
        return tempNode.next;
    }
}
````

### 📊 Time Complexity:

`O(max(m, n))` : m = length of l1, n = length of l2

### 🧠 Space Complexity:

`O(max(m, n))` — for the output linked list

### ❌ Mistakes / Challenges Faced:

* One might think of first adding both numbers as integers and then generating a new list, but that approach can easily fail in many edge cases. A better and more reliable method is to add the digits of both linked lists node by node, starting from the head. If a node is null, we treat its value as 0 to avoid errors. Handling the carryover properly is crucial—especially when there's a carry from the last nodes, which may require creating an extra node. It's also important to manage node traversal carefully, since either list can be shorter and may reach null earlier.

### 🧩 Pattern/Topic:

`Linked List`, `Math`, `Recursion`
