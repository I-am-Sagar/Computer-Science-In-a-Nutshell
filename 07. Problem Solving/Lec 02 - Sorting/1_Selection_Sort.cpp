// Video Link 1: https://www.youtube.com/watch?v=pkkFqlG0Hds
// Video Link 2: https://www.youtube.com/watch?v=GUDLRan2DWM

/*
a) Find the minimum element of array from 0 to n-1 and swap it with 0th element.
b) Find the minimum element of array from 1 to n-1 and swap it with 1st element.
c) Find the minimum element of array from 2 to n-1 and swap it with 2nd element and so on.

O(n^2) Time Complexity. */

#include <bits/stdc++.h>
using namespace std;

// Auxiliary Functions
void swap (int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray (int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main Logic of Selection Sort
void selectionSort (int arr[], int n) {
    int i, j, min_index;

    for (i = 0; i < n-1; i++) {
        min_index = i;

        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_index])
                min_index = j;

        swap (&arr[min_index], &arr[i]);
    }
}

/* -------------------- MAIN DRIVER CODE ------------------- */
int main() {
    int size;

    cout << "Size = ";
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "a[" << i << "] = ";
        cin >> arr[i];
    }

    selectionSort(arr, size);
    printArray(arr, size);

    return 0;
}
