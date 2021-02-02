/*

Given an array of elements, task is to sort these elements using stack.

Approach:
1. Create a temporary stack say tmpStack.
2. While input stack is NOT empty do this:
    - Pop an element from input stack call it temp
    - while temporary stack is NOT empty and top of temporary stack is greater 
      than temp, pop from temporary stack and push it to the input stack
    - push temp in temporary stack
3. The sorted numbers are in tmpStack. Put them back to array.

input: [34, 3, 31, 98, 92, 23]

Element taken out               Input                       tmpStack
        23                [34, 3, 31, 98, 92]          [23]
        92                [34, 3, 31, 98]              [23, 92]
        98                [34, 3, 31]                  [23, 92, 98]
        31                [34, 3, 98, 92]              [23, 31]
        92                [34, 3, 98]                  [23, 31, 92]
        98                [34, 3]                      [23, 31, 92, 98]
        3                 [34, 98, 92, 31, 23]         [3]
        23                [34, 98, 92, 31]             [3, 23]
        31                [34, 98, 92]                 [3, 23, 31]
        92                [34, 98]                     [3, 23, 31, 92]
        98                [34]                         [3, 23, 31, 92, 98]
        34                [98, 92]                     [3, 23, 31, 34]
        92                [98]                         [3, 23, 31, 34, 92]
        98                []                           [3, 23, 31, 34, 92, 98]

final sorted list: [3, 23, 31, 34, 92, 98]

*/

#include <bits/stdc++.h>
using namespace std;

// This function returns the sorted stack
stack<int> sortStack(stack<int> input) {
    stack<int> tmpStack;
    while (!input.empty()) {
        // pop out the first element
        int tmp = input.top();
        input.pop();
        // while temporary stack is not empty
        // and top of stack is smaller than temp
        while (!tmpStack.empty() && tmpStack.top() < tmp) {
            // pop from temporary stack and
            // push it to the input stack
            input.push(tmpStack.top());
            tmpStack.pop();
        }
        // push temp in tempory of stack
        tmpStack.push(tmp);
    }
    return tmpStack;
}

void sortArrayUsingStacks(int arr[], int n) {
    // Push array elements to stack
    stack<int> input;
    for (int i=0; i<n; i++)
       input.push(arr[i]);
    // Sort the temporary stack
    stack<int> tmpStack = sortStack(input);
    // Put stack elements in arr[]
    for (int i=0; i<n; i++) {
        arr[i] = tmpStack.top();
        tmpStack.pop();
    }
}

/* ---------------- MAIN DRIVER CODE --------------- */
int main() {
    int arr[] = {10, 5, 15, 45};
    int n = sizeof(arr)/sizeof(arr[0]);

    sortArrayUsingStacks(arr, n);

    for (int i=0; i<n; i++)
       cout << arr[i] << " ";

    return 0;
}