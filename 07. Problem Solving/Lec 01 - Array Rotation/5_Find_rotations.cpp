/* PROBLEM: Given a sorted and rotated array, write a function
    which returns the number of rotations performed on sorted array.

   SOLUTION:
    Let the initial array be: arr[] = {1, 2, 3, 4, 5, 6, 7} and after
    rotations, array be: arr[] = {6, 7, 1, 2, 3, 4, 5}.

    We can achieve this configuration by two ways:
    a) If the array was left_rotated, we need 5 rotations.
    b) If the array was right_rotated, we need 2 rotations.

    We can see one thing, if the index of pivot element is 'i',
    (pivot is the maximum element of the array) then -

    No. of left rotations performed = N - i - 1
    No. of right rotations performed = i + 1

    So now our task is - to find the index of the pivot element.
    We can do this in O(logN) time by "Finding a peak."

    Peak in an array is defined as the element which is greater than
    both of its adjacent elements.
*/

#include <iostream>
using namespace std;

// Main Logic of Code
int findPivot (int arr[], int low, int high) {
    while (low <= high) {
        int mid = low+(high-low)/2;

        // If pivot is at 'mid'
        if (mid < high && arr[mid] > arr[mid+1])
            return mid;

        // If pivot is at 'mid-1'
        if (mid > low && arr[mid] < arr[mid-1])
            return mid-1;

        if (arr[low] >= arr[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    // If reached here, it means array is not at all rotated
    return -1;
}

/* ------------------- MAIN DRIVER CODE ------------------ */
int main() {
    int arr[] = {6, 7, 1, 2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);

    int pivot = findPivot(arr, 0, size-1);
    int left_rotations = size - pivot - 1;
    int right_rotations = pivot + 1;
    cout << "Left Rotations: " << left_rotations << endl;
    cout << "Right Rotations: " << right_rotations << endl;

    return 0;
}