#include<bits/stdc++.h>
using namespace std;

bool checkIfSumPairExists(vector<int> arr, int target, int left, int right) {

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            return true;
        }
        if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return false;
}

// TC: O(n^2)
// AS: O(1)
bool checkIfTripletSumExists(vector<int> arr, int target) {

    sort(arr.begin(), arr.end());
    
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int newTarget = target - arr[i];

        // Using 2-ptr technique to find a pair with sum = newTarget.
        if (checkIfSumPairExists(arr, newTarget, i + 1, n - 1)) {
            return true;
        }
    }

    return false;
}

bool checkIfQuadrupleSumExists(vector<int> arr, int target) {

    sort(arr.begin(), arr.end());
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int newTarget = target - arr[i] - arr[j];

            // Using 2-ptr technique to find a pair with sum = newTarget.
            if (checkIfSumPairExists(arr, newTarget, i + 1, n - 1)) {
                return true;
            }
        }
    }
}

int main() {
    cout << checkIfTripletSumExists({1, 4, 45, 6, 10, 8}, 13) << endl;
    cout << checkIfTripletSumExists({1, 4, 45, 6, 10, 8}, 30) << endl;
    cout << checkIfTripletSumExists({1, 4, 45, 6, 10, 8}, 26) << endl;
    cout << checkIfTripletSumExists({1}, 3) << endl;
}