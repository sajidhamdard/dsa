#include<bits/stdc++.h>
using namespace std;

int fib(int n) {
    // Base case
    if (n <= 1) {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

int main() {
    cout << fib(10) << endl;
}