/*  PROBLEM:
    Given an array and a number k where k is smaller
    than size of array, we need to find the k’th smallest
    element in the given array. It is given that all array
    elements are distinct.

    SOLUTION:
    We can find k’th smallest element in time complexity
    better than O(N*Log N) viz. achieved by sorting.
    A simple optomization is to create a Min Heap of the
    given n elements and call extractMin() k times.
*/

#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    int* arr;
    int capacity;
    int heap_size;
public:
    MinHeap(int a[], int size);
    void minHeapify(int i);
    int parent (int i)  { return (i-1)/2; }
    int left (int i) { return (2*i+1); }
    int right (int i) { return (2*i+2); }
    int extractMin();
    int getMin() { return arr[0]; }
};

MinHeap::MinHeap(int a[], int size) {
    heap_size = size;
    arr = a;
    int i = (heap_size - 1)/2;
    while (i >= 0) {
        minHeapify(i);
        i--;
    }
}

int MinHeap::extractMin() {
    if (heap_size == 0)
        return INT_MAX;

    int root = arr[0];

    if (heap_size > 1) {
        arr[0] = arr[heap_size-1];
        minHeapify(0);
    }
    heap_size--;

    return root;
}

void MinHeap :: minHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && arr[l] < arr[i])
        smallest = l;
    if (r < heap_size && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(smallest);
    }
}

// Main Function
int kthSmallest(int arr[], int n, int k) {
    MinHeap heap(arr, n);
    for (int i=0; i<k-1; i++)
        heap.extractMin();
    return heap.getMin();
}

/* ------------------- MAIN DRIVER CODE --------------------- */
int main() {
    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr)/sizeof(arr[0]), k = 2;
    cout << "K'th smallest element is " << kthSmallest(arr, n, k) << endl;
    return 0;
}