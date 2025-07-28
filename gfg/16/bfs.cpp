#include<bits/stdc++.h>
using namespace std;

// TC: O(V + E)
// AS: O(V)
vector<int> bfs(vector<vector<int>> adj, int source) {

    int V = adj.size();
    queue<int> q;
    vector<bool> vis(V, false);
    q.push(source);
    vis[source] = true;

    vector<int> result;

    while (!q.empty()) {
        
        int sz = q.size();
        for (int _ = 0; _ < sz; _++) {
            int u = q.front();
            q.pop();

            result.push_back(u);
            for (int v : adj[u]) {
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }

    return result;
}

int main() {

    vector<int> res = bfs({{1, 2},
                           {0, 3, 4},
                           {0, 4, 5},
                           {1, 4},
                           {1, 2, 3},
                           {2}}, 0);

    for (int i : res) {
        cout << i << " ";
    }
}