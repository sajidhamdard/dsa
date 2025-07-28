#include<bits/stdc++.h>
using namespace std;

// TC: O(n * m)
// AS: O(1)
void makeMatrixZeros(vector<vector<int>> &arr) {
    int n = arr.size();
    int m = arr[0].size();

    bool firstRowZero = false;
    bool firstColZero = false;

    for (int i = 0; i < n; i++) {
        if (arr[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }
    for (int j = 0; j < m; j++) {
        if (arr[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 0) {
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }
    }

   for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][0] == 0 || arr[0][j] == 0) {
                arr[i][j] = 0;
            }
        } 
    }

    if (firstColZero) {
        for (int i = 0; i < n; i++) {
            arr[i][0] = 0;
        }
    }
    if (firstRowZero) {
        for (int j = 0; j < m; j++) {
            arr[0][j] = 0;
        }
    }
}

int main() {
    vector<vector<int>> arr = {
                                {1, 1, 1, 1, 1},
                                {1, 1, 0, 0, 1}, 
                                {1, 0, 1, 1, 1},
                                {0, 1, 1, 1, 1}
                            };


    makeMatrixZeros(arr);

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}