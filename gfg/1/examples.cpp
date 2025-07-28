// TC: O(A + B)

for (int i = 0; i < A.size(); i++) { 
    cout << A[i] << endl;
}
for (int i = 0; i < B.size(); i++) { 
    cout << B[i] << endl;
}

// ---------------------------------------------------

// TC: O(AB)
for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < B.size(); j++) {
        cout << A[i] + B[j] << endl;
    }
}

// ---------------------------------------------------

// TC: O(n^2)
void func(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << i + j << endl;
        }
    }
}

// ---------------------------------------------------

// TC: O(n^2 * len(s))
void func(int n, string s) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << s << endl;
        }
    }
}

// ---------------------------------------------------

// AS: O(n)
// Input Space: O(m^2)
// Output Space: O(k)
// SC: O(n + m^2 + k)
vector<int> func(vector<vector<int>> arr) { // arr: m^2, output: k
    // ....
    vector<int> temp(n);
    // ....

    vector<int> result;
    // ....
    return result;
}

// ---------------------------------------------------

// Input Space: O(m * len)
// Output Space: O(len)
// AS: O(n * len)
// SC: O(len * (n + m))
string func(vector<string> arr) { // arr: m
    // ...
    vector<string> temp(n);

    // ...
    return result;
}