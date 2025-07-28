#include<bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// AS: O(1)
int sqrtOfN(int n) {

    int low = 1, high = n/2 + 1;

    int result = high;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (mid * mid == n) {
            return mid;
        }
        if (mid * mid < n) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    cout << sqrtOfN(1) << endl;
    cout << sqrtOfN(25) << endl;
    cout << sqrtOfN(30) << endl;
}