#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
int maxSumOfAnySubarray(vector<int> arr) {
    int n = arr.size();

    vector<int> maxSum(n);

    int result = arr[0];
    maxSum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        maxSum[i] = max(arr[i], maxSum[i - 1] + arr[i]);
        result = max(result, maxSum[i]);
    }

    return result;
}

// TC: O(n)
// AS: O(1)
int maxSumOfAnySubarrayWithoutExtraSpace(vector<int> arr) {
    int n = arr.size();

    int result = arr[0];
    int maxTillPrev = arr[0];
    for (int i = 1; i < n; i++) {
        maxTillPrev = max(arr[i], maxTillPrev + arr[i]);
        result = max(result, maxTillPrev);
    }

    return result;
}

int main() {
    cout << maxSumOfAnySubarrayWithoutExtraSpace({1, 2, 3, -2, 5}) << endl;
    cout << maxSumOfAnySubarrayWithoutExtraSpace({-1, -2, -3}) << endl;
    cout << maxSumOfAnySubarrayWithoutExtraSpace({1, 2, 3, 2, 5}) << endl;
    cout << maxSumOfAnySubarrayWithoutExtraSpace({-1, 2, 3, -2, -5}) << endl;
}