#include<bits/stdc++.h>
using namespace std;

// TC: O(V + E)
// AS: O(V)
vector<int> topologicalOrdering(vector<vector<int>> adj) {
    int V = adj.size();
    vector<int> result;
    
    vector<int> inDegrees(V, 0);

    for (vector<int> neighborsOfU : adj) {
        for (int v : neighborsOfU) {
            inDegrees[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (inDegrees[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        result.push_back(u);

        for (int v : adj[u]) {
            inDegrees[v]--;
            if (inDegrees[v] == 0) {
                q.push(v);
            }
        }
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