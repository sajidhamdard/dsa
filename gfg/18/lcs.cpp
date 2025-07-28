#include<bits/stdc++.h>
using namespace std;

int lcsUtil(string &s1, int i, string &s2, int j, vector<vector<int>> &memo) {
    if (i == s1.length() || j == s2.length()) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    if (s1[i] == s2[j]) {
        memo[i][j] = 1 + lcsUtil(s1, i + 1, s2, j + 1, memo);
        return memo[i][j];
    }

    memo[i][j] = max(lcsUtil(s1, i + 1, s2, j, memo), lcsUtil(s1, i, s2, j + 1, memo));
    return memo[i][j];
}

// TC: O(nm)
// AS: O(nm)
int lcs(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> memo(n, vector<int>(m, -1));
    return lcsUtil(s1, 0, s2, 0, memo);
}

// TC: O(nm)
// AS: O(nm)
int lcsBottomUp(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // Accommodate the base cases.
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    
    cout << lcs("abcdgh", "aedfhr") << endl;
    cout << lcs("abc", "ac") << endl;

    cout << lcsBottomUp("abcdgh", "aedfhr") << endl;
    cout << lcsBottomUp("abc", "ac") << endl;
}