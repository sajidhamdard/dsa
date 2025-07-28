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

unordered_map<Node*, int> heights;

// TC: O(n)
// AS: O(H)
int height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    // If the height of the current node is already computed.
    if (heights.find(root) != heights.end()) {
        return heights[root];
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int res = max(leftHeight, rightHeight) + 1;
    heights[root] = res;
    return res;
}

// TC: O(n)
// AS: O(H)
int diameterBF(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    int leftDiam = diameterBF(root->left);
    int rightDiam = diameterBF(root->right);

    return max({leftDiam, rightDiam, lh + rh});
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

    cout << diameterBF(root) << endl;

}