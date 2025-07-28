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


int main() {
    Node* newNode = new Node(5);
    cout << newNode->data << endl;
}