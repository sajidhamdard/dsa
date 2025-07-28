#include<bits/stdc++.h>
using namespace std;

// TC: O(k^2 * log(k))
// AS: O(k)
vector<int> mergeKSortedArrays(vector<vector<int>> arr) {
    int k = arr.size();

    priority_queue<pair<int, pair<int, int>>> pq; // {-val, {i, j}}

    for (int i = 0; i < k; i++) {
        pq.push({-arr[i][0], {i, 0}});
    }

    vector<int> result;
    while (!pq.empty()) {
        pair<int, pair<int, int>> curr = pq.top();
        pq.pop();

        int val = -curr.first;
        int i = curr.second.first;
        int j = curr.second.second;

        result.push_back(val);
        if (j + 1 < k) {
            pq.push({-arr[i][j + 1], {i, j + 1}});
        }
    }

    return result;
}

int main() {

    vector<int> result = mergeKSortedArrays({{1, 2, 5, 6},
                                            {3, 4, 7, 8},
                                            {1, 3, 4, 4},
                                            {9, 10, 11, 12}});
    
    for (int i : result) {
        cout << i << " ";
    }
}