#include<bits/stdc++.h>
using namespace std;

bool isAlphaNumeric(char ch) {
    return (ch >= 'A' && ch <= 'Z') || 
            (ch >= 'a' && ch <= 'z') || 
            (ch >= '0' && ch <= '9');
}

bool isSame(char a, char b) {
    // if (a == b) {
    //     return true;
    // }

    // if (a - 'a' + 'A' == b) {
    //     return true;
    // }
    // if (a - 'A' + 'a' == b) {
    //     return true;
    // }

    return (a == b) || 
            (a - 'a' + 'A' == b) || 
            (a - 'A' + 'a' == b);
}

// TC: O(n)
// AS: O(1)
bool isSpecialPalindrome(string s) {

    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (!isAlphaNumeric(s[i])) {
            i++;
        }
        else if (!isAlphaNumeric(s[j])) {
            j--;
        } 
        else {
            if (!isSame(s[i], s[j])) {
                return false;
            }
            i++;
            j--;
        }
    }

    return true;
}

int main() {
    cout << isSpecialPalindrome("level") << endl;
    cout << isSpecialPalindrome("levels") << endl;
    cout << isSpecialPalindrome("race a car") << endl;
    cout << isSpecialPalindrome("A man: nama") << endl;
}