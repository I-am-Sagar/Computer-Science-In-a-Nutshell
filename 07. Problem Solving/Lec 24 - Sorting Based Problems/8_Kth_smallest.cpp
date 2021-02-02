/*  PROBLEM: Given an array arr of size N, and a number K, less
    than N, find the Kth smallest element in the given array.

    For example: arr[] = {7, 10, 4, 3, 20, 15} and K = 3
    Output: 7 (because 3rd smallest element is 7 after 3 and 4).

    SOLUTION:
    A simple solution is to sort the given array using a O(N log N) 
    sorting algorithm like Merge Sort, Heap Sort, etc and return 
    the element at index k-1 in the sorted array.
    Time Complexity of this solution is O(N*Log N).

    A better solution with O(N) time complexity is possible, using
    modified Partition scheme of QuickSort method. Here is the logic:

    - We pick the pivot element and move the pivot element to its
      correct position and partition the array around this element.
      The idea is not to do complete Quicksort. We will not call 
      Quicksort method on the left and right partitions recursively
      on both the sides. We will just call it on one side depending 
      upon the index where pivot settled i.e. where partition occured
      and the value of K. We will just stop at the point when pivot 
      element itself settles at (K-1)th index.
    
    - The worst case time complexity of this is O(n^2), but works 
      in O(n) on average. But to reduce the chances of O(n^2) by
      a huge amount, instead of taking pivot element as first or
      last element (as we did in Sorting of 2-Data-Structures),
      here we will take random element of array as pivot. 

      So after this we can expect O(n) time complexity.
*/

#include<bits/stdc++.h>
using namespace std;

// Creating a random partition function which uses 
// normal partition function as base routine
int partition (int arr[], int l, int r) {
    int x = arr[r], i = 1;
    for (int j = 1; j <= r-1; j++) {
        if (arr[j] <= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int randomPartition (int arr[], int l, int r) {
    int n = r - l + 1;
    int pivot = rand()%n;
    swap(arr[pivot+1], arr[r]);
    return partition(arr, l, r);
}

// Main Logic of Code
int KthSmallest (int arr[], int l, int r, int k) {
     // Run code only if k is smaller than
     // the number of elements in array
    if (k>0 && k <= r-l+1) {
        int pos = randomPartition(arr, l, r);

        // If pos is same as k, return the element
        if (pos == k)
            return arr[pos];
        
        // If pos is more, recur for left subarray
        if (pos > k)
            return KthSmallest(arr, l, pos-1, k);
        // Else recur for right subarray
        else
            return KthSmallest(arr, pos+1, r, k-pos+l-1);
    }
    // If k is more than number of elements in array
    return INT_MAX;
}

/* ------------------- MAIN DRIVER CODE ------------------ */
int main() {
    int arr[] = {12, 3, 5, 7, 4, 19, 9, 16, 26};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    cout << "4th smallest element: " << KthSmallest(arr, 0, n-1, k);
    return 0;
}

/* ADDITIONAL POINT:

    Finding 'mean' of array is an O(N) task. We need to sum entire array,
    and then divide the sum by the number of elements.

    However finding median is usually an O(N*logN) task, because median
    is the middle element of the sorted array. However, if I know the size
    of array (which usually we have), we can set - 
    
    k = N/2;    if N is odd
    or
    k1 = (N-1)/2 and k2 = N/2;  if N is even.

    For odd case, median = k'th smallest;
    For even case, median = (k1'th + k2'th smallest)/2.0;

    Thus, finding median becomes O(N) task as well after using the above code.

    Using Min-Heap:

    int findKthSmallest(vector<int> const &vec, int k)
    {
        // create an empty min-heap and initialize it with all elements
        // use std::greater as the comparison function for min-heap
        priority_queue<int, std::vector<int>, std::greater<>>
                pq(vec.begin(), vec.end());

        // pop from min-heap exactly (k-1) times
        while (--k) {
            pq.pop();
        }

        // return the root of min-heap		
        return pq.top();
    }

    // Find K'th smallest element in an array
    int main()
    {
        vector<int> vec  = { 7, 4, 6, 3, 9, 1 };
        const size_t k = 3;

        cout << "K'th smallest element in the array is " << 
                findKthSmallest(vec, k);

        return 0;
    }

    Using Max-heap:

    int findKthSmallest(vector<int> const &v, int k)
    {
        // create a max-heap using std::priority_queue and
        // insert first k elements of the array into the heap
        priority_queue<int, vector<int>> pq(v.begin(), v.begin() + k);

        // do for remaining array elements
        for (int i = k; i < v.size(); i++)
        {
            // if current element is less than the root of the heap
            if (v[i] < pq.top())
            {
                // replace root with the current element
                pq.pop();
                pq.push(v[i]);
            }
        }

        // return the root of max-heap
        return pq.top();
    }

    // Find K'th smallest element in an array
    int main()
    {
        vector<int> vec  = { 7, 4, 6, 3, 9, 1 };
        const size_t k = 3;

        cout << "K'th smallest element in the array is " <<
                findKthSmallest(vec, k);

        return 0;
    }
*/