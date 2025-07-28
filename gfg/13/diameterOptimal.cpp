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

int getHeightAndCalcDiam(Node* root, int &diam) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = getHeightAndCalcDiam(root->left, diam);
    int rightHeight = getHeightAndCalcDiam(root->right, diam);

    diam = max(diam, leftHeight + rightHeight);

    return max(leftHeight, rightHeight) + 1;
}

// TC: O(n)
// AS: O(H)
int diameter(Node* root) {
    int result = 0;
    getHeightAndCalcDiam(root, result);
    return result;
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

    cout << diameter(root) << endl;

}