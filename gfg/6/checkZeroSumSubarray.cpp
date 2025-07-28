#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
bool checkZeroSumSubarray(vector<int> arr) {

    int sum = 0;
    unordered_set<int> sums;
    sums.insert(0);

    int n = arr.size();
    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sums.find(sum) != sums.end()) {
            return true;
        }

        sums.insert(sum);
    }

    return false;
}

int main() {

    cout << checkZeroSumSubarray({4, 2, -3, 1, 6}) << endl;
    cout << checkZeroSumSubarray({4, 2, 0, 1, 6}) << endl;
    cout << checkZeroSumSubarray({4, 2, -3, 1, -4}) << endl;
    cout << checkZeroSumSubarray({4, -4, 3, 4, 6}) << endl;
    cout << checkZeroSumSubarray({4, 2, 3, -6, 6}) << endl;
    cout << checkZeroSumSubarray({4, 2, 3, 6, 6}) << endl;
    
}