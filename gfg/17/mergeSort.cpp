#include<bits/stdc++.h>
using namespace std;

void merge(int start, int mid, int end, vector<int> &arr) {

    int start1 = start;
    int end1 = mid;
    int start2 = mid + 1;
    int end2 = end;

    
    vector<int> temp;
    while (start1 <= end1 && start2 <= end2) {
        if (arr[start1] < arr[start2]) {
            temp.push_back(arr[start1]);
            start1++;
        } else {
            temp.push_back(arr[start2]);
            start2++;
        }
    }

    while (start1 <= end1) {
        temp.push_back(arr[start1]);
        start1++;
    }

    while (start2 <= end2) {
        temp.push_back(arr[start2]);
        start2++;
    }

    for (int i = 0; i < temp.size(); i++) {
        arr[start + i] = temp[i];
    }
}

void mergeSortUtil(int start, int end, vector<int> &arr) {
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;

    mergeSortUtil(start, mid, arr);
    mergeSortUtil(mid + 1, end, arr);

    merge(start, mid, end, arr);
}

// TC: O(n * log(n))
// AS: O(n)
void mergeSort(vector<int> &arr) {

    return mergeSortUtil(0, arr.size() - 1, arr);
}

int main() {

    vector<int> arr = {2, 3, 5, 7, 1, 6, 8, 9};
    mergeSort(arr);

    for (int i : arr) {
        cout << i << " ";
    }
}