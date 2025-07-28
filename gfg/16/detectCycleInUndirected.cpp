#include<bits/stdc++.h>
using namespace std;

bool isCyclicUtil(int u, vector<vector<int>> &adj, vector<bool> &vis, int parent) {

    vis[u] = true;

    for (int v : adj[u]) {
        if (vis[v] && v != parent) {
            return true;
        }
        if (!vis[v] && isCyclicUtil(v, adj, vis, u)) {
            return true;
        }
    }

    return false;
}

// TC: O(V + E)
// AS: O(V)
bool isCyclic(vector<vector<int>> adj) {
    
    int V = adj.size();
    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++) {
        if (!vis[i] && isCyclicUtil(i, adj, vis, -1)) {
            return true;
        }
    }

    return false;
}

int main() {
    cout << isCyclic({{1},
                      {0, 2, 4},
                      {1, 3},
                      {2, 4},
                      {1, 3}}) << endl;

    cout << isCyclic({{1},
                      {0, 2},
                      {1, 3},
                      {2, 4},
                      {3}}) << endl;

    cout << isCyclic({{1, 4},
                      {0, 2},
                      {1, 3},
                      {2, 4},
                      {3, 0}}) << endl;
    
    cout << isCyclic({{},
                      {2, 3},
                      {1, 3},
                      {1, 2}}) << endl;

    cout << isCyclic({{0}}) << endl;
}