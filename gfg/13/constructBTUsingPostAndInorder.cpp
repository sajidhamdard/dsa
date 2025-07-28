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
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// TC: O(n)
// AS: O(H)
void postorder(Node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

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

Node* constructBTUsingPostAndInorderUtil(vector<int> &in, int start, int end, vector<int> &post, int &postIdx) {
    if (start > end) {
        return NULL;
    }

    Node* root = new Node(post[postIdx]);
    postIdx--;

    int inIdx = start;
    for (int i = start + 1; i <= end; i++) {
        if (in[i] == root->data) {
            inIdx = i;
            break;
        }
    }

    root->right = constructBTUsingPostAndInorderUtil(in, inIdx + 1, end, post, postIdx);
    root->left = constructBTUsingPostAndInorderUtil(in, start, inIdx - 1, post, postIdx);

    return root;
}

// TC: O(n^2)
// AS: O(H)
Node* constructBTUsingPostAndInorder(vector<int> in, vector<int> post) {

    int postIdx = post.size() - 1;
    return constructBTUsingPostAndInorderUtil(in, 0, in.size() - 1, post, postIdx);
}

int main() {

    Node* root = constructBTUsingPostAndInorder({4, 8, 2, 5, 1, 6, 3, 7}, {8, 4, 5, 2, 6, 7, 3, 1});

    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

    preorder(root);

}