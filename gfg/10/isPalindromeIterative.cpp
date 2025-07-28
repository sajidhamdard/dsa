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

Node* getMiddleNode(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* reverse(Node* head) {

    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

// TC: O(n)
// AS: O(1)
bool isPalindromeIterative(Node* head) {
    if (head == NULL) {
        return true;
    }

    // Step-1: get the mid node of linked list
    Node* mid = getMiddleNode(head);

    // Step-2: Break the linked list into two equal halves.
    Node* head2 = mid->next;
    mid->next = NULL;

    // Step-3: Reverse the second half.
    head2 = reverse(head2);

    // Step-4: Compare the two halves node by node.
    while (head != NULL && head2 != NULL) {
        if (head->data != head2->data) {
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }

    return true;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    cout << isPalindromeIterative(head) << endl;


    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);

    cout << isPalindromeIterative(head) << endl;


    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);

    cout << isPalindromeIterative(head) << endl;

    head = new Node(1);
    cout << isPalindromeIterative(head) << endl;

    cout << isPalindromeIterative(NULL) << endl;
}