#include<bits/stdc++.h>
using namespace std;

// TC: O(n * log(n))
// AS: O(n)
double getMaxValue(int W, vector<int> vals, vector<int> wts) {

    int n = vals.size();
    vector<pair<double, int>> unitValByWt;
    for (int i = 0; i < n; i++) {
        unitValByWt.push_back({((double)vals[i]) / wts[i], wts[i]});
    }

    sort(unitValByWt.begin(), unitValByWt.end());

    double value = 0;
    for (int i = n - 1; i >= 0; i--) {
        double unitVal = unitValByWt[i].first;
        int wt = unitValByWt[i].second;

        if (wt <= W) {
            value += unitVal * wt;
            W -= wt;
        } else {
            value += unitVal * W;
            W = 0;
            break;
        }
    }

    return value;
}

int main() {

}