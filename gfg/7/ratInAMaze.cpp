#include<bits/stdc++.h>
using namespace std;


bool isSafe(int i, int j, vector<vector<int>> &maze) {
    return i >= 0 && i < maze.size() &&
           j >= 0 && j < maze[i].size() &&
           maze[i][j] == 1; 
}

int dx[4] = {+1, +0, +0, -1};
int dy[4] = {+0, -1, +1, +0};
char dir[4] = {'D', 'L', 'R', 'U'};
void getPossiblePathsUtil(int i, int j, vector<vector<int>> &maze, 
                        string &currPath, vector<string> &result) {

    if (i == maze.size() - 1 && j == maze[i].size() - 1) {
        result.push_back(currPath);
        return;
    }

    maze[i][j] = 0;

    for (int k = 0; k < 4; k++) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];

        if (isSafe(new_i, new_j, maze)) {
            currPath.push_back(dir[k]);
            getPossiblePathsUtil(new_i, new_j, maze, currPath, result);
            currPath.pop_back();
        }
    }

    maze[i][j] = 1;
}

// TC: O(4 ^ (n^2))
// AS: O(n^2)
vector<string> getPossiblePaths(vector<vector<int>> maze) {

    string currPath = "";
    vector<string> result;
    getPossiblePathsUtil(0, 0, maze, currPath, result);
    return result;
}

int main() {

    vector<string> result = getPossiblePaths({{1, 0, 0, 0},
                                              {1, 1, 0, 1},
                                              {1, 1, 0, 0},
                                              {0, 1, 1, 1}});

    vector<string> result2 = getPossiblePaths({{1, 0, 0, 0},
                                              {1, 1, 0, 1},
                                              {1, 1, 0, 0},
                                              {0, 1, 1, 0}});

    vector<string> result3 = getPossiblePaths({{1, 1, 1},
                                              {1, 1, 1},
                                              {1, 1, 1}});

    
    cout << result.size() << endl;
    for (string path : result) {
        cout << path << " ";
    }
    cout << endl;

    cout << result2.size() << endl;
    for (string path : result2) {
        cout << path << " ";
    }
    cout << endl;

    cout << result3.size() << endl;
    int maxLen = 0;
    for (string path : result3) {
        cout << path << " ";
        if (path.length() > maxLen) {
            maxLen = maxLen = path.length();
        }
    }
    cout << maxLen << endl;
    cout << endl;
}