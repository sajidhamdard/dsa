public class LinkedListClass {
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    private Node head;

    // TC: O(1)
    public void insertAtBeginning(int val) {
        Node newNode = new Node(val);
        newNode.next = head;
        head = newNode;
    }

    // TC: O(n)
    public void insertAtEnd(int val) {
        if (head == null) {
            insertAtBeginning(val);
            return;
        }

        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }

        Node newNode = new Node(val);
        temp.next = newNode;
    }

    // TC: O(min(pos, n))
    public void insertAtPos(int val, int pos) {
        if (head == null || pos == 0) {
            insertAtBeginning(val);
            return;
        }

        Node temp = head;
        int hops = 0;
        while (hops < pos - 1 && temp.next != null) {
            temp = temp.next;
            hops++;
        }

        Node newNode = new Node(val);
        newNode.next = temp.next;
        temp.next = newNode;
    }

    // TC: O(1)
    public void deleteFromBeginning() {
        if (head == null) return;

        Node toDel = head;
        head = head.next;
        toDel = null;
    }

    // TC: O(n)
    public void deleteFromEnd() {
        if (head == null || head.next == null) {
            deleteFromBeginning();
            return;
        }

        Node temp = head;
        while (temp.next.next != null) {
            temp = temp.next;
        }

        temp.next = null;
    }

    // TC: O(min(pos, n))
    public void deleteFromPos(int pos) {
        if (head == null || pos == 0) {
            deleteFromBeginning();
            return;
        }

        Node temp = head;
        int hops = 0;

        while (hops < pos - 1 && temp.next != null && temp.next.next != null) {
            temp = temp.next;
            hops++;
        }

        if (temp.next != null) {
            temp.next = temp.next.next;
        }
    }

    // TC: O(n)
    public void reverse() {
        Node curr = head;
        Node prev = null;

        while (curr != null) {
            Node nextTemp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextTemp;
        }

        head = prev;
    }

    // TC: O(n)
    public int getMiddleNode() {
        if (head == null) return -1;

        Node slow = head;
        Node fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow.data;
    }

    // TC: O(n), AS: O(n)
    private Node isPalindromeRecUtil(Node curr, Node[] headRef, boolean[] result) {
        if (curr == null) return headRef[0];

        Node temp = isPalindromeRecUtil(curr.next, headRef, result);
        if (!result[0]) return null;

        if (temp.data != curr.data) {
            result[0] = false;
        }

        return temp.next;
    }

    public boolean isPalindromeRec() {
        boolean[] result = new boolean[]{true};
        Node[] headRef = new Node[]{head};
        isPalindromeRecUtil(head, headRef, result);
        return result[0];
    }

    public void printLinkedList() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    // main method for testing
    public static void main(String[] args) {
        LinkedListClass ll = new LinkedListClass();

        ll.insertAtBeginning(4);
        ll.insertAtBeginning(3);
        ll.insertAtBeginning(2);
        ll.insertAtBeginning(1);
        ll.printLinkedList();

        ll.insertAtEnd(5);
        ll.insertAtEnd(6);
        ll.printLinkedList();

        ll.insertAtPos(0, 0);
        ll.insertAtPos(10, 100);
        ll.insertAtPos(7, 4);
        ll.printLinkedList();

        ll.deleteFromBeginning();
        ll.printLinkedList();

        ll.deleteFromEnd();
        ll.printLinkedList();

        ll.deleteFromPos(3);
        ll.deleteFromPos(0);
        ll.deleteFromPos(300);
        ll.printLinkedList();

        ll.reverse();
        ll.printLinkedList();

        System.out.println("Middle node: " + ll.getMiddleNode());

        ll.insertAtEnd(1);
        ll.printLinkedList();
        System.out.println("Middle node: " + ll.getMiddleNode());

        System.out.println("Is Palindrome? " + ll.isPalindromeRec());

        ll.insertAtEnd(2);
        ll.insertAtEnd(3);
        ll.insertAtEnd(4);
        ll.insertAtEnd(5);
        ll.printLinkedList();
        System.out.println("Is Palindrome? " + ll.isPalindromeRec());
    }
}
