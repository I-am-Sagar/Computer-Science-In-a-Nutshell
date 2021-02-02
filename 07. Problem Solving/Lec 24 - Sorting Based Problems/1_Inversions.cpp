// Video Link: https://www.youtube.com/watch?v=Vj5IOD7A6f8

#include <bits/stdc++.h>
using namespace std;

// Merge Function returns the number of inversions
// caused when left and right parts of array are merged
long merge (int arr[], int left, int mid, int right) {
    int i = left, j = mid, k = 0;
    int temp[right-left+1];
    long count = 0;

    while (i < mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            count += mid-i; // Counting statement
        }
    }

    while (i < mid)
        temp[k++] = arr[i++];
    
    while (j <= right)
        temp[k++] = arr[j++];
    
    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
    
    return count;
}

// Main logic of modified mergeSort() which returns 
// the total number of inversions in array
long mergeSort (int arr[], int left, int right) {
    long inversion_count = 0;

    if (right > left) {
        int mid = left + (right-left)/2;

        inversion_count  = mergeSort(arr, left, mid);
        inversion_count += mergeSort(arr, mid+1, right);
        inversion_count += merge(arr, left, mid+1, right);
    }

    return inversion_count;
}

/* ------------------ MAIN DRIVER CODE ----------------------- */
int main() {
    int arr[] = {2, 5, 1, 3, 4, 7, 6};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Inversions = " << mergeSort(arr, 0, size-1) << endl;
    return 0;
}

/* ADDITIONAL POINT: 

Source: https://www.spoj.com/problems/DCEPC206/

Take the following question:
    Given an array A, for every element, find the sum of all 
    the previous elements which are smaller than the current element.
    Print the total sum of all such individual sums.

    For eg. arr = {1 5 3 6 4};

    For i = 0: sum = 0
    For i = 1: sum = 1 (1 is smaller than 5)
    For i = 2: sum = 1 (only 1 is smaller than 3)
    For i = 3: sum = 9 (1, 5, 3 all are smaller than 6)
    For i = 4: sum = 4 (1, 3 are smaller than 4)

    Total sum = 0 + 1 + 1 + 9 + 4 = 15
    Output = 15.

    SOLUTION:
    Here we are not interested in inversions, instead we are interested
    in the pairs which are in order. So, the only difference will be - 

    In above code, we wrote "Counting statement" in 'else' part. Here, 
    we will write "Summing statement" in 'if' part of merge().

    // CODE
    long merge (int A[], int left, int mid, int right) {
        int i = left, j = mid, k = 0;
        int temp[right-left+1];
        long sum = 0;
        
        while ( i < mid && j <= right) {
            if (A[i] < A[j]) {
                sum += (right-j+1)*A[i];  //Summing statement
                temp[k++] = A[i++];
            }
            else 
                temp[k++] = A[j++];
        }

        while (i < mid)
            temp[k++] = A[i++];
            
        while (j <= right)
            temp[k++] = A[j++];
        
        for (i = left, k = 0; i <= right; i++, k++)
            A[i] = temp[k];
        
        return count;
    }

    long merge_sort (int A[], int left, int right) {
        long sum = 0;
        
        if (right > left) {
            int mid = (left+right)/2;
            
            long sum  = merge_sort (A, left, mid);
            long sum += merge_sort (A, mid+1, right);
            long sum += merge(A, left, mid+1, right);
        }
        return sum;
    }
*/