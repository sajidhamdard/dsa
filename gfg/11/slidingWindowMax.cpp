#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(k)
vector<int> slidingWindowMax(vector<int> arr, int k) {
    int n = arr.size();
    if (k == 1) {
        return arr;
    }

    vector<int> res;
    deque<int> dq;

    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    res.push_back(arr[dq.front()]);

    for (int i = k; i < n; i++) {
        if (dq.front() <= i - k) {
            dq.pop_front();
        }
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);

        res.push_back(arr[dq.front()]);
    }

    return res;
}

int main() {
}