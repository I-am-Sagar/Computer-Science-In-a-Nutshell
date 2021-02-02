/*  PROBLEM: Given a sorted and rotated array, find if there is
    a pair with given sum, assuming all elements to be distinct.

    SOLUTION:
    a) Find the pivot element of the rotated array.
    b) Use two pointers with left pointer pointing to minimum element
       and right pointer pointing to maximum element.
    c) Find sum of the elements pointed by both the pointers.
       If sum is equal to x, then increment count.
       If sum is less than x, then move left pointer by incrementing it.
       If sum is greater than x, then move right pointer by decrementing it.
    d) Repeat step 3 and 4 until left pointer is not equal to right pointer.
    e) Print all pairs and the count of such pairs.
*/

#include <iostream>
using namespace std;

// Auxiliary Function
int findPivot (int arr[], int low, int high) {
    while (low <= high) {
        int mid = low+(high-low)/2;

        if (mid < high && arr[mid] > arr[mid+1])
            return mid;

        if (mid > low && arr[mid] < arr[mid-1])
            return mid-1;

        if (arr[low] >= arr[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

// Main Logic of Code
int pairsInRotated(int arr[], int n, int x) {
    int pivot = findPivot (arr, 0, n-1);
    int r = pivot;	// r is index of maximum element.
    int l = (pivot + 1)%n; // l is index of minimum element.
    int count = 0;	// Variable to store count of number of pairs

    while (l != r) {
        if (arr[l] + arr[r] == x) {
            count++;
        cout << arr[l] << " " << arr[r] << endl;

        // Condition to check that left and right pointers have met
        // At this point, loop should terminate
            if(l == (r - 1 + n) % n)
            return count;

        // Move left and right pointers for next finding pair
            l = (l + 1) % n;
            r = (r - 1 + n) % n;
        }
        // If current pair sum is less, move to the higher sum side.
        else if (arr[l] + arr[r] < x)
            l = (l + 1) % n;
        // If current pair sum is greater, move to the lower sum side.
        else
            r = (n + r - 1)%n;
    }
    return count;
}

/* ----------------- MAIN DRIVER CODE ----------------- */
int main() {
    int size, sum, count;

    cout << "Size = ";
    cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    cout << "Sum = ";
    cin >> sum;

    count = pairsInRotated(arr, size, sum);
    cout << count << endl;

    return 0;
}
