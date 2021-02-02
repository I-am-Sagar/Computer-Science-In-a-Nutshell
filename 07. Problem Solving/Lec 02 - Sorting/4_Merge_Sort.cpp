// Video Link 1: https://www.youtube.com/watch?v=TzeBrDU-JaY
// Video Link 2: https://www.youtube.com/watch?v=0nlPxaC2lTw

#include <bits/stdc++.h>
using namespace std;

// Auxiliary Function
void printArray(int arr[], int n) {
    for (int i=0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Merge function to merge two sorted arrays into one
void merge (int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    //Temporary arrays
    int* left = new int[n1];
    int* right = new int[n2];

    int i, j;
    //Copying data to Temp array
    for (i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[mid + 1+ j];

    //Now merge the temporary arrays back
    i = 0;		//Initial index of first subarray
    j = 0;		//Initial index of second subarray
    int k = low;	//Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    //Copying remaining elements of left[] if any
    while (i < n1)
        arr[k++] = left[i++];
    //Copying remaining elements of right[] if any
    while (j < n2)
        arr[k++] = right[j++];
}

// Main Logic of Recursive MergeSort
void mergeSort1 (int arr[], int low, int high) {
    if (low < high) {
        int mid = low +(high-low)/2;
        mergeSort1 (arr, low, mid);
        mergeSort1 (arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

// Main Logic of Iterative MergeSort
void mergeSort2 (int arr[], int n) {
    int current_size, left_start;
    for (current_size = 1; current_size < n-1; current_size = 2*current_size) {
        for (left_start = 0; left_start < n-1; left_start += 2*current_size) {
            int mid = left_start + current_size - 1;
            int right_end = min(left_start + 2*current_size - 1, n-1);

            merge (arr, left_start, mid, right_end);
        }
    }
}

/* ------------------ MAIN DRIVER CODE ------------------ */
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

    mergeSort1(arr1, 0, size);
    printArray(arr1, size);

    mergeSort2(arr2, size);
    printArray(arr2, size);

    return 0;
}

/* ADDITIONAL POINT:

We may see that - Iterative Mergesort requires only two
arguments - array and size of array. Whereas Recursive
Mergesort takes three arguments - array, lower index and
higher index. If we are suppose to fill recursive function,
with two arguments only - Here is how we do that:

    void merge (int *arr, int *L, int leftCount, int *R, int rightCount) {
        int i = 0, j = 0, k = 0;
        // i - to mark the index of left aubarray (L)
        // j - to mark the index of right subarray (R)
        // k - to mark the index of merged subarray (arr)

        while(i<leftCount && j< rightCount) {
            if(L[i]  < R[j])	arr[k++] = L[i++];
            else	arr[k++] = R[j++];
        }
        while(i < leftCount) arr[k++] = L[i++];
        while(j < rightCount) arr[k++] = R[j++];
    }

    void mergeSort(int input[], int size) {
        int mid, i;

        if (size < 2)    return;

        mid = size/2;
        int* L = new int[mid];
        int* R = new int[size-mid];

        for (i = 0; i < mid; i++)	L[i] = input[i];
        for (i = mid; i < size; i++)	R[i-mid] = input[i];

        mergeSort(L, mid);
        mergeSort(R, size-mid);
        merge(input, L, mid, R, size-mid);

        delete L;
        delete R;
    }
*/
