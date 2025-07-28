#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1, +1, +0, +0};
int dy[4] = {+0, +0, -1, +1};

bool isSafe(int i, int j, vector<vector<int>> &arr) {
    return
        i >= 0 and i < arr.size() and
        j >= 0 and j < arr[i].size() and
        arr[i][j] == 1;
}

// TC: O(nm)
// AS: O(nm)
int getMinTimeToRot(vector<vector<int>> arr) {
    int n = arr.size();
    int m = arr[0].size();

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 2) {
                q.push({i, j});
            }
        }
    }

    int time = 0;

    while (!q.empty()) {
        int sz = q.size();
        time++;
        for (int _ = 0; _ < sz; _++) {
            pair<int, int> curr = q.front();
            q.pop();

            int i = curr.first;
            int j = curr.second;

            for (int k = 0; k < 4; k++) {
                int newI = i + dx[k];
                int newJ = j + dy[k];

                if (isSafe(newI, newJ, arr)) {
                    arr[newI][newJ] = 2;
                    q.push({newI, newJ});
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                return -1;
            }
        }
    }

    return time - 1;
}

int main() {
    cout << getMinTimeToRot({{0, 1, 2},
                             {0, 1, 2},
                             {2, 1, 1}}) << endl;
    cout << getMinTimeToRot({{2, 2, 0, 1}}) << endl;
    cout << getMinTimeToRot({{2, 2, 2},
                             {0, 2, 0}}) << endl;
    cout << getMinTimeToRot({{1, 2, 1},
                             {1, 1, 1},
                             {1, 1, 1}}) << endl;
}