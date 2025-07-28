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

void getPathUtil(Node* root, int val, vector<int> &currPath, vector<int> &result) {
    if (root == NULL) {
        return;
    }

    currPath.push_back(root->data);

    if (root->data == val) {
        result = currPath;
    }

    getPathUtil(root->left, val, currPath, result);
    getPathUtil(root->right, val, currPath, result);

    currPath.pop_back();
}

vector<int> getPath(Node* root, int val) {

    vector<int> currPath, result;
    getPathUtil(root, val, currPath, result);

    return result;
}

// TODO: Calculate LCA in a single traversal of the Binary Tree.=
// TC: O(n)
// AS: O(H)
int lca(Node* root, int n1, int n2) {

    vector<int> pathN1 = getPath(root, n1);
    vector<int> pathN2 = getPath(root, n2);

    int i = 1;
    int result = pathN1[0];

    while (i < pathN1.size() && i < pathN2.size()) {
        if (pathN1[i] != pathN2[i]) {
            break;
        }

        result = pathN1[i];
        i++;
    }

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

    
    cout << lca(root, 8, 9) << endl; // 4
    cout << lca(root, 5, 8) << endl; // 2
    cout << lca(root, 4, 7) << endl; // 1
    cout << lca(root, 3, 10) << endl; // 3

}