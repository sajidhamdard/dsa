#include<bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, int w, vector<vector<pair<int, int>>> &adj) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

// TC: O((V + E) * log(V))
// AS: O(V)
vector<int> dijikstra(vector<vector<pair<int, int>>> adj, int source) { // {u -> [{v, w}]}

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min-heap of {dist, node}

    int V = adj.size();
    vector<int> dist(V, 1e9);

    dist[source] = 0;

    pq.push({dist[source], source});

    while(!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();

        int distU = curr.first;
        int u = curr.second;

        for (pair<int, int> neighbor : adj[u]) {
            int v = neighbor.first;
            int distUV = neighbor.second;

            if (distU + distUV < dist[v]) {
                dist[v] = distU + distUV;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}


// TC: O((V + E) * log(V))
// AS: O(V)
vector<int> dijikstraUsingSet(vector<vector<pair<int, int>>> adj, int source) { // {u -> [{v, w}]}

    set<pair<int, int>> s;

    int V = adj.size();
    vector<int> dist(V, 1e9);

    dist[source] = 0;

    s.insert({dist[source], source});

    while(!s.empty()) {
        pair<int, int> curr = *s.begin();
        s.erase(s.begin());

        int distU = curr.first;
        int u = curr.second;

        for (pair<int, int> neighbor : adj[u]) {
            int v = neighbor.first;
            int distUV = neighbor.second;

            if (distU + distUV < dist[v]) {
                if (s.find({dist[v], v}) != s.end()) {
                    s.erase(s.find({dist[v], v}));
                }

                dist[v] = distU + distUV;
                s.insert({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {

    vector<vector<pair<int, int>>> adj(9);
    addEdge(0, 1, 4, adj);
    addEdge(0, 7, 8, adj);
    addEdge(1, 7, 11, adj);
    addEdge(1, 2, 8, adj);
    addEdge(7, 8, 7, adj);
    addEdge(7, 6, 1, adj);
    addEdge(2, 8, 2, adj);
    addEdge(8, 6, 6, adj);
    addEdge(2, 3, 7, adj);
    addEdge(2, 5, 4, adj);
    addEdge(6, 5, 2, adj);
    addEdge(3, 5, 14, adj);
    addEdge(3, 4, 9, adj);
    addEdge(5, 4, 10, adj);

    vector<int> dist = dijikstra(adj, 0);
    for (int i : dist) {
        cout << i << " ";
    }
}