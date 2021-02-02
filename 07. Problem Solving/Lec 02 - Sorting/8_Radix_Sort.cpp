// Video Link: https://www.youtube.com/watch?v=YXFI4osELGU

/*
Need of Radix Sort:
    CountSort is not comparison based algorithm. It has the
    complexity of O(n+k), where k is the maximum element of
    the input array. So, if k is O(n), CountSort becomes
    linear sorting, which is better than comparison based
    sorting algorithms.
    The idea is to extend the CountSort algorithm to get a better
    time complexity when k goes O(n^2). Here comes the idea of
    Radix Sort.

Complexity:
    Let there be d digits in input integers. Radix Sort takes
    O(d*(n+b)) time where b is the base for representing numbers,
    for example, for decimal system, b is 10.

    What is the value of d? If k is the maximum possible value,
    then d would be O(logb(k)). So overall time complexity is O((n+b) * logb(k)).
    This looks more than the time complexity of comparison based sorting algorithms
    for a large k. Let us first limit k. Let k <= nc where c is a constant.

    In that case, the complexity becomes O(nLogb(n)).
    But it still doesn’t beat comparison based sorting algorithms.

    What if we make value of b larger?. What should be the value of
    b to make the time complexity linear? If we set b as n,
    we get the time complexity as O(n). In other words, we can sort
    an array of integers with range from 1 to n if the numbers are
    represented in base n.

Advantages :
    1. Fast when the keys are short i.e. when the range of the array
       elements is less.

Disadvantages:
    1. Since Radix Sort depends on digits or letters,
       Radix Sort is much less flexible than other sorts.
       Hence, for every different type of data it needs to be rewritten.
    2. The constant for Radix sort is greater compared to other sorting algorithms.
    3. It takes more space compared to Quicksort which is inplace sorting.
*/

#include<bits/stdc++.h>
#define RANGE 10
using namespace std;

// Utility functions
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Function to do counting sort as per the digit's "place"
void countSort (int arr[], int n, int place) {
    int i, freq[RANGE] = {0};   // Range for integers is 10 i.e. 0-9
    int output[n];

    // Store the count of occurence of digit as position 'place'
    for (i = 0; i < n; i++)
        freq[(arr[i]/place)%10]++;

    // Change freq[i] into cumulative sum array
    for (i = 1; i < 10; i++)
        freq[i] += freq[i-1];

    // Build the output array
    for (int i = n-1; i>=0; i--) {
        output[freq[(arr[i]/place)%10]-1] = arr[i];
        freq[(arr[i]/place)%10]--;
    }

    // Copy this output array to arr[], so arr[] should contain
    // sorted elements  according to digits at current 'place'
     for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// Main Logic of Radix Sort
void radixSort (int arr[], int n) {
    int m = getMax(arr, n);
    for (int place = 1; m/place > 0; place *= 10)
        countSort(arr, n, place);
}

/* -------------------- MAIN DRIVER CODE ------------------ */
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66, 253, 1001};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixSort(arr, n);
    print(arr, n);
    return 0;
}
