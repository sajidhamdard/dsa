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

int getSmallest(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }

    return root->data;
}

// TC: O(H)
// AS: O(H)
Node* deleteFromBst(Node* root, int val) {
    if (root == NULL) {
        return NULL;
    }

    if (val < root->data) {
        root->left = deleteFromBst(root->left, val);
    } else if (val > root->data) {
        root->right = deleteFromBst(root->right, val);
    } else {

        // int childCount = 0;
        // if (root->left != NULL) {
        //     childCount++;
        // }
        // if (root->right != NULL) {
        //     childCount++;
        // }

        // if (childCount == 0) {
        //     return NULL;
        // }
        // if (childCount == 1) {
        //     if (root->left != NULL) {
        //         return root->left;
        //     }
        //     return root->right;
        // }

        if (root->left == NULL) {
            return root->right;
        }
        if (root->right == NULL) {
            return root->left;
        }

        int inorderSucc = getSmallest(root->right);
        root->data = inorderSucc;

        root->right = deleteFromBst(root->right, inorderSucc);
    }

    return root;
}

// TC: O(n)
// AS: O(H)
bool isBstUtil(Node* root, int low, int high) {
    if (root == NULL) {
        return true;
    }

    return root->data >= low && root->data <= high && 
            isBstUtil(root->left, low, root->data - 1) && 
            isBstUtil(root->right, root->data + 1, high);
}

bool isBst(Node* root) {

    return isBstUtil(root, -1e9, +1e9);
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

    deleteFromBst(root, 9);
    deleteFromBst(root, 4);
    deleteFromBst(root, 5);

    cout << endl;
    inorder(root);
}