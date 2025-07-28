#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// TC: O(n)
// AS: O(H)
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void pushLeft(Node* root, stack<Node*> &s) {

    while (root != NULL) {
        s.push(root);
        root = root->left;
    }
}

// TC: O(n)
// AS: O(H)
vector<int> iterativeInorder(Node* root) {

    stack<Node*> s;
    vector<int> res;

    pushLeft(root, s);

    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();

        res.push_back(curr->data);

        pushLeft(curr->right, s);
    }

    return res;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->right->left->left = new Node(10);

    vector<int> res = iterativeInorder(root);
    for (int i  : res) {
        cout << i << " ";
    }
    cout << endl;

    inorder(root);
}