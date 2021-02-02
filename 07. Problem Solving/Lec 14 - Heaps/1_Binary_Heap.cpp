/*
    A Binary Heap is a Binary Tree with following properties:

    1. It’s a complete tree (All levels are completely filled
       except possibly the last level and the last level has
       all keys as left as possible). This property of Binary
       Heap makes them suitable to be stored in an array.

    2. A Binary Heap is either Min Heap or Max Heap. In a
       Min Binary Heap, the key at root must be minimum among
       all keys present in Binary Heap. The same property must
       be recursively true for all nodes in Binary Tree.

    A binary heap is typically represented as an array.

    The root element will be at Arr[0].
    For the ith node, i.e., Arr[i]:
    a) Arr[(i-1)/2]	Returns the parent node
    b) Arr[(2*i)+1]	Returns the left child node
    c) Arr[(2*i)+2]	Returns the right child node

    Operations on Min-Heap:
    1) getMin(): It returns the root element of Min Heap.
       Time Complexity of this operation is O(1).

    2) extractMin(): Removes the minimum element from MinHeap.
       Time Complexity of this Operation is O(Logn) as this
       operation needs to maintain the heap property
       (by calling heapify()) after removing root.

    3) decreaseKey(): Decreases value of key.
       Time complexity of this operation is O(Logn).
       If the decreases key value of a node is greater than
       the parent of the node, then we don’t need to do anything.
       Otherwise, we need to traverse up to fix the violated
       heap property.

    4) insert(): Inserting a new key takes O(Logn) time.
       We add a new key at the end of the tree. If new key is
       greater than its parent, then we don’t need to do anything.
       Otherwise, we need to traverse up to fix the violated
       heap property.

    5) delete(): Deleting a key also takes O(Logn) time. We
       replace the key to be deleted with minum infinite by
       calling decreaseKey(). After decreaseKey(), the minus
       infinite value must reach root, so we call
       extractMin() to remove the key.
*/

#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    int* arr;
    int capacity;
    int heap_size;
public:
    MinHeap(int capacity);
    void minHeapify (int);
    int parent(int i) { return (i-1)/2; }
    int left (int i) { return (2*i+1); }
    int right (int i) { return (2*i+2); }
    int extractMin();
    void decreaseKey (int i, int new_value);
    int getMin() { return arr[0]; }
    void deleteKey (int i);
    void insertKey (int k);
};

// Function Definitions
MinHeap :: MinHeap (int cap) {
    heap_size = 0;
    capacity = cap;
    arr = new int[cap];
}

void MinHeap::insertKey(int k) {
    if (heap_size == capacity) {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
    // Insert node key in the end
    heap_size++;
    int i = heap_size - 1;
    arr[i] = k;
    // Heapify if heap property is violated
    while (i != 0 && arr[parent(i)] > arr[i]) {
       swap(arr[i], arr[parent(i)]);
       i = parent(i);
    }
}

void MinHeap :: decreaseKey (int i, int new_value) {
    arr[i] = new_value;
    while (i != 0 && arr[parent(i)]>arr[i]) {
        swap (arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

int MinHeap :: extractMin () {
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1) {
        heap_size--;
        return arr[0];
    }
    int root = arr[0];
    arr[0] = arr[heap_size-1];
    heap_size--;
    minHeapify(0);

    return root;
}

void MinHeap :: deleteKey (int i) {
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap :: minHeapify (int i) {
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

/* --------------- MAIN DRIVER CODE ---------------- */
int main() {
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin() << endl;
    return 0;
}