/*  Problem: Next Greater Frequency (NGF) Element

Given an array, for each element find the value of the nearest element
to the right which is having frequency greater than as that of current
element. If there doesn't exist an answer for a position, make value -1.

Example:
    Input:  {1, 1, 2, 3, 4, 2, 1}
    Output: {-1, -1, 1, 2, 2, 1, -1}

Explanation:
    Given array is {1, 1, 2, 3, 4, 2, 1}.
    Now frequency of each element in array is {3, 3, 2, 1, 1, 2, 3}.

    For element a[0] = 1, frequency = 3. There is no element to the
    right of 1, whose frequency is greater than 3. So output[0] = -1.

    For element a[1] = 1, output[1] = -1 by same logic.

    For element a[2] = 2, frequency = 2. There is element '1' in array,
    at position 6, whose frequency is 3 and is more than 2. So output[2] = 1.

    For element a[3] = 3, frequency = 1. The nearest next higher frequency
    element for 3 is '2' whose frequency is 2. So output[3] = 2.

    We can go on for other elements now.

SOLUTION: (Implement the steps by taking above sample problem on paper)

    1. Create an array/map to store frequency of each element.
    2. Push the position of first element to stack.
    3. Push rest of the positions of elements one by one and
       follow following steps in loop:
       a) Mark the position of current element as 'i'
       b) If
            the frequency of the element which is pointed by the top
            of stack is GREATER than frequency of the current element,
            push the current position i to stack

          Else
            If
                the frequency of the element which is pointed by the top
                of stack is LESS than frequency of the current element,
                and the stack is not empty,
                while (above condition fails) {
                    output[stack's top position] = frequency of this ith element
                    pop the element from stack
                }
            Then push the current position i to stack.
    4. After the loop in step 3 is over, the positions left in stack are those
       positions whose NGF element was not found.

Time Complexity: O(n)
Space Complexity: O(n)

*/

#include <bits/stdc++.h>
using namespace std;

// Main Logic
void nextGreaterFreq (int arr[], int n) {
    // Creating a hash Table which stores frequency of each element
    map <int, int> freq;
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    // Stack to store position of array elements
    stack <int> s;
    s.push(0);

    // result array to store NGF element for each element
    int result[n] = {0};

    for (int i = 1; i < n; i++) {
        /* If the frequency of the element, which is at the position
        at the top of the stack, is greater than frequency of current
        element, then push the current position i in stack */
        if (freq[arr[s.top()]] > freq[arr[i]])
            s.push(i);
        else {
            /* If the frequency of the element, which is at the position
            at the top of the stack, is less than frequency of current
            element, then pop the stack and continue popping until
            the above condition is true while the stack is not empty */
            while (freq[arr[s.top()]] < freq[arr[i]] && !s.empty()) {
                result[s.top()] = arr[i];
                s.pop();
            }
            // Now push the current element
            s.push(i);
        }
    }

    while (!s.empty()) {
        result[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
    cout << endl;
}

// Main Driver Code
int main() {
    int arr[] = {1, 1, 2, 3, 4, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    nextGreaterFreq(arr, size);
    return 0;
}

/*
    SOME ADDITIONAL VIDEOS TO WATCH ON STACKS:
    1. https://www.youtube.com/watch?v=Os5FM4KQtxw
    2. https://www.youtube.com/watch?v=Qk7obcDReHE
*/