#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
string firstNonRepInStream(string s) {
    int n = s.length();

    vector<int> freq(26, 0);
    queue<char> q;

    string res = "";

    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
        if (freq[s[i] - 'a'] == 1) {
            q.push(s[i]);
        }

        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty()) {
            res.push_back('#');
        } else {
            res.push_back(q.front());
        }
    }

    return res;
}

int main() {
    cout << firstNonRepInStream("aabc") << endl;
    cout << firstNonRepInStream("bcbdcd") << endl;
    cout << firstNonRepInStream("aaaa") << endl;
    cout << firstNonRepInStream("abcd") << endl;
    cout << firstNonRepInStream("a") << endl;
}