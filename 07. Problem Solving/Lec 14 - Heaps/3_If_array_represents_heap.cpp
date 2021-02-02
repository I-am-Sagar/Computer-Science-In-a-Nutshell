/*  PROBLEM:
    Given an array, how to check if the given array
    represents a Binary Max-Heap.

    SOLUTION:
    The idea is to compare root only with its children
    (not all descendants), if root is greater than its
    children and the same is true for all nodes, then
    tree is max-heap (This conclusion is based on transitive
    property of > operator, i.e., if x > y and y > z, then x > z).
*/

#include<bits/stdc++.h>
using namespace std;

// Main Logic
bool isHeap (int arr[], int i, int n) {
    // If node is a leaf node
    if (i > (n-2)/2)
        return true;
    // If node is an internal node and is greater than its children
    // and same is recursively true for children as well
    if (arr[i] >= arr[2*i+1] && arr[i] >= arr[2*i+2] && isHeap(arr, 2*i+1, n) && isHeap(arr, 2*i+2, n))
        return true;
    return false;
}

/* ------------- MAIN DRIVER CODE ------------- */
int main() {
    int arr[] = {90, 15, 10, 7, 12, 2, 7, 3};
    int n = sizeof(arr) / sizeof(int)-1;

    isHeap(arr, 0, n)? printf("Yes\n"): printf("No\n");

    return 0;
}