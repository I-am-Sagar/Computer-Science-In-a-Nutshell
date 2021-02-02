// Video Link: https://www.youtube.com/watch?v=i-SKeOcBwko

/*	Consider {12, 11, 13, 5, 6}

Loop for i = 1 (second element of the array) to 5 (size of the array)

i = 1 --> Since 11 is smaller than 12, move 12 and
          insert 11 before 12. {11, 12, 13, 5, 6}

i = 2 --> 13 will remain at its position as all elements
          in A[0...i-1] are smaller than 13. {11, 12, 13, 5, 6}

i = 3 --> 5 will move to the beginning and all other elements
          from 11 to 13 will move one position ahead of their
          current position. {5, 11, 12, 13, 6}

i = 4 --> 6 will move to position after 5, and elements from
          11 to 13 will move one position ahead of their
          current position. {5, 6, 11, 12, 13}


Again the above logic could be solved recursively:
    a) If array size is 1, return.
    b) Recur for (n-1) elements
    c) Insert last element at its correct position in sorted array

O(n^2) time complexity
*/

#include <bits/stdc++.h>
using namespace std;

// Auxiliary Functions
void printArray(int arr[], int n) {
    for (int i=0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Iterative Insertion Sort Logic
void insertionSort1 (int arr[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;
        // Move elements of arr[0..i-1], that are
        // greater than key, to one position ahead
        // of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
    // Cant replace key by arr[i] or arr[j+1] = arr[i]
        arr[j+1] = key;
    }
}

// Recursive Iteration Sort Logic
void insertionSort2 (int arr[], int n) {
    // Base Case
    if (n <= 1)	return;

    // First sort n-1 elements
    insertionSort2 (arr, n-1);

    // Insert last element at its correct position
    int last = arr[n-1];
    int j = n-2;

    while (j >=0  && arr[j] > last) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}

/* ---------------- MAIN LOGIC CODE ---------------- */
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

    insertionSort1(arr1, size);
    printArray(arr1, size);

    insertionSort2(arr2, size);
    printArray(arr2, size);

    return 0;
}
