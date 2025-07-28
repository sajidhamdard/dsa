#include<bits/stdc++.h>
using namespace std;

void dfsUtil(int curr, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &result) {

    result.push_back(curr);
    vis[curr] = true;

    for (int neighbor : adj[curr]) {
        if (!vis[neighbor]) {
            dfsUtil(neighbor, adj, vis, result);
        }
    }
}

// TC: O(V + E)
// AS: O(V)
vector<int> dfs(vector<vector<int>> adj) {
    int V = adj.size();

    vector<bool> vis(V, false);

    vector<int> result;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfsUtil(i, adj, vis, result);
        }
    }
    return result;
}

int main() {
    vector<int> res = dfs({{1},
                           {0},
                           {3},
                           {2, 4, 5},
                           {3, 5},
                           {3, 4, 6},
                           {5},
                           {}});
    
    for (int i : res) {
        cout << i << " ";
    }
}