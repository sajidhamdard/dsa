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
// AS: O(n)
vector<int> levelorder(Node* root) {
    if (root == NULL) {
        return {};
    }

    vector<int> result;
    queue<Node*> q;

    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        result.push_back(curr->data);

        if (curr->left != NULL) {
            q.push(curr->left);
        }
        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }

    return result;
}

// TC: O(n)
// AS: O(n)
vector<vector<int>> levelByLevelTraversal(Node* root) {
    if (root == NULL) {
        return {};
    }

    vector<vector<int>> result;
    queue<Node*> q;

    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        vector<int> currLevel;
       
        for (int i = 0; i < sz; i++) {
            Node* curr = q.front();
            q.pop();
            // if (i == 0) {
            //     leftView.push_back(curr->data); 
            // }
            // if (i == sz - 1) {
            //     rightView.push_back(curr->data); 
            // }

            currLevel.push_back(curr->data);

            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
        result.push_back(currLevel);
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

    vector<int> res = levelorder(root);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;

    vector<vector<int>> res2 = levelByLevelTraversal(root);
    for (auto level : res2) {
        for (int i : level) {
            cout << i << " ";
        }
        cout << endl;
    }
}