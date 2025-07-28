#include<bits/stdc++.h>
using namespace std;

// TC: O(2 ^ max(n, target))
// AS: O(max(n, target))
void combinationSumUtil(int i, int target, vector<int> &arr, 
                        vector<int> &currCombination, vector<vector<int>> &result) {

    if (target == 0) {
        result.push_back(currCombination);
        return;
    }
    if (i == arr.size()) {
        return;
    }

    // Possibility-1: Consider arr[i], if possible
    if (arr[i] <= target) {
        currCombination.push_back(arr[i]);
        combinationSumUtil(i, target - arr[i], arr, currCombination, result);
        currCombination.pop_back();
    }

    // Possibility-2: Skip arr[i]
    combinationSumUtil(i + 1, target, arr, currCombination, result);
}

vector<vector<int>> combinationSum(vector<int> arr, int target) {

    vector<vector<int>> result;
    vector<int> currCombination;

    combinationSumUtil(0, target, arr, currCombination, result);
    return result;
}

int main() {
    vector<vector<int>> res = combinationSum({2, 4, 6, 8}, 8);
    vector<vector<int>> res2 = combinationSum({2, 4, 6, 8}, 9);

    for (auto i : res) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    for (auto i : res2) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}