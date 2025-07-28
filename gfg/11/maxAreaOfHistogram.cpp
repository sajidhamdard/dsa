#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElements(vector<int> arr) {
    int n = arr.size();
    stack<int> s;
    vector<int> result(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            result[i] = n;
        } else {
            result[i] = s.top();
        }

        s.push(i);
    }

    return result;
}

vector<int> prevSmallerElements(vector<int> arr) {
    int n = arr.size();
    stack<int> s;
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top();
        }

        s.push(i);
    }

    return result;
}

// TC: O(n)
// AS: O(n)
int maxHistogramArea(vector<int> bars) {

    vector<int> nextSmaller = nextSmallerElements(bars);
    vector<int> prevSmaller = prevSmallerElements(bars);

    int maxArea = 0;
    for (int i = 0; i < bars.size(); i++) {
        int height = bars[i];
        int width = nextSmaller[i] - prevSmaller[i] - 1;

        maxArea = max(maxArea, height * width);
    }

    return maxArea;
}

int main() {
    cout << maxHistogramArea({6, 2, 5, 4, 5, 1, 6}) << endl;
}