#include<bits/stdc++.h>
using namespace std;

// Checks if an allocation is possible such that no student
// receives more than `mid` number of pages.
bool isPossible(vector<int> &pages, int M, int mid) {

    // [10, 20, 10, 30] mid = 39
    int studentCount = 1, pagesAllocated = 0;
    for (int i = 0; i < pages.size(); i++) {
        if (pagesAllocated + pages[i] <= mid) {
            pagesAllocated += pages[i];
        } else {
            studentCount++;
            pagesAllocated = pages[i];
        }
    }

    return studentCount <= M;
}

// TC: O(n * log(sum))
// AS: O(1)
int pageAllocation(vector<int> pages, int M) {
    int n = pages.size();
    
    if (n < M) {
        return -1;
    }

    int low = pages[0], high = pages[0];
    for (int i = 1; i < n; i++) {
        low = max(low, pages[i]);
        high += pages[i];
    }

    int result = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(pages, M, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    cout << pageAllocation({12, 34, 67, 90}, 2) << endl;
    cout << pageAllocation({10, 20, 10, 30}, 2) << endl;
    cout << pageAllocation({10, 20, 10, 30}, 4) << endl;
    cout << pageAllocation({10, 20, 10, 30}, 1) << endl;
    cout << pageAllocation({10, 20, 10, 30}, 5) << endl;
}