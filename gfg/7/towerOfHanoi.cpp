#include<bits/stdc++.h>
using namespace std;

int towerOfHanoiUtil(int n, string A, string C, string B) {
    if (n == 0) {
        return 0;
    }

    int result = towerOfHanoiUtil(n - 1, A, B, C);
    cout << "Move " << n << "-th Disk from " << A << " to " << C << endl; 
    result++; // Moving the n-th disk from A to C.
    result += towerOfHanoiUtil(n - 1, B, C, A);

    return result;
}

// TC: O(2^n)
// AS: O(n)
int towerOfHanoi(int n) {
    return towerOfHanoiUtil(n, "A", "C", "B");
}

// TC: O(n)
// AS: O(n)
int towerOfHanoiWithoutVisuals(int n) {
    if (n == 0) {
        return 0;
    }

    return 2*towerOfHanoiWithoutVisuals(n - 1) + 1;
}

int main() {
    
    cout << towerOfHanoiWithoutVisuals(2) << endl;
    cout << towerOfHanoiWithoutVisuals(3) << endl;
}