#include<bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// AS: O(1)
int countDigitsFrom1ToN(int n) {

    int result = 0;
    for (int i = 1; i - 1 < n; i *= 10) {
        result += n - (i - 1);
    }

    return result;
}

int main() {
    cout << countDigitsFrom1ToN(1) << endl;
    cout << countDigitsFrom1ToN(25) << endl;
    cout << countDigitsFrom1ToN(100) << endl;
    cout << countDigitsFrom1ToN(99) << endl;
}