#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
vector<int> productExceptSelf(vector<int> arr) {

    int n = arr.size();
    // vector<int> prefProd(n); 
    vector<int> suffProd(n);

    // prefProd[0] = 1;
    // for (int i = 1; i < n; i++) {
    //     prefProd[i] = prefProd[i - 1] * arr[i - 1]; 
    // }

    suffProd[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        suffProd[i] = suffProd[i + 1] * arr[i + 1]; 
    }

    vector<int> ans(n);
    ans[0] = suffProd[0];
    int prefProd = 1;
    for (int i = 1; i < n; i++) {
        prefProd = prefProd * arr[i - 1];
        ans[i] = prefProd * suffProd[i]; 
    }

    return ans;
}

int main() {
    
}