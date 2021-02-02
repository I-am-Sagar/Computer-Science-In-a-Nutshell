// Video Link 1: https://www.youtube.com/watch?v=COk73cpQbFQ
// Video Link 2: https://www.youtube.com/watch?v=3Bbm3Prd5Fo

/* The idea of Quicksort is to pick an element as pivot and
partition the given array about that pivot.

There are many different versions of quickSort that pick
pivot in different ways.

    a) Always pick first element as pivot.
    b) Always pick last element as pivot (implemented below)
    c) Pick a random element as pivot.
    d) Pick median as pivot.

The key process in quickSort is partition(). Target of partitions is,
given an array and an element x of array as pivot, put x at its
correct position in sorted array and put all smaller elements
(smaller than x) before x, and put all greater elements
(greater than x) after x. All this should be done in linear time.

    PARTITION ALGORITHM:

The logic is - we start from the leftmost element and keep
track of index of smaller (or equal to) elements as i.

While traversing, if we find a smaller element, we swap current
element with arr[i]. Otherwise we ignore current element.

ILLUSTRATION:
                        10, 80, 90, 40, 50, 70
                            /\ (partition about 70)
                          /   \
                10, 40, 50    90 80
(partition about 50)  /\         /\  (partition about 80)
                    /   \      /   \
                10, 40   {}   {}   90
                /\
              /   \ (partition about 40)
            10    {}

*/

#include <bits/stdc++.h>
using namespace std;

// Auxiliary Functions
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n) {
    for (int i=0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Following partition() function takes last element as pivot,
// and places the pivot element at its correct position.
int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high-1; j++)
        if (arr[j] <= pivot)
            swap (&arr[i++], &arr[j]);
    swap (&arr[i+1], &arr[high]);

    return (i+1);
}

// Following function implements quickSort recursively
void quickSort1 (int arr[], int low, int high) {
    if (low < high) {
        int partition_index = partition (arr, low, high);
        quickSort1 (arr, low, partition_index - 1);
        quickSort1 (arr, partition_index + 1, high);
    }
}

// Following function implements quickSort iteratively
void quickSort2 (int arr[], int low, int high) {
    // Create an auxiliary stack
    int stack [high - low + 1];
    //Initialize top of the stack
    int top = -1;

    //Push initial values of low and high to stack
    stack[++top] = low;
    stack[++top] = high;

    //Keep popping from stack while it is not empty
    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        //Sets pivot at correct position
        int partition_index = partition (arr, low, high);

        //If elements are on the left side of pivot, then push left side to stack
        if (partition_index - 1 > low ) {
            stack[++top] = low;
            stack[++top] = partition_index - 1;
        }

        //If elements are on the right side of pivot, then push right side to stack
        if (partition_index + 1 < high ) {
            stack[++top] = partition_index + 1;
            stack[++top] = high;
        }
    }
}

/* ---------------- MAIN DRIVER CODE ----------------- */
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

    quickSort1(arr1, 0, size);
    printArray(arr1, size);

    quickSort2(arr2, 0, size-1);
    printArray(arr2, size);

    return 0;
}

/* ADDITIONAL POINT:

Like in previous code, how can we quicksort with just
two arguments recursively - array and its size?
Below is its implementation (here pivot is considered
as the first element):

    int partition (int arr[], int size) {
        int partition_value = arr[0];
        int left = 1;
        int right = size-1;

        while (1) {
            while (left <= right && arr[left] <= partition_value)   left++;
            while (partition_value < arr[right])    right--;

            if (left > right)
                break;
            else
                swap (arr[left], arr[right]);
        }
        swap (arr[0], arr[right]);
        return right;
    }

    void quickSort(int input[], int size) {
        if (size > 1) {
            int partition_index = partition(input, size);
            quickSort(input, partition_index);
            quickSort(input+partition_index+1, size-partition_index-1);
        }
    }

*/
