#include<bits/stdc++.h>
using namespace std;

// Assume value <= 1e4

// TC: O(2 ^ max(n, value)) -> O(n * value)
// AS: O(max(n, value)) -> O(n * value)
int getMinCoinsUtil(int i, vector<int> &coins, int value, vector<vector<int>> &memo) {
    if (value == 0) {
        return 0;
    }
    if (i == coins.size()) {
        return 1e5;
    }
    if (memo[i][value] != -1) {
        return memo[i][value];
    }

    // Exclude.
    int result = getMinCoinsUtil(i + 1, coins, value, memo);

    // Include, if possible.
    if (coins[i] <= value) {
        result = min(result, 1 + getMinCoinsUtil(i, coins, value - coins[i], memo));
    }

    memo[i][value] = result;
    return result;
}

int getMinCoins(vector<int> coins, int value) {
    vector<vector<int>> memo(coins.size(), vector<int> (value + 1, -1));

    int result = getMinCoinsUtil(0, coins, value, memo);
    if (result >= 1e5) {
        return -1;
    }
    return result;
}

int main() {

    cout << getMinCoins({3, 6, 3}, 5) << endl;
    cout << getMinCoins({2, 5, 3, 6}, 10) << endl;
    cout << getMinCoins({1, 2, 5, 3, 6}, 10) << endl;
}