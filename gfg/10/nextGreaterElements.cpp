#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
vector<int> nextGreaterElements(vector<int> arr) {
    int n = arr.size();
    stack<int> s;
    vector<int> result(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top();
        }

        s.push(arr[i]);
    }

    return result;
}


int main() {
    vector<int> res1 = nextGreaterElements({5, 3, 6, 4, 2, 3, 9, 10});
    vector<int> res2 = nextGreaterElements({1, 2, 3, 4});
    vector<int> res3 = nextGreaterElements({4, 3, 2, 1});
    vector<int> res4 = nextGreaterElements({5, 4, 3, 2, 1, 10});

    for (int i : res1) {
        cout << i << " ";
    }
    cout << endl;

    for (int i : res2) {
        cout << i << " ";
    }
    cout << endl;

    for (int i : res3) {
        cout << i << " ";
    }
    cout << endl;

    for (int i : res4) {
        cout << i << " ";
    }
    cout << endl;
}