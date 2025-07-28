#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
bool checkIfSumExists(vector<int> arr, int target) {

    int left = 0;
    int right = arr.size() - 1;

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

int main() {
    
    cout << checkIfSumExists({1, 2, 5, 6, 10}, 8) << endl;
    cout << checkIfSumExists({1, 2, 5, 6, 10}, 9) << endl;
    cout << checkIfSumExists({1, 2, 5, 6, 10}, 10) << endl;
    cout << checkIfSumExists({1, 2, 5, 5, 6, 10}, 10) << endl;
    cout << checkIfSumExists({1}, 2) << endl;
    cout << checkIfSumExists({1}, 1) << endl;
}