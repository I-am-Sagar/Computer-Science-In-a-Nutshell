// Video Link: https://www.youtube.com/watch?v=TTnvXY82dtM

/* This sorting technique works when keys are between a
   specific range. Lets say the range is 0 to 9.

Input: 1, 4, 1, 2, 7, 5, 2

1. Store the count of occurences of particular number in the
   array from 0 to range.

Index:  0	1	2	3	4	5	6	7	8	9
Count:  0	2	2	0	1	1	0	1	0	0

2. Find the cumulative sum array of Count[] by modifying it.

Index: 0	1	2	3	4	5	6	7	8	9
Count: 0	2	4	4	5	6	6	7	7	7

3. Now we have two arrays, Input array and count array.
   The first element of Input is 1. We will now go to
   index 1 of count array. The value is 2. This means
   in sorted array the position of 1 will be index 2.

   Now we reduce the count by one in that particular
   element. So count[1] = 1. Now we see 4. This means
   the position of 4 in sorted array is 5. Next time
   we again got 1 and the position of 1 in sorted array
   is 1. So in this way, after traversing whole input
   array, we get out sorted array.

Index:  1	2	3	4	5	6	7
Sorted: 1	1	2	2	4   5   7

Time complexity is O(n) and space complexity is O(n).
*/

#include <bits/stdc++.h>
#define RANGE 100
using namespace std;

//Auxiliary Function
void printArray(int arr[], int n) {
    for (int i=0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}


// Main Logic of Counting Sort
void countSort (int arr[], int n) {
    int count[RANGE] = {0};
    int i, output[n];

    for(i=0; i<n; i++)
        ++count[arr[i]];

    for(i=1; i<RANGE; i++)
        count[i] += count[i-1];

    for(i=n-1; i>=0; i--) {
        output[ count[arr[i]] -1 ] = arr[i];
        --count[arr[i]];
    }

    for(i=0; i<n; i++)
        arr[i] = output[i];
}

/* --------------------- MAIN DRIVER CODE --------------- */
int main() {
    int size;

    cout << "Size = ";
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "a[" << i << "] = ";
        cin >> arr[i];
    }

    countSort (arr, size);
    printArray (arr, size);

    return 0;
}
