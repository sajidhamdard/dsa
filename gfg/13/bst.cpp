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

// TC: O(H)
// AS: O(H)
bool search(Node* root, int val) {
    if (root == NULL) {
        return false;
    }

    if (root->data == val) {
        return true;
    }

    if (root->data > val) {
        return search(root->left, val); 
    }
    return search(root->right, val);
}

// TC: O(H)
// AS: O(1)
bool searchIterative(Node* root, int val) {

    while (root != NULL) {
        if (root->data == val) {
            return true;
        }
        if (root->data > val) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return false;
}

// TC: O(H)
// AS: O(H)
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (root->data == val) {
        return root;
    }

    if (root->data > val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

int main() {

    Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, 3);
    root = insert(root, 9);

    cout << search(root, 3) << endl;
    cout << search(root, 11) << endl;
    cout << search(root, 12) << endl;
    cout << search(root, 5) << endl;

    inorder(root);
}