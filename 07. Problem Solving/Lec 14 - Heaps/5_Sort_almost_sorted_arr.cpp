/*  Lets say, we have to - "Sort an almost sorted array".

    That means, given an array of 'n' elements, where each
    element is at most k away from its target position,
    devise an algorithm that sorts in O(n*logk).

    For example, let us consider k is 2, an element at index
    7 in the sorted array, can be at indexes 5, 6, 7, 8, 9
    in the given array.

    Input : arr[] = {6, 5, 3, 2, 8, 10, 9} and k = 3
    Output : arr[] = {2, 3, 5, 6, 8, 9, 10}

    Input : arr[] = {10, 9, 8, 7, 4, 70, 60, 50} and k = 4
    Output : arr[] = {4, 7, 8, 9, 10, 50, 60, 70}

    We can do so, with the use of Heap data structure.
    1) Create a Min Heap of size k+1 with first k+1 elements.
       This will take O(k) time.
    2) One by one remove min element from heap, put it in
       result array, and add a new element to heap from
       remaining elements.

    Removing an element and adding a new element to min heap
    will take Logk time.

    So overall complexity will be O(k) + O((n-k)*logk).

    -------------------------------------------------------
    Heaps in STL are implemented under the container name -
    "priority queues".

    Check this video link for more details:
    https://www.youtube.com/watch?v=wptevk0bshY
*/

#include <bits/stdc++.h>
using namespace std;

// Auxiliary function to print array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main Logic
int sortK (int arr[], int n, int k) {
    // Insert first k+1 elements in priority queue
    priority_queue<int, vector<int>, greater<int>> pq (arr, arr+k+1);
    int index = 0;
    for (int i = k+1; i < n; i++) {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while (!pq.empty()) {
        arr[index++] = pq.top();
        pq.pop();
    }
}

/* ---------------- MAIN DRIVER CODE --------------- */
int main() {
    int k = 3;
    int arr[] = { 2, 6, 3, 12, 56, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sortK(arr, n, k);

    cout << "Following is sorted array:\n";
    printArray(arr, n);

    return 0;
}