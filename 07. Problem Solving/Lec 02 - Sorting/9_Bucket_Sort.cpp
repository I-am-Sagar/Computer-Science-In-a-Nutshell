// Video Link: https://www.youtube.com/watch?v=geVyIsFpxUs

/*
    Bucket sort is mainly useful when input is uniformly distributed
    over a range. For example, consider the following problem.

       Sort a large set of floating point numbers which are in range
       from 0.0 to 1.0 and are uniformly distributed across the range.
    How do we sort the numbers efficiently?

    bucketSort(arr[], n)
    1) Create n empty buckets (or lists).
    2) Do following for every array element arr[i].
       a) Insert arr[i] into bucket[n*arr[i]]
    3) Sort individual buckets using insertion sort.
    4) Concatenate all sorted buckets.
*/

#include <bits/stdc++.h>
using namespace std;

// Main Logic of Bucket Sort
void bucketSort(float arr[], int n) {
    // 1) Create n empty buckets
    vector<float> b[n];

    // 2) Put array elements in different buckets
    for (int i=0; i<n; i++) {
        // Index in bucket
        int bi = n*arr[i];
        b[bi].push_back(arr[i]);
    }

    // 3) Sort individual buckets
    for (int i=0; i<n; i++)
        sort(b[i].begin(), b[i].end());

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

/* -------------------- MAIN DRIVER CODE ------------------- */
int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr, n);

    cout << "Sorted array is: \n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
