#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n * log(n)) -> TODO: Optimize to O(1) by using res as the queue.
vector<string> generateFirstNBinaryNumbers(int n) {

    queue<string> q;
    vector<string> res;

    q.push("1");
    int inserts = 1;

    while (inserts < n) {
        string curr = q.front();
        q.pop();

        res.push_back(curr);

        q.push(curr + "0");
        q.push(curr + "1");
        inserts += 2;
    }

    while (res.size() != n) {
        string curr = q.front();
        q.pop();

        res.push_back(curr);
    }

    return res;
}

int main() {

    vector<string> res = generateFirstNBinaryNumbers(11);
    for (string i : res) {
        cout << i << endl;
    }
}