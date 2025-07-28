#include<bits/stdc++.h>
using namespace std;

// Recursion -> Memoized
// TC: O(2^n) -> O(n*W) 
// AS: O(n) -> O(n*W) 
int getMaxValueUtil(int i, vector<int> &vals, vector<int> &wts, int W, vector<vector<int>> &memo) {
    if (i == vals.size() || W == 0) {
        return 0;
    }
    if (memo[i][W] != -1) {
        return memo[i][W];
    }

    // Exclude the current item from the knapsack.
    int result = getMaxValueUtil(i + 1, vals, wts, W, memo);

    // Include the current item in the knapsack, if possible.
    if (wts[i] <= W) {
        result = max(result, vals[i] + getMaxValueUtil(i + 1, vals, wts, W - wts[i], memo));
    }

    memo[i][W] = result;
    return result;
}

int getMaxValue(vector<int> vals, vector<int> wts, int W) {
    // memo -> n x (W+1)
    int n = vals.size();
    vector<vector<int>> memo(n, vector<int> (W + 1, -1));
    int result = getMaxValueUtil(0, vals, wts, W, memo);

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= W; j++) {
    //         cout << memo[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return result;
}

int main() {

    cout << getMaxValue({60, 100, 120}, {10, 20, 30}, 50) << endl;
    cout << getMaxValue({60, 100, 120}, {10, 20, 50}, 50) << endl;
}