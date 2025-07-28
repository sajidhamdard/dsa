#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int longestSubstrWithDistinctChars(string s) {

    vector<bool> isPresent(26, false);

    int n = s.length();
    int result = 0;
    
    int left = 0, right = 0;
    while (right < n) {
        if (!isPresent[s[right] - 'a']) {
            isPresent[s[right] - 'a'] = true;
            result = max(result, right - left + 1);
        } else {
            while (s[left] != s[right]) {
                isPresent[s[left] - 'a'] = false;
                left++;
            }
            left++;
        }
        right++;
    }

    return result;
}

int main() {
    cout << longestSubstrWithDistinctChars("geeksforgeeks") << endl;
    cout << longestSubstrWithDistinctChars("aaaa") << endl;
    cout << longestSubstrWithDistinctChars("geforegkse") << endl;
}