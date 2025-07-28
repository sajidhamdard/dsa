#include<bits/stdc++.h>
using namespace std;

// TC: O(n + maxx)
// AS: O(maxx)
int maxInNRanges(vector<int> L, vector<int> R) {
    int n = L.size();
    
    int maxx = R[0];
    for (int i = 1; i < n; i++) { // O(n)
        maxx = max(maxx, R[i]);
    }

    vector<int> freq(maxx + 2, 0);
    for (int i = 0; i < n; i++) { // O(n)
        freq[L[i]]++;
        freq[R[i] + 1]--;
    }

    int result = 0;
    for (int i = 1; i < freq.size(); i++) { // O(maxx)
        freq[i] += freq[i - 1];
        if (freq[i] > freq[result]) {
            result = i;
        }
    }

    return result;
}

int main() {
    cout << maxInNRanges({2, 1, 3}, {5, 4, 9}) << endl;
}