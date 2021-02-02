// Video Link: https://www.youtube.com/watch?v=Jdtq5uKz-w4

/*	Bubble Sort is the simplest sorting algorithm that works
    by repeatedly swapping the adjacent elements if they are
    in wrong order. In this we generally find the biggest
    element and swap it with the last element.

    We can also implement the logic recursively.
    Recursive Bubble Sort has no performance advantages, but
    can be a good question to check one’s understanding of
    Bubble Sort and recursion.

    If we take a closer look at Bubble Sort algorithm, we can
    notice that in first pass, we move largest element to end
    (Assuming sorting in increasing order). In second pass,
    we move second largest element to second last position and so on.

    Recursive Implementation:
    a) Base Case: If array size is 1, return.
    b) Do One Pass of normal Bubble Sort.
       This pass fixes last element of current subarray.
    c) Recur for all elements except last of current subarray.

O(n^2) time complexity
*/

#include <bits/stdc++.h>
using namespace std;

// Auxiliary Functions
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int arr[], int n) {
    for (int i=0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Iterative Bubble Sort Logic
void bubbleSort1 (int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

// Recursive Bubble Sort Logic
void bubbleSort2 (int arr[], int n) {
    if (n==1) return;  //Base Case

    for (int i = 0; i < n-1; i++)
        if (arr[i] > arr[i+1])
            //Passing the largest element to end
            swap(arr[i], arr[i+1]);

    bubbleSort2 (arr, n-1);
}

/* ----------------- MAIN DRIVER CODE -------------- */
int main() {
    int size;

    cout << "Size = ";
    cin >> size;

    int* arr1 = new int[size];
    int* arr2 = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "a[" << i << "] = ";
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }

    bubbleSort1(arr1, size);
    printArray(arr1, size);

    bubbleSort2(arr2, size);
    printArray(arr2, size);

    return 0;
}
