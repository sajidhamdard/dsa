#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
    private:

    Node* head;
    Node* isPalindromeRecUtil(Node* curr, Node* head, bool &result) {
        if (curr == NULL) {
            return head;
        }

        Node* temp = isPalindromeRecUtil(curr->next, head, result);
        if (curr->data != temp->data) {
            result = false;
        }

        return temp->next;
    }

    public:

    // TC: O(1)
    // AS: O(1)
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // TC: O(n)
    // AS: O(1)
    void printLinkedList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // TC: O(n)
    // AS: O(1)
    void insertAtEnd(int val) {
        if (head == NULL) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        temp->next = newNode;
    }

    // TC: O(min(pos, n))
    // AS: O(1)
    void insertAtPos(int val, int pos) {
        if (head == NULL || pos == 0) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;
        int hops = 0;
        while (hops < pos - 1 && temp->next != NULL) {
            temp = temp->next;
            hops++;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // TC: O(1)
    // AS: O(1)
    void deleteFromBeginning() {
        if (head == NULL) {
            return;
        }

        Node* toDel = head;
        head = head->next;
        delete(toDel);
    }

    // TC: O(n)
    // AS: O(1)
    void deleteFromEnd() {
        if (head == NULL || head->next == NULL) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        Node* toDel = temp->next;
        temp->next = NULL;
        delete(toDel);
    }

    // TC: O(min(pos, n))
    // AS: O(1)
    void deleteFromPos(int pos) {
        if (head == NULL || pos == 0) {
            deleteFromBeginning();
            return;
        }

        int hops = 0;
        Node* temp = head;

        while (hops < pos - 1 && temp->next->next != NULL) {
            temp = temp->next;
            hops++;
        }

        Node* toDel = temp->next;
        temp->next = temp->next->next;
        delete(toDel);
    }

    // TC: O(n)
    // AS: O(1)
    void reverse() {

        Node* curr = head;
        Node* prev = NULL;

        while (curr != NULL) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        head = prev;
    }

    // TC: O(n)
    // AS: O(1)
    int getMiddleNode() {
        if (head == NULL) {
            return -1;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }

    // TC: O(n)
    // AS: O(n)
    bool isPalindromeRec() {
        bool result = true;
        isPalindromeRecUtil(head, head, result);
        return result;
    }
};



int main() {
    
    LinkedList* ll = new LinkedList;

    ll->insertAtBeginning(4);
    ll->insertAtBeginning(3);
    ll->insertAtBeginning(2);
    ll->insertAtBeginning(1);

    ll->printLinkedList();

    ll->insertAtEnd(5);
    ll->insertAtEnd(6);

    ll->printLinkedList();

    ll->insertAtPos(0, 0);
    ll->insertAtPos(10, 100);
    ll->insertAtPos(7, 4);

    ll->printLinkedList();

    ll->deleteFromBeginning();
    ll->printLinkedList();

    ll->deleteFromEnd();
    ll->printLinkedList();

    ll->deleteFromPos(3);
    ll->deleteFromPos(0);
    ll->deleteFromPos(300);

    ll->printLinkedList();

    ll->reverse();
    ll->printLinkedList();

    cout << ll->getMiddleNode() << endl;

    ll->insertAtEnd(1);
    ll->printLinkedList();
    cout << ll->getMiddleNode() << endl;

    ll->printLinkedList();
    cout << ll->isPalindromeRec() << endl;

    ll->insertAtEnd(2);
    ll->insertAtEnd(3);
    ll->insertAtEnd(4);
    ll->insertAtEnd(5);
    ll->printLinkedList();
    cout << ll->isPalindromeRec() << endl;
}