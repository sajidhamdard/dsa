#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
long long int countSubarraysWithEqual0sAnd1s(vector<int> arr) {

    long long int res = 0;
    int n = arr.size();

    unordered_map<int, long long int> sumFreq;

    int sum = 0;

    sumFreq[0] = 1;
    for (int i = 0; i < n; i++) {
        sum += (arr[i] == 1 ? +1 : -1);
        res += sumFreq[sum];

        sumFreq[sum]++;
    }

    return res;
}

int main() {
    
    cout << countSubarraysWithEqual0sAnd1s({1, 0, 0, 1, 0, 1, 1}) << endl;
    cout << countSubarraysWithEqual0sAnd1s({1, 1, 1, 1, 1, 1, 1}) << endl;
    cout << countSubarraysWithEqual0sAnd1s({0, 0, 0}) << endl;
    cout << countSubarraysWithEqual0sAnd1s({0, 1, 1, 1, 1}) << endl;
}