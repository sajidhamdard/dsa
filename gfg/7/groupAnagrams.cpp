#include<bits/stdc++.h>
using namespace std;

string createHashKey(string s) {

    vector<int> freq(26, 0);
    for (char ch : s) {
        freq[ch - 'a']++;
    }

    string result = "";
    for (int i = 0; i < 26; i++) {
        result += to_string(freq[i]);
        result += "#";
    }

    return result;
}

// TC: O(n * k), where k = maxLen
// AS: O(n * k)
// TODO: Optimize the AS to O(n) by storing unordered_map<string, vector<int>>
vector<vector<string>> groupAnagrams(vector<string> arr) {

    int n = arr.size();

    unordered_map<string, vector<string>> anagrams;

    for (int i = 0; i < n; i++) {
        string key = createHashKey(arr[i]);

        if (anagrams.find(key) == anagrams.end()) {
            anagrams[key] = {};
        }

        anagrams[key].push_back(arr[i]);
    }

    vector<vector<string>> result;

    // Pushing all the values in the result.
    for (auto i : anagrams) {
        result.push_back(i.second);
    }
    return result;
}

int main() {

    vector<vector<string>> res = groupAnagrams({"act", "dog", "cat", "god", "tac"});
    for (vector<string> list : res) {
        for (string i : list) {
            cout << i << " ";
        }
        cout << endl;
    }
}