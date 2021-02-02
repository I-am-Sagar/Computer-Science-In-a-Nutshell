/*	Find maximum value of Sum(i*arr[i]) when only left
    rotations are allowed.

    A simple solution of adding and checking sum at each
    element takes O(n^2) complexity.

    An efficient solution with O(n) complexity has the idea
    to calculate next rotation value from previous rotation,
    i.e., calculate Lj from Lj-1, where
        Lj = Sum(i*arr[i]) after j rotations.

    L0 = 0*a[0] + 1*a[1] + 2*a[2] + 3*a[3] + .... + (n-2)*a[n-2] + (n-1)*a[n-1]
    L1 = 1*a[0] + 2*a[1] + 3*a[2] + 4*a[3] + .... + (n-1)*a[n-2] + 0*a[n-1]
    L2 = 2*a[0] + 3*a[1] + 4*a[2] + 5*a[3] + .... +   0 * a[n-2] + 1*a[n-1]

    L1 - L0 = 1*a[0] + 1*a[1] + 1*a[2] + .... + 1*a[n-2] - (n-1)*a[n-1]
        = Sum of elements of array - n*a[n-1]

    L2 - L1 = 1*a[0] + 1*a[1] + 1*a[2] + .... + 1*a[n-3] - (n-1)*a[n-2] + 1*a[n-1]
        = Sum of elements of array - n*a[n-2]

    Similarly,
    L3 - L2 = Sum of elements of array - n*a[n-3]

    Lj - Lj-1 = Sum of elements of array - n*a[n-j]

    1) Complete the sum of elements of array, in arrSum
    2) Compute L0 from the given arrray
    3) Initialize result: maxVal = currVal
    4) Do following for j = 1 to n-1
        a) currVal = currVal + arrSum-n*arr[n-j];
        b) If (currVal > maxVal)
            maxVal = currVal
            rotation = j
    5) Print maxVal and rotations
*/

#include <iostream>
using namespace std;

// Main Logic of Code
void maxSum(int arr[], int n) {
    int arrSum = 0;  // Sum of arr[i]
    int currVal = 0;  // Sum of i*arr[i]
    int rotation = 0; // Number of rotations at which sum is max

    for (int i=0; i<n; i++) {
        arrSum = arrSum + arr[i];
        currVal = currVal+(i*arr[i]);
    }

    int maxVal = currVal;
    for (int j=1; j<n; j++) {
        currVal = currVal + arrSum - n*arr[n-j];
        if (currVal > maxVal) {
            maxVal = currVal;
            rotation = j;
        }
    }
    cout << "Max Sum(i*arr[i]): " << maxVal << " after " << rotation << " rotations.\n";
}

/* -------------- MAIN DRIVER CODE ---------------- */
int main() {
    int size;

    cout << "Size = ";
    cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    maxSum (arr, size);

    return 0;
}
