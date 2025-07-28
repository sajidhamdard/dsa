#include<bits/stdc++.h>
using namespace std;

// TC: O(n * log(k))
// AS: O(k)
int kthLargestElement(vector<int> arr, int k) {
    int n = arr.size();

    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap

    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++) {
        // If arr[i] > smallest of k-largest elements, then arr[i] becomes a part
        // of the top-k elements.
        if (arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}


int main() {
    
    cout << kthLargestElement({3, 5, 4, 2, 9}, 3) << endl;
    cout << kthLargestElement({3, 5, 4, 2, 9}, 1) << endl;
    cout << kthLargestElement({3, 5, 4, 2, 9}, 5) << endl;
}