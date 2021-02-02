/*
Given an array of N distinct elements where elements are between 1 and N both
inclusive, check if it is stack-sortable or not. An array A[] is said to be
stack sortable if it can be stored in another array B[], using a temporary
stack S.

The operations that are allowed on array are:
    - Remove the starting element of array A[] and push it into the stack.
    - Remove the top element of the stack S and append it to the end of array B.

If all the element of A[] can be moved to B[] by performing these operations
such that array B is sorted in ascending order, then array A[] is stack
sortable.

Input : A[] = { 3, 2, 1 }
Output : YES

Explanation :
Step 1: Remove the starting element of array A[]
        and push it in the stack S. ( Operation 1)
        That makes A[] = { 2, 1 } ; Stack S = { 3 }
Step 2: Operation 1
        That makes A[] = { 1 } Stack S = { 3, 2 }
Step 3: Operation 1
        That makes A[] = {} Stack S = { 3, 2, 1 }
Step 4: Operation 2
        That makes Stack S = { 3, 2 } B[] = { 1 }
Step 5: Operation 2
        That makes Stack S = { 3 } B[] = { 1, 2 }
Step 6: Operation 2
        That makes Stack S = {} B[] = { 1, 2, 3 }

Input : A[] = { 2, 3, 1}
Output : NO


APPROACH:
    Given, array A[] is a permutation of [1, …, N], so let us suppose the
    initially B[] = {0}. Now we can observe that:
    - We can only push an element in the stack S if the stack is empty or
      the current element is less than the top of the stack.
    - We can only pop from the stack only if the top of the stack is B[end] + 1
      as the array B[] will contain {1, 2, 3, 4, …, n}.
    If we are not able to push the starting element of the array A[], then the
    given array is Not Stack Sortable.

*/

#include <bits/stdc++.h>
using namespace std;

// Function to check if A[] is Stack Sortable or Not.
bool check(int A[], int N) {

    stack<int> S;
    // Pointer to the end value of array B.
    int B_end = 0;

    // Checking if there is a valid operation that can be performed.
    for (int i = 0; i < N; i++) {
        if (!S.empty()) {
            int top = S.top();
            // If the top of the stack is equal to B_end+1, we will pop it
            // and increment B_end by 1.
            while (top == B_end + 1) {
                // if current top is equal to B_end+1, we will increment
                // B_end to B_end+1
                B_end = B_end + 1;

                S.pop();

                // If the stack is empty, we cannot further perfom this
                // operation. Therefore, break.
                if (S.empty())
                    break;

                // Current Top
                top = S.top();
            }

            // If stack is empty, push the current element
            if (S.empty()) {
                S.push(A[i]);
            }
            else {
                top = S.top();

                // If the current element of the array A[] is smaller than the
                // top of the stack, we can push it in the Stack.
                if (A[i] < top)
                    S.push(A[i]);
                // Else we cannot sort the array using any valid operations.
                else {
                    // Not Stack Sortable
                    return false;
                }
            }
        }
        else {
            // If the stack is empty push the current element in the stack.
            S.push(A[i]);
        }
    }
    // Stack Sortable
    return true;
}

/* ---------------- MAIN DRIVER CODE --------------- */
int main() {
    int A[] = { 4, 1, 2, 3 };
    int N = sizeof(A) / sizeof(A[0]);
    check(A, N) ? cout<<"YES" : cout<<"NO";
    return 0;
}
