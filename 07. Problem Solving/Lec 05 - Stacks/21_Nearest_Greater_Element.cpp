// Video Link: https://www.youtube.com/watch?v=sgelJuvX1bU

/* PROBLEM:
    Given an array, print the Next Greater Element (NGE) for every element.
    The Next greater Element for an element x is the first greater element
    on the right side of x in array. Elements for which no greater element
    exist, consider next greater element as -1.

   SOLUTION:
    1. Push the first element to stack.
    2. Pick rest of the elements one by one and follow the following steps in loop.
        a) Mark the current element as next.
        b) If stack is not empty, compare top element of stack with next.
        c) If next is greater than the top element, pop element from stack.
            'next' is the next greater element for the popped element.
        d) Keep popping from the stack while the popped element is smaller than 'next'.
            'next' becomes the next greater element for all such popped elements
    3. Finally, push the next in the stack.
    4. After the loop in step 2 is over, pop all the elements from stack and print -1
        as next element for them.
*/

#include <bits/stdc++.h>
using namespace std;

void printNGE(int arr[], int n) {
    stack <int> s;
    s.push(arr[0]);

    for (int i = 1; i < n; i++) {
        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }

        while (s.empty() == false && s.top() < arr[i]) {
            printf("%3d %3d\n", s.top(), arr[i]);
            s.pop();
        }

        s.push(arr[i]);
    }

    while (!s.empty()) {
        printf("%3d %3d\n", s.top(), -1);
        s.pop();
    }
}

/* -------------------- MAIN DRIVER CODE ------------------ */
int main() {
    int arr[] = {11, 13, 21, 3, 5, 11, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}
