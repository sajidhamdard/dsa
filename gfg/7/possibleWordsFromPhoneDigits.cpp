#include<bits/stdc++.h>
using namespace std;

vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// TC: O(4^n)
// AS: O(n)
void getPossibleWordsUtil(int i, vector<int> &digits, string &currWord, vector<string> &result) {
    if (i == digits.size()) {
        result.push_back(currWord);
        return;
    }

    int digit = digits[i];

    for (char ch : keypad[digit]) {
        currWord.push_back(ch);
        getPossibleWordsUtil(i + 1, digits, currWord, result);
        currWord.pop_back();
    }
}

vector<string> getPossibleWords(vector<int> digits) {

    string currWord = "";
    vector<string> result;

    getPossibleWordsUtil(0, digits, currWord, result);
    return result;
}


int main() {

    vector<string> result = getPossibleWords({2, 3});
    for (string word : result) {
        cout << word << " ";
    }
}