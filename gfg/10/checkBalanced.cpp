#include<bits/stdc++.h>
using namespace std;


bool isMatch(char cl, char op) {
    return 
        (op == '(' && cl == ')') ||
        (op == '{' && cl == '}') ||
        (op == '[' && cl == ']');
}

// TC: O(n)
// AS: O(n)
bool isBalanced(string s) {

    stack<char> openingBraces;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            openingBraces.push(s[i]);
        } else {
            if (openingBraces.empty() || !isMatch(s[i], openingBraces.top())) {
                return false;
            }
            openingBraces.pop();
        }
    }

    // if (!openingBraces.empty()) {
    //     return false;
    // }
    // return true;

    return openingBraces.empty();
}

int main() {

    cout << isBalanced("({[]})") << endl;
    cout << isBalanced("({[]})()") << endl;

    cout << isBalanced("({[]})(") << endl;
    cout << isBalanced(")({[]})") << endl;
    cout << isBalanced("({[}])") << endl;
}