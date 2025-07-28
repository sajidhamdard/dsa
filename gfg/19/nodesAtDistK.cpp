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

void getPathUtil(Node* root, int target, vector<Node*> &currPath, vector<Node*> &result) {
    if (root == NULL || result.size() > 0) {
        return;
    }

    currPath.push_back(root);
    if (root->data == target) {
        result = currPath;
        return;
    }

    getPathUtil(root->left, target, currPath, result);
    getPathUtil(root->right, target, currPath, result);

    currPath.pop_back();
}

vector<Node*> getPath(Node* root, int target) {
    vector<Node*> currPath;
    vector<Node*> result;

    getPathUtil(root, target, currPath, result);

    return result;
}

void getNodesAtDistKBelowTarget(Node* root, int k, vector<int> &result) {
    if (root == NULL || k < 0) {
        return;
    }

    if (k == 0) {
        result.push_back(root->data);
        return;
    }

    getNodesAtDistKBelowTarget(root->left, k - 1, result);
    getNodesAtDistKBelowTarget(root->right, k - 1, result);
    
}

// TC: O(n)
// AS: O(H)
vector<int> nodesAtDistK(Node* root, int target, int k) {

    vector<Node*> path = getPath(root, target); // O(n)
    int n = path.size();

    vector<int> result;

    if (n - k - 1 >= 0) {
        result.push_back(path[n - k - 1]->data);
    }

    getNodesAtDistKBelowTarget(path[n - 1], k, result); // O(n)
    k--;

    for (int i = path.size() - 2; i >= 0; i--) { // O(n)
        if (path[i + 1] == path[i]->left) {
            getNodesAtDistKBelowTarget(path[i]->right, k - 1, result);
        } else {
            getNodesAtDistKBelowTarget(path[i]->left, k - 1, result);
        }
        k--;
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

    vector<int> res = nodesAtDistK(root, 3, 1);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> res2 = nodesAtDistK(root, 7, 2);
    for (int i : res2) {
        cout << i << " ";
    }
}