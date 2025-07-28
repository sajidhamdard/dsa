#include<bits/stdc++.h>
using namespace std;


// class PQ {
// private:
//     vector<int> arr;
// public:
//     push();
//     pop();
//     get();
//     empty();
// }

void print(vector<int> &heap) {
    for (int i : heap) {
        cout << i << " ";
    }
    cout << endl;
}

void topDownHeapify(vector<int> &heap, int index) {

    int leftChildIndex = 2*index + 1;
    int rightChildIndex = 2*index + 2;

    int maxValIndex = index;
    if (leftChildIndex < heap.size() && heap[leftChildIndex] > heap[maxValIndex]) {
        maxValIndex = leftChildIndex;
    }
    if (rightChildIndex < heap.size() && heap[rightChildIndex] > heap[maxValIndex]) {
        maxValIndex = rightChildIndex;
    }

    if (maxValIndex != index) {
        swap(heap[index], heap[maxValIndex]);
        topDownHeapify(heap, maxValIndex);
    }
}

// TC: O(log(n))
// AS: O(1) -> tail recursion
void deleteFromHeap(vector<int> &heap) {
    if (heap.size() == 0) {
        return;
    }

    heap[0] = heap[heap.size() - 1];
    heap.pop_back();

    topDownHeapify(heap, 0);
}

void bottomUpHeapify(vector<int> &heap, int index) {

    int parentIndex = (index - 1) / 2;

    if (parentIndex >= 0 && heap[index] > heap[parentIndex]) {
        swap(heap[index], heap[parentIndex]);
        bottomUpHeapify(heap, parentIndex);
    }
}

// TC: O(log(n))
// AS: O(1) -> tail recursion
void insert(vector<int> &heap, int val) {

    heap.push_back(val);
    bottomUpHeapify(heap, heap.size() - 1);
}

int main() {

    vector<int> heap = {10, 5, 3, 2, 4};
    deleteFromHeap(heap);

    print(heap);

    heap = {100, 30, 50, 24, 25, 44, 40, 20};
    insert(heap, 37);

    print(heap);
}