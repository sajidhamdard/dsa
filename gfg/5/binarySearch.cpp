#include<bits/stdc++.h>
using namespace std;

// TC: O(log(n))
// AS: O(1)
int binarySearch(vector<int> arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (target > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {

    cout << binarySearch({1, 3, 5, 9, 100, 250, 500}, 250) << endl;
    cout << binarySearch({1, 3, 5, 9, 100, 250, 500}, 1) << endl;
    cout << binarySearch({1, 3, 5, 9, 100, 250, 500}, 500) << endl;
    cout << binarySearch({1, 3, 5, 9, 100, 250, 500}, 300) << endl;
    cout << binarySearch({1, 3, 5, 9, 100, 250, 500}, 0) << endl;
    cout << binarySearch({1, 3, 5, 9, 100, 250, 500}, 10000) << endl;
}