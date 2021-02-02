/*  PROBLEM: Rearrange positive and negative numbers in array such that 
        they are stored in alternate form. The numbers of positive and 
        negative elements in the array need not to be equal, 
        the extra elements are to be pushed at the end.
    
    SOLUTION:
    A simple solution is to remove and store all positive elements from array
    into an temporary array and then append these numbers to the array. This
    will result in all negative elements in the start and positive elements
    after them. Now we can swap +ve and -ve elements to create desired pattern.
    Time Complexity: O(n) and Space Complexity: O(n)

    However there is an efficient method to solve this problem using Quicksort's
    partition algorithm by considering pivot point as '0'. After partition process 
    all the negative numbers come at beginning of array and all positive numbers 
    go at end of the array. We then swap the positive and negative elements to 
    get the desired result.
    Time Complexity: O(n) and Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

// Auxiliary Function
void swap (int *a, int *b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void printArray(int arr[], int n) { 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl;
} 

// Main Logic of Code
void rearrange (int arr[], int n) {
    // Partition algorithm with pivot as 0
    int i = -1;	
    for (int j = 0; j < n; j++)
        if (arr[j] < 0)
            swap (&arr[++i], &arr[j]);
    
    // Now swap +ve and -ve elements to make them alternating
    int neg = 0, pos = i + 1;
    while (pos < n && neg < n) {
        swap (&arr[neg], &arr[pos]);
        pos++;
        neg += 2;
    }
}

// Utility function to perform right rotation by 1
void rightrotate(int arr[], int n, int out_of_place_index, int current) { 
    int tmp = arr[current]; 
    for (int i = current; i > out_of_place_index; i--) 
        arr[i] = arr[i-1]; 
    arr[out_of_place_index] = tmp; 
} 

void rearrange_in_order (int arr[], int n) {
    int out_of_place_index = -1;

    for (int i = 0; i < n; i++) {
        // if no entry has been found which is out of place,
        // check if the current entry is out of place or not.
        if (out_of_place_index == -1) {
            // condition for element to be out of place
            if (((arr[i] >= 0) && (i & 1)) || ((arr[i] < 0) && !(i & 1)))
                out_of_place_index = i;
        }

        if (out_of_place_index >= 0) {
            if (((arr[i] >= 0) && (arr[out_of_place_index] < 0)) || ((arr[i] < 0) && (arr[out_of_place_index] >= 0))) {
                rightrotate(arr, n, out_of_place_index, i);
                // if the rotated elements are adjacent
                if (i - out_of_place_index < 2)
                    out_of_place_index = -1;
                // else the new out of place entry is two steps ahead
                else
                    out_of_place_index += 2;
                
            }
        }
    }
}

/* --------------------- MAIN DRIVER CODE -------------- */
int main()  
{ 
    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    
    rearrange(arr, n); 
    printArray(arr, n); 
    
    return 0; 
}

/* ADDITIONAL POINT:

    1. What if we were given an array of +ve integers only, 
    and instead of alternate +ve and -ve arrangement, we
    were asked to make alternate odd and even arrangement?

    Input  = {12, 34, 45, 9, 8, 90, 3}
    Output = {12, 34, 8, 90, 45, 9, 3}

    Could you change above code and solve above problem!

    SOLUTION:
    void rearrange (int arr[], int n) {
        int i = -1;	
        for (int j = 0; j < n; j++)
            if (arr[j]%2 == 0)          // Modification
                swap (&arr[++i], &arr[j]);
        
        // Now there are all even numbers till index i
        int even = 0, odd = i + 1;
        while (even < n && odd < n) {
            swap (&arr[even], &arr[odd]);
            odd++;
            even += 2;
    }

    2. Let's say there is an array A = {1, 0, 2, 0, 0, 3, 4, 0, 5}.
    Now you want to push all zeros towards the end and produce an 
    array = {1, 2, 3, 4, 5, 0, 0, 0, 0}. Note here non-zero elements
    are in same order as that in input. How will you do this?

    SOLUTION: By using a modified Partition algorithm.

    void zerosToEnd (int arr[], int n) {
        int count = 0;
        for (int i = 0; i < n; i++)
            if (arr[i] != 0)
                swap (&arr[count++], &arr[i]);
    }
*/