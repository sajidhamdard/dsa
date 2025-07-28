#include<bits/stdc++.h>
using namespace std;

void dfsUtil(int curr, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &s) {

    vis[curr] = true;

    for (int neighbor : adj[curr]) {
        if (!vis[neighbor]) {
            dfsUtil(neighbor, adj, vis, s);
        }
    }

    s.push(curr);
}

// TC: O(V + E)
// AS: O(V)
vector<int> topologicalOrdering(vector<vector<int>> adj) {
    int V = adj.size();

    vector<bool> vis(V, false);
    stack<int> s;

    vector<int> result;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfsUtil(i, adj, vis, s);
        }
    }

    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }

    return result;
}

int main() {

    vector<int> res = topologicalOrdering({{},
                                           {3},
                                           {3},
                                           {},
                                           {1, 0},
                                           {0, 2}});
    
    for (int i : res) {
        cout << i << " ";
    }
}