#include<bits/stdc++.h>
using namespace std;

int getFirstOcc(vector<int> arr, int target) {
    int low = 0, high = arr.size() - 1;

    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            result = mid;
            high = mid - 1;
        }
        else if (target > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int getLastOcc(vector<int> arr, int target) {
    int low = 0, high = arr.size() - 1;

    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            result = mid;
            low = mid + 1;
        }
        else if (target > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

// TC: O(log(n))
// AS: O(1)
vector<int> findFirstAndLastOcc(vector<int> arr, int target) {
    
    int firstOcc = getFirstOcc(arr, target);
    if (firstOcc == -1) {
        return {-1, -1};
    }

    return {firstOcc, getLastOcc(arr, target)};
}

int main() {

    vector<int> res = findFirstAndLastOcc({1, 3, 5, 5, 5, 5, 67, 123, 125}, 5);
    vector<int> res2 = findFirstAndLastOcc({1, 3, 5, 5, 5, 5, 67, 123, 125}, 123);
    vector<int> res3 = findFirstAndLastOcc({5, 5, 5, 5}, 5);
    vector<int> res4 = findFirstAndLastOcc({1, 3, 5, 5, 5, 5, 67, 123, 125}, 68);

    cout << res[0] << " " << res[1] << endl;
    cout << res2[0] << " " << res2[1] << endl;
    cout << res3[0] << " " << res3[1] << endl;
    cout << res4[0] << " " << res4[1] << endl;
}