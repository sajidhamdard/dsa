#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int removeDuplicatesInPlace(vector<int> &arr) {
    int n = arr.size();

    int i = 0, j = 0;
    while (j < n) {
        arr[i] = arr[j];

        while (j < n && arr[j] == arr[i]) {
            j++;
        }
        i++;
    }

    return i;
}

int main() {
    vector<int> arr = {1, 1, 2, 3, 3, 4, 5, 5};
    int res = removeDuplicatesInPlace(arr);
    
    for (int i = 0; i < res; i++) {
        cout << arr[i] << " ";
    }
}