#include<bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -1, -1, +0, +1, +1, +1, +0};
int dy[8] = {-1, +0, +1, +1, +1, +0, -1, -1};

bool isSafe(int i, int j, vector<vector<int>> &arr) {
    return i >= 0 && i < arr.size() && j >= 0 && j < arr[i].size() && arr[i][j] == 1;
}

void dfs(int i, int j, vector<vector<int>> &arr) {

    arr[i][j] = 0;

    for (int k = 0; k < 8; k++) {
        int newI = i + dx[k];
        int newJ = j + dy[k];

        if (isSafe(newI, newJ, arr)) {
            dfs(newI, newJ, arr);
        }
    }
}

// TC: O(nm)
// AS: O(nm)
int countIslands(vector<vector<int>> arr) {

    int result = 0;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == 1) {
                result++;
                dfs(i, j, arr);
            }
        }
    }

    return result;
}

int main() {
}