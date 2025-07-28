#include<bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -2, -2, -1, +1, +2, +2, +1};
int dy[8] = {-2, -1, +1, +2, +2, +1, -1, -2};

bool isSafe(int i, int j, int n, vector<vector<int>> &vis) {
    return 
        i >= 1 && i <= n &&
        j >= 1 && j <= n &&
        !vis[i][j];

}

// TC: O(n^2)
// AS: O(n^2)
int stepsByKnight(int n, pair<int, int> sourcePos, pair<int, int> targetPos) {
    vector<vector<int>> vis(n + 1, vector<int> (n + 1, false));
    queue<pair<int, int>> q;
    
    q.push(sourcePos);
    vis[sourcePos.first][sourcePos.second] = true;

    int dist = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int _ = 0; _ < sz; _++) {
            pair<int, int> u = q.front();
            q.pop();
            if (u == targetPos) {
                return dist;
            }

            int i = u.first;
            int j = u.second;
            for (int k = 0; k < 8; k++) {
                int newI = i + dx[k];
                int newJ = j + dy[k];

                if (isSafe(newI, newJ, n, vis)) {
                    vis[newI][newJ] = true;
                    q.push({newI, newJ});
                }
            }
            
        }
        dist++;
    }

    return -1; // won't be executed.
}

int main() {

    cout << stepsByKnight(3, {3, 3}, {1, 2}) << endl;
    cout << stepsByKnight(6, {4, 5}, {1, 1}) << endl;
}