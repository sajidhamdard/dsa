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
