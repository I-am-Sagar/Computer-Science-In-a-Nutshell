/*  Now we need to Bucket Sort elements that
    may contain negative elements as well.

    sortMixed(arr[], n)
    1) Split array into two parts
          - Create two empty vectors Neg[], Pos[]
          - Store all negative element in Neg[] by
             converting into positive (Neg[i] = -1 * Arr[i])
          - Store all +ve in pos[]  (pos[i] =  Arr[i])

    2) Call function bucketSortPositive(Pos, pos.size())
       Call function bucketSortPositive(Neg, Neg.size())

        3) Then concatenate Neg and Pos in reverse and forward
           order respectively.
*/

#include <bits/stdc++.h>
using namespace std;

// Basic bucketSort for +ve elements
void bucketSort(vector<float> &arr, int n) {
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
    arr.clear();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr.push_back(b[i][j]);
}

// Main Logic of Mixed bucketSort
void sortMixed(float arr[], int n) {
    vector<float>Neg ;
    vector<float>Pos;

    // segregate elements in respective arrays
    for (int i=0; i<n; i++) {
        if (arr[i] < 0)
            Neg.push_back (-1 * arr[i]) ;
        else
            Pos.push_back (arr[i]) ;
    }

    bucketSort(Neg, (int)Neg.size());
    bucketSort(Pos, (int)Pos.size());

    // First store elements of Neg[] array by converting into -ve
    for (int i=0; i < Neg.size(); i++)
        arr[i] = -1 * Neg[ Neg.size() -1 - i];

    // store +ve element
    for(int j=Neg.size(); j < n; j++)
        arr[j] = Pos[j - Neg.size()];
}

/* ---------------------- MAIN DRIVER CODE -------------------- */
int main() {
    float arr[] = {-0.897, 0.565, 0.656, -0.1234, 0.0, 0.3434};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortMixed(arr, n);

    cout << "Sorted array is \n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
