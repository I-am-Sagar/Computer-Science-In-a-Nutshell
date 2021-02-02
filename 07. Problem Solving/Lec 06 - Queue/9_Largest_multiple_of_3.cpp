/*  PROBLEM:
    Given an array of non-negative integers. Find the
    largest multiple of 3 that can be formed from array
    elements.

    For example: If the input array is {8, 1, 7, 6, 0},
    output should be “8 7 6 0”.

    SOLUTION:
    (NOTE: Before reading the solution below, we request
        the reader to read the "BIGGEST_NUMBER.cpp" problem
        given in "05-ALGORITHMS -> LEC 01 - SORTING BASED PROBLEMS")

    Approach 1 - Using Queues -> O(n*logn) solution

    1. Sort the array in non-decreasing order.
    2. Take three queues. One for storing elements which on
        dividing by 3 gives remainder as 0. The second queue
        stores digits which on dividing by 3 gives remainder as 1.
        The third queue stores digits which on dividing by 3 gives
        remainder as 2. Call them as queue0, queue1 and queue2.
    3. Find the sum of all the digits.
    4. Three cases arise:
        4.1 The sum of digits is divisible by 3. Dequeue all the
            digits from the three queues. Sort them in non-increasing order.
            Output the array.
        4.2 The sum of digits produces remainder 1 when divided by 3.
            Remove one item from queue1. If queue1 is empty, remove
            two items from queue2. If queue2 contains less than two items,
            the number is not possible.
        4.3 The sum of digits produces remainder 2 when divided by 3.
            Remove one item from queue2. If queue2 is empty, remove two
            items from queue1. If queue1 contains less than two items,
            the number is not possible.
    5. Finally empty all the queues into an auxiliary array.
        Sort the auxiliary array in non-increasing order.
        Output the auxiliary array.

    Below is it's implementation.
*/

#include<bits/stdc++.h>
using namespace std;

// Comparison function to sort numbers in lexicographic order
bool myCompare (int a, int b) {
    string temp1 = to_string(a).append(to_string(b));
    string temp2 = to_string(b).append(to_string(a));
    return (temp1 > temp2);
}

// Utility function: This function puts all the
// elements of 3 queues in the auxiliary array
void addInAuxArray (int aux[], queue<int> q0, queue<int> q1, queue<int> q2, int* top) {
    while (!q0.empty()) {
        aux[(*top)++] = q0.front();
        q0.pop();
    }
    while(!q1.empty()) {
        aux[(*top)++] = q1.front();
        q1.pop();
    }
    while(!q2.empty()) {
        aux[(*top)++] = q2.front();
        q2.pop();
    }
}

// Main Logic
void findMaxMultipleOf3 (int arr[], int size) {
    // flag will be turned false when there is no
    // number which could be formed that is multiple of 3
    bool flag = true;
    // 1. Sort the array in non-decreasing order
    sort (arr, arr+size);
    // 2. and 3. Get the sum of numbers and place
    // them into proper queues
    queue<int> queue0, queue1, queue2;
    int i, sum = 0;
    for (i = 0; i < size; i++) {
        sum += arr[i];
        if ((arr[i]%3) == 0)
            queue0.push(arr[i]);
        else if ((arr[i] % 3) == 1)
            queue1.push(arr[i]);
        else
            queue2.push(arr[i]);
    }
    // 4.2 The sum produces remainder 1
    if ((sum % 3) == 1) {
        // either remove one item from queue1
        if (!queue1.empty())
            queue1.pop();
        // or remove two items from queue2
        else {
            if (!queue2.empty())
                queue2.pop();
            else
                flag = false;

            if (!queue2.empty())
                queue2.pop();
            else
                flag = false;
        }
    }
    // 4.3 The sum produces remainder 2
    else if ((sum % 3) == 2) {
        // either remove one item from queue2
        if (!queue2.empty())
            queue2.pop();
        // or remove two items from queue1
        else {
            if (!queue1.empty())
                queue1.pop();
            else
                flag = false;

            if (!queue1.empty())
                queue1.pop();
            else
                flag = false;
        }
    }
    int aux[size], top = 0;
    addInAuxArray(aux, queue0, queue1, queue2, &top);
    sort (aux, aux+top, myCompare);

    if (!flag) {
        cout << "Not possible to form any number.\n";
    }
    else {
        for (int j = 0; j < top; j++)
            cout << aux[j] << " ";
        cout << endl;
    }
}

/* -------------- MAIN DRIVER CODE ------------- */
int main() {
    int arr[] = { 8, 81, 7, 61, 0 };
    int size = sizeof(arr) / sizeof(arr[0]);
    findMaxMultipleOf3 (arr, size);

    return 0;
}
