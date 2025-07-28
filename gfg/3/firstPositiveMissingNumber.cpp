#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int firstPositiveMissingNumber(vector<int> arr) {

    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] <= 0) {
            arr[i] = n + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        // Register the occurrence of abs(arr[i]) if its in range [1, n].
        if (abs(arr[i]) <= n) {
            int bucketIndex = abs(arr[i]) - 1;
            if (arr[bucketIndex] > 0) {
                arr[bucketIndex] *= -1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            return i + 1;
        }
    }

    return n + 1;
}

int main() {
    
    cout << firstPositiveMissingNumber({1, 2, 3, 4, 5}) << endl;
    cout << firstPositiveMissingNumber({0, -10, 1, 3, -20}) << endl;
    cout << firstPositiveMissingNumber({2, 5, 3, 2, 4, 1, 7}) << endl;
}