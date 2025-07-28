#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
void reverse(queue<int> &q) {
    if (q.empty()) {
        return;
    }

    int a = q.front();
    q.pop();

    reverse(q);

    q.push(a);
}

int main() {

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    reverse(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}