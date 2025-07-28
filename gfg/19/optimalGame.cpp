#include<bits/stdc++.h>
using namespace std;

// TC: O(4^n) -> O(n^2)
// AS: O(n) -> O(n^2)
int getMaxScoreUtil(int i, int j, vector<int> &coins, vector<vector<int>> &memo) {
    if (i > j) {
        return 0;
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    int case1 = coins[i] + min(getMaxScoreUtil(i + 2, j, coins, memo), getMaxScoreUtil(i + 1, j - 1, coins, memo));
    int case2 = coins[j] + min(getMaxScoreUtil(i + 1, j - 1, coins, memo), getMaxScoreUtil(i, j - 2, coins, memo));

    memo[i][j] = max(case1, case2);
    return max(case1, case2);
}

int getMaxScore(vector<int> coins) {
    int n = coins.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return getMaxScoreUtil(0, coins.size() - 1, coins, memo);
}

int main() {

    cout << getMaxScore({5, 3, 7, 10}) << endl;
    cout << getMaxScore({5, 3, 70, 10}) << endl;
}