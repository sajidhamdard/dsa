#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
vector<int> removeDuplicates(vector<int> arr) {
    int n = arr.size();

    vector<int> result;
    result.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            result.push_back(arr[i]);
        }
    }

    return result;
}

int main() {
    vector<int> res = removeDuplicates({1, 1, 2, 3, 3, 4, 5, 5});
    for (int i : res) {
        cout << i << " ";
    }
}