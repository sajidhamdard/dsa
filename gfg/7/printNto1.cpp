#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1) as its tail recursion
void printNto1(int n) {
    if (n <= 0) {
        return;
    }

    cout << n << endl;
    printNto1(n - 1);
}

int main() {
    
    printNto1(10);
}